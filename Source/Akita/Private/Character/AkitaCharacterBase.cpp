// Copyright Imo Games


#include "Character/AkitaCharacterBase.h"

AAkitaCharacterBase::AAkitaCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AAkitaCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAkitaCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}