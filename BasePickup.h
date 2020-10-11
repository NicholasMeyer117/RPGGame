// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasePickup.generated.h"

UENUM(BlueprintType)
enum class EPickupType : uint8
{
	Weapon,
	Shield,
	Helmet,
	Consumable,
	Arrow
};

USTRUCT(BlueprintType)
struct FItemInfo
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Armor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Block;


};

UCLASS()
class RPGGAME_API ABasePickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasePickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
		FItemInfo ItemInfo;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
