


#include "Actors/AmmoPickup.h"
#include "Ipvmulti/IpvmultiCharacter.h"
#include "Net/UnrealNetwork.h"


AAmmoPickup::AAmmoPickup(): MeshComponent(nullptr), bHasBeenPickedUp(false)
{
	AmmoRestoreAmount = 5;
	SetReplicates(true);
}

void AAmmoPickup::BeginPlay()
{
	Super::BeginPlay();
	
}



void AAmmoPickup::OnPickedUp(AActor* OtherActor)
{
	AIpvmultiCharacter* Player = Cast<AIpvmultiCharacter>(OtherActor);
	if (Player && Player->HasAuthority()) 
		if (Player && Player->HasAuthority()) 
		{
			Player->Server_RefillAmmo_Implementation();
        
			Player->bIsFiringWeapon = true; 
			DestroyPickup();
		}
}

void AAmmoPickup::DestroyPickup()
{
	if (HasAuthority())
	{
		Destroy();
	}
}




void AAmmoPickup::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AAmmoPickup, bHasBeenPickedUp);
}


