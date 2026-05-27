// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RoguePickupActor.h"
#include "RogueHealthPickup.generated.h"

UCLASS()
class ARLFIVE_API ARogueHealthPickup : public ARoguePickupActor
{
	GENERATED_BODY()
	
	
protected:
	UPROPERTY(VisibleAnywhere, Category="Component")
	TObjectPtr<UStaticMeshComponent> PickupMeshComponent;
	
	UPROPERTY(EditDefaultsOnly, Category="Pickup")
	TObjectPtr<USoundBase> PickupSound;
	
	UPROPERTY(EditDefaultsOnly, Category="Pickup")
	float HealingAmount = 50.0f;
	
	virtual void OnActorOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) override;
	

public:
	ARogueHealthPickup();
};
