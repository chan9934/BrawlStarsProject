// Fill out your copyright notice in the Description page of Project Settings.


#include "BrawlStarsCharacter.h"

// Sets default values
ABrawlStarsCharacter::ABrawlStarsCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABrawlStarsCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABrawlStarsCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABrawlStarsCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

