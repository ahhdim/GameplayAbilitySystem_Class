// Copyright Imo Games

#pragma once

#include "CoreMinimal.h"
#include "Character/AkitaCharacterBase.h"
#include "AkitaCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AKITA_API AAkitaCharacter : public AAkitaCharacterBase
{
	GENERATED_BODY()
public:
	AAkitaCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilityActorInfo();	
};
