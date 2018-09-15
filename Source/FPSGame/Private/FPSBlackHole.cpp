// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSBlackHole.h"
// #include "DrawDebugHelpers.h"
#include "Components/SphereComponent.h"
#include "Components/MeshComponent.h"


// Sets default values
AFPSBlackHole::AFPSBlackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
  Strength = 20000.0f;

  MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
  RootComponent = MeshComp;

  CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComp"));
  CollisionComp->SetSphereRadius(250.0f);
  CollisionComp->SetupAttachment(MeshComp);

  //
  // CollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
  CollisionComp->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
  CollisionComp->SetCollisionResponseToAllChannels(ECR_Ignore);
  CollisionComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

  ForceComp = CreateDefaultSubobject<USphereComponent>(TEXT("ForceComp"));
  ForceComp->SetSphereRadius(500.0f);
  ForceComp->SetupAttachment(MeshComp);
  ForceComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void AFPSBlackHole::BeginPlay()
{
	Super::BeginPlay();

  // DrawDebugSphere(GetWorld(), GetActorLocation(), CollisionComp->GetScaledSphereRadius(), 32, FColor::Magenta, true);
  // AddForce();
}

// Called every frame
void AFPSBlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFPSBlackHole::AddForce()
{
  // Array of hit results
  TArray<FHitResult> OutHits;

  // Get Actor location
  FVector ActorLocation = GetActorLocation();

  //
  FVector Start = ActorLocation;
  FVector End = ActorLocation;

  // The collision sphere
  float Radius = 500.0f;
  FCollisionShape ColSphere = FCollisionShape::MakeSphere(Radius);

  // Debug
  // DrawDebugSphere(GetWorld(), ActorLocation, Radius, 32, FColor::Cyan, true);

  //
  bool isHit = GetWorld()->SweepMultiByChannel(OutHits, Start, End, FQuat::Identity, ECC_WorldStatic, ColSphere);
  if (isHit)
  {
    UE_LOG(LogTemp, Warning, TEXT("HIT %d"), OutHits.Num());
    for (auto& Hit : OutHits)
    {
      UStaticMeshComponent* HitComp = Cast<UStaticMeshComponent>((Hit.GetActor())->GetRootComponent());
      // if (MeshComp)
      // {
      //   // UE_LOG(LogTemp, Warning, TEXT(MeshComp->GetLocation()));
      //   // UE_LOG(LogTemp, Warning, TEXT("%s"), MeshComp->GetComponentLocation().ToString());
      //   // UE_LOG(LogTemp, Warning, TEXT("%s"), *MeshComp->GetFName().ToString());
      //   UE_LOG(LogTemp, Warning, TEXT("hit"));
      // }
    }
  } else {
    UE_LOG(LogTemp, Warning, TEXT("NO HITS"));
  }


}

void AFPSBlackHole::NotifyActorBeginOverlap(AActor* OtherActor)
{
  Super::NotifyActorBeginOverlap(OtherActor);

  if(OtherActor != nullptr) {
    UE_LOG(LogTemp, Warning, TEXT("OVERLAY"));
  }
}
