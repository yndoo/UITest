// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "NetDataRow.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FNetDataRow : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	inline FString GetName() const
	{
		return Name;
	}
	inline FString GetIP() const
	{
		return IP;
	}
	inline FString GetPORT() const
	{
		return PORT;
	}
	inline bool GetIsServer() const
	{
		return IsServer;
	}

	void SetName(FString _Name)
	{
		Name = _Name;
	}

	void SetIP(FString _IP)
	{
		IP = _IP;
	}

	void SetPORT(FString _PORT)
	{
		PORT = _PORT;
	}

	void SetIsServer(bool _IsServer)
	{
		IsServer = _IsServer;
	}

private:
	UPROPERTY(Category = "Parameter", EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = "true"))
	FString Name = "";

	UPROPERTY(Category = "Parameter", EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = "true"))
	FString IP = "127.0.0.1";

	UPROPERTY(Category = "Parameter", EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = "true"))
	FString PORT = "30001";

	UPROPERTY(Category = "Parameter", EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = "true"))
	bool IsServer = false;
};
