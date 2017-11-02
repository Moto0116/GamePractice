#ifndef ENEMYSLEEPSTATE_H
#define ENEMYSLEEPSTATE_H

//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "EnemyStateBase.h"


/*** エネミーの睡眠状態クラス */
class EnemySleepState : public EnemyStateBase
{
public:
	/*** コンストラクタ */
	EnemySleepState();

	/*** デストラクタ */
	virtual ~EnemySleepState();

	/*** 実行関数 */
	virtual EnemyStateBase* Run();

private:
	static const int m_SleepTimeMax;	//!< 睡眠時間.

	int m_SleepTime;	//!< 睡眠してからの時間.

};


#endif // !ENEMYSLEEPSTATE_H
