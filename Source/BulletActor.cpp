// Fill out your copyright notice in the Description page of Project Settings.

#include "Reacher.h"
#include "BulletActor.h"
#include "ReacherCharacter.h"
#include "MyGameMode.h"

// Sets default values
ABulletActor::ABulletActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Root Box"));
	CollisionComponent->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	CollisionComponent->bGenerateOverlapEvents = true;
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ABulletActor::OnOverlap);
}

// Called when the game starts or when spawned
void ABulletActor::BeginPlay()
{
	Super::BeginPlay();
	CurrentLocation = GetActorLocation();
	FinalLocation = CurrentLocation;
	FinalLocation.X = CurrentLocation.X - 20000.0f;
	SpawnLocation = FinalLocation;
	SpawnLocation.X = (FinalLocation.X)*2.0f;
	NewLocation = CurrentLocation;

}

// Called every frame
void ABulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	NewLocation.X += -Speed*DeltaTime;
	SetActorLocation(NewLocation);
	if (NewLocation.X <= FinalLocation.X)
	{
		this->Destroy();
	}

}
void ABulletActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(AReacherCharacter::StaticClass()))
	{
		((AMyGameMode*)GetWorld()->GetAuthGameMode())->OnCollideBullet();
		this->Destroy();
	}

	
}


