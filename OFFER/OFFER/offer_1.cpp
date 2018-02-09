#include "offer_1.h"


// 添加赋值运算符
class CMyString
{
public:
	CMyString(char* pData=nullptr);
	CMyString(const CMyString& str);
	~CMyString();
	CMyString& operator=(const CMyString&  str);
private:
	char* m_pData;
};



CMyString::CMyString(char* pData)
{
	if (pData != nullptr) {								// 缺少默认构造函数，pData若为nullptr 则无法进行strlen
		m_pData = new char[strlen(pData) + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString& str)
{
	m_pData = new char[strlen(str.m_pData) + 1];		// 开辟内存
	strcpy(m_pData, str.m_pData);						// 进行字符串拷贝
}

CMyString::~CMyString()
{
	delete[] m_pData;
}

CMyString& CMyString::operator=(const CMyString&  str)   // 要求返回为该类型的引用，可以进行连续赋值， 传入参数为常亮引用，提高效率防止修改
{
	if (this != &str) {						// 判断是否是自己 减少开销
		CMyString str_tmp(str);				// 先生成个中间变量，防止开辟不出导致原有实例改变，异常安全
		char* p_char = str_tmp.m_pData;		
		str_tmp.m_pData = m_pData;			// 由于str_tmp临时变量在if出去后离开作用域，会调用析构函数，从而释放原有的m_pData空间，防止内存泄漏
		m_pData = p_char;					// 将str中的m_pData 赋值给实例
	}
	return *this;							// 返回自身的引用（*this） 可以进行连续赋值
}

void offer_1_test()
{
	CMyString str("ser");
	CMyString str1, str2;
	str1 = str2 = str;
	str1 = str1;
	cout << "offer_1 success" << endl;
}
