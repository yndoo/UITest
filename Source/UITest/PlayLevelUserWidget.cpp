// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayLevelUserWidget.h"
#include "Kismet/GameplayStatics.h"


void UPlayLevelUserWidget::NativeTick(const FGeometry& _MyGeometry, float _InDeltaTime)
{
	Super::NativeTick(_MyGeometry, _InDeltaTime);
	TestHP += _InDeltaTime;
	if (TestHP >= TestMaxHP)
	{
		TestHP = 0.0f;
	}
}

float UPlayLevelUserWidget::HPUpdate()
{
	// 현재 체력 / MAX 체력 
	return TestHP / TestMaxHP;
}

