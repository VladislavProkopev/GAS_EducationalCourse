// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AuraEffectActor.h"
#include "ManaAuraEffectActor.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AManaAuraEffectActor : public AAuraEffectActor
{
	GENERATED_BODY()
public:

	virtual void BeginPlay() override;
	
	UFUNCTION()
	virtual void OnSphereBeginOverlap (UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	virtual void OnSphereEndOverlap (UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
};
