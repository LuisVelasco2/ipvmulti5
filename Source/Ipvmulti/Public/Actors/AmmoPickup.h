// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AmmoPickup.generated.h"

UCLASS()
class IPVMULTI_API AAmmoPickup : public AActor
{
	GENERATED_BODY()

public:
	AAmmoPickup();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION()
	void OnPickedUp(AActor* OtherActor);
	void DestroyPickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AmmoRestoreAmount;

	UPROPERTY(Replicated)
	bool bHasBeenPickedUp;

	
private:
	FTimerHandle TimerHandle; 

};
