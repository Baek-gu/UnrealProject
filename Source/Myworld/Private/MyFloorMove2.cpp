#include "MyFloorMove2.h"

AMyFloorMove2::AMyFloorMove2()
{
    PrimaryActorTick.bCanEverTick = true;

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
}

void AMyFloorMove2::BeginPlay()
{
    Super::BeginPlay();

    StartLocation = FVector(180.0f, 1600.0f, -300.0f);
    SetActorLocation(StartLocation);
    SetActorRotation(FRotator::ZeroRotator);
    SetActorScale3D(FVector::OneVector);

    TargetLocation = StartLocation + FVector(0.0f, 0.0f, MovementRange);
}

void AMyFloorMove2::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!FMath::IsNearlyZero(TransformSpeed))
    {
        FVector CurrentLocation = GetActorLocation();
        FVector MoveDirection;

        if (bMovingToTarget)
        {
            MoveDirection = FVector(0.0f, 0.0f, 1.0f);
            if (CurrentLocation.Z >= TargetLocation.Z)
            {
                bMovingToTarget = false;
            }
        }
        else
        {
            MoveDirection = FVector(0.0f, 0.0f, -1.0f);
            if (CurrentLocation.Z <= StartLocation.Z)
            {
                bMovingToTarget = true;
            }
        }

        FVector DeltaLocation = MoveDirection * TransformSpeed * DeltaTime;
        AddActorLocalOffset(DeltaLocation);
    }
}
