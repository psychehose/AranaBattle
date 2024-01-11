// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/ABCharacterBase.h"
#include "InputActionValue.h"
#include "Interface/ABCharacterHUDInterface.h"
#include "ABCharacterPlayer.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API AABCharacterPlayer : public AABCharacterBase, public IABCharacterHUDInterface
{
	GENERATED_BODY()

public:
	AABCharacterPlayer();

protected:
	// 입력 맵핑 컨텍스트를 할당하는 역할을 할 것
	virtual void BeginPlay() override;

public:
	// 입력 액션과 Move, Look 함수와 맵핑
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


// Character Control Setcion

protected:
	void ChangeCharacterControl();
	void SetCharacterControl(ECharacterControlType NewCharacterControlType);

	virtual void SetCharacterControlData(const class UABCharacterControlData* CharacterControlData) override;
	




	// Camera Setting
protected:
	// Meta - AllowPrivateAcess는 블루프린트에서도 접근 가능하게 함
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> CameraBoom;
	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraComponent> FollowCamera;

	// Input System - 매핑 컨텍스트와 액션에 대한 에셋
protected:


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> ChangeControlAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> ShoulderMoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> ShoulderLookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> QuaterMoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> AttackAction;




	void ShoulderMove(const FInputActionValue& Value);
	void ShoulderLook(const FInputActionValue& Value);

	void QuaterMove(const FInputActionValue& Value);

	ECharacterControlType CurrentCharacterControlType;

	void Attack();

// UI Section

protected:
	virtual void SetupHUDWidget(class UABHUDWidget* InHUDWidget) override;

};
