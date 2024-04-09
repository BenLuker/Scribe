// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/MyPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AMyPlayerController::AMyPlayerController()
{
}

void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();
    check(Context); // Ensure that the input mapping context is valid.

    // Add the input mapping context to the local player subsystem.
    UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
    if (Subsystem)
    {
        Subsystem->AddMappingContext(Context, 0);
    }
}

void AMyPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    // Bind input actions to functions for handling movement and camera look.
    UEnhancedInputComponent *EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
    EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyPlayerController::Move);
    EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMyPlayerController::Look);
}

void AMyPlayerController::Move(const FInputActionValue &Value)
{
    FVector2D MovementVector = Value.Get<FVector2D>();

    const FRotator Rotation = GetControlRotation();
    const FRotator YawRotation(0, Rotation.Yaw, 0);

    const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
    const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

    if (APawn *ControlledPawn = GetPawn<APawn>())
    {
        ControlledPawn->AddMovementInput(ForwardDirection, MovementVector.Y);
        ControlledPawn->AddMovementInput(RightDirection, MovementVector.X);
    }
}

void AMyPlayerController::Look(const FInputActionValue &Value)
{
    FVector2D LookVector = Value.Get<FVector2D>();
    AddPitchInput(LookVector.Y);
    AddYawInput(LookVector.X);
}
