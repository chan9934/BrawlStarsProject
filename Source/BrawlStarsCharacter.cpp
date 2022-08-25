// Fill out your copyright notice in the Description page of Project Settings.


#include "BrawlStarsCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Animation/AnimMontage.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "NiagaraSystem.h"
#include "Animation/AnimInstance.h"


// Sets default values
ABrawlStarsCharacter::ABrawlStarsCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//ConstructorHelpers::FObjectFinder< UNiagaraSystem > NiagaraSystem = (TEXT("/Game/edgar/Decal/Smoke_Ns.Smoke_NS'"));
	//if (NiagaraSystem.Succeeded())
	//{
	//	ESkillPostNiagara = NiagaraSystem.Object;
	//}

	bIsESkill = false;
	bSetVisibility = false;

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

	PlayerInputComponent->BindAction(TEXT("EEE"), EInputEvent::IE_Pressed, this, &ABrawlStarsCharacter::ESkill);

}

void ABrawlStarsCharacter::ESkill()
{
	/*UE_LOG(LogTemp, Warning, TEXT("eee"));*/
	bool DoOnce = true;
	if (DoOnce)
	{
		DoOnce = false;
		bIsESkill = true;
		GetCharacterMovement()->Deactivate();
		GetCharacterMovement()->StopMovementImmediately();

		PlayAnAnimationMontage();
		DoOnce = true;
		/*FOnMontageBlendingOutStarted OnCompleted;*/
		/*OnCompleted.BindUObject(this, &ABrawlStarsCharacter::EMontageCompleted);*/
	
			




		//if (!(ESkillMontage->IsValidToPlay()))
		//{
		//	
		//	bSetVisibility = true;
		//	GetCharacterMovement()->Activate();
		//	bIsESkill = false;
		//	DoOnce = true;


		//	//spawnactor bp erange�� ���߿�
		//}

		float WaitTime = { 0.9f }; //�ð��� �����ϰ�
		GetWorld()->GetTimerManager().SetTimer(DelayTimeHandle, FTimerDelegate::CreateLambda([&]()
			{

				// ���⿡ �ڵ带 ġ�� �ȴ�.
				USkeletalMeshComponent* TestMesh = GetMesh();


				UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ESkillPostNiagara, TestMesh->GetSocketLocation(TEXT("L_ankle_s")));

				float WaitTime2 = { 5.0f }; //�ð��� �����ϰ�
				GetWorld()->GetTimerManager().SetTimer(DelayTimeHandle, FTimerDelegate::CreateLambda([&]()
					{

						bSetVisibility = false;


					}
				), WaitTime2, false); //�ݺ��� ���⼭ �߰� ������ ������ ��������

			}
		), WaitTime, false); //�ݺ��� ���⼭ �߰� ������ ������ ��������




	}

}

void ABrawlStarsCharacter::PlayAnAnimationMontage()
{
	

	if (ESkillMontage)
	{
		Montage_Play(ESkillMontage, 1.0f);
		FOnMontageBlendingOutStarted CompleteDelegate;
		CompleteDelegate.BindUObject(this, &ABrawlStarsCharacter::FunctionToExecuteOnAnimationEnd);
		Montage_SetEndDelegate(CompleteDelegate, ESkillMontage);
	}
}

void ABrawlStarsCharacter::FunctionToExecuteOnAnimationEnd()
{
	bSetVisibility = true;
	GetCharacterMovement()->Activate();
	bIsESkill = false;
	
}
