// Fill out your copyright notice in the Description page of Project Settings.


#include "TurtleStatusComponent.h"

// Sets default values for this component's properties
UTurtleStatusComponent::UTurtleStatusComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTurtleStatusComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTurtleStatusComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTurtleStatusComponent::SetSlowMultiplier(float NewSlowValue)
{
	SlowMultiplier = NewSlowValue;
}

void UTurtleStatusComponent::SetDamage(float NewDamageValue)
{
	Damage = NewDamageValue;
}
