// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TurtleStaminaComponent.generated.h"

UENUM(BlueprintType)
enum class EStaminaUsageType : uint8
{
	None UMETA(DisplayName = "None"),
	Jump UMETA(DisplayName = "Jump"),
	Dash UMETA(DisplayName = "Dash"),
	Slide UMETA(DisplayName = "Slide"),
	Sprint UMETA(DisplayName = "Sprint")
};

UCLASS( ClassGroup=(Custom), BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent) )
class TURTLEPROJECT_API UTurtleStaminaComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTurtleStaminaComponent();
	
	UFUNCTION(BlueprintCallable, Category="Stamina")
	void DrainStamina(const float DeltaTime, const float DamageTaken, const EStaminaUsageType UsageType);
	
	UFUNCTION(BlueprintPure, Category="Stamina")
	float GetCurrentStamina() const;
	
	UFUNCTION(BlueprintPure, Category="Stamina")
	float GetMaxStamina() const;
	
	UFUNCTION(BlueprintPure, Category="Stamina")
	bool CanSprint() const;
	
	UFUNCTION(BlueprintCallable, Category="Stamina")
	void SetSprinting(const bool bSprintingNow);
	
	UFUNCTION(BlueprintCallable, Category="Stamina")
	void SetStamina(const float NewStamina);
	
	UFUNCTION(BlueprintCallable, Category="Stamina")
	void RegenStamina(const float DeltaTime, const float DamageTaken);
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
private:
	
	UPROPERTY(EditAnywhere, Category="Stamina")
	float MaxStamina = 100.f;
	
	UPROPERTY(EditAnywhere, Category="Stamina")
	float CurrentStamina = 100.f;
	
	UPROPERTY(EditAnywhere, Category="Stamina")
	float DrainRate = 20.f;
	
	UPROPERTY(EditAnywhere, Category="Stamina")
	float RegenRate = 40.f;
	
	UPROPERTY(EditAnywhere, Category="Stamina")
	float JumpStaminaUsage = 20.f;
	
	UPROPERTY(EditAnywhere, Category="Stamina")
	float DashStaminaUsage = 50.f;
	
	UPROPERTY(VisibleAnywhere, Category="Stamina")
	bool bIsSprinting = false;
		
};
