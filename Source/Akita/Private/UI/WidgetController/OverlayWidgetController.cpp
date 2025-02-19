// Copyright Imo Games


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AkitaAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UAkitaAttributeSet* AkitaAttributeSet = CastChecked<UAkitaAttributeSet>(AttributeSet);
	
	OnHealthChanged.Broadcast(AkitaAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AkitaAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(AkitaAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(AkitaAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UAkitaAttributeSet* AkitaAttributeSet = CastChecked<UAkitaAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AkitaAttributeSet->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	AkitaAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AkitaAttributeSet->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
	AkitaAttributeSet->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);

}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
