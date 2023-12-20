// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/AnimNotify_AttackHitCheck.h"

void UAnimNotify_AttackHitCheck::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if(MeshComp) 
	{
		// Skeletal Mesh Comp가 있다면, Owner를 가져와서 캐릭터 공격판정 해주자
		// 캐릭터 공격판정을 하기 위해서는 헤더를 인클루드 해야한다. 이는 캐릭터가 늘어날 때마다, 헤더를 추가해줘야함
		// 이는 의존성 ++++ -> 인터페이스를 이용합시다
		MeshComp->GetOwner();
	}
}
