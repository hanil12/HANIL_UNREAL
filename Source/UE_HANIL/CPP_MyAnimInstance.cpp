// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MyAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"
#include "MyCharacter.h"

UCPP_MyAnimInstance::UCPP_MyAnimInstance()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> AM(TEXT("AnimMontage'/Game/Animation/AM_Attack.AM_Attack'"));

	if (AM.Succeeded())
	{
		AttackMontage = AM.Object;
	}
}

void UCPP_MyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();

	if (IsValid(Pawn))
	{
		Speed = Pawn->GetVelocity().Size();

		auto Character = Cast<AMyCharacter>(Pawn);
		if (Character)
		{
			IsFalling = Character->GetMovementComponent()->IsFalling();

			Horizontal = Character->HorizontalValue;
			Vertical = Character->VerticalValue;
		}
	}
}

void UCPP_MyAnimInstance::PlayAttackMontage()
{
	if (!Montage_IsPlaying(AttackMontage))
	{
		UE_LOG(LogTemp, Log, TEXT("Attack!!"));
		Montage_Play(AttackMontage, 1.f);
	}
}

void UCPP_MyAnimInstance::JumpToSection(int32 SectionIndex)
{
	UE_LOG(LogTemp, Log, TEXT("SectionIndex : %d"), SectionIndex);
	FName Name = GetAttackMontageName(SectionIndex);
	Montage_JumpToSection(Name, AttackMontage);
}

FName UCPP_MyAnimInstance::GetAttackMontageName(int32 SectionIndex)
{
	return FName(*FString::Printf(TEXT("Fire%d"), SectionIndex));
}

void UCPP_MyAnimInstance::AnimNotify_Fire()
{
	UE_LOG(LogTemp, Log, TEXT("Fire!!"));
}
