// Fill out your copyright notice in the Description page of Project Settings.


#include "Input/AuraInputConfig.h"

const UInputAction* UAuraInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound)
{
	for (const auto& Action: AbilityInputActions)
	{
		if (Action.InputTag.IsValid() && Action.InputTag.MatchesTagExact(InputTag))
		{			
			return Action.InputAction;
		}
	}
	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Warning, TEXT("Input action in UAuraInputConfig::FindAbilityInputActionForTag not found"));
	}
	return nullptr;
}
