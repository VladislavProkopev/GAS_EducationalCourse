// Fill out your copyright notice in the Description page of Project Settings.


#include "EffectActor/HealthAuraEffectActor.h"

#include "AbilitySystemInterface.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Components/SphereComponent.h"

void AHealthAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
	//Sphere->OnComponentBeginOverlap.AddDynamic(this,&AHealthAuraEffectActor::OnSphereBeginOverlap);
	//Sphere->OnComponentEndOverlap.AddDynamic(this,&AHealthAuraEffectActor::OnSphereEndOverlap);
}

