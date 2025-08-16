// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/EnemyCharacter/AuraEnemy.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Components/CapsuleComponent.h"

AAuraEnemy::AAuraEnemy()
{

	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
	
}

void AAuraEnemy::BeginPlay()
{
	Super::BeginPlay();

	if (GetCapsuleComponent())
	{
		GetCapsuleComponent()->OnBeginCursorOver.AddDynamic(this, &AAuraEnemy::HighLightActor);
		GetCapsuleComponent()->OnEndCursorOver.AddDynamic(this,&AAuraEnemy::UnHighLightActor);
	}
	InitAbilityActorInfo();
}

void AAuraEnemy::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this,this);
	Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();

	InitializeDefaultAttributes();
}

void AAuraEnemy::HighLightActor(UPrimitiveComponent* TouchedComponent)
{
	//DrawDebugSphere(GetWorld(),GetActorLocation(),32.f,24,FColor::Red,false,1.f);
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(250);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(250);
}

void AAuraEnemy::UnHighLightActor(UPrimitiveComponent* TouchedComponent)
{
	//DrawDebugSphere(GetWorld(),GetActorLocation(),32.f,24,FColor::Green,false,1.f);
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

int32 AAuraEnemy::GetPlayerLevel()
{
	return Level;
}
