#include "offer_44.h"

/*
	序列中某一位的数字
*/

int countOfIntegers(int digits);
int digitAtIndex(int index, int digits);
int beginNumber(int digits);

int digitAtIndex(int index)
{
	if (index < 0)
		return false;

	int digits = 1;
	while (true)
	{
		int number = countOfIntegers(digits);
		if (index < number*digits)
			return digitAtIndex(index, digits);
		index -= (number * digits);
		digits++;
	}
}

int countOfIntegers(int digits) 
{
	if (digits == 1)
		return 10;
	int result = pow(10, digits - 1);
	result *= 9;
	return result;
}

int digitAtIndex(int index, int digits)
{
	int begin = beginNumber(digits);
	begin += (index / digits);
	int site = digits - index%digits;
	int result = 0;
	for (int i = 0;i < site;++i) {
		result = begin % 10;
		begin = begin / 10;
	}
	return result;

}

int beginNumber(int digits)
{
	if (digits == 1)
		return 0;
	return pow(10, digits - 1);
}


// ====================测试代码====================
void Test_44(const char* testName, int inputIndex, int expectedOutput)
{
	if (digitAtIndex(inputIndex) == expectedOutput)
		cout << testName << " passed." << endl;
	else
		cout << testName << " FAILED." << endl;
}

void Test_44_1()
{
	Test_44("Test_44_1", 0, 0);
}

void Test_44_2()
{
	Test_44("Test_44_2", 1, 1);
}

void Test_44_3()
{
	Test_44("Test_44_3", 9, 9);
}

void Test_44_4()
{
	Test_44("Test_44_4", 10, 1);
}

void Test_44_5()
{
	Test_44("Test_44_5", 189, 9);
}

void Test_44_6()
{
	Test_44("Test_44_6", 190, 1);
}

void Test_44_7()
{
	Test_44("Test_44_7", 1000, 3);
}

void Test_44_8()
{
	Test_44("Test_44_8", 1001, 7);
}

void Test_44_9()
{
	Test_44("Test_44_8", 1002, 0);
}

void offer_44_test()
{
	Test_44_1();
	Test_44_2();
	Test_44_3();
	Test_44_4();
	Test_44_5();
	Test_44_6();
	Test_44_7();
	Test_44_8();
	Test_44_9();

	cout << "offer_44 success" << endl;
}