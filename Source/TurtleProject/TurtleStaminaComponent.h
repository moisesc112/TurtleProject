// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TurtleStaminaComponent.generated.h"


UCLASS( ClassGroup=(Custom), BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent) )
class TURTLEPROJECT_API UTurtleStaminaComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTurtleStaminaComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stamina")
	float MaxStamina = 100.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stamina")
	float CurrentStamina = 100.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stamina")
	float DrainRate = 20.f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Stamina")
	float RegenRate = 40.f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Stamina")
	float JumpStaminaUsage = 20.f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Stamina")
	bool bIsSprinting = false;
	
	UFUNCTION(BlueprintCallable, Category="Stamina")
	void DrainStamina(float DeltaTime, float DamageTaken, bool bJustJumped);
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	
		
};
