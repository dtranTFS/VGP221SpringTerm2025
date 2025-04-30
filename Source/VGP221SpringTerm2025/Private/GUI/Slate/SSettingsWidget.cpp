// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/Slate/SSettingsWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSettingsWidget::Construct(const FArguments& InArgs)
{
	// Import parameters
	OwningHUD = InArgs._OwningHUD;
	MyInt = InArgs._MyInt;

	// Paddings around stuff
	const FMargin ContentPadding = FMargin(500.0f, 300.0f);
	const FMargin ButtonPadding = FMargin(10.0f);

	// Title
	FSlateFontInfo TitleTextStyle = FCoreStyle::Get().GetFontStyle("EmbassedText");
	TitleTextStyle.Size = 60.0f;

	const FText TitleText = FText::FromString("Settings Menu");

	// Buttons
	FSlateFontInfo ButtonTextStyle = TitleTextStyle;
	TitleTextStyle.Size = 40.0f;

	const FText ResumeText = FText::FromString("Resume");
	const FText SettingsText = FText::FromString("Settings");
	const FText QuitText = FText::FromString("Quit");
	
	ChildSlot
	[
		SNew(SOverlay)
		+SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.ColorAndOpacity(FColor::Black)
		]
		+SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(ContentPadding)
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			[
				SNew(STextBlock)
				.Font(TitleTextStyle)
				.Text(TitleText)
				.Justification(ETextJustify::Center)
			]
			+SVerticalBox::Slot()
			.Padding(ButtonPadding)
			[
				SNew(SButton)
				.OnClicked(this, &SSettingsWidget::OnResumeClicked)
				[
					SNew(STextBlock)
					.Font(ButtonTextStyle)
					.Text(ResumeText)
					.Justification(ETextJustify::Center)
				]
			]
			+SVerticalBox::Slot()
			.Padding(ButtonPadding)
			[
				SNew(SButton)
				.OnClicked(this, &SSettingsWidget::OnSettingsClicked)
				[
					SNew(STextBlock)
					.Font(ButtonTextStyle)
					.Text(SettingsText)
					.Justification(ETextJustify::Center)
				]
			]
			+SVerticalBox::Slot()
			.Padding(ButtonPadding)
			[
				SNew(SButton)
				.OnClicked(this, &SSettingsWidget::OnQuitClicked)
				[
					SNew(STextBlock)
					.Font(ButtonTextStyle)
					.Text(QuitText)
					.Justification(ETextJustify::Center)
				]
			]
		]
	];
}
FReply SSettingsWidget::OnResumeClicked() const
{
	UE_LOG(LogTemp, Warning, TEXT("Resume Clicked"));
	if (OwningHUD.IsValid()) {
		OwningHUD->HideSettingsMenu();
	}

	return FReply::Handled();
}
FReply SSettingsWidget::OnSettingsClicked() const
{
	UE_LOG(LogTemp, Warning, TEXT("Settings Clicked"));
	UE_LOG(LogTemp, Warning, TEXT("MyInt: %i"), MyInt);

	return FReply::Handled();
}
FReply SSettingsWidget::OnQuitClicked() const
{
	UE_LOG(LogTemp, Warning, TEXT("Quit Clicked"));
	if (OwningHUD.IsValid()) {
		if (APlayerController* PC = OwningHUD->PlayerOwner) {
			PC->ConsoleCommand("quit");
		}
	}

	return FReply::Handled();
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
