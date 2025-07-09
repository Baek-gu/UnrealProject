// Fill out your copyright notice in the Description page of Project Settings.

//#pragma once
//
//#include "CoreMinimal.h"
//#include "GameFramework/Actor.h"
//#include "Item.generated.h" // ���÷��� �ý��ۿ� �ʿ��� �ʼ� ��� ���� (�׻� ������)
//
//UCLASS() // Ŭ������ ���÷��� ��Ʈ�ۿ� ������ִ� ����
//class MYWORLD_API AItem : public AActor
//{
//	GENERATED_BODY() //UCLASS�� ȯ���� ¦��
//
//public:
//	AItem();
//
//protected:
//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Componets") // ������ ���÷��Ϳ� ��Ͻ�Ű�� ��ũ��
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