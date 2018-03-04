#include "offer_17.h"

/*
	打印从1到最大的n位数 
*/

void PrintNumber(char* number);
bool Increment(char* number);
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);


// 非递归方法
void Print1ToMaxOfNDigits_1(int n)
{
	if (n <= 0)
		return;

	char* number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number)){
		PrintNumber(number);
	}
	delete[] number;
}

bool Increment(char* number)
{
	if (number == nullptr)
		return false;

	bool isOverFlow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);

	for (int i = nLength - 1; i >= 0; --i) {
		if (i == nLength - 1)
			nTakeOver = 1;

		int nSum = number[i] - '0' + nTakeOver;

		if (nSum >= 10 && i == 0) {
			isOverFlow = true;
			break;
		}

		if (nSum >= 10) {
			nSum -= 10;
			nTakeOver = 1;
		}
		else
			nTakeOver = 0;

		number[i] = '0' + nSum;
	}

	return isOverFlow;
}

void PrintNumber(char* number)
{
	if (number == nullptr)
		return;

	int startIndex = 0;
	int nLength = strlen(number);
	for (; startIndex < nLength; ++startIndex){
		if (number[startIndex] != '0')
			break;
	}

	for (; startIndex < nLength; ++startIndex) {
		cout << number[startIndex];
	}
	cout << "\t";
}



// ====================测试代码====================
void Test_17(int n)
{
	printf("Test for %d begins:\n", n);

	Print1ToMaxOfNDigits_1(n);
	//Print1ToMaxOfNDigits_2(n);

	printf("\nTest for %d ends.\n", n);
}

void Test_17_1()
{
	Test_17(1);
}

void Test_17_2()
{
	Test_17(2);
}

void Test_17_3()
{
	Test_17(3);
}

void Test_17_4()
{
	Test_17(0);
}

void Test_17_5()
{
	Test_17(-1);
}

void offer_17_test()
{
	Test_17_1();
	Test_17_2();
	Test_17_3();
	Test_17_4();
	Test_17_5();

	cout << "offer_17 success" << endl;
}