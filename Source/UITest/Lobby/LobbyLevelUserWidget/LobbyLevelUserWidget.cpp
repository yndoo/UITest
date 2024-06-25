// Fill out your copyright notice in the Description page of Project Settings.


#include "Lobby/LobbyLevelUserWidget/LobbyLevelUserWidget.h"
#include "Global/GlobalGameInstance.h"

void ULobbyLevelUserWidget::TravelToNext()
{
	UGlobalGameInstance* Inst = GetWorld()->GetGameInstanceChecked<UGlobalGameInstance>();
	if (nullptr != Inst && true == Inst->CurNetInfo.GetIsServer())
	{
		GetWorld()->ServerTravel("/Game/PlayLevel/PlayLevel");
	}
}

bool ULobbyLevelUserWidget::IsServer()
{
	UGlobalGameInstance* Inst = GetWorld()->GetGameInstanceChecked<UGlobalGameInstance>();
	return Inst->CurNetInfo.GetIsServer();
}