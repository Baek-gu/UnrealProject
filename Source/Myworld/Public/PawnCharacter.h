#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "PawnCharacter.generated.h"

class UCapsuleComponent;
class USkeletalMeshComponent;
class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;

UCLASS()
class MYWORLD_API APawnCharacter : public APawn
{
	GENERATED_BODY()

public:
	APawnCharacter();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCapsuleComponent* Capslecomp; 

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USkeletalMeshComponent* SkeletalMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inputs")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inputs")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inputs")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MouseSensitivity;

	float CurrentYaw; // 좌우 회전 각도 정의
	float CurrentPitch; // 상하 회전 각도 정의

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; // 플레이어 입력 컴포넌트 설정
};