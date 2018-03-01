#include "offer_2.h"

std::mutex mtx;

/*
	实现一个单例模式   
*/
 
// 懒汉模式
class Singleton1 final
{
public:
	~Singleton1();
	static Singleton1* getInstance();
private:
	Singleton1();							// 构造函数、复制构造函数设为私有 则外部不能通过构造函数创建实例
	Singleton1(const Singleton1&);
	Singleton1& operator=(const Singleton1&);
	static Singleton1* instance;
	string longmao;


};
Singleton1* Singleton1::instance = NULL;
Singleton1::Singleton1()
{
	longmao = "longmao";
}
Singleton1::Singleton1(const Singleton1&) 
{
}

Singleton1& Singleton1::operator=(const Singleton1&)
{
	return *this;
}

Singleton1::~Singleton1()
{
}

Singleton1* Singleton1::getInstance()
{
	if (instance == NULL)					// 先判断是否为空，减少多次判断的时候的时间访问   注意：此处有两个判断 
	{
		mtx.lock();							// 枷锁 防止多线程冲突
		if (instance == NULL)				// 加锁后判断该类是否存在实例 防止在加锁前 if后有线程生成实例
			instance = new Singleton1();	// 生成实例
		mtx.unlock();						// 解锁
	}
	return instance;
}


// 饿汉模式
class Singleton2 final
{
public:
	~Singleton2();
	static Singleton2* getInstance();		// 静态成员函数
private:
	Singleton2();
	Singleton2(Singleton2&);
	Singleton2& operator=(Singleton2&);
	static Singleton2 *instance;			// 静态成员
	string longmao;
};

Singleton2::Singleton2()
{
	longmao = "longmao";
}

Singleton2::Singleton2(Singleton2&)
{
}

Singleton2& Singleton2::operator=(Singleton2&)
{
	return *this;
}

Singleton2::~Singleton2()
{
}
Singleton2* Singleton2::instance = new Singleton2();	// 程序开始时就创造静态成员
	
Singleton2* Singleton2::getInstance()					// 由于肯定已经创建了 因此直接返回即可
{
	return instance;
}

// 静态内部类
//class Singleton3 final
//{
//public:
//	~Singleton3();
//	class Nested
//	{
//	public:
//		~Nested();
//
//	private:
//		Nested();
//		static Singleton3 instance = new Singleton3();
//	};
//
//	Nested::Nested()
//	{
//	}
//
//	Nested::~Nested()
//	{
//	}
//
//private:
//	Singleton3();
//};
//
//Singleton3::Singleton3()
//{
//}
//
//Singleton3::~Singleton3()
//{
//}

void offer_2_test()
{
 	Singleton1* singleton1 = Singleton1::getInstance();
	Singleton1* singleton2 = Singleton1::getInstance();

	if (singleton1 == singleton2)
		cout << "Singleton1 success" << endl;

	Singleton2* singleton3 = Singleton2::getInstance();
	Singleton2* singleton4 = Singleton2::getInstance();

	if (singleton3 == singleton4)
		cout << "Singleton2 success" << endl;
}