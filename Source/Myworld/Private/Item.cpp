// Fill out your copyright notice in the Description page of Project Settings.


//#include "Item.h"
//
//AItem::AItem()
//{
//	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
//	SetRootComponent(SceneRoot);
//
//	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
//	StaticMeshComp->SetupAttachment(SceneRoot);
//
//	//static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Star_B.SM_Star_B"));
//	//if (MeshAsset.Succeeded())
//	//{
//	//	StaticMeshComp->SetStaticMesh(MeshAsset.Object);
//	//}
//
//	//static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Gem_D.M_Gem_D"));
//	//if (MaterialAsset.Succeeded())
//	//{
//	//	StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
//	//}
//
//
//	PrimaryActorTick.bCanEverTick = true; //Ư���ϰ� ����� ���Ѵٸ� flase�� �α�
//	RotationSpeed = 90.0f;
//}
//
//void AItem::BeginPlay()
//{
//	Super::BeginPlay();
//
//	OnItemPickedup();
//
//	//SetActorLocation(FVector(300.0f, 200.0f, 100.0f));
//	//SetActorRotation(FRotator(0.0f, 90.0f, 0.0f)); 
//	//SetActorScale3D(FVector(2.0f));
//
//	//FVector NewLocation(300.0f, 200.0f, 100.0f);
//	//FRotator NewRotator(0.0f, 90.0f, 0.0f);
//	//FVector NewScale(2.0f);
//
//	//FTransform NewTransform(NewLocation, NewRotator, NewScale);
//
//
//	//SetActorTransform(NewTransform);
//
//	//- pitch, yaw, roll
//	//- y ��, z��, x��
//}
//
//void AItem::Tick(float DeltaTime) // DeltaTime -> �����Ӵ� �ð� <�߿���> - ������ �������� �ð�
//{
//	Super::Tick(DeltaTime);
//
//	//AddActorLocalRotation(FRotator(0.0f, RotationSpeed, 0.0f)); ->  �̷��� ������ �� �������� �� �����Ӹ��� ������ �� 
//
//	if(!FMath::IsNearlyZero(RotationSpeed))
//	{ 
//	AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
//	}
//}
//
//void AItem::ResetActorPosition()
//{
//	SetActorLocation(FVector::ZeroVector);
//}
//
//float AItem::GetRotationSpeed() const
//{
//	return RotationSpeed;
//}


// - ���� - 
// ������ - �޸𸮿� ����� �� �� �� ȣ���
// PostInitialzeComponents() - ������Ʈ�� �ϼ��� ���� ȣ��. ������Ʈ���� ������ �ְ� �ް� ��ȣ�ۿ���
// BeginPlay() - ��ġ (Spawn) ����

// - �ൿ - 
// Tick(float DeltaTime) - �� �����Ӹ��� ȣ�� 

// - ���� -
// Destoyed() - ���� �Ǳ� ������ ȣ��
// EndPlay() - ���� ����, �ı� (Destoryed()), ���� ��ȯ


// Destoyed �� �� EndPlay �ڵ����� ����
// ���� ������ ������ ���� ��Ű�� EndPlay�� �ٷ� ȣ��