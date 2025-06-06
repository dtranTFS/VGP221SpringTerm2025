// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine/Canvas.h"
#include "GUI/Slate/SSettingsWidget.h"
#include "GUI/FPSUserWidget.h"
#include "FPSHud.generated.h"

/**
 * 
 */
UCLASS()
class VGP221SPRINGTERM2025_API AFPSHud : public AHUD
{
	GENERATED_BODY()
	
protected:
	// This will be drawn at the center of the screen.
	UPROPERTY(EditDefaultsOnly)
	UTexture2D* CrosshairTexture;

public:
	virtual void BeginPlay() override;

	// 1. HUD method of Making UI
	virtual void DrawHUD() override;

	// 2. Slates method of making UI
	TSharedPtr<class SSettingsWidget> SettingsWidget;
	TSharedPtr<class SWidget> SlateWidgetContainer;

	void ShowSettingsMenu();
	void HideSettingsMenu();

	// 3. UMG method of making UI
	UPROPERTY(EditAnywhere)
	TSubclassOf<UFPSUserWidget> StartingGameWidget;
	UFPSUserWidget* GameWidgetContainer;

	void ShowGameMenu(TSubclassOf<UFPSUserWidget> newGameWidget);
};
