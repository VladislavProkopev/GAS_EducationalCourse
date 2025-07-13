// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AuraEffectActor.h"
#include "HealthAuraEffectActor.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AHealthAuraEffectActor : public AAuraEffectActor
{
	GENERATED_BODY()
public:

	virtual  void BeginPlay() override;
	
	
};
