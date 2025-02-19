// Copyright Imo Games


#include "Character/AkitaCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/AkitaAbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AkitaPlayerController.h"
#include "Player/AkitaPlayerState.h"
#include "UI/HUD/AkitaHUD.h"

AAkitaCharacter::AAkitaCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void AAkitaCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability actor info for the Server
	InitAbilityActorInfo();
}

void AAkitaCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability actor info for the Client
	InitAbilityActorInfo();
	
}

void AAkitaCharacter::InitAbilityActorInfo()
{
	AAkitaPlayerState* AkitaPlayerState = GetPlayerState<AAkitaPlayerState>();
	check(AkitaPlayerState);
	AkitaPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AkitaPlayerState, this);
	AbilitySystemComponent = AkitaPlayerState->GetAbilitySystemComponent();
	AttributeSet = AkitaPlayerState->GetAttributeSet();

	if (AAkitaPlayerController* AkitaPlayerController = Cast<AAkitaPlayerController>(GetController()))
	{
		if (AAkitaHUD* AkitaHUD = Cast<AAkitaHUD>(AkitaPlayerController->GetHUD()))
		{
			AkitaHUD->InitOverlay(AkitaPlayerController, AkitaPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
}
