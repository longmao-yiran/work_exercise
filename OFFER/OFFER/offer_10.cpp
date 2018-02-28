#include "offer_10.h"

/*
	f(0) = 0
	f(1) = 1
	f(n) = f(n-1) + f(n-2)
	大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。n<=39
*/

// 递归
long long Fibonacci_Solution1(unsigned int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	if (n > 1)
		return Fibonacci_Solution1(n - 1) + Fibonacci_Solution1(n - 2);
}

// 循环
long long Fibonacci_Solution2(unsigned int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	long long result1 = 0;
	long long result2 = 1;
	for (int i = 2; i <= n; i++) {
		int tempInt = result2;
		result2 = result1 + result2;
		result1 = tempInt;
	}
	return result2;
}

// ====================测试代码====================
void Test_10(int n, int expected)
{
	if (Fibonacci_Solution1(n) == expected)
		printf("Test for %d in solution1 passed.\n", n);
	else
		printf("Test for %d in solution1 failed.\n", n);

	if (Fibonacci_Solution2(n) == expected)
		printf("Test for %d in solution2 passed.\n", n);
	else {
		printf("Test for %d in solution2 failed.\n", n);
		printf("Your answer is %d, the right answer is %d. \n", Fibonacci_Solution2(n), expected);
	}
}

// 特殊情况 0
void Test_10_1()
{
	Test_10(0, 0);
}

// 特殊情况 1
void Test_10_2()
{
	Test_10(1, 1);
}

// 特殊情况 2
void Test_10_3()
{
	Test_10(2, 1);
}

// 计算得出 
void Test_10_4()
{
	Test_10(3, 2);
}

void Test_10_5()
{
	Test_10(6, 8);
}

void Test_10_6()
{
	Test_10(10, 55);
}

// 大数
void Test_10_7()
{
	Test_10(40, 102334155);
}

void offer_10_test()
{
	Test_10_1();
	Test_10_2();
	Test_10_3();
	Test_10_4();
	Test_10_5();
	Test_10_6();
	Test_10_7();

	cout << "offer_10 success" << endl;
}

// 牛客网 ac
/*
class Solution {
public:
	int Fibonacci(int n) {
		if (n <= 0)
			return 0;
		if (n == 1)
			return 1;
		long long result1 = 0;
		long long result2 = 1;
		for (int i = 2; i <= n; i++) {
			int tempInt = result2;
			result2 = result1 + result2;
			result1 = tempInt;
		}
		return result2;
	}
};
*/

// 牛客网 ac
/*
	一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/
/*
class Solution {
public:
    int jumpFloor(int number) {
        if (number <= 0)
			return 0;
		if (number == 1)
			return 1;
		long long result1 = 1;
		long long result2 = 1;
		for (int i = 2; i <= number; i++) {
			int tempInt = result2;
			result2 = result1 + result2;
			result1 = tempInt;
		}
		return result2;
    }
};
*/

// 牛客网 ac
/*
	一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/
/*
class Solution {
public:
    int jumpFloorII(int number) {
        if (number <= 0)
			return 0;
		if (number == 1)
			return 1;
		long long result = 2;
		for (int i = 2; i < number; i++) {
			result = result * 2;
		}
		return result;
    }
};
*/

// 牛客网 ac
/*
	我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/
/*
class Solution {
public:
    int rectCover(int number) {
        if (number <= 0)
			return 0;
		if (number == 1)
			return 1;
		long long result1 = 1;
		long long result2 = 1;
		for (int i = 2; i <= number; i++) {
			int tempInt = result2;
			result2 = result1 + result2;
			result1 = tempInt;
		}
		return result2;
    }
};
*/