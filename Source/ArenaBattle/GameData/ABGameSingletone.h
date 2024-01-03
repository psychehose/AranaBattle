// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ABCharacterStat.h"
#include "ABGameSingletone.generated.h"


DECLARE_LOG_CATEGORY_EXTERN(LogABGameSingletone, Error, All);

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABGameSingletone : public UObject
{
	GENERATED_BODY()
public:
	UABGameSingletone();
	static UABGameSingletone& Get();


	// Getter Setter
public:
	FORCEINLINE FABCharacterStat GetCharacterStat(int32 InLevel) const { return CharacterStatTable.IsValidIndex(InLevel - 1) ? CharacterStatTable[InLevel - 1] : FABCharacterStat(); }

	UPROPERTY()
	int32 CharacterMaxLevel;
private:
	TArray<FABCharacterStat> CharacterStatTable;
	
};
