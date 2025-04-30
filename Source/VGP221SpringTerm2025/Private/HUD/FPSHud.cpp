// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/FPSHud.h"
#include "Widgets/SWeakWidget.h"

void AFPSHud::BeginPlay()
{
	Super::BeginPlay();

	// 2. Slate
	//ShowSettingsMenu();

	// 3. UMG
	ShowGameMenu(StartingGameWidget);
}

void AFPSHud::DrawHUD()
{
	Super::DrawHUD();

	if (!CrosshairTexture) return;

	FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
	FVector2D CrosshairHalfSize(CrosshairTexture->GetSurfaceWidth() * 0.5f, CrosshairTexture->GetSurfaceHeight() * 0.5f);
	FVector2D CrosshairDrawPosition(Center.X - CrosshairHalfSize.X, Center.Y - CrosshairHalfSize.Y);

	FCanvasTileItem TileItem(CrosshairDrawPosition, CrosshairTexture->GetResource(), FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);
}

void AFPSHud::ShowSettingsMenu()
{
	SettingsWidget = SNew(SSettingsWidget).OwningHUD(this).MyInt(10);
	GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(SlateWidgetContainer, SWeakWidget).PossiblyNullContent(SettingsWidget.ToSharedRef()));

	PlayerOwner->bShowMouseCursor = true;
	PlayerOwner->SetInputMode(FInputModeUIOnly());
}

void AFPSHud::HideSettingsMenu()
{
	GEngine->GameViewport->RemoveViewportWidgetContent(SlateWidgetContainer.ToSharedRef());

	PlayerOwner->bShowMouseCursor = false;
	PlayerOwner->SetInputMode(FInputModeGameOnly());
}

void AFPSHud::ShowGameMenu(TSubclassOf<UFPSUserWidget> newGameWidget)
{
	if (GameWidgetContainer) {
		GameWidgetContainer->RemoveFromParent();
		GameWidgetContainer = nullptr;
	}

	GameWidgetContainer = CreateWidget<UFPSUserWidget>(GetWorld(), newGameWidget);
	GameWidgetContainer->AddToViewport();
}
