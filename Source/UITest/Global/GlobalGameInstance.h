// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "../TestGameInfo.h"
#include "GlobalGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UITEST_API UGlobalGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	FTestGameInfo MyTestGameInfo;

private:
	UGlobalGameInstance();
};
