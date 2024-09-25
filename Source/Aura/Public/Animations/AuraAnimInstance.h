// Copyright marikocat

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AuraAnimInstance.generated.h"

class AAuraCharacter;
class UCharacterMovementComponent;

UCLASS()
class AURA_API UAuraAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds);

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<AAuraCharacter> Character;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCharacterMovementComponent> CharacterMovement;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float GroundSpeed = 0.f;
};
