#pragma once

#include "CoreMinimal.h"
#include "ItemSpawnRow.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

class UBoxComponent;

UCLASS()
class MYWORLD_API ASpawnVolume : public AActor
{
    GENERATED_BODY()
	
public:	
    ASpawnVolume();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
    USceneComponent* Scene;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
    UBoxComponent* SpawningBox;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
    UDataTable* ItemDataTable;

    UFUNCTION(BlueprintCallable, Category = "Spawning")
    AActor* SpawnRandomItem(); // 리턴 형식을 AActor* 로 변경

    FItemSpawnRow* GetRandomItem() const;
    AActor* SpawnItem(TSubclassOf<AActor> ItemClass);
    FVector GetRandomPointInVolume() const;
};