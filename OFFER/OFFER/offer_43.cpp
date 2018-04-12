#include "offer_43.h"

/*
	整数中1出现的次数（从1到n整数中1出现的次数）
	求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
	为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
	但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,
	可以很快的求出任意非负整数区间中1出现的次数。
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

// 统计最高位出现的次数+出去最高位其他位出现的次数 统计10^n 每段中出现的次数
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

	// 最高位 如果最高位为1 最高位出现次数为 最高位后面的数字+1 如果不是则为10^（最高位的位数-1）
	if (first == 1)
		numberFirstDigit = atoi(strN + 1) + 1;
	else if (first != 0)								// 注意此处最高位为0 则最高位出现次数为0
		numberFirstDigit = PowerBase10(length - 1);

	// 组合问题 C(1,length-1)*10^(length - 2) 除了最高位其他位出现次数
	int numberOtherDigit = 0;
	numberOtherDigit = first * (length - 1)*PowerBase10(length - 2);

	// 递归下一位
	int numberRecurisive = 0;
	numberRecurisive = NumberOf2(strN + 1);
	
	return numberFirstDigit + numberOtherDigit + numberRecurisive;
}

int NumberOf1Between1AndN_Solution2(int n)
{
	if (n <= 0)
		return 0;

	char strN[50];
	sprintf(strN, "%d", n);		// int 转char

	return NumberOf2(strN);
}

// ====================测试代码====================
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

// 牛客网ac 时间长
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