// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/FPSUserWidget.h"

void UFPSUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SetHealthBar(1.0f);
	SetScoreText(0);

	for (int i = 0; i < 4; i++) {
		UUserWidget* widget = CreateWidget(this, ButtonWidgetPrefab);
		ButtonContainer->AddChildToVerticalBox(widget);

		UButtonWidget* button = Cast<UButtonWidget>(widget);
		button->SetText(i);
	}
}

void UFPSUserWidget::SetHealthBar(float percentage)
{
	if (!HealthBar) return;

	HealthBar->SetPercent(percentage);
}

void UFPSUserWidget::SetScoreText(int amount)
{
	if (!ScoreText) return;

	UIScore += amount;
	ScoreText->SetText(FText::FromString("Score: " + FString::FromInt(UIScore)));
}
