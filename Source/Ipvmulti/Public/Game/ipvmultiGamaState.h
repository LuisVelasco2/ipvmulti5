// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ipvmultiGamaState.generated.h"


UCLASS()
class IPVMULTI_API AipvmultiGamaState : public AGameStateBase
{
	GENERATED_BODY()
public:
	UFUNCTION(NetMulticast, Reliable)
	void MultiCastOnMissionComplete(APawn* InstigatorPawn, bool bMissionSuccess);
};
