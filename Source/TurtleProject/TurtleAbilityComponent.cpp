// Fill out your copyright notice in the Description page of Project Settings.


#include "TurtleAbilityComponent.h"
#include "TurtleBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TurtleStaminaComponent.h"
#include "TurtleStatusComponent.h"

// Sets default values for this component's properties
UTurtleAbilityComponent::UTurtleAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTurtleAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	TurtleOwner = Cast<ATurtleBaseCharacter>(GetOwner());
	
}


// Called every frame
void UTurtleAbilityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UTurtleAbilityComponent::HasEnoughStamina() const
{
	if (TurtleOwner == nullptr)
		return false;
	
	const UTurtleStaminaComponent* StaminaComp =  TurtleOwner->GetStaminaComponent();
	if (StaminaComp == nullptr)
		return false;
	
	return StaminaComp->GetCurrentStamina() > 0.0f;
}

void UTurtleAbilityComponent::TryDash()
{
	if (!TurtleOwner)
		return;
	
	UTurtleStaminaComponent* StaminaComp =  TurtleOwner->GetStaminaComponent();
	if (!StaminaComp)
		return;
	
	const UTurtleStatusComponent* StatusComp =  TurtleOwner->GetStatusComponent();
	if (!StatusComp)
		return;
	
	UCharacterMovementComponent* MovementComp =  TurtleOwner->GetCharacterMovement();
	if (!MovementComp)
		return;
	
	if (!HasEnoughStamina())
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("Not Enough Stamina to Dash"));
		return;
	}
	
	FVector DashDirection = TurtleOwner->GetActorForwardVector();
	DashDirection.Z = 0.0f;
	DashDirection.Normalize();
	
	FVector NewVelocity = (DashDirection * DashStrength) + MovementComp->Velocity;
	
	MovementComp->Velocity = NewVelocity;
	StaminaComp->DrainStamina(0.0f, StatusComp->GetDamage(), EStaminaUsageType::Dash);
}
