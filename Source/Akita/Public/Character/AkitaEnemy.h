// Copyright Imo Games

#pragma once

#include "CoreMinimal.h"
#include "Character/AkitaCharacterBase.h"
#include "Interaction/TargetInterface.h"
#include "AkitaEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AKITA_API AAkitaEnemy : public AAkitaCharacterBase, public ITargetInterface
{
	GENERATED_BODY()

public:
	AAkitaEnemy();
	
	/** Enemy Interface **/
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/** End Enemy Interface **/
	
protected:
	virtual void BeginPlay() override;

};
