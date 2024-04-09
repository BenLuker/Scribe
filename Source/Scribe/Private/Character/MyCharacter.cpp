// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/MyCharacter.h"
#include "AbilitySystem/MyAbilitySystemComponent.h"

AMyCharacter::AMyCharacter()
{
	// Create an Ability System Component (ASC) for this character.
	AbilitySystemComponent = CreateDefaultSubobject<UMyAbilitySystemComponent>("AbilitySystemComponent");
}

UAbilitySystemComponent *AMyCharacter::GetAbilitySystemComponent() const
{
	// Return the ASC associated with this character.
	return AbilitySystemComponent;
}
