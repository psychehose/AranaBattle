// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ABCharacterAIInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UABCharacterAIInterface : public UInterface
{
	GENERATED_BODY()
};

DECLARE_DELEGATE(FAICharacterAttackFinished);


/**
 * 
 */
class ARENABATTLE_API IABCharacterAIInterface
{
	GENERATED_BODY()


public:
	virtual float GetAIPatrolRadius() = 0;
	virtual float GetAIDetectRange() = 0;
	virtual float GetAIAttackRange() = 0;
	virtual float GetAITurnSpeed() = 0;


	virtual void SetAIAttackDelegate(FAICharacterAttackFinished& InOnAttackFinished) = 0;
	virtual void AttackByAI() = 0;


};
