// Fill out your copyright notice in the Description page of Project Settings.

#include "Reacher.h"
#include "MyGameMode.h"
#include "BulletActor.h"
#include "MyUserWidget.h"

void AMyGameMode::BeginPlay()
{
	Super::BeginPlay();
	ChangeMenuWidget(NewWidgetClass);
	((UMyUserWidget*)CurrentWidget)->Load();

}

// Called every frame
void AMyGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GameTimer += DeltaTime;
	EnemyTimer -= DeltaTime;
	if (EnemyTimer <= 0.0f)
	{
		float DifficultyPercentage = FMath::Min(GameTimer / Time_To_Interval, 1.0f);
		EnemyTimer = Maximum_Interval - (Maximum_Interval - Minimum_Interval)*DifficultyPercentage;

		UWorld* World = GetWorld();
		if (World)
		{	
			FVector Location1 = FVector(40720.0f, FMath::RandRange(1610.0f, 2340.0f), 940.0f);
			World->SpawnActor<ABulletActor>(BulletBlueprint, Location1, FRotator::ZeroRotator);

			FVector Location2 = FVector(40720.0f, FMath::RandRange(2570.0f, 3360.0f), 940.0f);
			World->SpawnActor<ABulletActor>(BulletBlueprint, Location2, FRotator::ZeroRotator);

		}
	}

}
void AMyGameMode::OnCollideCoin()
{
	Score += 10;
	((UMyUserWidget*)CurrentWidget)->OnCollide(Score, Health);
}
void AMyGameMode::OnCollideBullet()
{
	Health -= 10;
	((UMyUserWidget*)CurrentWidget)->OnCollide(Score, Health);
	if (Health <= 0)
	{
		((UMyUserWidget*)CurrentWidget)->OnGameOver();
		UGameplayStatics::SetGamePaused(GetWorld(), true);
	}
}
void AMyGameMode::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}
	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (CurrentWidget != nullptr)
			CurrentWidget->AddToViewport();
	}
}