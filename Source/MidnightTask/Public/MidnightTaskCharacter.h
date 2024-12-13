// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "MidnightTaskCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
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


private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* WallJump;

	FTimerHandle SlideTimer;

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

protected:

	virtual void NotifyControllerChanged() override;

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaSeconds);

	virtual void Jump();
	virtual void StopJumping();

	void PlayJumpMontage(UAnimMontage* Montage, FName JumpSide);


public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION(BlueprintPure)
	FORCEINLINE UTaskCharacterMovementComponent* GetCustomCharacterMovement() const { return MovementComponent; }


};

