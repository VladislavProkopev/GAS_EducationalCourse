// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraAssetManager.h"

#include "AbilitySystemGlobals.h"
#include "AuraGameplayTags.h"

UAuraAssetManager& UAuraAssetManager::Get()
{
	check(GEngine);
	UAuraAssetManager* AuraAssetManager = Cast<UAuraAssetManager>(GEngine->AssetManager);
	return *AuraAssetManager;
}

void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	
	FAuraGameplayTags::InitializeNativeGameplayTags();

	//Это необходимо для корректной работы GAS - обязательно должно быть вызвано либо в GameModule
	//Либо что считается лучшей практикой в Кастомном ассет менеджере - что мы собственно и сделали
	UAbilitySystemGlobals::Get().InitGlobalData();
}
