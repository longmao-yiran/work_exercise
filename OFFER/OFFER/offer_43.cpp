#include "offer_43.h"

/*
	������1���ֵĴ�������1��n������1���ֵĴ�����
	���1~13��������1���ֵĴ���,�����100~1300��������1���ֵĴ�����
	Ϊ�����ر�����һ��1~13�а���1��������1��10��11��12��13��˹�����6��,
	���Ƕ��ں�����������û���ˡ�ACMerϣ�����ǰ����,������������ձ黯,
	���Ժܿ���������Ǹ�����������1���ֵĴ�����
*/

int NumberOf1(unsigned int n)
{
	if (n <= 0)
		return 0;
	int number = 0;

	while (n >0 )
	{
		if ((n % 10) == 1)
			++number;
		n = n / 10;
	}
	return number;
}

int NumberOf1Between1AndN_Solution1(unsigned int n)
{
	int result = 0;
	for (int i = 0;i <= n;++i) {
		int number = NumberOf1(i);
		result += number;
	}
	return result;
}

int PowerBase10(unsigned int n)
{
	int result = 1;
	for (int i = 0;i < n;++i)
		result *= 10;
	return result;
}

// ͳ�����λ���ֵĴ���+��ȥ���λ����λ���ֵĴ��� ͳ��10^n ÿ���г��ֵĴ���
int NumberOf2(const char* strN)
{
	if (*strN <'0' || *strN > '9' || *strN == '\0')
		return 0;

	int first = *strN - '0';

	const int length = strlen(strN);

	if (length == 1 && first == 0)
		return 0;
	if (length == 1 && first >= 1)
		return 1;

	int numberFirstDigit = 0;

	// ���λ ������λΪ1 ���λ���ִ���Ϊ ���λ���������+1 ���������Ϊ10^�����λ��λ��-1��
	if (first == 1)
		numberFirstDigit = atoi(strN + 1) + 1;
	else if (first != 0)								// ע��˴����λΪ0 �����λ���ִ���Ϊ0
		numberFirstDigit = PowerBase10(length - 1);

	// ������� C(1,length-1)*10^(length - 2) �������λ����λ���ִ���
	int numberOtherDigit = 0;
	numberOtherDigit = first * (length - 1)*PowerBase10(length - 2);

	// �ݹ���һλ
	int numberRecurisive = 0;
	numberRecurisive = NumberOf2(strN + 1);
	
	return numberFirstDigit + numberOtherDigit + numberRecurisive;
}

int NumberOf1Between1AndN_Solution2(int n)
{
	if (n <= 0)
		return 0;

	char strN[50];
	sprintf(strN, "%d", n);		// int תchar

	return NumberOf2(strN);
}

// ====================���Դ���====================
void Test_43(const char* testName, int n, int expected)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	if (NumberOf1Between1AndN_Solution1(n) == expected)
		printf("Solution1 passed.\n");
	else
		printf("Solution1 failed.  answer: %d    result: %d\n", NumberOf1Between1AndN_Solution1(n), expected);

	if (NumberOf1Between1AndN_Solution2(n) == expected)
		printf("Solution2 passed.\n");
	else
		printf("Solution2 failed.  answer: %d    result: %d\n", NumberOf1Between1AndN_Solution2(n), expected);

	printf("\n");
}

void Test_43_1()
{
	Test_43("Test_43_1", 1, 1);
}

void Test_43_2()
{
	Test_43("Test_43_2", 5, 1);
}

void Test_43_3()
{
	Test_43("Test_43_3", 10, 2);
}

void Test_43_4()
{
	Test_43("Test_43_4", 55, 16);
}

void Test_43_5()
{
	Test_43("Test_43_5", 99, 20);
}

void Test_43_6()
{
	Test_43("Test_43_6", 10000, 4001);
}

void Test_43_7()
{
	Test_43("Test_43_7", 21345, 18821);
}

void Test_43_8()
{
	Test_43("Test_43_8", 0, 0);
}

void offer_43_test()
{
	Test_43_1();
	Test_43_2();
	Test_43_3();
	Test_43_4();
	Test_43_5();
	Test_43_6();
	Test_43_7();
	Test_43_8();

	cout << "offer_43 success" << endl;
}

// ţ����ac ʱ�䳤
/*
class Solution {
public:
    
    int NumberOf1(unsigned int n)
    {
        if (n <= 0)
            return 0;
        int number = 0;

        while (n >0 )
        {
            if ((n % 10) == 1)
                ++number;
            n = n / 10;
        }
        return number;
    }
    
    int NumberOf1Between1AndN_Solution(int n)
    {
        int result = 0;
        for (int i = 0;i <= n;++i) {
            int number = NumberOf1(i);
            result += number;
        }
        return result;
    }
};
*/