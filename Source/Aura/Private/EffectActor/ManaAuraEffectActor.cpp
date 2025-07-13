// Fill out your copyright notice in the Description page of Project Settings.


#include "EffectActor/ManaAuraEffectActor.h"

#include "AbilitySystemInterface.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Components/SphereComponent.h"

void AManaAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
	//Sphere->OnComponentBeginOverlap.AddDynamic(this,&AManaAuraEffectActor::OnSphereBeginOverlap);
	//Sphere->OnComponentEndOverlap.AddDynamic(this,&AManaAuraEffectActor::OnSphereEndOverlap);
}

