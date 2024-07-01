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
	const FNetDataRow* GetNetData(FName _Name);

	UFUNCTION(BlueprintCallable)
	const FNetDataRow GetNetDataForBP(FName _Name);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FNetDataRow CurNetInfo;

	UDataTable* GetNetDataTable()
	{
		return NetDataTable;
	}

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool CreateRoomUION;	

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool NeedRefresh = false;	// �� ����Ʈ ���ΰ�ħ�� �ʿ��� ��

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FString MyID;

	UFUNCTION(BlueprintCallable)
	bool IsMyIp(FString _ip);
private:
	UGlobalGameInstance();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = "true"));
	UDataTable* NetDataTable = nullptr;
};
