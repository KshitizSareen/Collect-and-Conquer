// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Blueprint/UserWidget.h"
#include "BulletActor.h"
#include "GameFramework/GameMode.h"
#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class REACHER_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()
	float Minimum_Interval = 0.5f;
	float Maximum_Interval = 2.0f;
	float Time_To_Interval = 30.0f;
public:
	
		
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaSeconds) override;
		void OnCollideCoin();
		void OnCollideBullet();
		void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

		float EnemyTimer;
		float GameTimer;
		ABulletActor* Bullet;
		int Score = 0, Health = 100;
protected:
	UPROPERTY(EditAnywhere,Category="Spawning")
	TSubclassOf<class ABulletActor> BulletBlueprint;
	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<UUserWidget> NewWidgetClass;
	UPROPERTY(EditAnywhere,Category="Location")
	FVector CurrentLocation;
	UUserWidget* CurrentWidget;
	
	
};
