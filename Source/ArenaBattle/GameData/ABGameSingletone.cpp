// Fill out your copyright notice in the Description page of Project Settings.


#include "GameData/ABGameSingletone.h"


DEFINE_LOG_CATEGORY(LogABGameSingletone);

UABGameSingletone::UABGameSingletone()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> DataTableRef(TEXT("/Script/Engine.DataTable'/Game/ArenaBattle/GameData/ABCharacterStatTable.ABCharacterStatTable'"));

	if (nullptr != DataTableRef.Object)
	{
		const UDataTable* DataTable = DataTableRef.Object;
		check(DataTable->GetRowMap().Num() > 0);

		TArray<uint8*> ValueArray;
		DataTable->GetRowMap().GenerateValueArray(ValueArray);
		Algo::Transform(ValueArray, CharacterStatTable, 
			[](uint8* Value)
			{
				return *reinterpret_cast<FABCharacterStat*>(Value);
			}
			
		);
	}

	CharacterMaxLevel = CharacterStatTable.Num();
	ensure(CharacterMaxLevel > 0);

}

UABGameSingletone& UABGameSingletone::Get()
{
	// TODO: insert return statement here

	UABGameSingletone*  Singleton = CastChecked<UABGameSingletone>(GEngine->GameSingleton);

	if (Singleton)
	{
		return *Singleton;
	}

	UE_LOG(LogABGameSingletone, Error, TEXT("Invalid Game Singletone"));

	// 이 부분은 코드 완성을 위한 코드일 뿐, 이 코드가 실행되면 에러임.
	return *NewObject<UABGameSingletone>();
}
