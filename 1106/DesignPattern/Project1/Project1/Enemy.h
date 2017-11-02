#ifndef ENEMY_H
#define ENEMY_H

class EnemyStateBase;


/*** エネミークラス */
class Enemy
{
public:
	/*** コンストラクタ */
	Enemy();

	/*** デストラクタ */
	~Enemy();

	/*** 更新処理 */
	void Update();

private:
	EnemyStateBase* m_pState;	//!< エネミーの状態クラス.

};


#endif // !ENEMY_H
