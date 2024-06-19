// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UTestEnum.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EBtnType : uint8
{
	None,
	MenuBtn1 = 1,
	MenuBtn2 = 2,
	MenuBtn3 = 3,
	MenuBtn4 = 4,
	GameBtn,
	ListBtn1,
	ListBtn2,
};


UCLASS()
class UITEST_API UUTestEnum : public UObject
{
	GENERATED_BODY()
	
};
