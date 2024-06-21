// Fill out your copyright notice in the Description page of Project Settings.


#include "TestGameMode.h"
#include "Global/GlobalGameInstance.h"

ATestGameMode::ATestGameMode()
{

}

void ATestGameMode::ListenServerOn()
{
	UGlobalGameInstance* Inst = GetWorld()->GetGameInstanceChecked<UGlobalGameInstance>();
	if (nullptr != Inst && true == Inst->MyTestGameInfo.IsServer)
	{
		FString& Port = Inst->MyTestGameInfo.PORT;
		int PortNumber = FCString::Atoi(*Port);
		if (PortNumber == 0)
		{
			return;
			//UE_LOG(GIMATLog, Fatal, TEXT("%S(%u)> if (PortNumber == 0)"), __FUNCTION__, __LINE__);
		}

		Inst->EnableListenServer(true, PortNumber);
	}
}