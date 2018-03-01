#include "offer_2.h"

std::mutex mtx;

/*
	ʵ��һ������ģʽ   
*/
 
// ����ģʽ
class Singleton1 final
{
public:
	~Singleton1();
	static Singleton1* getInstance();
private:
	Singleton1();							// ���캯�������ƹ��캯����Ϊ˽�� ���ⲿ����ͨ�����캯������ʵ��
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
	if (instance == NULL)					// ���ж��Ƿ�Ϊ�գ����ٶ���жϵ�ʱ���ʱ�����   ע�⣺�˴��������ж� 
	{
		mtx.lock();							// ���� ��ֹ���̳߳�ͻ
		if (instance == NULL)				// �������жϸ����Ƿ����ʵ�� ��ֹ�ڼ���ǰ if�����߳�����ʵ��
			instance = new Singleton1();	// ����ʵ��
		mtx.unlock();						// ����
	}
	return instance;
}


// ����ģʽ
class Singleton2 final
{
public:
	~Singleton2();
	static Singleton2* getInstance();		// ��̬��Ա����
private:
	Singleton2();
	Singleton2(Singleton2&);
	Singleton2& operator=(Singleton2&);
	static Singleton2 *instance;			// ��̬��Ա
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
Singleton2* Singleton2::instance = new Singleton2();	// ����ʼʱ�ʹ��쾲̬��Ա
	
Singleton2* Singleton2::getInstance()					// ���ڿ϶��Ѿ������� ���ֱ�ӷ��ؼ���
{
	return instance;
}

// ��̬�ڲ���
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