// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUD/FPSHud.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class VGP221SPRINGTERM2025_API SSettingsWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSettingsWidget)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AFPSHud>, OwningHUD);
	SLATE_ARGUMENT(int, MyInt);
	SLATE_END_ARGS()

	/*
	* Smart Pointers
	* 
		unique_ptr(TUniquePtr) = one copied, can't be copied
		- Manage resouces of class. Variables

		shared_ptr - Mutual ownership
		- Eg. Sharing player Health
	
		weak_ptr - No ones owns this pointer
		- Observer patterns
		- Preload memory without having the object spawn yet
	*/

	TWeakObjectPtr<class AFPSHud> OwningHUD;
	int MyInt;

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	FReply OnResumeClicked() const;
	FReply OnSettingsClicked() const;
	FReply OnQuitClicked() const;
};
