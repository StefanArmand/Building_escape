// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Building_Escape.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"



// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();

	//UE_LOG(LogTemp, Warning, TEXT("The door rotation is %s"), *Owner);
}

void UOpenDoor::OpenDoor()
{
	Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
}

void UOpenDoor::CloseDoor()
{
	Owner->SetActorRotation(FRotator(0.0f, 0.f, 0.0f));
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PressurePlate->IsOverlappingActor(ActorThatOpens)) {
		Owner = GetOwner();
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	/*if(GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay) {
			CloseDoor();
		}*/

	

	// ...
}

