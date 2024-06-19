// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleLevelUserWidget.h"


int UTitleLevelUserWidget::MyBtnHover()
{
	return static_cast<int>(HoverBtnType);
}

int UTitleLevelUserWidget::MyBtnUnhover()
{
	return static_cast<int>(UnHoverBtnType);
}
