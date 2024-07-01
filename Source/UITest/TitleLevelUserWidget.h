// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UTestEnum.h"
#include "TitleLevelUserWidget.generated.h"

/**
 * 
 */
class UComboBoxString;
struct FNetDataRow;
UCLASS()
class UITEST_API UTitleLevelUserWidget : public UUserWidget
{
	GENERATED_BODY()
	

	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);


public:
	UFUNCTION(BlueprintImplementableEvent)
	void TestTick();
	UFUNCTION(BlueprintCallable, Category = "MyBtnEvent")
	int MyBtnHover();
	UFUNCTION(BlueprintCallable, Category = "MyBtnEvent")
	int MyBtnUnhover();

	UFUNCTION(BlueprintCallable)
	void ServerStart();
	UFUNCTION(BlueprintCallable)
	void Connect(FString _IP);
	UFUNCTION(BlueprintCallable)
	void ServerInitialize(FName _IPName); 

	// ½ÇÇè Áß
	UFUNCTION(BlueprintCallable)
	bool IsPortOpen(const FString& _IPAddress, int32 _Port);
	//virtual bool Initialize() override;

	UFUNCTION(BlueprintCallable)
	void RoomIPDataInit(UDataTable* _IPData, UComboBoxString* _Combo);
	UFUNCTION(BlueprintCallable)
	void RoomIPSelectChange(FString _Text);
	UFUNCTION(BlueprintCallable)
	void SetBrowserOnOff(bool _Setting);
	UFUNCTION(BlueprintCallable)
	bool GetBrowserOnOff();

	UPROPERTY(Category = "Contents", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FString IPAddress = TEXT("127.0.0.1");
	UPROPERTY(Category = "Contents", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FString Port = TEXT("30001");


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool NeedRefresh = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool IsHoverOnOff;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EBtnType HoverBtnType;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EBtnType UnHoverBtnType;

	const FNetDataRow* TempNetData;
};
