#include "PawnCharacter.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

APawnCharacter::APawnCharacter()
{
    PrimaryActorTick.bCanEverTick = false;

    MovementSpeed = 600.0f;
    MouseSensitivity = 2.0f;
    CurrentYaw = 0.0f;
    CurrentPitch = 0.0f;
        
    Capslecomp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent")); // ĸ�� ������Ʈ - ��Ʈ ������Ʈ
    RootComponent = Capslecomp;
    Capslecomp->SetCapsuleHalfHeight(88.0f);
    Capslecomp->SetCapsuleRadius(34.0f);
    Capslecomp->SetSimulatePhysics(false);
    Capslecomp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    Capslecomp->SetCollisionResponseToAllChannels(ECR_Block);
        
    SkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent")); // ���̷�Ż �޽� ������Ʈ
    SkeletalMeshComp->SetupAttachment(RootComponent);
    SkeletalMeshComp->SetRelativeLocation(FVector(0.0f, 0.0f, -88.0f));
    SkeletalMeshComp->SetSimulatePhysics(false);
    SkeletalMeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        
    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent")); // ������ �� ������Ʈ
    SpringArmComp->SetupAttachment(RootComponent);
    SpringArmComp->TargetArmLength = 400.0f;
    SpringArmComp->bUsePawnControlRotation = false;
    SpringArmComp->bInheritPitch = false;
    SpringArmComp->bInheritYaw = false;
    SpringArmComp->bInheritRoll = false;
    SpringArmComp->bDoCollisionTest = true;
        
    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent")); // ī�޶� ������Ʈ
    CameraComp->SetupAttachment(SpringArmComp);
}

void APawnCharacter::BeginPlay()
{
    Super::BeginPlay();

    if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
        {
            Subsystem->AddMappingContext(DefaultMappingContext, 0);
        }
    }
}

void APawnCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APawnCharacter::Move);
        EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APawnCharacter::Look);
    }
}

void APawnCharacter::Move(const FInputActionValue& Value)
{
    const FVector2D MovementVector = Value.Get<FVector2D>();

    if (!Controller || MovementVector.IsNearlyZero())
    {
        return;
    }

    const FVector LocalMoveDirection(MovementVector.Y, MovementVector.X, 0.0f); // ���� ��ǥ�� ���� �̵� ���� ���
     
    const float DeltaTime = GetWorld()->GetDeltaSeconds();
    const FVector MovementOffset = LocalMoveDirection * MovementSpeed * DeltaTime;
    AddActorLocalOffset(MovementOffset, true);
}

void APawnCharacter::Look(const FInputActionValue& Value)
{
    const FVector2D LookVector = Value.Get<FVector2D>();

    if (!Controller || LookVector.IsNearlyZero())
    {
        return;
    }
     
    CurrentYaw += LookVector.X * MouseSensitivity; // Yaw/Pitch ���
    CurrentPitch = FMath::Clamp(CurrentPitch - LookVector.Y * MouseSensitivity, -89.9f, 89.9f); 

    SpringArmComp->SetRelativeRotation(FRotator(CurrentPitch, CurrentYaw, 0.0f)); // ȸ�� ����
    SetActorRotation(FRotator(0.0f, CurrentYaw, 0.0f));
}