// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AuraWidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;

USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	GENERATED_BODY()

	FWidgetControllerParams(){};
	FWidgetControllerParams(APlayerController* PlayerController,APlayerState* PlayerState
		,UAbilitySystemComponent* AbilitySystemComponent,UAttributeSet* AttributeSet)
			: PlayerController(PlayerController), PlayerState(PlayerState),
			  AbilitySystemComponent(AbilitySystemComponent),AttributeSet(AttributeSet){}

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<APlayerController> PlayerController;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<APlayerState> PlayerState;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<UAttributeSet> AttributeSet;
};

class UAttributeSet;
class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class AURA_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintCallable)
	void SetWidgetControllerParams(const FWidgetControllerParams& Params);
	virtual void BroadcastInitialValues();
	virtual void BindCallbacksToDependencies();
protected:

	UPROPERTY(BlueprintReadOnly,Category="AuraWidgetController")
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY(BlueprintReadOnly,Category="AuraWidgetController")
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY(BlueprintReadOnly,Category="AuraWidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly,Category="AuraWidgetController")
	TObjectPtr<UAttributeSet> AttributeSet;
};
