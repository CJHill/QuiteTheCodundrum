// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AI_Controller_Boss.generated.h"

class UBehaviorTreeComponent;
/**
 * 
 */
UCLASS()
class QUITETHECODUNDRUM_API AAI_Controller_Boss : public AAIController
{
	GENERATED_BODY()
	
public:
	AAI_Controller_Boss();

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = true))
		TObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI", meta = (AllowPrivateAccess = true))
		TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = true))
		TObjectPtr<UBlackboardComponent> BlackboardComponent;

};
