#include "offer_15.h"

/*
	��������1�ĸ���
	����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
*/

int NumberOf1_Solution1(int n)
{
	int count = 0;
	int flag = 1;
	bool xx = -1;
	while (flag)
	{
		if (n&flag)
			++count;
		flag = flag << 1;
	}
	return count;
}

int NumberOf1_Solution2(int n)
{
	int count = 0;
	int number = n;
	while (number)
	{
		++count;
		number = (number - 1)&number;
	}
	return count;
}

// ====================���Դ���====================
void Test_15(int number, unsigned int expected)
{
	int actual = NumberOf1_Solution1(number);
	if (actual == expected)
		printf("Solution1: Test for %p passed.\n", number);
	else
		printf("Solution1: Test for %p failed.\n", number);

	actual = NumberOf1_Solution2(number);
	if (actual == expected)
		printf("Solution2: Test for %p passed.\n", number);
	else
		printf("Solution2: Test for %p failed.\n", number);

	printf("\n");
}

// ����0���ڴ��������0
void Test_15_1()
{
	Test_15(0, 0);
}

// ����1���ڴ��������1
void Test_15_2()
{
	Test_15(1, 1);
}
// ����10���ڴ��������2
void Test_15_3()
{
	Test_15(10, 2);
}

// ����0x7FFFFFFF���ڴ��������31
void Test_15_4()
{
	Test_15(0x7FFFFFFF, 31);
}

// ����0xFFFFFFFF�����������ڴ��������32
void Test_15_5()
{
	Test_15(0xFFFFFFFF, 32);
}

// ����0x80000000�����������ڴ��������1
void Test_15_6()
{
	Test_15(0x80000000, 1);
}

void offer_15_test()
{
	Test_15_1();
	Test_15_2();
	Test_15_3();
	Test_15_4();
	Test_15_5();
	Test_15_6();

	cout << "offer_15 success" << endl;
}

// ţ���� ac
/*
class Solution {
public:
     int  NumberOf1(int n) {
        int count = 0;
        int number = n;
        while (number)
        {
            ++count;
            number = (number - 1)&number;
        }
        return count;
     }
};
*/