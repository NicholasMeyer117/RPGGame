// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "AbilitySystemsActorComponent.generated.h"

UENUM(BlueprintType)
enum class ESelectedAbility : uint8
{
	None,
	LightMelee,
	HeavyMelee,
	JumpAttack,
	FireBall,
	Bow
};

USTRUCT(BlueprintType)
struct FPlayerStats : public FTableRowBase
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CurrentHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxStamina;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CurrentStamina;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ArmorValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BlockValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Gold;


};


UCLASS(blueprintable)
class RPGGAME_API UAbilitySystemsActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAbilitySystemsActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
