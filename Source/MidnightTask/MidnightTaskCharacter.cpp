// Copyright Epic Games, Inc. All Rights Reserved.

#include "MidnightTaskCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AMidnightTaskCharacter

AMidnightTaskCharacter::AMidnightTaskCharacter()
{
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

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
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
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AMidnightTaskCharacter::Tick(float DeltaSeconds)
{
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

	Super::Tick(DeltaSeconds);
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

void AMidnightTaskCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
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

