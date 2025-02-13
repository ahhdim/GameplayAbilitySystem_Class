// Copyright Imo Games


#include "Actor/AkitaEffectActor.h"

#include "AbilitySystemInterface.h"
#include "AbilitySystem/AkitaAttributeSet.h"
#include "Components/SphereComponent.h"

AAkitaEffectActor::AAkitaEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
	
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(Mesh);
}

void AAkitaEffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AAkitaEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AAkitaEffectActor::EndOverlap);
	
}

void AAkitaEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//TODO: Change this to apply a Gameplay Effect. For now, using const_cast as a hack!
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UAkitaAttributeSet* AuraAttributeSet = Cast<UAkitaAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UAkitaAttributeSet::StaticClass()));
		UAkitaAttributeSet* MutableAuraAttributeSet = const_cast<UAkitaAttributeSet*>(AuraAttributeSet);
		MutableAuraAttributeSet->SetHealth(AuraAttributeSet->GetHealth() + 25.f);
		Destroy();
	}
}

void AAkitaEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}


