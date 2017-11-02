//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "EnemySearchState.h"

#include "EnemyBattleState.h"
#include "EnemySleepState.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//----------------------------------------------------------------------
// Static Private Variables
//----------------------------------------------------------------------
const int EnemySearchState::m_SearchTimeMax = 3;


//----------------------------------------------------------------------
// Constructor	Destructor
//----------------------------------------------------------------------
EnemySearchState::EnemySearchState() : 
	m_SearchTime(0)
{
}

EnemySearchState::~EnemySearchState()
{
}


//----------------------------------------------------------------------
// Public Functions
//----------------------------------------------------------------------
EnemyStateBase* EnemySearchState::Run()
{
	printf("--捜索状態--\n");

	// 戦闘対象を発見したら戦闘状態に遷移.
	srand((unsigned int)time(nullptr));
	if (rand() % 100 < 50)
	{
		printf("\n--------戦闘状態に遷移--------\n");
		return new EnemyBattleState();	// C++でreturn newは好ましくないのであくまで一例.
	}

	// 戦闘対象を発見できなかったら睡眠状態に遷移.
	m_SearchTime++;
	if (m_SearchTime == m_SearchTimeMax)
	{
		printf("\n--------睡眠状態に遷移--------\n");
		return new EnemySleepState();	// C++でreturn newは好ましくないのであくまで一例.
	}

	return nullptr;
}
