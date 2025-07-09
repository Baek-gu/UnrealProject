// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFloor.h"

AMyFloor::AMyFloor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMashComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMashComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/SkyTown/Meshes/SM_StoneStairs01_2m.SM_StoneStairs01_2m'"));
	if (MeshAsset.Succeeded())
	{
		StaticMashComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Script/Engine.Material'/Game/SkyTown/Materials/M_Outhouse01_StoneBottom01.M_Outhouse01_StoneBottom01'"));
	if (MaterialAsset.Succeeded())
	{
		StaticMashComp->SetMaterial(0, MaterialAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 90.0f;

}

void AMyFloor::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(1000.0f, 1800.0f, -0.5f));
	SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
	SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));
}

void AMyFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}

