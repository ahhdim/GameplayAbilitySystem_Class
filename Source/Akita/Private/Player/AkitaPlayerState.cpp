// Copyright Imo Games


#include "Player/AkitaPlayerState.h"
#include "AbilitySystem/AkitaAbilitySystemComponent.h"
#include "AbilitySystem/AkitaAttributeSet.h"

AAkitaPlayerState::AAkitaPlayerState()
{
	SetNetUpdateFrequency(100.f);

	AbilitySystemComponent = CreateDefaultSubobject<UAkitaAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UAkitaAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AAkitaPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
