// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CubeActor.generated.h"

UCLASS()
class REACHER_API ACubeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubeActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	UPROPERTY(EditAnywhere, Category = "Movement")
	float speed=100.f;
	
	UPROPERTY(VisibleAnywhere, Category = "Movement")
		FVector CurrentLocation;
	UPROPERTY(VisibleAnywhere, Category = "Movement")
		FVector FinalLocation;
	UPROPERTY(VisibleAnywhere, Category = "Movement")
		FVector NewLocation;
	
};
