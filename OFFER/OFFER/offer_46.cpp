#include "offer_46.h"

/*
	Êı×Ö·­Òë³É×Ö·û´®
*/

int GetTranslationCount(const string& number);

int GetTranslationCount(int number) 
{
	if (number < 0)
		return 0;
	string numberInString = to_string(number);

	return GetTranslationCount(numberInString);
}

int GetTranslationCount(const string& number)
{
	int length = number.length();

	int* count = new int[length + 1];
	count[length] = 1;
	count[length - 1] = 1;
	// ×´Ì¬×ªÒÆ·½³Ì f(i) = f(i+1) + Pi,k*f(i+2);
	for (int i = length - 2;i >= 0;--i) {
		count[i] = count[i+1];
		int numberInt = number[i + 1] - '0' + (number[i] - '0') * 10;
		if (numberInt >= 10 && numberInt <= 25) {
			count[i] += count[i + 2];
		}
	}
	return count[0];
}

// ====================²âÊÔ´úÂë====================
void Test_46(const string& testName, int number, int expected)
{
	if (GetTranslationCount(number) == expected)
		cout << testName << " passed." << endl;
	else
		cout << testName << " FAILED." << "result: " << GetTranslationCount(number) <<"  answer: " <<expected << endl;
}

void Test_46_1()
{
	int number = 0;
	int expected = 1;
	Test_46("Test_46_1", number, expected);
}

void Test_46_2()
{
	int number = 10;
	int expected = 2;
	Test_46("Test_46_2", number, expected);
}

void Test_46_3()
{
	int number = 125;
	int expected = 3;
	Test_46("Test_46_3", number, expected);
}

void Test_46_4()
{
	int number = 126;
	int expected = 2;
	Test_46("Test_46_4", number, expected);
}

void Test_46_5()
{
	int number = 426;
	int expected = 1;
	Test_46("Test_46_5", number, expected);
}

void Test_46_6()
{
	int number = 100;
	int expected = 2;
	Test_46("Test_46_6", number, expected);
}

void Test_46_7()
{
	int number = 101;
	int expected = 2;
	Test_46("Test_46_7", number, expected);
}

void Test_46_8()
{
	int number = 12258;
	int expected = 5;
	Test_46("Test_46_8", number, expected);
}

void Test_46_9()
{
	int number = -100;
	int expected = 0;
	Test_46("Test_46_9", number, expected);
}

void offer_46_test()
{
	Test_46_1();
	Test_46_2();
	Test_46_3();
	Test_46_4();
	Test_46_5();
	Test_46_6();
	Test_46_7();
	Test_46_8();
	Test_46_9();

	cout << "offer_45 success" << endl;
}
