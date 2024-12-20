// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

// Sets default values
AItem::AItem() :
	ItemState(EItemState::EIS_Pickup),
	ItemName(FString("Default")),
	ItemCount(0),
	SlotIndex(0),
	bCharacterInventoryFull(false)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;

	PickupWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("PickupWidget"));
	PickupWidget->SetupAttachment(GetRootComponent());

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
	Sphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Sphere->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	if (PickupWidget)
	{
		PickupWidget->SetVisibility(false);
	}
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnSphereOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AItem::OnSphereEndOverlap);
	SetItemProperties(ItemState);

}

void AItem::SetItemProperties(EItemState State)
{
	switch (State)
	{
	case EItemState::EIS_Pickup:

		ItemMesh->SetSimulatePhysics(false);
		ItemMesh->SetVisibility(true);
		ItemMesh->SetEnableGravity(false);
		ItemMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
		ItemMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

		Sphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
		Sphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		Sphere->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);

		break;
	case EItemState::EIS_Equipped:

		PickupWidget->SetVisibility(false);
		ItemMesh->SetSimulatePhysics(false);
		ItemMesh->SetEnableGravity(false);
		ItemMesh->SetVisibility(true);
		ItemMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
		ItemMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

		Sphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
		Sphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;

	case EItemState::EIS_Falling:

		ItemMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		ItemMesh->SetSimulatePhysics(true);
		ItemMesh->SetEnableGravity(true);
		ItemMesh->SetVisibility(true);
		ItemMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
		ItemMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);

		Sphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
		Sphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;

	case EItemState::EIS_PickedUp:

		PickupWidget->SetVisibility(false);
		ItemMesh->SetSimulatePhysics(false);
		ItemMesh->SetEnableGravity(false);
		ItemMesh->SetVisibility(false);
		ItemMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
		ItemMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

		Sphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
		Sphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;
	}
}




// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::SetItemState(EItemState State)
{
	ItemState = State;
	SetItemProperties(State);
}

void AItem::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMidnightTaskCharacter* TaskCharacter = Cast<AMidnightTaskCharacter>(OtherActor);
	if (TaskCharacter)
	{
		TaskCharacter->SetOverlappingItem(this);	
		TaskCharacter->IncrementOverlappedItemCount(1);

	}

}

void AItem::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AMidnightTaskCharacter* TaskCharacter = Cast<AMidnightTaskCharacter>(OtherActor);
	if (TaskCharacter)
	{
		TaskCharacter->SetOverlappingItem(nullptr);
		TaskCharacter->IncrementOverlappedItemCount(-1);

	}
}


void AItem::PlayEquipSound(AMidnightTaskCharacter* Char, bool bForcePlaySound)
{
	Character = Char;

	if (Character)
	{
		if (bForcePlaySound)
		{
			Character->StartEquipSoundTimer();
			if (EquipSound)
			{
				UGameplayStatics::PlaySound2D(this, EquipSound);

			}
		}
		else if (Character->ShouldPlayEquipSound())
		{
			Character->StartEquipSoundTimer();
			if (EquipSound)
			{
				UGameplayStatics::PlaySound2D(this, EquipSound);

			}
		}
	}
}