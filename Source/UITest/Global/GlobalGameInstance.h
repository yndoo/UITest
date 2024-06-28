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


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool CreateRoomUION;	

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool NeedRefresh = false;	// 방 리스트 새로고침이 필요한 지

	//UPROPERTY(/*Replicated, */BlueprintReadWrite)
	//TArray<FGameRoomInfo> GameRooms;
private:
	UGlobalGameInstance();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = "true"));
	UDataTable* NetDataTable = nullptr;
};
