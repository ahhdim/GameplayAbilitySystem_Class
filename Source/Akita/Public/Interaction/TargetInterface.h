// Copyright Imo Games

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TargetInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTargetInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AKITA_API ITargetInterface
{
	GENERATED_BODY()
public:
	virtual void HighlightActor() = 0;
	virtual void UnHighlightActor() = 0;
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
};
