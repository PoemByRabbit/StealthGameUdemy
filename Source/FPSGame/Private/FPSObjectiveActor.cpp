// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSObjectiveActor.h"
#include "FPSCharacter.h"
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFPSObjectiveActor::AFPSObjectiveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

  // Component
  MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
  // Collision
  MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
  // Setup
  RootComponent = MeshComp;

  // Component
  SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
  // Collision
  SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
  SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
  SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
  // Setup
  SphereComp->SetupAttachment(MeshComp);
  SphereComp->SetSphereRadius(275.0f);
  //
}

// Called when the game starts or when spawned
void AFPSObjectiveActor::BeginPlay()
{
	Super::BeginPlay();
  PlayEffects();
}

void AFPSObjectiveActor::PlayEffects()
{
  UGameplayStatics::SpawnEmitterAtLocation(this, PickupFX, GetActorLocation());
}

void AFPSObjectiveActor::NotifyActorBeginOverlap(AActor* OtherActor) {
  Super::NotifyActorBeginOverlap(OtherActor);

  PlayEffects();
  AFPSCharacter* MyCharacter = Cast<AFPSCharacter>(OtherActor);
  if (MyCharacter)
  {
    MyCharacter->bIsCarryingObjective = true;
    Destroy();
  }
}
