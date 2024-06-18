// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UTestEnum.h"
#include "TitleLevelUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class UITEST_API UTitleLevelUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category="MyBtnEvent")
	int MyText();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool IsHoverOnOff;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EHoverBtn HoverBtnType;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EUnHoverBtn UnHoverBtnType;
};
