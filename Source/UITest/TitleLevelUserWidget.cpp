// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleLevelUserWidget.h"


int UTitleLevelUserWidget::MyText()
{
	if (true == IsHoverOnOff)
	{
		return static_cast<int>(HoverBtnType);
	}
	else
	{
		return static_cast<int>(UnHoverBtnType);
	}
}
