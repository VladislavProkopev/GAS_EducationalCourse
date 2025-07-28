// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/AuraCharacterBase.h"
#include "Inrerfaces/CombatInterface.h"
#include "AuraCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase, public  ICombatInterface
{
	GENERATED_BODY()
public:
	AAuraCharacter();
	
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	// Combat Interface
	virtual int32 GetPlayerLevel() override;
	// End Combat Interface
protected:
	virtual void InitAbilityActorInfo() override;
private:

	UPROPERTY(EditAnywhere,Category=Camera)
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(EditAnywhere,Category=Camera)
	TObjectPtr<UCameraComponent> Camera;

	
};
