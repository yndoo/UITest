// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleLevelUserWidget.h"
#include "Global/GlobalGameInstance.h"
#include "Kismet/GameplayStatics.h"

int UTitleLevelUserWidget::MyBtnHover()
{
	return static_cast<int>(HoverBtnType);
}

int UTitleLevelUserWidget::MyBtnUnhover()
{
	return static_cast<int>(UnHoverBtnType);
}

void UTitleLevelUserWidget::ServerStart()
{
	UGlobalGameInstance* Inst = GetGameInstance<UGlobalGameInstance>();

	if (nullptr == Inst)
	{
		return;
	}

	Inst->CurNetInfo.SetIsServer(true);
	Inst->CurNetInfo.SetPORT(Port);

	//int PortNumber = FCString::Atoi(*Port);
	//Inst->EnableListenServer(true, PortNumber);

	UGameplayStatics::OpenLevel(GetWorld(), TEXT("LobbyLevel"));
}

void UTitleLevelUserWidget::Connect(FString _IP)
{
	UGlobalGameInstance* Inst = GetGameInstance<UGlobalGameInstance>();

	if (nullptr == Inst)
	{
		return;
	}

	if (false == _IP.IsEmpty())
	{
		IPAddress = _IP;
	}

	Inst->CurNetInfo.SetIP(IPAddress);
	Inst->CurNetInfo.SetPORT(Port);

	FString ConnectLevelName = FString::Printf(TEXT("%s:%s"), *IPAddress, *Port);
	UGameplayStatics::OpenLevel(GetWorld(), *ConnectLevelName);
}

bool UTitleLevelUserWidget::Initialize()
{
	bool ReturnValue = Super::Initialize();

	IPAddress = TEXT("127.0.0.1");

	return ReturnValue;
}

void UTitleLevelUserWidget::ServerTest(FName _IPName)
{
	UGlobalGameInstance* Inst = GetGameInstance<UGlobalGameInstance>();
	if (true == _IPName.IsNone())
	{
		_IPName = FName("LocalNet");
	}
	Test = Inst->GetNetData(_IPName);
	IPAddress = Test->GetIP();
	/*FNetDataRow Data = Inst->GetNetDataValue(_IPName);

	IPAddress = Data.GetIP();*/
	Inst->CurNetInfo.SetIP(IPAddress);
	Inst->CurNetInfo.SetPORT(Port);
}

