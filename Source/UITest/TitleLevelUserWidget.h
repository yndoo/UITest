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
	UFUNCTION(BlueprintCallable, Category = "MyBtnEvent")
	int MyBtnHover();
	UFUNCTION(BlueprintCallable, Category = "MyBtnEvent")
	int MyBtnUnhover();


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool IsHoverOnOff;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EBtnType HoverBtnType;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EBtnType UnHoverBtnType;
};
