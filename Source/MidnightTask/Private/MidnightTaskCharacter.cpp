// Copyright Epic Games, Inc. All Rights Reserved.

#include "MidnightTaskCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "TaskCharacterMovementComponent.h"
#include "InputActionValue.h"
#include "ActorComponents/HealthComponent.h"
#include "ActorComponents/AttackComponent.h"
#include "ActorComponents/CombatState.h"
#include "Items/Weapon.h"
#include "Components/WidgetComponent.h"
#include "Sound/SoundCue.h"


DEFINE_LOG_CATEGORY(LogTemplateCharacter);


AMidnightTaskCharacter::AMidnightTaskCharacter(const FObjectInitializer& ObjectInitializer) : 
	Super(ObjectInitializer.SetDefaultSubobjectClass<UTaskCharacterMovementComponent>(ACharacter::CharacterMovementComponentName)) ,
	CombatState(ECombatState::ECS_Unoccupied),
	CharacterState(ECharacterState::ECS_Unequipped),
	bShouldTraceForItems(false),
	bFireButtonPressed(false),
	AmmoCapacity(100),
	OverlappedItemCount(0),
	bAiming(false),
	CameraDefaultFOV(90.f),
	CameraZoomedFOV(60.f),
	CameraCurrentFOV(0.f),
	ZoomInterpSpeed(0.f)

{
	MovementComponent = Cast<UTaskCharacterMovementComponent>(GetCharacterMovement());

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	//Wall run gravity values
	WallRunGravityScale = 0.65f;
	DefaultGravityScale = 1.8f;
	WallJumpForce = 450.0f;
	WallRunRange = 40.0f;


	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	HandSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("HandSceneComp"));

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));

	AttackComponent = CreateDefaultSubobject<UAttackComponent>(TEXT("Attack Component"));
}

//////////////////////////////////////////////////////////////////////////
// Input

void AMidnightTaskCharacter::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();

	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void AMidnightTaskCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMidnightTaskCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMidnightTaskCharacter::Look);

		PlayerInputComponent->BindAction("Climb", IE_Pressed, this, &AMidnightTaskCharacter::Climb);
		PlayerInputComponent->BindAction("Cancel Climb", IE_Pressed, this, &AMidnightTaskCharacter::CancelClimb);

		PlayerInputComponent->BindAction("Slide", IE_Pressed, this, &AMidnightTaskCharacter::Slide);
		PlayerInputComponent->BindAction("Slide", IE_Released, this, &AMidnightTaskCharacter::CancelSlide);

		PlayerInputComponent->BindAction("Equip", IE_Pressed, this, &AMidnightTaskCharacter::EKeyPressed);
		PlayerInputComponent->BindAction("Equip", IE_Released, this, &AMidnightTaskCharacter::EKeyReleased);

		PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AMidnightTaskCharacter::FireButtonPressed);
		PlayerInputComponent->BindAction("Attack", IE_Released, this, &AMidnightTaskCharacter::FireButtonReleased);

		PlayerInputComponent->BindAction("AimingButton", IE_Pressed, this, &AMidnightTaskCharacter::AimingButtonPressed);
		PlayerInputComponent->BindAction("AimingButton", IE_Released, this, &AMidnightTaskCharacter::AimigButtonReleased);


		PlayerInputComponent->BindAction("1Key", IE_Pressed, this, &AMidnightTaskCharacter::OneKeyPressed);
		PlayerInputComponent->BindAction("2Key", IE_Pressed, this, &AMidnightTaskCharacter::TwoKeyPressed);

		PlayerInputComponent->BindAction("ReloadButton", IE_Pressed, this, &AMidnightTaskCharacter::ReloadButtonPressed);




	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AMidnightTaskCharacter::Tick(float DeltaSeconds)
{ 
	Super::Tick(DeltaSeconds);

	if (GetCharacterMovement()->IsFalling() && bHoldingJump)
	{
		FHitResult HitOutR = CheckWall(true);
		FHitResult HitOutL = CheckWall(false);

		if (WallHit.bBlockingHit) PreviousWallHitNormal = WallHit.ImpactNormal;

		WallHit = HitOutR.Distance >= HitOutL.Distance ? HitOutR : HitOutL;
		
		if (HitOutR.Distance >= HitOutL.Distance) RightWall = true;
		else RightWall = false;
	
		if (WallHit.bBlockingHit && !bWallRunning) ToggleWallRun(true);
		else if (!WallHit.bBlockingHit && bWallRunning)	ToggleWallRun(false);
		
	}
	else if (bWallRunning)
	{
		ToggleWallRun(false);
	}

	TraceForItems();
	CameraInterpZoom(DeltaSeconds);

}

void AMidnightTaskCharacter::Jump()
{
	bHoldingJump = true;

	Super::Jump();
}

void AMidnightTaskCharacter::StopJumping()
{
	//If the player is wall running when jump is released, perform a leap from the wall
	if (bWallRunning)
	{
		FVector LaunchVector = WallHit.ImpactNormal;
		LaunchVector.Normalize();

		LaunchVector = (LaunchVector + (GetActorUpVector() * 1.0)) / 2;

		LaunchCharacter(LaunchVector * WallJumpForce, false, false);

		if (CheckWall(true).Distance >= CheckWall(true).Distance) PlayJumpMontage(WallJump, "Right");
		else PlayJumpMontage(WallJump, "Left");
	}

	bHoldingJump = false;

	Super::StopJumping();
}

void AMidnightTaskCharacter::PlayJumpMontage(UAnimMontage* Montage, FName JumpSide)
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();

	if (AnimInstance && Montage)
	{
		AnimInstance->Montage_Play(Montage);
		AnimInstance->Montage_JumpToSection(JumpSide);
	}
}

void AMidnightTaskCharacter::GetPickupItem(AItem* Item)
{
	AWeapon* OverlappingWeapon = Cast<AWeapon>(Item);

	if (OverlappingWeapon)
	{
		EquipOrSwap(OverlappingWeapon);
		Item->PlayEquipSound(this);
	}
}

void AMidnightTaskCharacter::EquipOrSwap(AWeapon* WeaponToEquip)
{
	
	 if (Inventory.Num() < INVENTORY_CAPACITY)
	{
		WeaponToEquip->SetSlotIndex(Inventory.Num());
		PlayEquipMontage(EquipMontage);
		Inventory.Add(WeaponToEquip);
		WeaponToEquip->SetItemState(EItemState::EIS_PickedUp);
		return;
	}
	else
	{
		for (size_t i = 0; i < INVENTORY_CAPACITY; i++)
		{
			if (Inventory[i] == nullptr)
			{
				EquipWeapon(WeaponToEquip);
				Inventory[i] = WeaponToEquip;
				WeaponToEquip->SetItemState(EItemState::EIS_PickedUp);
				return;
			}
		}
	}

	SwapWeapon(WeaponToEquip);
}

void AMidnightTaskCharacter::PlayEquipMontage(UAnimMontage* Montage)
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();

	if (AnimInstance && Montage)
	{
		StopAiming();
		AnimInstance->Montage_Play(Montage);
		AnimInstance->Montage_JumpToSection(FName("Equip"));
	}
}

void AMidnightTaskCharacter::StopAiming()
{
	if (bAiming)
	{
		bAiming = false;
	}
}

void AMidnightTaskCharacter::EquipWeapon(AWeapon* WeaponToEquip)
{
	
	WeaponToEquip->Equip(GetMesh(), FName("RightHandSocket"));
	EquippedWeapon = WeaponToEquip;
	CharacterState = ECharacterState::ECS_EquipedFirstWeapon;
	EquippedWeapon->SetItemState(EItemState::EIS_Equipped);
	StopAiming();

}

void AMidnightTaskCharacter::SwapWeapon(AWeapon* WeaponToSwap)
{
	if (EquippedWeapon == nullptr)
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(20, -1, FColor::Cyan, TEXT("HOTBAR IS FULL"));
		return;
	}
	if (Inventory.Num() - 1 >= EquippedWeapon->GetSlotIndex())
	{
		Inventory[EquippedWeapon->GetSlotIndex()] = WeaponToSwap;
		WeaponToSwap->SetSlotIndex(EquippedWeapon->GetSlotIndex());
	}
	DropWeapon();
	EquipWeapon(WeaponToSwap);
	TraceHitItem = nullptr;
	TraceHitItemLastFrame = nullptr;
}

void AMidnightTaskCharacter::DropWeapon()
{
	if (EquippedWeapon)
	{
		if (EquippedWeapon->GetItemState() == EItemState::EIS_Falling || EquippedWeapon->GetItemState() == EItemState::EIS_Pickup) return;
		FDetachmentTransformRules DetachmentTransformRules(EDetachmentRule::KeepWorld, true);
		EquippedWeapon->GetItemMesh()->DetachFromComponent(DetachmentTransformRules);
		EquippedWeapon->SetItemState(EItemState::EIS_Falling);
		EquippedWeapon->ThrowWeapon();
		StopAiming();

	}
}

void AMidnightTaskCharacter::TraceForItems()
{
	if (bShouldTraceForItems)
	{
		FHitResult ItemTraceResult;
		FVector HitLocation;
		TraceUnderCrosshairs(ItemTraceResult, HitLocation);
		if (ItemTraceResult.bBlockingHit)
		{

			TraceHitItem = Cast<AItem>(ItemTraceResult.GetActor());

			if (TraceHitItem && TraceHitItem->GetItemState() == EItemState::EIS_Equipped)
			{
				TraceHitItem = nullptr;
				return;
			}

			if (TraceHitItem && TraceHitItem->GetPickupWidget())
			{
				TraceHitItem->GetPickupWidget()->SetVisibility(true);

				if (Inventory.Num() >= INVENTORY_CAPACITY) TraceHitItem->SetCharacterInventoryFull(true);
				else TraceHitItem->SetCharacterInventoryFull(false);
			}

			if (TraceHitItemLastFrame)
			{
				if (TraceHitItem != TraceHitItemLastFrame)	TraceHitItemLastFrame->GetPickupWidget()->SetVisibility(false);
			}
			TraceHitItemLastFrame = TraceHitItem;
		}
	}
	else if (TraceHitItemLastFrame)
	{
		TraceHitItemLastFrame->GetPickupWidget()->SetVisibility(false);
	}
}

bool AMidnightTaskCharacter::TraceUnderCrosshairs(FHitResult& OutHitResult, FVector& OutHitLocation)
{
	FVector2D ViewportSize{};
	if (GEngine && GEngine->GameViewport)
	{
		GEngine->GameViewport->GetViewportSize(ViewportSize);
	}

	FVector2D CrosshairLocation(ViewportSize.X / 2.f, ViewportSize.Y / 2.f);
	FVector CrosshairWorldPosition;
	FVector CrossHairWorldDirection;

	//Get world position and direction of crosshairs

	bool bScreenToWorld = UGameplayStatics::DeprojectScreenToWorld(
		UGameplayStatics::GetPlayerController(this, 0),
		CrosshairLocation,
		CrosshairWorldPosition,
		CrossHairWorldDirection);

	if (bScreenToWorld)
	{
		const FVector Start{ CrosshairWorldPosition };
		const FVector End{ Start + CrossHairWorldDirection * 50'000.f };
		OutHitLocation = End;
		GetWorld()->LineTraceSingleByChannel(OutHitResult, Start, End, ECollisionChannel::ECC_Visibility);

		if (OutHitResult.bBlockingHit)
		{
			OutHitLocation = OutHitResult.Location;
			return true;
		}
	}
	return false;
}

void AMidnightTaskCharacter::FireButtonPressed()
{
	bFireButtonPressed = true;
	FireWeapon();
}

void AMidnightTaskCharacter::FireButtonReleased()
{
	bFireButtonPressed = false;
}

void AMidnightTaskCharacter::FireWeapon()
{
	if (EquippedWeapon == nullptr) return;
	if (CombatState != ECombatState::ECS_Unoccupied) return;

	if (WeaponHasAmmo(EquippedWeapon))
	{
		PlayFireSound();
		

		AttackComponent->SpawnProjectile(EquippedWeapon->GetItemMesh()->GetSocketByName("BarrelSocket"), EquippedWeapon->GetItemMesh(),	EquippedWeapon->GetMuzzleFash(), GetViewRotation().Vector());

		PlayGunFireMontage();
		EquippedWeapon->DecrementAmmo();

		StartFireTimer();
	}
}

bool AMidnightTaskCharacter::WeaponHasAmmo(AWeapon* Weapon)
{
	if (Weapon == nullptr)	return false;

	return Weapon->GetAmmo() > 0;
}

void AMidnightTaskCharacter::PlayFireSound()
{
	if (EquippedWeapon->GetFireSound())
	{
		UGameplayStatics::PlaySound2D(this, EquippedWeapon->GetFireSound());
	}
}

void AMidnightTaskCharacter::PlayGunFireMontage()
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance && HipFireMontage)
	{
		AnimInstance->Montage_Play(HipFireMontage);
		AnimInstance->Montage_JumpToSection(FName("StartFire"));
	}
}

void AMidnightTaskCharacter::StartFireTimer()
{
	if (EquippedWeapon == nullptr) return;

	CombatState = ECombatState::ECS_FireTimerInProgress;
	GetWorldTimerManager().SetTimer(AutoFireTimer, this, &AMidnightTaskCharacter::AutoFireReset, EquippedWeapon->GetAutoFireRate());
}

void AMidnightTaskCharacter::AutoFireReset()
{
	CombatState = ECombatState::ECS_Unoccupied;

	if (WeaponHasAmmo(EquippedWeapon))
	{
		if (bFireButtonPressed)
		{
			FireWeapon();
		}
	}
	else
	{
		ReloadWeapon(EquippedWeapon);
	}
}

void AMidnightTaskCharacter::ReloadWeapon(AWeapon* Weapon, bool pocketReload)
{
	if (Weapon == nullptr) return;
	if (pocketReload)
	{
		GetWorldTimerManager().SetTimer(isPocketReloading, this, &AMidnightTaskCharacter::StartPocketReload, 1.0f);
	}
	if (CombatState != ECombatState::ECS_Unoccupied) return;

	if (!pocketReload)
	{
		if ((AmmoCapacity > 0) && !EquippedWeapon->ClipIsFull())
		{
			CombatState = ECombatState::ECS_Reloading;

			UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
			StopAiming();
			if (AnimInstance && ReloadMontage)
			{
				AnimInstance->Montage_Play(ReloadMontage);
				AnimInstance->Montage_JumpToSection(Weapon->GetReloadMontageSection());
			}
		}
	}


}

void AMidnightTaskCharacter::StartPocketReload()
{
	if (OldEquippedWeapon)
	{
		FinishReloading(OldEquippedWeapon);
	}
}

void AMidnightTaskCharacter::FinishReloading(AWeapon* Weapon)
{
	CombatState = ECombatState::ECS_Unoccupied;
	if (Weapon == nullptr) return;

	
	

	const int32 MagEmptySpace = Weapon->GetMagazineCapacity() - Weapon->GetAmmo();

	if (MagEmptySpace > AmmoCapacity)
	{
		// reload the magazine with all the ammo we are carrying
		Weapon->ReloadAmmo(AmmoCapacity);
		AmmoCapacity = 0;
	}
	else
	{
		// fill the magazine
		Weapon->ReloadAmmo(MagEmptySpace);
		AmmoCapacity -= MagEmptySpace;
	}
	
}

void AMidnightTaskCharacter::FinishEquipping()
{
	CombatState = ECombatState::ECS_Unoccupied;
}

void AMidnightTaskCharacter::OneKeyPressed()
{
	ExchangeInventoryItem(0);
}

void AMidnightTaskCharacter::TwoKeyPressed()
{
	ExchangeInventoryItem(1);
}

void AMidnightTaskCharacter::ExchangeInventoryItem(int32 NewItemIndex)
{
	if (NewItemIndex >= Inventory.Num()) return;

	auto NewWeapon = Cast<AWeapon>(Inventory[NewItemIndex]);

	if (EquippedWeapon == nullptr)
	{
		EquipWeapon(NewWeapon);
		NewWeapon->SetItemState(EItemState::EIS_Equipped);
		PlayEquipMontage(EquipMontage);
		NewWeapon->PlayEquipSound(this, true);
		return;
	}

	else if ((EquippedWeapon->GetSlotIndex() == NewItemIndex) || (Inventory[NewItemIndex] == nullptr) || CombatState != ECombatState::ECS_Unoccupied) return;

	else ExchangeWeapon(NewWeapon);


}

void AMidnightTaskCharacter::ExchangeWeapon(AWeapon* WeaponToExchange)
{
	
	OldEquippedWeapon = EquippedWeapon;
	OldEquippedWeapon->SetItemState(EItemState::EIS_PickedUp);

	if (OldEquippedWeapon->GetItemState() == EItemState::EIS_Pickup) return;

	ReloadWeapon(OldEquippedWeapon, true);
	
	EquipWeapon(WeaponToExchange);

	if (WeaponToExchange->GetItemState() == EItemState::EIS_Pickup) return;

	WeaponToExchange->SetItemState(EItemState::EIS_Equipped);

	CombatState = ECombatState::ECS_Equipping;

	PlayEquipMontage(EquipMontage);
	WeaponToExchange->PlayEquipSound(this, true);

}

void AMidnightTaskCharacter::ReloadButtonPressed()
{
	ReloadWeapon(EquippedWeapon);
}

void AMidnightTaskCharacter::GrabClip()
{
	if (EquippedWeapon == nullptr) return;
	if (HandSceneComponent == nullptr) return;

	int32 ClipBoneIndex{ EquippedWeapon->GetItemMesh()->GetBoneIndex(EquippedWeapon->GetClipBoneName()) };

	ClipTransform = EquippedWeapon->GetItemMesh()->GetBoneTransform(ClipBoneIndex);

	FAttachmentTransformRules AttachmentRules(EAttachmentRule::KeepRelative, true);
	HandSceneComponent->AttachToComponent(GetMesh(), AttachmentRules, FName(TEXT("b_LeftHand")));
	HandSceneComponent->SetWorldTransform(ClipTransform);

	EquippedWeapon->SetMovingClip(true);
}

void AMidnightTaskCharacter::ReleaseClip()
{
	EquippedWeapon->SetMovingClip(false);
}

void AMidnightTaskCharacter::AimingButtonPressed()
{
	if (CombatState == ECombatState::ECS_Reloading || CombatState == ECombatState::ECS_Equipping) return;
	bAiming = true;
	GetCharacterMovement()->MaxWalkSpeed = 300;
}

void AMidnightTaskCharacter::AimigButtonReleased()
{
	bAiming = false;
	GetCharacterMovement()->MaxWalkSpeed = 500;
}

void AMidnightTaskCharacter::CameraInterpZoom(float DeltaTime)
{
	if (bAiming)
	{
		CameraCurrentFOV = FMath::FInterpTo(CameraCurrentFOV, CameraZoomedFOV, DeltaTime, ZoomInterpSpeed);
	}
	else
	{
		CameraCurrentFOV = FMath::FInterpTo(CameraCurrentFOV, CameraDefaultFOV, DeltaTime, ZoomInterpSpeed);
	}
	GetFollowCamera()->SetFieldOfView(CameraCurrentFOV);
}

void AMidnightTaskCharacter::IncrementOverlappedItemCount(int8 Amount)
{
	if (OverlappedItemCount + Amount <= 0)
	{
		OverlappedItemCount = 0;
		bShouldTraceForItems = false;
	}
	else
	{
		OverlappedItemCount += Amount;
		bShouldTraceForItems = true;
	}
}

void AMidnightTaskCharacter::StartEquipSoundTimer()
{
	bShouldPlayEquipSound = false;
	GetWorldTimerManager().SetTimer(EquipSoundTimer, this, &AMidnightTaskCharacter::ResetEquipSoundTimer, EquipSoundResetTime);
}

float AMidnightTaskCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	HealthComponent->ReceiveDamage(DamageAmount);
	if (!HealthComponent->IsAlive())
	{
		//TODO: Player death
	}
	return DamageAmount;
}

void AMidnightTaskCharacter::ResetEquipSoundTimer()
{
	bShouldPlayEquipSound = true;
}

void AMidnightTaskCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();
	FVector DirectionX;
	FVector DirectionY;

	if (Controller != nullptr && !MovementComponent->IsClimbing())
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		if(!bWallRunning)AddMovementInput(RightDirection, MovementVector.X);
	}
	else if (Controller != nullptr && MovementComponent->IsClimbing())
	{
		DirectionY = FVector::CrossProduct(MovementComponent->GetClimbSurfaceNormal(), -GetActorRightVector());
		DirectionX = FVector::CrossProduct(MovementComponent->GetClimbSurfaceNormal(), GetActorUpVector());

		AddMovementInput(DirectionY, MovementVector.Y);
		AddMovementInput(DirectionX, MovementVector.X);
	}
}

void AMidnightTaskCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

FHitResult AMidnightTaskCharacter::CheckWall(bool bRight)
{
	const FName TraceTag("WallTraceTag");

	FCollisionQueryParams TraceParams = FCollisionQueryParams(TraceTag, true, this);
	TraceParams.bTraceComplex = true;
	TraceParams.bReturnPhysicalMaterial = false;
	TraceParams.bFindInitialOverlaps = true;

	FHitResult HitOut(ForceInit);

	float DirectionMultiplier = bRight ? WallRunRange : -1.0f * WallRunRange;
	FVector End = GetActorLocation() + (GetActorForwardVector() * GetCapsuleComponent()->GetScaledCapsuleRadius()) + (GetActorRightVector() * DirectionMultiplier);

	FCollisionShape TraceShape = FCollisionShape::MakeSphere(30.0f);

	GetWorld()->SweepSingleByChannel(
		HitOut,
		GetActorLocation(),
		End,
		GetActorRotation().Quaternion(),
		ECollisionChannel::ECC_Visibility,
		TraceShape,
		TraceParams
	);

	return HitOut;
}

void AMidnightTaskCharacter::ToggleWallRun(bool bEnable)
{
	if (bEnable)
	{
		GetCharacterMovement()->GravityScale = WallRunGravityScale;

		APlayerController* PC = Cast<APlayerController>(GetController());
		PC->PlayerCameraManager->ViewPitchMax = 20.0f;
		PC->PlayerCameraManager->ViewPitchMin = -20.0f;

		if (FVector::DotProduct(GetActorUpVector(), GetVelocity() / GetVelocity().Size()) < 0.0f && PreviousWallHitNormal != WallHit.ImpactNormal)
		{
			LaunchCharacter(GetActorUpVector() * 100.0f, false, true);
		}

		bWallRunning = true;
	}
	else
	{
		GetCharacterMovement()->GravityScale = DefaultGravityScale;

		APlayerController* PC = Cast<APlayerController>(GetController());
		PC->PlayerCameraManager->ViewPitchMax = 89.900002;
		PC->PlayerCameraManager->ViewPitchMin = -89.900002;

		bWallRunning = false;
	}
}

void AMidnightTaskCharacter::Climb()
{
	MovementComponent->TryClimbing();
}

void AMidnightTaskCharacter::CancelClimb()
{
	MovementComponent->CancelClimbing();
}

void AMidnightTaskCharacter::Slide()
{
	if (!isSliding && CanSlide && !GetCharacterMovement()->IsFalling() && (GetVelocity().Length() > 0))
	{
		isSliding = true;
		CanSlide = false;
		GetCharacterMovement()->GroundFriction = 4;
		GetCharacterMovement()->BrakingDecelerationWalking = 100;
		LaunchCharacter(GetActorForwardVector() * 1125, false, true);
	}
}

void AMidnightTaskCharacter::CancelSlide()
{
	isSliding = false;
	GetCharacterMovement()->GroundFriction = 8;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000;

	GetWorldTimerManager().SetTimer(SlideTimer, this, &AMidnightTaskCharacter::ResetSlideTime, SlideReloadTime);
}

void AMidnightTaskCharacter::ResetSlideTime()
{
	CanSlide = true;
}

void AMidnightTaskCharacter::EKeyPressed()
{
	if (CombatState != ECombatState::ECS_Unoccupied) return;

	if (TraceHitItem)
	{
		GetPickupItem(OverlappingItem);
		TraceHitItem = nullptr;
	}
}

void AMidnightTaskCharacter::EKeyReleased()
{
}

