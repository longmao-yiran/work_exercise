#include "offer_20.h"

/*
	表示数值的字符串
	请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
	例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
	但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/

bool scanUnsignedInteger(const char** str);	
bool scanInteger(const char** str);

// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，其中A和C都是
// 整数（可以有正负号，也可以没有），而B是一个无符号整数
bool isNumeric(const char* str) 
{
	if (str == nullptr)
		return false;

	bool isA = scanInteger(&str);
	bool isB = false;
	bool isC = true;

	if (*str == '.') {
		++str;
		isB = scanUnsignedInteger(&str);
	}
	// .	A == false B == false	false
	// 无   A == false B == false	false
	// A.	A == true  B == false	true
	// A.B	A == true  B == true	true
	// .B	A == false B == true	true
	// A	A == ture  B == false	true
	if (isA == false && isB == false)				// 注意：此处如果数字不合格 或者没有数字 直接跳出
		return false;
	if (*str == 'e' || *str == 'E') {
		++str;
		isC = scanInteger(&str);
	}

	return isC && *str=='\0';						// 注意：此处要判断str=='\0' 防止后面还有奇怪的东西
}

bool scanUnsignedInteger(const char** str) 
{
	const char *strTemp = *str;
	while ((**str != '\0') &&(**str >= '0' && **str <='9')){
		++(*str);
	}
	return *str > strTemp;
}

bool scanInteger(const char** str)
{
	if (**str == '+' ||**str == '-')
		++(*str);
	return scanUnsignedInteger(str);
}

// ====================测试代码====================
void Test_20(const char* testName, const char* str, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (isNumeric(str) == expected)
		printf("Passed.\n");
	else
		cout << "FAILED. The str is "<< str <<" Your anser is " << isNumeric(str) << " The right answer is " << expected << endl;
}
void Test_20_1()
{
	Test_20("Test_20_1", "100", true);
}
void Test_20_2()
{
	Test_20("Test_20_2", "123.45e+6", true);
}
void Test_20_3()
{
	Test_20("Test_20_3", "+500", true);
}
void Test_20_4()
{
	Test_20("Test_20_4", "5e2", true);
}
void Test_20_5()
{
	Test_20("Test_20_5", "3.1416", true);
}
void Test_20_6()
{
	Test_20("Test_20_6", "600.", true);
}
void Test_20_7()
{
	Test_20("Test_20_7", "-.123", true);
}
void Test_20_8()
{
	Test_20("Test_20_8", "-1E-16", true);
}
void Test_20_9()
{
	Test_20("Test_20_9", "1.79769313486232E+308", true);
}
void Test_20_10()
{
	Test_20("Test_20_10", "12e", false);
}
void Test_20_11()
{
	Test_20("Test_20_11", "1a3.14", false);
}
void Test_20_12()
{
	Test_20("Test_20_12", "1+23", false);
}
void Test_20_13()
{
	Test_20("Test_20_13", "1.2.3", false);
}
void Test_20_14()
{
	Test_20("Test_20_14", "+-5", false);
}
void Test_20_15()
{
	Test_20("Test_20_15", "12e+5.4", false);
}
void Test_20_16()
{
	Test_20("Test_20_16", ".", false);
}
void Test_20_17()
{
	Test_20("Test_20_17", ".e1", false);
}
void Test_20_18()
{
	Test_20("Test_20_18", "e1", false);
}
void Test_20_19()
{
	Test_20("Test_20_19", "+.", false);
}
void Test_20_20()
{
	Test_20("Test_20_20", "", false);
}
void Test_20_21()
{
	Test_20("Test_20_21", nullptr, false);
}


void offer_20_test()
{
	Test_20_1();
	Test_20_2();
	Test_20_3();
	Test_20_4();
	Test_20_5();
	Test_20_6();
	Test_20_7();
	Test_20_8();
	Test_20_9();
	Test_20_10();
	Test_20_11();
	Test_20_12();
	Test_20_13();
	Test_20_14();
	Test_20_15();
	Test_20_16();
	Test_20_17();
	Test_20_18();
	Test_20_19();
	Test_20_20();
	Test_20_21();

	cout << "offer_20 success" << endl;
}

// 牛客网ac
/*
class Solution {
public:
    bool isNumeric(const char* str) 
    {
        if (str == nullptr)
            return false;

        bool isA = scanInteger(&str);
        bool isB = false;
        bool isC = true;

        if (*str == '.') {
            ++str;
            isB = scanUnsignedInteger(&str);
        }
        // .	A == false B == false	false
        // 无   A == false B == false	false
        // A.	A == true  B == false	true
        // A.B	A == true  B == true	true
        // .B	A == false B == true	true
        // A	A == ture  B == false	true
        if (isA == false && isB == false)				// 注意：此处如果数字不合格 或者没有数字 直接跳出
            return false;
        if (*str == 'e' || *str == 'E') {
            ++str;
            isC = scanInteger(&str);
        }

        return isC && *str=='\0';
    }

    bool scanUnsignedInteger(const char** str) 
    {
        const char *strTemp = *str;
        while ((**str != '\0') &&(**str >= '0' && **str <='9')){
            ++(*str);
        }
        return *str > strTemp;
    }

    bool scanInteger(const char** str)
    {
        if (**str == '+' ||**str == '-')
            ++(*str);
        return scanUnsignedInteger(str);
    }

};
*/