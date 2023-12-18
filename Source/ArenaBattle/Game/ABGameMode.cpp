// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/ABGameMode.h"
// #include "Player/ABPlayerController.h"

AABGameMode::AABGameMode()
{
	// DefaultPawnClass
	// BP Class�̹Ƿ� �������κ��� C++ Ŭ���� ������ �����;���
	// ConstructorHelpers�� ���ؼ� ������ �� ����.
	/*static ConstructorHelpers::FClassFinder<APawn> ThirdPersonClassRef(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter_C"));

	if (ThirdPersonClassRef.Class)
	{
		DefaultPawnClass = ThirdPersonClassRef.Class;
	}*/


	// C++ ������ Class�� ����
	static ConstructorHelpers::FClassFinder<APawn> DefaultPawnClassRef(TEXT("/Script/ArenaBattle.ABCharacterPlayer"));
	if (DefaultPawnClassRef.Class)
	{
		DefaultPawnClass = DefaultPawnClassRef.Class;
	}

	// PlayerController
	//
	// C++ Class�̹Ƿ� �ٷ� ���� ���� (����� ��Ŭ��� �ؾ���)
	//PlayerControllerClass = AABPlayerController::StaticClass();

	// ����� ��Ŭ��� ���� �ʴ� ���(������ ���߱�)
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerClassRef(TEXT("/Script/ArenaBattle.ABPlayerController"));
	PlayerControllerClass = PlayerControllerClassRef.Class;
}
