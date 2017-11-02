#ifndef ENEMYSTATEBASE_H
#define ENEMYSTATEBASE_H


/*** エネミーの状態を表す基底クラス */
class EnemyStateBase
{
public:
	/*** コンストラクタ */
	EnemyStateBase();

	/*** デストラクタ */
	virtual ~EnemyStateBase();

	/*** 実行関数 */
	virtual EnemyStateBase* Run();

};


#endif // !ENEMYSTATEBASE_H
