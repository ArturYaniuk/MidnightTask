// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "ActorComponents/CombatState.h"
#include "NiagaraComponent.h"
#include "MidnightTaskCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class AItem;
class AWeapon;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class AMidnightTaskCharacter : public ACharacter 
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

public:
	AMidnightTaskCharacter(const FObjectInitializer& ObjectInitializer);

	// Base turn rate, in deg/sec. Other scaling may affect final turn rate
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	// Base look up/down rate, in deg/sec. Other scaling may affect final rate
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	//The end goal of the test level
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	AActor* LevelGoalActor;

	//If the player is continuing to hold jump key
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = WallRun)
	bool bHoldingJump;

	//The extent of the wall trace
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WallRun)
	float WallRunRange;

	//The gravity scale used while wall running
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WallRun)
	float WallRunGravityScale;

	//The gravity scale used when in normal movement
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WallRun)
	float DefaultGravityScale;

	//The force the player uses to jump off of a wall
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WallRun)
	float WallJumpForce;

	//Is the player currently running on a wall
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = WallRun)
	bool bWallRunning;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = WallRun)
	bool RightWall;

	//The closest hit wall result
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = WallRun)
	FHitResult WallHit;

	//The normal vector of the previously hit wall
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = WallRun)
	FVector PreviousWallHitNormal;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Sliding)
	bool isSliding = false;

	bool CanSlide = true;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Sliding)
	float SlideReloadTime = 5.0f;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;



private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* WallJump;

	FTimerHandle SlideTimer;

	FTimerHandle EquipSoundTimer;

	bool bShouldPlayEquipSound = true;

	void ResetEquipSoundTimer();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Items, meta = (AllowPrivateAccess = "true"))
	float EquipSoundResetTime = 0.2f;

	UPROPERTY(VisibleInstanceOnly)
	AItem* OverlappingItem;

	UPROPERTY(VisibleAnywhere)
	class UHealthComponent* HealthComponent;

	UPROPERTY(VisibleAnywhere)
	class UAttackComponent* AttackComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Combat, meta = (AllowPrivateAccess = "true"))
	ECombatState CombatState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Combat, meta = (AllowPrivateAccess = "true"))
	ECharacterState CharacterState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Combat, meta = (AllowPrivateAccess = "true"))
	AItem* TraceHitItem;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Items, meta = (AllowPrivateAccess = "true"))
	AItem* TraceHitItemLastFrame;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Inventory, meta = (AllowPrivateAccess = "true"))
	TArray<AItem*> Inventory;

	const int32 INVENTORY_CAPACITY{ 2 };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Character, meta = (AllowPrivateAccess = "true"))
	bool bAiming;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* ReloadMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* EquipMontage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Combat, meta = (AllowPrivateAccess = "true"))
	AWeapon* EquippedWeapon;

	bool bShouldTraceForItems;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Items, meta = (AllowPrivateAccess = "true"))
	bool bFireButtonPressed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* HipFireMontage;

	FTimerHandle AutoFireTimer;

	FTimerHandle isPocketReloading;

	AWeapon* OldEquippedWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	int32 AmmoCapacity;

	/** Number of overlapped AItems */
	int8 OverlappedItemCount;

	// Scene component to attach to the Character's hand during reloading
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Combat, meta = (AllowPrivateAccess = "true"))
	USceneComponent* HandSceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Combat, meta = (AllowPrivateAccess = "true"))
	FTransform ClipTransform;

	float CameraDefaultFOV;

	float CameraZoomedFOV;

	float CameraCurrentFOV;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float ZoomInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	UNiagaraSystem* ImpactParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	UParticleSystem* BeamParticles;

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
	
	FHitResult CheckWall(bool bRight);

	/**
	 * Toggles player movement values when the player leaves a wall run by touching the ground or leaping off or starts a wall run.
	 */
	void ToggleWallRun(bool bEnable);

	class UTaskCharacterMovementComponent* MovementComponent;

	void Climb();

	void CancelClimb();

	void Slide();

	void CancelSlide();

	void ResetSlideTime();

	void EKeyPressed();
	void EKeyReleased();

protected:

	virtual void NotifyControllerChanged() override;

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaSeconds);

	virtual void Jump();
	virtual void StopJumping();

	void PlayJumpMontage(UAnimMontage* Montage, FName JumpSide);

	void GetPickupItem(AItem* Item);

	void EquipOrSwap(AWeapon* WeaponToEquip);

	void PlayEquipMontage(UAnimMontage* Montage);

	void StopAiming();

	void EquipWeapon(AWeapon* WeaponToEquip);

	void SwapWeapon(AWeapon* WeaponToSwap);

	void DropWeapon();

	void TraceForItems();

	bool TraceUnderCrosshairs(FHitResult& OutHitResult, FVector& OutHitLocation);

	void FireButtonPressed();

	void FireButtonReleased();

	void FireWeapon();

	bool WeaponHasAmmo(AWeapon* Weapon);

	void PlayFireSound();

	void PlayGunFireMontage();

	void StartFireTimer();

	void AutoFireReset();

	void ReloadWeapon(AWeapon* Weapon, bool pocketReload = false);

	void StartPocketReload();

	UFUNCTION(BlueprintCallable)
	void FinishReloading(AWeapon* Weapon);

	UFUNCTION(BlueprintCallable)
	void FinishEquipping();

	void OneKeyPressed();

	void TwoKeyPressed();

	void ExchangeInventoryItem(int32 NewItemIndex);

	void ExchangeWeapon(AWeapon* WeaponToExchange);

	void ReloadButtonPressed();

	UFUNCTION(BlueprintCallable)
	void GrabClip();

	UFUNCTION(BlueprintCallable)
	void ReleaseClip();

	void AimingButtonPressed();

	void AimigButtonReleased();
	
	void CameraInterpZoom(float DeltaTime);

	void SendBullet();

	bool GetBeamEndLocation(
		const FVector& MuzzleSocketLocation,
		FHitResult& OutHitResult);


public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION(BlueprintPure)
	FORCEINLINE UTaskCharacterMovementComponent* GetCustomCharacterMovement() const { return MovementComponent; }

	void StartEquipSoundTimer();

	FORCEINLINE bool ShouldPlayEquipSound() const { return bShouldPlayEquipSound; }
	FORCEINLINE void SetOverlappingItem(AItem* Item) { OverlappingItem = Item; }

	void IncrementOverlappedItemCount(int8 Amount);

};

