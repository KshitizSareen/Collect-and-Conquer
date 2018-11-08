// Fill out your copyright notice in the Description page of Project Settings.

#include "Reacher.h"
#include "MyUserWidget.h"

void UMyUserWidget::Load()
{
	const FName TextBlockName = FName("TextBlockName");
	if (TextBlock == nullptr)
		TextBlock = (UTextBlock*)(WidgetTree->FindWidget(TextBlockName));
	SetScore(0, 100);
}
void UMyUserWidget::SetScore(int Score, int Health)
{
	if (TextBlock != nullptr)
		TextBlock->SetText(FText::FromString(FString("Score ") + FString::FromInt(Score) + FString(" Health : ") + FString::FromInt(Health)));
}
void UMyUserWidget::OnCollide(int Score, int Health)
{
	if (TextBlock != nullptr)
		TextBlock->SetText(FText::FromString(FString("Score ") + FString::FromInt(Score) + FString(" Health : ") + FString::FromInt(Health)));
}
void UMyUserWidget::OnGameOver()
{
	if (TextBlock != nullptr)
		TextBlock->SetText(FText::FromString(FString("The Game is over \n Press R to Restart")));
}



