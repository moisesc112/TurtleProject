// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TurtleStatusComponent.generated.h"


UCLASS( ClassGroup=(Custom), BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent) )
class TURTLEPROJECT_API UTurtleStatusComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTurtleStatusComponent();
	
	UFUNCTION(BlueprintPure, Category = "Status Effects")
	float GetSlowMultiplier() const { return SlowMultiplier; };
	
	UFUNCTION(BlueprintCallable, Category = "Status Effects")
	void SetSlowMultiplier(float NewSlowValue);
	
	UFUNCTION(BlueprintPure, Category = "Status Effects")
	float GetDamage() const { return Damage; };
	
	UFUNCTION(BlueprintCallable, Category = "Status Effects")
	void SetDamage(float NewDamageValue);
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere, Category = "Status Effects")
	float Damage = 0.0f;
	
	UPROPERTY(EditAnywhere, Category = "Status Effects")
	float SlowMultiplier = 1.f;
};
