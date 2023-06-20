// Fill out your copyright notice in the Description page of Project Settings.


#include "Coew/AI/AI_Controller_Boss.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

AAI_Controller_Boss::AAI_Controller_Boss() {

	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behavior Tree Component"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard Component"));
}

void AAI_Controller_Boss::BeginPlay() {
	Super::BeginPlay();

	if (IsValid(BehaviorTree.Get()))
	{
		RunBehaviorTree(BehaviorTree.Get());
		BehaviorTreeComponent->StartTree( *BehaviorTree.Get());
	}
}

void AAI_Controller_Boss::OnPossess(APawn* InPawn) {
	Super::OnPossess(InPawn);

	if (IsValid(Blackboard.Get()) && IsValid(BehaviorTree.Get()))
	{
		Blackboard->InitializeBlackboard(* BehaviorTree.Get()->BlackboardAsset.Get());
	}
}