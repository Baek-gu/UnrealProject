#include "MyWorldGameMode.h"
#include "PawnCharacter.h"

AMyWorldGameMode::AMyWorldGameMode()
{
    DefaultPawnClass = APawnCharacter::StaticClass();
}