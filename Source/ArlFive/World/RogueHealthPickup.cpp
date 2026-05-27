// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueHealthPickup.h"

#include "ActionSystem/RogueActionSystemComponent.h"

#include "Kismet/GameplayStatics.h"


ARogueHealthPickup::ARogueHealthPickup()
{
	PickupMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("PickupMeshComp");
	PickupMeshComponent->SetCollisionProfileName("NoCollision");
	PickupMeshComponent->SetupAttachment(RootComponent);
}


void ARogueHealthPickup::OnActorOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnActorOverlapped(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	
	URogueActionSystemComponent* ActionComp = OtherActor->GetComponentByClass<URogueActionSystemComponent>();
	
	if (ensure(ActionComp != nullptr) && !ActionComp->IsFullHealth())
	{
		ActionComp->ApplyHealthChange(HealingAmount);
		
		UGameplayStatics::PlaySoundAtLocation(this,PickupSound, GetActorLocation(), FRotator::ZeroRotator);
		
		Destroy();
	}
}