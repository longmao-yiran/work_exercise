#include "offer_1.h"


// ��Ӹ�ֵ�����
class CMyString
{
public:
	CMyString(char* pData=nullptr);
	CMyString(const CMyString& str);
	~CMyString();
	CMyString& operator=(const CMyString&  str);
	void Print();
private:
	char* m_pData;
};



CMyString::CMyString(char* pData)
{
	if (pData != nullptr) {								// ȱ��Ĭ�Ϲ��캯����pData��Ϊnullptr ���޷�����strlen
		m_pData = new char[strlen(pData) + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString& str)
{
	m_pData = new char[strlen(str.m_pData) + 1];		// �����ڴ�
	strcpy(m_pData, str.m_pData);						// �����ַ�������
}

CMyString::~CMyString()
{
	delete[] m_pData;
}

CMyString& CMyString::operator=(const CMyString&  str)   // Ҫ�󷵻�Ϊ�����͵����ã����Խ���������ֵ�� �������Ϊ�������ã����Ч�ʷ�ֹ�޸�
{
	if (this != &str) {						// �ж��Ƿ����Լ� ���ٿ���
		CMyString str_tmp(str);				// �����ɸ��м��������ֹ���ٲ�������ԭ��ʵ���ı䣬�쳣��ȫ
		char* p_char = str_tmp.m_pData;		
		str_tmp.m_pData = m_pData;			// ����str_tmp��ʱ������if��ȥ���뿪�����򣬻���������������Ӷ��ͷ�ԭ�е�m_pData�ռ䣬��ֹ�ڴ�й©
		m_pData = p_char;					// ��str�е�m_pData ��ֵ��ʵ��
	}
	return *this;							// ������������ã�*this�� ���Խ���������ֵ
}

// ====================���Դ���====================
void CMyString::Print()
{
	printf("%s", m_pData);
}

void Test_1_1()
{
	printf("Test_1_1 begins:\n");

	char* text = "Hello world";

	CMyString str1(text);
	CMyString str2;
	str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.Print();
	printf(".\n");
}

// ��ֵ���Լ�
void Test_1_2()
{
	printf("Test_1_2 begins:\n");

	char* text = "Hello world";

	CMyString str1(text);
	str1 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str1.Print();
	printf(".\n");
}

// ������ֵ
void Test_1_3()
{
	printf("Test_1_3 begins:\n");

	char* text = "Hello world";

	CMyString str1(text);
	CMyString str2, str3;
	str3 = str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.Print();
	printf(".\n");

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str3.Print();
	printf(".\n");
}

void offer_1_test()
{
	Test_1_1();
	Test_1_2();
	Test_1_3();
	cout << "offer_1 success" << endl;
}
