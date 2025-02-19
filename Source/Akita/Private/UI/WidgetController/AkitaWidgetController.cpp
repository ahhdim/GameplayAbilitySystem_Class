// Copyright Imo Games


#include "UI/WidgetController/AkitaWidgetController.h"

void UAkitaWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UAkitaWidgetController::BroadcastInitialValues()
{
	
}

void UAkitaWidgetController::BindCallbacksToDependencies()
{
}
