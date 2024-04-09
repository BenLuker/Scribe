// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 *
 */
UCLASS()
class SCRIBE_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Constructor for the player controller.
	AMyPlayerController();

protected:
	// Called when the player controller begins play.
	virtual void BeginPlay() override;

	// Set up input bindings for this player controller.
	virtual void SetupInputComponent() override;

	// Handle movement input.
	void Move(const FInputActionValue &Value);

	// Handle camera look input.
	void Look(const FInputActionValue &Value);

private:
	// The input mapping context associated with this player controller.
	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputMappingContext> Context;

	// The input action for character movement.
	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputAction> MoveAction;

	// The input action for camera look.
	UPROPERTY(EditAnywhere, Category = Input)
	TObjectPtr<UInputAction> LookAction;
};
