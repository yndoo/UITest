// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LobbyLevelUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class UITEST_API ULobbyLevelUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void TravelToNext();
};
