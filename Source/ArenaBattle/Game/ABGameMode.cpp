// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/ABGameMode.h"
// #include "Player/ABPlayerController.h"

AABGameMode::AABGameMode()
{
	// DefaultPawnClass
	// BP Class이므로 에셋으로부터 C++ 클래스 정보를 가져와야함
	// ConstructorHelpers를 통해서 가져올 수 있음.
	/*static ConstructorHelpers::FClassFinder<APawn> ThirdPersonClassRef(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter_C"));

	if (ThirdPersonClassRef.Class)
	{
		DefaultPawnClass = ThirdPersonClassRef.Class;
	}*/


	// C++ 생성한 Class로 변경
	static ConstructorHelpers::FClassFinder<APawn> DefaultPawnClassRef(TEXT("/Script/ArenaBattle.ABCharacterPlayer"));
	if (DefaultPawnClassRef.Class)
	{
		DefaultPawnClass = DefaultPawnClassRef.Class;
	}

	// PlayerController
	//
	// C++ Class이므로 바로 변경 가능 (헤더를 인클루드 해야함)
	//PlayerControllerClass = AABPlayerController::StaticClass();

	// 헤더를 인클루드 하지 않는 방법(의존성 낮추기)
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerClassRef(TEXT("/Script/ArenaBattle.ABPlayerController"));
	PlayerControllerClass = PlayerControllerClassRef.Class;
}
