// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "GameRoomInfo.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FGameRoomInfo : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(Category = "Parameter", EditAnywhere, BlueprintReadWrite)
	FString RoomTitle;
	UPROPERTY(Category = "Parameter", EditAnywhere, BlueprintReadWrite)
	FString MapName;
	UPROPERTY(Category = "Parameter", EditAnywhere, BlueprintReadWrite)
	int Count = 0;
};
