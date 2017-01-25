// Fill out your copyright notice in the Description page of Project Settings.

#include "HolodeckPrivatePCH.h"
#include "HolodeckAgent.h"


// Sets default values
AHolodeckAgent::AHolodeckAgent()
{
	PrimaryActorTick.bCanEverTick = true;
	Reward = 0;
	Terminal = false;
	AgentName = "";
}

// Called when the game starts or when spawned
void AHolodeckAgent::BeginPlay()
{
	Super::BeginPlay();
	HolodeckController = Cast<AHolodeckPawnController>(Controller);
	if (HolodeckController == nullptr)
		GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, TEXT("NO HOLODECK CONTROLLER ON HOLODECK AGENT!"));
	
}

// Called every frame
void AHolodeckAgent::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	RewardMessage.Data = FString::FromInt(Reward);
	RewardMessage.Type = "Reward";
	if (HolodeckController)
		HolodeckController->Publish(RewardMessage);

	TerminalStateMessage.Data = Terminal ? TEXT("True") : TEXT("False");
	TerminalStateMessage.Type = "Terminal";
	if (HolodeckController)
		HolodeckController->Publish(TerminalStateMessage);
}

// Called to bind functionality to input
void AHolodeckAgent::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}
