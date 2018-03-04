#include "offer_16.h"

/*
	数值的整数次方
	给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/

bool g_InvalidInput = false;
bool equal(double num1, double num2);
double PowerWithUnsignedExponent(double base, unsigned int exponent);

double Power(double base, int exponent)
{
	g_InvalidInput = false;
	// 注意：防止除0 即：底数为0 指数为负数
	if (equal(base, 0.0) && exponent < 0)
	{
		g_InvalidInput = true;
		return 0.0;
	}
	unsigned int absExponent = 0;
	if (exponent > 0)
		absExponent = unsigned int(exponent);
	else
		absExponent = unsigned int(-exponent);

	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;
	return result;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	double result = PowerWithUnsignedExponent(base, exponent >> 1);		// 注意此处是向左移位
	result = result * result;
	if ((exponent & 0x1) == 1)
		result = result * base;

	return result;
}

bool equal(double num1, double num2) 
{
	double result = num1 > num2 ? num1 - num2 : num2 - num1;
	if (result < 0.000001)
		return true;
	else
		return false;
}

// ====================测试代码====================
void Test_16(const char* testName, double base, int exponent, double expectedResult, bool expectedFlag)
{
	double result = Power(base, exponent);
	if (equal(result, expectedResult) && g_InvalidInput == expectedFlag)
		std::cout << testName << " passed" << std::endl;
	else
		std::cout << testName << " FAILED" << "Your answer is " << result << "  The right answer is " << expectedResult << std::endl;
}

// 底数、指数都为正数
void Test_16_1()
{
	Test_16("Test_16_1", 2, 3, 8, false);
}

// 底数为负数、指数为正数
void Test_16_2()
{
	Test_16("Test_16_2", -2, 3, -8, false);
}

// 指数为负数
void Test_16_3()
{
	Test_16("Test_16_3", 2, -3, 0.125, false);
}

// 指数为0
void Test_16_4()
{
	Test_16("Test_16_4", 2, 0, 1, false);
}

// 底数、指数都为0
void Test_16_5()
{
	Test_16("Test_16_5", 0, 0, 1, false);
}

// 底数为0、指数为正数
void Test_16_6()
{
	Test_16("Test_16_6", 0, 4, 0, false);
}

// 底数为0、指数为负数
void Test_16_7()
{
	Test_16("Test_16_7", 0, -4, 0, true);
}

void offer_16_test()
{
	Test_16_1();
	Test_16_2();
	Test_16_3();
	Test_16_4();
	Test_16_5();
	Test_16_6();
	Test_16_7();

	cout << "offer_16 success" << endl;
}

// 牛客网 ac
/*
class Solution {
public:
    bool g_InvalidInput = false;
    double Power(double base, int exponent)
    {
        g_InvalidInput = false;
        // 注意：防止除0 即：底数为0 指数为负数
        if (equal(base, 0.0) && exponent < 0)
        {
            g_InvalidInput = true;
            return 0.0;
        }
        unsigned int absExponent = 0;
        if (exponent > 0)
            absExponent = (unsigned int)(exponent);
        else
            absExponent = (unsigned int)(-exponent);

        double result = PowerWithUnsignedExponent(base, absExponent);
        if (exponent < 0)
            result = 1.0 / result;
        return result;
    }

    double PowerWithUnsignedExponent(double base, unsigned int exponent)
    {
        if (exponent == 0)
            return 1;
        if (exponent == 1)
            return base;

        double result = PowerWithUnsignedExponent(base, exponent >> 1);		// 注意此处是向左移位
        result = result * result;
        if ((exponent & 0x1) == 1)
            result = result * base;

        return result;
    }

    bool equal(double num1, double num2) 
    {
        double result = num1 > num2 ? num1 - num2 : num2 - num1;
        if (result < 0.000001)
            return true;
        else
            return false;
    }
};
*/