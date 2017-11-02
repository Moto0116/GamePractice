//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "EnemySleepState.h"

#include "EnemySearchState.h"

#include <stdio.h>


//----------------------------------------------------------------------
// Static Private Variables
//----------------------------------------------------------------------
const int EnemySleepState::m_SleepTimeMax = 5;


//----------------------------------------------------------------------
// Constructor	Destructor
//----------------------------------------------------------------------
EnemySleepState::EnemySleepState() : 
	m_SleepTime(0)
{
}

EnemySleepState::~EnemySleepState()
{
}


//----------------------------------------------------------------------
// Public Functions
//----------------------------------------------------------------------
EnemyStateBase* EnemySleepState::Run()
{
	printf("--睡眠状態--\n");

	m_SleepTime++;
	if (m_SleepTime == m_SleepTimeMax)
	{
		// 睡眠を終えたら起床して捜索状態に遷移.
		printf("\n--------捜索状態に遷移--------\n");
		return new EnemySearchState();	// C++でreturn newは好ましくないのであくまで一例.
	}

	return nullptr;
}
