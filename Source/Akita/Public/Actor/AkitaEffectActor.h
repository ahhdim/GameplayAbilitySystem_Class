// Copyright Imo Games

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AkitaEffectActor.generated.h"

class USphereComponent;

UCLASS()
class AKITA_API AAkitaEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AAkitaEffectActor();

protected:
	virtual void BeginPlay() override;

public:	
	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;
};
