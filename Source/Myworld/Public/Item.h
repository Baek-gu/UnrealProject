// Fill out your copyright notice in the Description page of Project Settings.

//#pragma once
//
//#include "CoreMinimal.h"
//#include "GameFramework/Actor.h"
//#include "Item.generated.h" // 리플랙션 시스템에 필요한 필수 헤더 파일 (항상 마지막)
//
//UCLASS() // 클래스를 리플랙션 시트템에 등록해주는 역할
//class MYWORLD_API AItem : public AActor
//{
//	GENERATED_BODY() //UCLASS랑 환상의 짝궁
//
//public:
//	AItem();
//
//protected:
//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Componets") // 변수를 리플랙터에 등록시키는 매크로
//	USceneComponent* SceneRoot;
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Componets")
//	UStaticMeshComponent* StaticMeshComp;
//
//	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Componets")
//	float RotationSpeed;
//
//	virtual void BeginPlay() override;
//	virtual void Tick(float DeltaTime) override;
//
//	UFUNCTION(BlueprintCallable, Category = "Item|Actions")
//	void ResetActorPosition();
//	UFUNCTION(BlueprintPure, Category = "Item|Properties")
//	float GetRotationSpeed() const;
//	UFUNCTION(BlueprintImplementableEvent, Category = "Item|Event")
//	void OnItemPickedup();
//};