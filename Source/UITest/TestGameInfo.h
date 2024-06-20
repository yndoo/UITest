// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "TestGameInfo.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FTestGameInfo : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	FString IP;
	FString PORT;
	bool IsServer = false;
};
