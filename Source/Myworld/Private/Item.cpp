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
//	PrimaryActorTick.bCanEverTick = true; //특별하게 사용을 안한다면 flase로 두기
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
//	//- y 축, z축, x축
//}
//
//void AItem::Tick(float DeltaTime) // DeltaTime -> 프레임당 시간 <중요함> - 프레임 독립적인 시간
//{
//	Super::Tick(DeltaTime);
//
//	//AddActorLocalRotation(FRotator(0.0f, RotationSpeed, 0.0f)); ->  이렇게 구현할 시 문제점은 매 프레임마다 실행이 됨 
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


// - 생성 - 
// 생성자 - 메모리에 생기며 딱 한 번 호출됨
// PostInitialzeComponents() - 컴포넌트가 완선된 직후 호출. 컴포넌트끼리 데이터 주고 받고 상호작용함
// BeginPlay() - 배치 (Spawn) 직후

// - 행동 - 
// Tick(float DeltaTime) - 매 프레임마다 호출 

// - 죽음 -
// Destoyed() - 삭제 되기 직전에 호출
// EndPlay() - 게임 종료, 파괴 (Destoryed()), 레벨 전환


// Destoyed 할 시 EndPlay 자동으로 실행
// 만약 게임을 강제로 종료 시키면 EndPlay가 바로 호출