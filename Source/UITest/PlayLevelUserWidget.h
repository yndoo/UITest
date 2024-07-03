// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayLevelUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class UITEST_API UPlayLevelUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
	void NativeTick(const FGeometry& _MyGeometry, float _InDeltaTime);

	UFUNCTION(BlueprintCallable)
	float HPUpdate();

	float TestHP = 0.0f;
	float TestMaxHP = 100.0f;
};
