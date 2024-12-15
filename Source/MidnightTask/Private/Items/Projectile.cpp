// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Projectile.h"
#include "./Items/Weapon.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AProjectile::AProjectile() :
	CollisionRadius(15.0f),
	CollisionHalfHeight(40.0f),
	InitialSpeed(3000.0f),
	MaxSpeed(3000.0f),
	bShouldBounce(true),
	Bounciness(0.5f),
	GravityScale(0.5f),
	LifeSpan(3.0f),
	ImpactImpulse(100.0f),
	HitDamage(1.0f)
{
	PrimaryActorTick.bCanEverTick = true;


	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSceneComponent"));

	ProjectileStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileStaticMeshComponent"));


	CollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("SphereComponent"));
	// Set the sphere's collision profile name to "Projectile".
	CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
	// Event called when component hits something.
	CollisionComponent->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
	// Set the Capsule's collision radius.
	CollisionComponent->InitCapsuleSize(CollisionRadius, CollisionHalfHeight);
	// Set the root component to be the collision component.
	RootComponent = CollisionComponent;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileStaticMeshComponent->SetupAttachment(RootComponent);

	ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionComponent->InitCapsuleSize(CollisionRadius, CollisionHalfHeight);
	ProjectileMovementComponent->InitialSpeed = InitialSpeed;
	ProjectileMovementComponent->MaxSpeed = MaxSpeed;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bRotationRemainsVertical = true;
	ProjectileMovementComponent->bShouldBounce = bShouldBounce;
	ProjectileMovementComponent->Bounciness = Bounciness;
	ProjectileMovementComponent->ProjectileGravityScale = GravityScale;



	// Delete the projectile after 3 seconds.
	InitialLifeSpan = LifeSpan;
}

void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != nullptr && OtherActor != this && OtherComponent != nullptr && OtherComponent->IsSimulatingPhysics())
	{

		OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * ImpactImpulse, Hit.ImpactPoint);

	}

	if (OtherActor != nullptr && OtherActor != this && OtherComponent != nullptr)
	{

		FHitResult BeamHitResult;

		IBulletHitInterface* BulletHitInterface = Cast<IBulletHitInterface>(OtherActor);
		if (BulletHitInterface)
		{
			BulletHitInterface->BulletHit_Implementation(Hit);
		}

		auto HitEnemy = Cast<APawn>(OtherActor);
		if (HitEnemy)
		{

			UGameplayStatics::ApplyDamage(
				OtherActor,
				HitDamage,
				HitEnemy->GetController(),
				Owner,
				UDamageType::StaticClass());

		}



		else
		{
			// Spawn default particles
			if (ImpactParticles)
			{
				UNiagaraFunctionLibrary::SpawnSystemAtLocation(
					GetWorld(),
					ImpactParticles,
					Hit.Location,
					Hit.ImpactPoint.Rotation());
			}
		}

	}
	Destroy(true);
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::FireInDirection(const FVector& ShootDirection)
{
	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}

