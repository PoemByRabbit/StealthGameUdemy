// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DrawDebugHelpers.h"

#include "FPSBlackHole.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class FPSGAME_API AFPSBlackHole : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFPSBlackHole();

protected:

  UPROPERTY(VisibleAnywhere, Category = "Components")
  UStaticMeshComponent* MeshComp;

  UPROPERTY(VisibleAnywhere, Category = "Components")
  USphereComponent* CollisionComp;

  UPROPERTY(VisibleAnywhere, Category = "Components")
  USphereComponent* ForceComp;

  UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Physics")
  float Strength;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

  // Add radial force to nearby actors
  void AddForce();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

  // Event when this actor overlaps another actor.
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

};
