#ifndef ENEMYBATTLESTATE_H
#define ENEMYBATTLESTATE_H

//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "EnemyStateBase.h"


/*** エネミーの戦闘状態クラス */
class EnemyBattleState : public EnemyStateBase
{
public:
	/*** コンストラクタ */
	EnemyBattleState();

	/*** デストラクタ */
	virtual ~EnemyBattleState();

	/*** 実行関数 */
	virtual EnemyStateBase* Run();

private:
	static const int m_BattleTimeMax;	//!< 戦闘時間.

	int m_BattleTime;	//!< 戦闘時間.

};


#endif // !ENEMYBATTLESTATE_H
