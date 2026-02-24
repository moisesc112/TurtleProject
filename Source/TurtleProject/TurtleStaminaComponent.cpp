// Fill out your copyright notice in the Description page of Project Settings.


#include "TurtleStaminaComponent.h"

#include "VectorUtil.h"

// Sets default values for this component's properties
UTurtleStaminaComponent::UTurtleStaminaComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTurtleStaminaComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTurtleStaminaComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (bIsSprinting)
	{
		DrainStamina(DeltaTime, 0.f, false);
	}
	// ...
}

void UTurtleStaminaComponent::DrainStamina(const float DeltaTime, const float DamageTaken, const bool bJustJumped)
{
	if (bJustJumped)
	{
		CurrentStamina = FMath::Clamp(CurrentStamina - JumpStaminaUsage, 0.f, MaxStamina - DamageTaken);
	}
	else
	{
		CurrentStamina = FMath::Clamp( CurrentStamina - (DeltaTime * DrainRate), 0.f, MaxStamina - DamageTaken);
	}
}

float UTurtleStaminaComponent::GetCurrentStamina() const
{
	return CurrentStamina;
}

float UTurtleStaminaComponent::GetMaxStamina() const
{
	return MaxStamina;
}

bool UTurtleStaminaComponent::CanSprint() const
{
	return CurrentStamina > 0.f;
}

void UTurtleStaminaComponent::SetSprinting(const bool bSprintingNow)
{
	bIsSprinting = bSprintingNow;
}

void UTurtleStaminaComponent::SetStamina(const float NewStamina)
{
	CurrentStamina = NewStamina;
}

void UTurtleStaminaComponent::RegenStamina(const float DeltaTime, const float DamageTaken)
{
	CurrentStamina = FMath::Clamp((DeltaTime * RegenRate) + CurrentStamina, 0.f, MaxStamina - DamageTaken);
}

