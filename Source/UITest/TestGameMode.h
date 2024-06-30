// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameRoomInfo.h"

#include "TestGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UITEST_API ATestGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ATestGameMode();

	UFUNCTION(BlueprintCallable)
	void ListenServerOn();

	UFUNCTION(BlueprintCallable)
	void AddRoomListIndex();

	UFUNCTION(BlueprintCallable)
	void PushRoomInfo(FString _title, FString _map);


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RoomListIndex = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FGameRoomInfo> RoomInfo;
};
