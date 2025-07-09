// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"
#include "MyFloorMove.generated.h"

UCLASS()
class MYWORLD_API AMyFloorMove : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyFloorMove();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MovementRange = 400.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float TransformSpeed = 300.0f;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* StaticMashComp;

	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

private:
	FVector StartLocation;
	FVector TargetLocation;
	bool bMovingToTarget = true;
};
