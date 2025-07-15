// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AuraAttributeSet.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayEffectExtension.h"
#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"

UAuraAttributeSet::UAuraAttributeSet()
{
	InitHealth(50.f);
	InitMaxHealth(100.f);
	InitMana(50.f);
	InitMaxMana(100.f);
}

void UAuraAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet,Health,COND_None,REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet,MaxHealth,COND_None,REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet,Mana,COND_None,REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet,MaxMana,COND_None,REPNOTIFY_Always);
}

void UAuraAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue,0,GetMaxHealth());
	}
	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue,0,GetMaxMana());
	}
}

void UAuraAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	SetHealth(FMath::Clamp(GetHealth(),0.f,GetMaxHealth()));
	SetEffectProperties(Data,EffectProperties);
}

void UAuraAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass,Health,OldHealth);
}

void UAuraAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass,MaxHealth,OldMaxHealth);
}

void UAuraAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass,Mana,OldMana);
}

void UAuraAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ThisClass,MaxMana,OldMaxMana);
}

void UAuraAttributeSet::SetEffectProperties(const struct FGameplayEffectModCallbackData& Data,
	FEffectProperties& OutProps) const
{
	
	const FGameplayEffectContextHandle SourceContext = Data.EffectSpec.GetContext();
	if (SourceContext.IsValid())
	{
		OutProps.EffectContextHandle = SourceContext;
		UAbilitySystemComponent* const SourceASC = SourceContext.GetInstigatorAbilitySystemComponent();
		if (IsValid(SourceASC))
		{
			OutProps.SourceAbilitySystemComponent = SourceASC;
			AActor* const SourceActor = SourceASC->AbilityActorInfo->AvatarActor.Get();
			if (IsValid(SourceActor))
			{
				OutProps.SourceAvatarActor = SourceActor;
			}
			APlayerController* const SourceController = SourceASC->AbilityActorInfo->PlayerController.Get();
			if (IsValid(SourceController))
			{
				OutProps.SourceController = SourceController;
			}
			ACharacter* const SourceCharacter = Cast<ACharacter>(SourceController->GetPawn());
			if (IsValid(SourceCharacter))
			{
				OutProps.SourceCharacter = SourceCharacter;
			}
		}
	}
	
	AActor* const TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
	if (IsValid(TargetAvatarActor))
	{
		OutProps.TargetAvatarActor = TargetAvatarActor;
	}
	AController* const TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
	if (IsValid(TargetController))
	{
		OutProps.TargetController = TargetController;
	}
	ACharacter* const TargetCharacter = Cast<ACharacter>(TargetController->GetPawn());
	if (IsValid(TargetCharacter))
	{
		OutProps.TargetCharacter = TargetCharacter;
	}
	UAbilitySystemComponent* const TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetAvatarActor);
	if (IsValid(TargetASC))
	{
		OutProps.TargetAbilitySystemComponent = TargetASC;
	}
}
