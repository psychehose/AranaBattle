// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/ABCharacterBase.h"
#include "Engine/StreamableManager.h"
#include "ABCharacterNonPlayer.generated.h"

/**
 * 
 */
UCLASS(config=ArenaBattle)
class ARENABATTLE_API AABCharacterNonPlayer : public AABCharacterBase
{
	GENERATED_BODY()

public:
	AABCharacterNonPlayer();
	virtual void PostInitializeComponents() override;

protected:
	void SetDead() override;
	void NPCMeshLoadCompleted();

	UPROPERTY(config) // config를 통해 주소값을 가져올 것임 주소값이기 대문에 FSoftObjectPtr 사용.
	TArray<FSoftObjectPath> NPCMeshs;
	
	// 비동기로 로딩 -> FStreamableHandle를 통해서
	TSharedPtr<FStreamableHandle> NPCMeshHandle;

};
