// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()
public:
	AAuraCharacter();
private:

	UPROPERTY(EditAnywhere,Category=Camera)
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(EditAnywhere,Category=Camera)
	TObjectPtr<UCameraComponent> Camera;
};
