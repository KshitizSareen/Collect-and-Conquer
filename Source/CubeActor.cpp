// Fill out your copyright notice in the Description page of Project Settings.

#include "Reacher.h"
#include "CubeActor.h"


// Sets default values
ACubeActor::ACubeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACubeActor::BeginPlay()
{
	Super::BeginPlay();
	CurrentLocation = GetActorLocation();
	FinalLocation.X = CurrentLocation.X + 2000.0f;
	NewLocation = CurrentLocation;
}

// Called every frame
void ACubeActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	NewLocation.X += speed*DeltaTime;
	SetActorLocation(NewLocation);
	if (NewLocation.X >= FinalLocation.X)
	{
		speed = -speed;
	}
	if (NewLocation.X <= CurrentLocation.X)
	{
		speed = -speed;
	}

}

