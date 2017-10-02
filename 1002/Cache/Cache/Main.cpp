// �X�^�b�N�T�C�Y�ɂ���.
// �L���b�V���ɂ���.
// �z��̃������z�u�ɂ���.


#include <Windows.h>
#include <chrono>

/**
* �f�o�b�O�p�^�C�}�[�N���X
*/
class DebugTimer
{
public:
	/**
	* �R���X�g���N�^
	*/
	DebugTimer() : m_DiffTime(0){}

	/**
	* �f�X�g���N�^
	*/
	~DebugTimer(){}

	/**
	* �v���J�n
	*/
	void StartTimer()
	{
#ifdef _DEBUG
		m_StartTime = std::chrono::system_clock::now();
#endif // _DEBUG
	}

	/**
	* �v���I��
	*/
	void EndTimer()
	{
#ifdef _DEBUG
		m_DiffTime = std::chrono::system_clock::now() - m_StartTime;
#endif // _DEBUG
	}

	/**
	* �v�����Ԏ擾
	* @return �v������(Seconds)
	*/
	LONGLONG GetSecond()
	{
		return std::chrono::duration_cast<std::chrono::seconds>(m_DiffTime).count();
	}

	/**
	* �v�����Ԏ擾
	* @return �v������(MilliSeconds)
	*/
	LONGLONG GetMilliSecond()
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(m_DiffTime).count();
	}

	/**
	* �v�����Ԏ擾
	* @return �v������(MicroSeconds)
	*/
	LONGLONG GetMicroSecond()
	{
		return std::chrono::duration_cast<std::chrono::microseconds>(m_DiffTime).count();
	}

private:
	typedef std::chrono::duration<
		std::chrono::system_clock::rep,
		std::chrono::system_clock::period> DebugDiffTime;

	std::chrono::system_clock::time_point	m_StartTime;	//!< �v���J�n����.
	DebugDiffTime m_DiffTime;								//!< �v������.

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
		Debugger.StartTimer();	// ���Ԍv���J�n.

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

		Debugger.EndTimer();				// �v���I��.
		Time = Debugger.GetMilliSecond();	// �v�����ʎ擾.


		Debugger.StartTimer();	// ���Ԍv���J�n.

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

		Debugger.EndTimer();				// �v���I��.
		Time2 = Debugger.GetMilliSecond();	// �v�����ʎ擾.


		printf("\nTime = %lldms\nTime2 = %lldms\n", Time, Time2);	// �v�����ʏo��.
	}

	while (1);
}

