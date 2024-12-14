// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ActorComponents/BulletHitInterface.h"
#include "NiagaraComponent.h"
#include "Engine/DataTable.h"
#include "Projectile.generated.h"


UCLASS()
class MIDNIGHTTASK_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProjectile();

	virtual void Tick(float DeltaTime) override;

	void FireInDirection(const FVector& ShootDirection);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* ProjectileMeshComponent;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	UNiagaraSystem* ImpactParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Properties", meta = (AllowPrivateAccess = "true"))
	float CollisionRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Properties", meta = (AllowPrivateAccess = "true"))
	float CollisionHalfHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Properties", meta = (AllowPrivateAccess = "true"))
	float InitialSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Properties", meta = (AllowPrivateAccess = "true"))
	float MaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Properties", meta = (AllowPrivateAccess = "true"))
	bool bShouldBounce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Properties", meta = (AllowPrivateAccess = "true"))
	float Bounciness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Properties", meta = (AllowPrivateAccess = "true"))
	float GravityScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Properties", meta = (AllowPrivateAccess = "true"))
	float LifeSpan;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Properties", meta = (AllowPrivateAccess = "true"))
	float ImpactImpulse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Properties", meta = (AllowPrivateAccess = "true"))
	float HitDamage;

public:
	FORCEINLINE float GetDamage() { return HitDamage; }
};