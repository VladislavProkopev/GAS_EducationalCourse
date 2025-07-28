// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/AuraCharacterBase.h"

#include "AbilitySystemComponent.h"
#include "Characters/PlayerCharacter/AuraPlayerState.h"

// Sets default values
AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AAuraCharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}



void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAuraCharacterBase::InitAbilityActorInfo()
{
}

void AAuraCharacterBase::ApplyEffectToSelf(const TSubclassOf<UGameplayEffect>& EffectToApply, float Level) const
{
	checkf(IsValid(GetAbilitySystemComponent()),TEXT("AAuraCharacterBase::InitializePrimaryAttributes() - AbilitySystemCompinent is not Valid!"))
	checkf(IsValid(EffectToApply),TEXT("AAuraCharacterBase::InitializePrimaryAttributes() - EffectToApply is not Valid!"));
	FGameplayEffectContextHandle DefaultEffectContext = GetAbilitySystemComponent()->MakeEffectContext();
	DefaultEffectContext.AddSourceObject(this);
	const FGameplayEffectSpecHandle DefaultEffectSpec = GetAbilitySystemComponent()->MakeOutgoingSpec(EffectToApply,Level,DefaultEffectContext);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*DefaultEffectSpec.Data.Get(),GetAbilitySystemComponent());
}

void AAuraCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes,1.f);
	ApplyEffectToSelf(DefaultSecondaryAttributes,1.f);
	ApplyEffectToSelf(DefaultVitalAttributes,1.f);
}



