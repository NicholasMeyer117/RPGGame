// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	Idle,
	Walk,
	Sprint
};

UENUM(BlueprintType)
enum class EAttackTypes : uint8
{
	None,
	Light,
	Heavy,
	Special,
	Air,
	Charge,
	Thrust
};

USTRUCT(BlueprintType)
struct FEquippedItems : public FTableRowBase
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool EquippedWeapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool EquippedShield;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool EquippedHelmet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool EquippedBow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool EquippedArrows;

};

USTRUCT(BlueprintType)
struct FEnemyInfo : public FTableRowBase
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SphereRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SphereDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float LightDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float HeavyDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SpecialDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ChargeDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AirDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RoamRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MeleeDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RangedDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MaxChaseDistance;

};

UCLASS()
class RPGGAME_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void TryDoDamage(float DamageAmount);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void Death();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
