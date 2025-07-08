// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/AuraCharacterBase.h"
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
	
protected:
	virtual void BeginPlay() override;
};
