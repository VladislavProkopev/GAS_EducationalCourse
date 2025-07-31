// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AuraAbilitySystemComponent.h"

#include "AuraGameplayTags.h"

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);

	//Тест добавления нативных тегов
	/*const FAuraGameplayTags& GameplayTags = FAuraGameplayTags::Get();
	GEngine->AddOnScreenDebugMessage(-1,
		10.f,
		FColor::Red,
		FString::Printf(TEXT("Tag Armor: %s"), *GameplayTags.Attributes_Secondary_Armor.ToString()));
	GEngine->AddOnScreenDebugMessage(-1,
		10.f,
		FColor::Red,
		FString::Printf(TEXT("Tag Armor Penetration: %s"), *GameplayTags.Attributes_Secondary_ArmorPenetration.ToString()));
	GEngine->AddOnScreenDebugMessage(-1,
		10.f,
		FColor::Red,
		FString::Printf(TEXT("Tag Block Chance: %s"), *GameplayTags.Attributes_Secondary_BlockChance.ToString()));
	GEngine->AddOnScreenDebugMessage(-1,
		10.f,
		FColor::Red,
		FString::Printf(TEXT("Tag Critical Hit Chance: %s"), *GameplayTags.Attributes_Secondary_CriticalHitChance.ToString()));
	GEngine->AddOnScreenDebugMessage(-1,
		10.f,
		FColor::Red,
		FString::Printf(TEXT("Tag Critical Hit Damage: %s"), *GameplayTags.Attributes_Secondary_CriticalHitDamage.ToString()));
	GEngine->AddOnScreenDebugMessage(-1,
		10.f,
		FColor::Red,
		FString::Printf(TEXT("Tag Health Regeneration: %s"), *GameplayTags.Attributes_Secondary_HealthRegeneration.ToString()));
	GEngine->AddOnScreenDebugMessage(-1,
		10.f,
		FColor::Red,
		FString::Printf(TEXT("Tag Mana Regeneration: %s"), *GameplayTags.Attributes_Secondary_ManaRegeneration.ToString()));
	GEngine->AddOnScreenDebugMessage(-1,
		10.f,
		FColor::Red,
		FString::Printf(TEXT("Tag Max Health: %s"), *GameplayTags.Attributes_Secondary_MaxHealth.ToString()));
	GEngine->AddOnScreenDebugMessage(-1,
		10.f,
		FColor::Red,
		FString::Printf(TEXT("Tag Max Mana: %s"), *GameplayTags.Attributes_Secondary_MaxMana.ToString()));*/
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);
	
	EffectAssetTags.Broadcast(TagContainer);
	
	
}
