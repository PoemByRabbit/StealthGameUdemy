// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSObjectiveActor.generated.h"

// @DOC The SphereComponent header file is included in the FPSObjectiveActor.cpp file. Only include 'class' in the 'FPSObjective.h' file to limit compilation time. This tells the compiler USphereComponent is a class (aka 'forward declaration')
class USphereComponent;

UCLASS()
class FPSGAME_API AFPSObjectiveActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFPSObjectiveActor();

protected:

  UPROPERTY(VisibleAnywhere, Category = "Components")
  UStaticMeshComponent* MeshComp;

  UPROPERTY(VisibleAnywhere, Category = "Components")
  USphereComponent* SphereComp; // for collision

  UPROPERTY(EditDefaultsOnly, Category = "Effects")
  UParticleSystem* PickupFX;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

  // Play effect on pickup
  void PlayEffects();

public:

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

};
