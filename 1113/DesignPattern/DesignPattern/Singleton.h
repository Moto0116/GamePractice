#ifndef SINGLETON_H
#define SINGLETON_H

struct NEW_CREATE;		   
struct LOCAL_STATIC_VALUE; // ローカル静的オブジェクトによる実装

//-----------------------------------------------------------

// 動的割り当てによる実装
class Singleton1
{
public:
	Singleton1(const Singleton1&) = delete;
	Singleton1& operator=(const Singleton1&) = delete;

	static Singleton1* Instance() {
		return m_Instance;
	}

	static void Create() {
		if (!m_Instance) {
			m_Instance = new Singleton1;
		}
	}

	static void Delete() {
		if (m_Instance) {
			delete m_Instance;
			m_Instance = nullptr;
		}
	}
private:
	Singleton1() {}
	~Singleton1() = default;

	static Singleton1* m_Instance;
};

Singleton1* Singleton1::m_Instance = nullptr;

//-----------------------------------------------------------

// ローカル静的オブジェクトによる実装
class Singleton2
{
public:
	Singleton2(const Singleton2&) = delete;
	Singleton2& operator=(const Singleton2&) = delete;

	static Singleton2* Instance()
	{
		static Singleton2 Instance;
		return &Instance;
	}

private:
	Singleton2() = default;
	~Singleton2() = default;

};

#endif
