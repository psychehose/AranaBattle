// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/AnimNotify_AttackHitCheck.h"

void UAnimNotify_AttackHitCheck::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if(MeshComp) 
	{
		// Skeletal Mesh Comp�� �ִٸ�, Owner�� �����ͼ� ĳ���� �������� ������
		// ĳ���� ���������� �ϱ� ���ؼ��� ����� ��Ŭ��� �ؾ��Ѵ�. �̴� ĳ���Ͱ� �þ ������, ����� �߰��������
		// �̴� ������ ++++ -> �������̽��� �̿��սô�
		MeshComp->GetOwner();
	}
}
