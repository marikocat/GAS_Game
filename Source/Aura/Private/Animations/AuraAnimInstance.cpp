// Copyright marikocat


#include "Animations/AuraAnimInstance.h"
#include "Character/AuraCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UAuraAnimInstance::NativeInitializeAnimation()
{
	if (IsValid(Character = Cast<AAuraCharacter>(TryGetPawnOwner())))
	{
		CharacterMovement = Character->GetCharacterMovement();
	}
}

void UAuraAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (IsValid(Character) && IsValid(CharacterMovement))
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(CharacterMovement->Velocity);
	}
}