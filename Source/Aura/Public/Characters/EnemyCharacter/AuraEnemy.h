// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/AuraCharacterBase.h"
#include "Inrerfaces/CombatInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraEnemy();
	
	
	UFUNCTION()
	void HighLightActor(UPrimitiveComponent* TouchedComponent);
	
	UFUNCTION()
	void UnHighLightActor(UPrimitiveComponent* TouchedComponent);

	// Combat Interface
	virtual int32 GetPlayerLevel() override;
	// End Combat Interface
protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="EnemyLevel")
	int32 Level = 1;
private:

	
};
