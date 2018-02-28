#include "offer_10.h"

/*
	f(0) = 0
	f(1) = 1
	f(n) = f(n-1) + f(n-2)
	��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n�n<=39
*/

// �ݹ�
long long Fibonacci_Solution1(unsigned int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	if (n > 1)
		return Fibonacci_Solution1(n - 1) + Fibonacci_Solution1(n - 2);
}

// ѭ��
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

// ====================���Դ���====================
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

// ������� 0
void Test_10_1()
{
	Test_10(0, 0);
}

// ������� 1
void Test_10_2()
{
	Test_10(1, 1);
}

// ������� 2
void Test_10_3()
{
	Test_10(2, 1);
}

// ����ó� 
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

// ����
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

// ţ���� ac
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

// ţ���� ac
/*
	һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������
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

// ţ���� ac
/*
	һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
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

// ţ���� ac
/*
	���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
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