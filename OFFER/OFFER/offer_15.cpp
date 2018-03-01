#include "offer_15.h"

/*
	二进制中1的个数
	输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
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

// ====================测试代码====================
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

// 输入0，期待的输出是0
void Test_15_1()
{
	Test_15(0, 0);
}

// 输入1，期待的输出是1
void Test_15_2()
{
	Test_15(1, 1);
}
// 输入10，期待的输出是2
void Test_15_3()
{
	Test_15(10, 2);
}

// 输入0x7FFFFFFF，期待的输出是31
void Test_15_4()
{
	Test_15(0x7FFFFFFF, 31);
}

// 输入0xFFFFFFFF（负数），期待的输出是32
void Test_15_5()
{
	Test_15(0xFFFFFFFF, 32);
}

// 输入0x80000000（负数），期待的输出是1
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

// 牛客网 ac
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