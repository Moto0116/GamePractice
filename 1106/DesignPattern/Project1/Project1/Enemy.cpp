//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "Enemy.h"

#include "EnemyBattleState.h"
#include "EnemySearchState.h"
#include "EnemySleepState.h"


//----------------------------------------------------------------------
// Constructor	Destructor
//----------------------------------------------------------------------
Enemy::Enemy()
{
	m_pState = new EnemySearchState();
}

Enemy::~Enemy()
{
	delete m_pState;
}


//----------------------------------------------------------------------
// Public Functions
//----------------------------------------------------------------------
void Enemy::Update()
{
	EnemyStateBase* pState = m_pState->Run();
	if (pState != nullptr)
	{
		// 状態の変更があれば現在の状態を削除して新しい状態を受け取る.
		delete m_pState;	// C++でdeleteとnewを分離するのはよくないが一例として.
		m_pState = pState;
	}
}
