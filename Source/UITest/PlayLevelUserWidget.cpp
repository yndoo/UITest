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
	// ���� ü�� / MAX ü�� 
	return TestHP / TestMaxHP;
}

