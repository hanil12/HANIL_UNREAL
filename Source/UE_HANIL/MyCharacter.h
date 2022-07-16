// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class UE_HANIL_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Attack();

	void UpDown(float Value);
	void LeftRight(float Value);
	void Yaw(float value);

	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

private:
	UPROPERTY(VisibleAnyWhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnyWhere)
	class UCameraComponent* Camera;

	UPROPERTY()
	class UCPP_MyAnimInstance* AnimInstace;

	UPROPERTY(VisibleAnywhere, Category = Pawn)
	bool IsAttacking = false;

	UPROPERTY()
	int32 AttackIndex = 0;

public:

	UPROPERTY()
	float HorizontalValue = 0.0f;

	UPROPERTY()
	float VerticalValue = 0.0f;
};
