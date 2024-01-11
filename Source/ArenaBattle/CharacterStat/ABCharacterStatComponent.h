// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameData/ABCharacterStat.h"
#include "ABCharacterStatComponent.generated.h"


DECLARE_MULTICAST_DELEGATE(FOnHpZeroDelegate)
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHpChangedDelegate, float /*CurrentHp*/);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnStatChangedDelegate, const FABCharacterStat& /*BaseStat*/, const FABCharacterStat& /*ModifierStat*/);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARENABATTLE_API UABCharacterStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UABCharacterStatComponent();

protected:
	// Called when the game starts
	virtual void InitializeComponent() override;


public:

	FOnHpZeroDelegate OnHpZero;
	FOnHpChangedDelegate OnHpChanged;
	FOnStatChangedDelegate OnStatChanged;

	void SetLevelStat(int32 InNewLevel);
	FORCEINLINE float GetCurrentLevel() const { return CurrentLevel; }

	FORCEINLINE void SetBaseStat(const FABCharacterStat& InBaseStat) { BaseStat = InBaseStat; OnStatChanged.Broadcast(BaseStat, ModifierStat); }
	FORCEINLINE void SetModifierStat(const FABCharacterStat& InModifierStat) { ModifierStat = InModifierStat; OnStatChanged.Broadcast(BaseStat, ModifierStat); }


	FORCEINLINE const FABCharacterStat& GetBaseStat() const { return BaseStat; }
	FORCEINLINE const FABCharacterStat& GetModiferStat() const { return ModifierStat; }
	FORCEINLINE FABCharacterStat GetTotalStat() const { return BaseStat + ModifierStat; }
	FORCEINLINE float GetCurrentHp() { return CurrentHp; }
	FORCEINLINE float GetAttackRadius() { return AttackRadius; }

	float ApplyDamage(float InDamage);

protected:

	void SetHp(float NewHp);


	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat)
	float CurrentHp;

	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat)
	float CurrentLevel;

	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat)
	float AttackRadius;

	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = "true"))
	FABCharacterStat BaseStat;

	UPROPERTY(Transient, VisibleInstanceOnly, Category = Stat, Meta = (AllowPrivateAccess = "true"))
	FABCharacterStat ModifierStat;

};

