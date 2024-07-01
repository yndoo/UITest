// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/GlobalGameInstance.h"

UGlobalGameInstance::UGlobalGameInstance()
{

}

const FNetDataRow* UGlobalGameInstance::GetNetData(FName _Name)
{
	if (nullptr == NetDataTable)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == NetDataTable)"), __FUNCTION__, __LINE__);
	}

	FNetDataRow* Data = NetDataTable->FindRow<FNetDataRow>(_Name, nullptr);

	if (nullptr == Data)
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> %s Name Data Is Nullptr"), __FUNCTION__, __LINE__, *_Name.ToString());
		return nullptr;
	}

	return Data;
}

const FNetDataRow UGlobalGameInstance::GetNetDataForBP(FName _Name)
{
	if (nullptr == NetDataTable)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == NetDataTable)"), __FUNCTION__, __LINE__);
	}

	FNetDataRow* Data = NetDataTable->FindRow<FNetDataRow>(_Name, nullptr);

	if (nullptr == Data)
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> %s Name Data Is Nullptr"), __FUNCTION__, __LINE__, *_Name.ToString());
		//return nullptr;
	}

	return *Data;
}

bool UGlobalGameInstance::IsMyIp(FString _ip)
{
	if (true == MyID.IsEmpty())
	{
		return false;
	}
	const FNetDataRow* data = GetNetData(FName(*MyID));
	if (_ip == data->GetIP())
	{
		return true;
	}
	return false;
}