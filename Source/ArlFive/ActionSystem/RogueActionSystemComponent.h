// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RogueActionSystemComponent.generated.h"


struct FRogueAttributeSet
{
	FRogueAttributeSet()
		: Health(100.0f) {}
	
	
	float Health;
};


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ARLFIVE_API URogueActionSystemComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	
	void ApplyHealthChange(float InvalueChange);
	
protected:
	
	FRogueAttributeSet Attributes;

public:
	
	URogueActionSystemComponent();

};
