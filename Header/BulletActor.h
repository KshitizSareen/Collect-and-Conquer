// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BulletActor.generated.h"

UCLASS()
class REACHER_API ABulletActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	FVector SpawnLocation;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Bullet")
		UShapeComponent* CollisionComponent;
	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UPROPERTY(VisibleAnywhere, Category = "Movement")
		FVector CurrentLocation;
	UPROPERTY(VisibleAnywhere, Category = "Movement")
		FVector NewLocation;
	UPROPERTY(VisibleAnywhere, Category = "Movement")
		FVector FinalLocation;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float Speed = FMath::RandRange(1000,10000);
	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class ABulletActor> BulletBlueprint;
};
