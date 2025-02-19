// Copyright Imo Games

#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AkitaUserWidget.generated.h"
/**
 * 
 */
UCLASS()
class AKITA_API UAkitaUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;
	
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};