// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ABCharacterNonPlayer.h"

AABCharacterNonPlayer::AABCharacterNonPlayer()
{
	
}

void AABCharacterNonPlayer::SetDead()
{
	Super::SetDead();

	// 5초를 재야하는데, 이것은 월드의 타임서비스를 이용하자

	FTimerHandle DeadTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(DeadTimerHandle, FTimerDelegate::CreateLambda(
		// 람다
		[&]()
		{
			Destroy();
		}
	), DeadEventDelayTime, false);
	
}
