//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "EnemyBattleState.h"

#include "EnemySearchState.h"

#include <stdio.h>


//----------------------------------------------------------------------
// Static Private Variables
//----------------------------------------------------------------------
const int EnemyBattleState::m_BattleTimeMax = 5;


//----------------------------------------------------------------------
// Constructor	Destructor
//----------------------------------------------------------------------
EnemyBattleState::EnemyBattleState() : 
	m_BattleTime(0)
{
}

EnemyBattleState::~EnemyBattleState()
{
}


//----------------------------------------------------------------------
// Public Functions
//----------------------------------------------------------------------
EnemyStateBase* EnemyBattleState::Run()
{
	printf("--戦闘状態--\n");

	m_BattleTime++;
	if (m_BattleTime == m_BattleTimeMax)
	{
		// 戦闘が終了したら新しい敵を探すために捜索状態に遷移.
		printf("\n--------捜索状態に遷移--------\n");
		return new EnemySearchState();	// C++でreturn newは好ましくないのであくまで一例.
	}

	return nullptr;
}
