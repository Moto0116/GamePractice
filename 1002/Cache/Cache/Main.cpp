// スタックサイズについて.
// キャッシュについて.
// 配列のメモリ配置について.


#include <Windows.h>
#include <chrono>

/**
* デバッグ用タイマークラス
*/
class DebugTimer
{
public:
	/**
	* コンストラクタ
	*/
	DebugTimer() : m_DiffTime(0){}

	/**
	* デストラクタ
	*/
	~DebugTimer(){}

	/**
	* 計測開始
	*/
	void StartTimer()
	{
#ifdef _DEBUG
		m_StartTime = std::chrono::system_clock::now();
#endif // _DEBUG
	}

	/**
	* 計測終了
	*/
	void EndTimer()
	{
#ifdef _DEBUG
		m_DiffTime = std::chrono::system_clock::now() - m_StartTime;
#endif // _DEBUG
	}

	/**
	* 計測時間取得
	* @return 計測時間(Seconds)
	*/
	LONGLONG GetSecond()
	{
		return std::chrono::duration_cast<std::chrono::seconds>(m_DiffTime).count();
	}

	/**
	* 計測時間取得
	* @return 計測時間(MilliSeconds)
	*/
	LONGLONG GetMilliSecond()
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(m_DiffTime).count();
	}

	/**
	* 計測時間取得
	* @return 計測時間(MicroSeconds)
	*/
	LONGLONG GetMicroSecond()
	{
		return std::chrono::duration_cast<std::chrono::microseconds>(m_DiffTime).count();
	}

private:
	typedef std::chrono::duration<
		std::chrono::system_clock::rep,
		std::chrono::system_clock::period> DebugDiffTime;

	std::chrono::system_clock::time_point	m_StartTime;	//!< 計測開始時間.
	DebugDiffTime m_DiffTime;								//!< 計測時間.

};

#define ARRAY_SIZE 500


void main()
{
	DebugTimer Debugger;
	long long Time, Time2;

	int A[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE];
	int B[ARRAY_SIZE][ARRAY_SIZE][ARRAY_SIZE];


	while (1)
	{
		Debugger.StartTimer();	// 時間計測開始.

		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			for (int j = 0; j < ARRAY_SIZE; j++)
			{
				for (int k = 0; k < ARRAY_SIZE; k++)
				{
					A[i][j][k] = 0;
				}
			}
		}

		Debugger.EndTimer();				// 計測終了.
		Time = Debugger.GetMilliSecond();	// 計測結果取得.


		Debugger.StartTimer();	// 時間計測開始.

		for (int i = 0; i < ARRAY_SIZE; i++)
		{
			for (int j = 0; j < ARRAY_SIZE; j++)
			{
				for (int k = 0; k < ARRAY_SIZE; k++)
				{
					B[k][j][i] = 0;
				}
			}
		}

		Debugger.EndTimer();				// 計測終了.
		Time2 = Debugger.GetMilliSecond();	// 計測結果取得.


		printf("\nTime = %lldms\nTime2 = %lldms\n", Time, Time2);	// 計測結果出力.
	}

	while (1);
}

