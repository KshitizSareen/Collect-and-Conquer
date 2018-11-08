// Fill out your copyright notice in the Description page of Project Settings.

#include "Reacher.h"
#include "CoinActor.h"
#include "ReacherCharacter.h"
#include "MyUserWidget.h"
#include "MyGameMode.h"


// Sets default values
ACoinActor::ACoinActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	CollisionBox->bGenerateOverlapEvents = true;
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ACoinActor::OnOverlap);
}

// Called when the game starts or when spawned
void ACoinActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoinActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}
void ACoinActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(AReacherCharacter::StaticClass()))
	{
		((AMyGameMode*)GetWorld()->GetAuthGameMode())->OnCollideCoin();
		this->Destroy();
	}
}
