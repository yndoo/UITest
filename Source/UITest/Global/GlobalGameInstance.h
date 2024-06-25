// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "../NetDataRow.h"
#include "GlobalGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UITEST_API UGlobalGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	const struct FNetDataRow* GetNetData(FName _Name);
	FNetDataRow CurNetInfo;
private:
	UGlobalGameInstance();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = "true"));
	UDataTable* NetDataTable = nullptr;
};
