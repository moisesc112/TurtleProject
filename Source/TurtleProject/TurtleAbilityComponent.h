// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TurtleAbilityComponent.generated.h"

class ATurtleBaseCharacter;

UCLASS( ClassGroup=(Custom), BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent) )
class TURTLEPROJECT_API UTurtleAbilityComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this component's properties
	UTurtleAbilityComponent();
	
	UFUNCTION(BlueprintCallable, Category="Dash")
	bool TryDash();
	
	UFUNCTION(BlueprintPure, Category="Ability")
	bool HasEnoughStamina() const;
	
	void EndDash();
	
	bool IsDashing() const { return bIsDashing; }

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY()
	ATurtleBaseCharacter* TurtleOwner = nullptr;
	
	UPROPERTY(EditAnywhere, Category="Dash")
	float DashStrength = 2000.f;
	
	UPROPERTY(EditAnywhere, Category="Dash")
	float DashCooldown = 0.5f;
	
	UPROPERTY(EditAnywhere, Category="Dash")
	bool bDashOnCooldown = false;
	
	UPROPERTY(EditAnywhere, Category="Dash")
	bool bIsDashing = false;
	
	FTimerHandle DashCooldownHandle;
};
