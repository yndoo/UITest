// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleLevelUserWidget.h"
#include "Global/GlobalGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ComboBoxString.h"
#include "Sockets.h"
#include "networking.h"


int UTitleLevelUserWidget::MyBtnHover()
{
	return static_cast<int>(HoverBtnType);
}

int UTitleLevelUserWidget::MyBtnUnhover()
{
	return static_cast<int>(UnHoverBtnType);
}

void UTitleLevelUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	TestTick();
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

//bool UTitleLevelUserWidget::Initialize()
//{
//	bool ReturnValue = Super::Initialize();
//
//	IPAddress = TEXT("127.0.0.1");
//
//	return ReturnValue;
//}

void UTitleLevelUserWidget::ServerInitialize(FName _RowName)
{
	UGlobalGameInstance* Inst = GetGameInstance<UGlobalGameInstance>();
	if (true == _RowName.IsNone())
	{
		_RowName = FName("LocalNet");
	}
	TempNetData = Inst->GetNetData(_RowName);
	IPAddress = TempNetData->GetIP();
	/*FNetDataRow Data = Inst->GetNetDataValue(_RowName);

	IPAddress = Data.GetIP();*/
	Inst->CurNetInfo.SetIP(IPAddress);
	Inst->CurNetInfo.SetPORT(Port);
}

void UTitleLevelUserWidget::RoomIPDataInit(UDataTable* _IPData, UComboBoxString* _Combo)
{
	TArray<FNetDataRow*> IPArr;
	_IPData->GetAllRows<FNetDataRow>(TEXT("GetAllRows"), IPArr);

	if (true == IPArr.IsEmpty())
	{
		return;
	}

	for (size_t i = 0; i < IPArr.Num(); ++i)
	{
		FNetDataRow* Data = IPArr[i];
		//FString Option = FString::Printf(TEXT("[%s][%s]"), *Data->GetName(), *Data->GetIP());
		FString Option = FString::Printf(TEXT("%s"), *Data->GetName());
		_Combo->AddOption(Option);
	}

	_Combo->SetSelectedIndex(0);
}

void UTitleLevelUserWidget::RoomIPSelectChange(FString _Text)
{
	_Text.RemoveAt(0);
	_Text.RemoveAt(_Text.Len() - 1);

	FString Name;
	FString IP;

	_Text.Split(TEXT("]["), &Name, &IP);

	IPAddress = IP;
}

void UTitleLevelUserWidget::SetBrowserOnOff(bool _Setting)
{
	UGlobalGameInstance* Inst = GetGameInstance<UGlobalGameInstance>();
	Inst->CreateRoomUION = _Setting;
}

bool UTitleLevelUserWidget::GetBrowserOnOff()
{
	UGlobalGameInstance* Inst = GetGameInstance<UGlobalGameInstance>();
	return Inst->CreateRoomUION;
}

bool UTitleLevelUserWidget::IsPortOpen(const FString& _IPAddress, int32 _Port)
{
	// Create an IPv4 endpoint
	FIPv4Endpoint Endpoint;
	bool bIsValid = FIPv4Address::Parse(_IPAddress, Endpoint.Address);
	if (!bIsValid)
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid IP address: %s"), *_IPAddress);
		return false;
	}
	Endpoint.Port = _Port;

	// Create a socket
	FSocket* Socket = FTcpSocketBuilder(TEXT("MySocket")).AsReusable().BoundToEndpoint(Endpoint);

	if (nullptr == Socket)
	{
		return false;
	}

//	return false;
	// Try to connect to the socket
	int bConnected = Socket->Connect(*Endpoint.ToInternetAddr());
	if (0 > bConnected)
	{
		// Connection failed, port is likely closed
		UE_LOG(LogTemp, Warning, TEXT("Port %d on IP address %s is closed."), _Port, *_IPAddress);
		return false;
	}

	// Close socket after checking
	Socket->Close();
	ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(Socket);

	// Connect되는 IP 중에 '나'는 제외시켜야 함
	UGlobalGameInstance* Inst = GetGameInstance<UGlobalGameInstance>();
	if (true == Inst->IsMyIp(_IPAddress))
	{
		return false;
	}

	UE_LOG(LogTemp, Warning, TEXT("Port %d on IP address %s is open."), _Port, *_IPAddress);
	return true;
}