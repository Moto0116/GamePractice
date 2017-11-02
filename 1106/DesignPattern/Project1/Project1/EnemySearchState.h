#ifndef ENEMYSEARCHSTATE_H
#define ENEMYSEARCHSTATE_H

//----------------------------------------------------------------------
// Include
//----------------------------------------------------------------------
#include "EnemyStateBase.h"


/*** エネミーの捜索状態クラス */
class EnemySearchState : public EnemyStateBase
{
public:
	/*** コンストラクタ */
	EnemySearchState();

	/*** デストラクタ */
	virtual ~EnemySearchState();

	/*** 実行関数 */
	virtual EnemyStateBase* Run();

private:
	static const int m_SearchTimeMax;	//!< 捜索時間.

	int m_SearchTime;	//!< 捜索してからの時間.

};


#endif // !ENEMYSEARCHSTATE_H
