// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Runtime/Core/Public/Math/Vector.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	
	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector PlayerViewpointLocation;
	FRotator PlayerViewpointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewpointLocation, 
		OUT PlayerViewpointRotation
	);

	//UE_LOG(LogTemp, Warning, TEXT("The viewers location is %s, and the rotation is %s"), 
	//	*PlayerViewpointLocation.ToString(), 
	//	*PlayerViewpointRotation.ToString()
	//);

	FVector LineTraceEnd = PlayerViewpointLocation + PlayerViewpointRotation.Vector() * Reach; 
	DrawDebugLine(
		GetWorld(),
		PlayerViewpointLocation,
		LineTraceEnd,
		FColor(255, 0, 0),
		false,
		0.f,
		0.f,
		10.f
	);

	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewpointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);
	// line trace/ ray cast
	AActor* ActorHit = Hit.GetActor();
	if (ActorHit) {
		UE_LOG(LogTemp, Warning, TEXT("The object hit is %s"),
			*(ActorHit->GetName())
		);
	}
}

