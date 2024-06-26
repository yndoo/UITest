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
	
public:
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
	//virtual bool Initialize() override;

	UFUNCTION(BlueprintCallable)
	void RoomIPDataInit(UDataTable* _IPData, UComboBoxString* _Combo);
	UFUNCTION(BlueprintCallable)
	void RoomIPSelectChange(FString _Text);

	UPROPERTY(Category = "Contents", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FString IPAddress = TEXT("127.0.0.1");
	UPROPERTY(Category = "Contents", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FString Port = TEXT("30002");

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool IsHoverOnOff;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EBtnType HoverBtnType;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EBtnType UnHoverBtnType;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool CreateRoomUION;	// 이건 좀 아닌것같은뎅..

	const FNetDataRow* TempNetData;
};
