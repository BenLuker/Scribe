// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

class UAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class SCRIBE_API AMyCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Constructor for this character.
	AMyCharacter();

protected:
	// The Ability System Component (ASC) manages gameplay abilities for this character.
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	// IAbilitySystemInterface implementation: Returns the ASC for this character.
	virtual UAbilitySystemComponent *GetAbilitySystemComponent() const override;
};
