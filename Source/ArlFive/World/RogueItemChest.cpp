// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueItemChest.h"



ARogueItemChest::ARogueItemChest()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;
	
	BaseMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMeshComp"));
	BaseMeshComponent->SetCollisionProfileName("Interaction");
	RootComponent = BaseMeshComponent;
	
	LidMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMeshComp"));
	LidMeshComponent->SetCollisionProfileName("NoCollision"); // worldstatic or worlddydnamic(ignore player's pawn -> never get stuck)
	LidMeshComponent->SetupAttachment(BaseMeshComponent);
}

void ARogueItemChest::Interact()
{
	SetActorTickEnabled(true);
}


void ARogueItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	CurrenntAnimationPitch = FMath::FInterpConstantTo(CurrenntAnimationPitch, AnimationTargetPitch, DeltaTime, AnimationSpeed);
	LidMeshComponent->SetRelativeRotation(FRotator(CurrenntAnimationPitch, 0.0f, 0.0f));
	
	if (FMath::IsNearlyEqual(CurrenntAnimationPitch, AnimationTargetPitch))
	{
		SetActorTickEnabled(false);
	}
}

