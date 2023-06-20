// Fill out your copyright notice in the Description page of Project Settings.


#include "Coew/AI/AI_Controller_Boss.h"

AAI_Controller_Boss::AAI_Controller_Boss() {

	BehaviorTreeComponent = CreateDefaultSubObject<UBehaviorTreeComponent>(TEXT("Behavior Tree Component"));
	BlackboardComponent = CreateDefaultSubObject<UBlackboardComponent>(TEXY("Blackboard Component"));
}

void AAI_Controller_Boss::BeginPlay() {
	Super::BeginPlay();

	if (IsValid(Test:BehaviorTree.Get()))
	{
		RunBehaviorTree(BTAsset:BehaviorTree.Get());
		BehaviorTreeComponent->StartTree([&] * BehaviorTree.Get());
	}
}

void AAI_Controller_Boss::OnPossess(APawn* InPawn) {
	Super::OnPossess(InPawn);

	if (IsValid(Test:Blackboard.Get()) && IsValid(Test:BehaviorTree.Get()))
	{
		Blackboard->InitializeBlackboard([&] * BehaviorTree.Get()->BlackboardAsset.Get());
	}
}