// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AuraAbilitySystemComponent.h"

#include "AuraGameplayTags.h"
#include "AbilitySystem/Abilities/AuraGameplayAbility.h"

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::ClientEffectApplied);

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

void UAuraAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{
	for (const TSubclassOf<UGameplayAbility> AbilityClass : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass,1);
		if (const UAuraGameplayAbility* AuraAbility = Cast<UAuraGameplayAbility>(AbilitySpec.Ability))
		{
			AbilitySpec.GetDynamicSpecSourceTags().AddTag(AuraAbility->StartupInputTag);
			GiveAbility(AbilitySpec);
		}
	}
}

void UAuraAbilitySystemComponent::AbilityInputTagHeld(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid()) return;

	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InputTag))
		{
			AbilitySpecInputPressed(AbilitySpec);
			if (!AbilitySpec.IsActive())
			{
				TryActivateAbility(AbilitySpec.Handle);
			}
		}
	}
}

void UAuraAbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid()) return;

	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InputTag))
		{
			AbilitySpecInputReleased(AbilitySpec);
		}
	}
}

void UAuraAbilitySystemComponent::ClientEffectApplied_Implementation(UAbilitySystemComponent* AbilitySystemComponent,
                                                const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);
	
	EffectAssetTags.Broadcast(TagContainer);
		
}
