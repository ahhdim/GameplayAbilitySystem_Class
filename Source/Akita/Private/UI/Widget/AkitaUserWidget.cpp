// Copyright Imo Games


#include "UI/Widget/AkitaUserWidget.h"

void UAkitaUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}