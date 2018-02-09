#include "offer_1.h"


// ��Ӹ�ֵ�����
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

void offer_1_test()
{
	CMyString str("ser");
	CMyString str1, str2;
	str1 = str2 = str;
	str1 = str1;
	cout << "offer_1 success" << endl;
}
