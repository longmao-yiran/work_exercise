#include "offer_16.h"

/*
	��ֵ�������η�
	����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
*/

bool g_InvalidInput = false;
bool equal(double num1, double num2);
double PowerWithUnsignedExponent(double base, unsigned int exponent);

double Power(double base, int exponent)
{
	g_InvalidInput = false;
	// ע�⣺��ֹ��0 ��������Ϊ0 ָ��Ϊ����
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

	double result = PowerWithUnsignedExponent(base, exponent >> 1);		// ע��˴���������λ
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

// ====================���Դ���====================
void Test_16(const char* testName, double base, int exponent, double expectedResult, bool expectedFlag)
{
	double result = Power(base, exponent);
	if (equal(result, expectedResult) && g_InvalidInput == expectedFlag)
		std::cout << testName << " passed" << std::endl;
	else
		std::cout << testName << " FAILED" << "Your answer is " << result << "  The right answer is " << expectedResult << std::endl;
}

// ������ָ����Ϊ����
void Test_16_1()
{
	Test_16("Test_16_1", 2, 3, 8, false);
}

// ����Ϊ������ָ��Ϊ����
void Test_16_2()
{
	Test_16("Test_16_2", -2, 3, -8, false);
}

// ָ��Ϊ����
void Test_16_3()
{
	Test_16("Test_16_3", 2, -3, 0.125, false);
}

// ָ��Ϊ0
void Test_16_4()
{
	Test_16("Test_16_4", 2, 0, 1, false);
}

// ������ָ����Ϊ0
void Test_16_5()
{
	Test_16("Test_16_5", 0, 0, 1, false);
}

// ����Ϊ0��ָ��Ϊ����
void Test_16_6()
{
	Test_16("Test_16_6", 0, 4, 0, false);
}

// ����Ϊ0��ָ��Ϊ����
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

// ţ���� ac
/*
class Solution {
public:
    bool g_InvalidInput = false;
    double Power(double base, int exponent)
    {
        g_InvalidInput = false;
        // ע�⣺��ֹ��0 ��������Ϊ0 ָ��Ϊ����
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

        double result = PowerWithUnsignedExponent(base, exponent >> 1);		// ע��˴���������λ
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