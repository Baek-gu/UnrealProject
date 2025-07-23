#pragma once

#include "CoreMinimal.h"
#include "ItemSpawnRow.generated.h"

USTRUCT(BlueprintType)
struct FItemSpawnRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ItemClass;
	// TSubclassOf : 하드 래퍼런스 -> 클래스가 항상 메모리에 로드된 상태에서 바로 접근
	// TSubclassPtr : 소프트 래퍼런스 -> 클래스의 경로만 유지
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpawnChance;
};
