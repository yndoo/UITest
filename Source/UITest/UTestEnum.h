// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UTestEnum.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EHoverBtn : uint8
{
	None,
	GameBtn,
	ListBtn1,
	ListBtn2,
	MenuBtn1,
	MenuBtn2,
	MenuBtn3,
	MenuBtn4,
};

UENUM(BlueprintType)
enum class EUnHoverBtn : uint8
{
	None,
	GameBtn,
	ListBtn1,
	ListBtn2,
	MenuBtn1,
	MenuBtn2,
	MenuBtn3,
	MenuBtn4,
};

UCLASS()
class UITEST_API UUTestEnum : public UObject
{
	GENERATED_BODY()
	
};
