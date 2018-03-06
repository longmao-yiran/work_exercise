#include "offer_19.h"

/*
	正则表达式匹配
	请实现一个函数用来匹配包括'.'和'*'的正则表达式。
	模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
	在本题中，匹配是指字符串的所有字符匹配整个模式。
	例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/

bool matchCore(const char* str, const char* pattern);

bool match(const char* str, const char* pattern)
{
	if (str == nullptr || pattern == false)
		return false;
	bool result = matchCore(str, pattern);
	return result;
}

bool matchCore(const char* str, const char* pattern)
{
	if (str == nullptr || pattern == nullptr)
		return false;

	if (*str != '\0'&& *pattern == '\0')					// 注意：此处只在patten走完的时候判断 因为存在 str="" pattern = ".*"
		return false;

	if (*str == '\0'&& *pattern == '\0')
		return true;

	//if (*str == *pattern) {								// 注意：此处不能先判断是不是相等，因为*也包括没有
	//	if (*(pattern + 1) == '*') {
	//		return matchCore(str, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str + 1, pattern + 2);
	//	}
	//	if (*(pattern + 1) == '.' && *(str+1) != '\0') {
	//		return matchCore(str + 2, pattern + 2);
	//	}
	//	else{
	//		return matchCore(str + 1, pattern + 1);
	//	}
	//}

	if (*(pattern + 1) == '*') {
		if ((*str == *pattern) || (*pattern == '.' && *str != '\0'))		// 注意：此处。不能匹配'\0'
			return matchCore(str, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str + 1, pattern + 2);
		else
			return matchCore(str, pattern + 2);
	}
	if ((*str == *pattern) || (*pattern == '.' && *str != '\0'))
		return  matchCore(str+1, pattern + 1);
	return false;
}

// ====================测试代码====================
void Test_19(const char* testName, const char* string, const char* pattern, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (match(string, pattern) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

void Test_19_1()
{
	Test_19("Test_19_01", "", "", true);
}
void Test_19_2()
{
	Test_19("Test_19_02", "", ".*", true);
}
void Test_19_3()
{
	Test_19("Test_19_03", "", ".", false);
}
void Test_19_4()
{
	Test_19("Test_19_04", "", "c*", true);
}
void Test_19_5()
{
	Test_19("Test_19_05", "a", ".*", true);
}
void Test_19_6()
{
	Test_19("Test_19_06", "a", "a.", false);
}
void Test_19_7()
{
	Test_19("Test_19_07", "a", "", false);
}
void Test_19_8()
{
	Test_19("Test_19_08", "a", ".", true);
}
void Test_19_9()
{
	Test_19("Test_19_09", "a", "ab*", true);
}
void Test_19_10()
{
	Test_19("Test_19_10", "a", "ab*a", false);
}
void Test_19_11()
{
	Test_19("Test_19_11", "aa", "aa", true);
}
void Test_19_12()
{
	Test_19("Test_19_12", "aa", "a*", true);
}
void Test_19_13()
{
	Test_19("Test_19_13", "aa", ".*", true);
}
void Test_19_14()
{
	Test_19("Test_19_14", "aa", ".", false);
}
void Test_19_15()
{
	Test_19("Test_19_15", "ab", ".*", true);
}
void Test_19_16()
{
	Test_19("Test_19_16", "ab", ".*", true);
}
void Test_19_17()
{
	Test_19("Test_19_17", "aaa", "aa*", true);
}
void Test_19_18()
{
	Test_19("Test_19_18", "aaa", "aa.a", false);
}
void Test_19_19()
{
	Test_19("Test_19_19", "aaa", "a.a", true);
}
void Test_19_20()
{
	Test_19("Test_19_20", "aaa", ".a", false);
}
void Test_19_21()
{
	Test_19("Test_19_21", "aaa", "a*a", true);
}
void Test_19_22()
{
	Test_19("Test_19_22", "aaa", "ab*a", false);
}
void Test_19_23()
{
	Test_19("Test_19_23", "aaa", "ab*ac*a", true);
}
void Test_19_24()
{
	Test_19("Test_19_24", "aaa", "ab*a*c*a", true);
}
void Test_19_25()
{
	Test_19("Test_19_25", "aaa", ".*", true);
}
void Test_19_26()
{
	Test_19("Test_19_26", "aab", "c*a*b", true);
}
void Test_19_27()
{
	Test_19("Test_19_27", "aaca", "ab*a*c*a", true);
}
void Test_19_28()
{
	Test_19("Test_19_28", "aaba", "ab*a*c*a", false);
}
void Test_19_29()
{
	Test_19("Test_19_29", "bbbba", ".*a*a", true);
}
void Test_19_30()
{
	Test_19("Test_19_30", "bcbbabab", ".*a*a", false);
}

void offer_19_test()
{
	Test_19_1();
	Test_19_2();
	Test_19_3();
	Test_19_4();
	Test_19_5();
	Test_19_6();
	Test_19_7();
	Test_19_8();
	Test_19_9();
	Test_19_10();
	Test_19_11();
	Test_19_12();
	Test_19_13();
	Test_19_14();
	Test_19_15();
	Test_19_16();
	Test_19_17();
	Test_19_18();
	Test_19_19();
	Test_19_20();
	Test_19_21();
	Test_19_22();
	Test_19_23();
	Test_19_24();
	Test_19_25();
	Test_19_26();
	Test_19_27();
	Test_19_28();
	Test_19_29();
	Test_19_30();

	cout << "offer_19 success" << endl;
}

// 牛客网 ac
/*
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (str == nullptr || pattern == nullptr)
            return false;
        bool result = matchCore(str, pattern);
        return result;
    }
    bool matchCore(const char* str, const char* pattern)
    {
        if (str == nullptr || pattern == nullptr)
            return false;

        if (*str != '\0'&& *pattern == '\0')					// 注意：此处只在patten走完的时候判断 因为存在 str="" pattern = ".*"
            return false;

        if (*str == '\0'&& *pattern == '\0')
            return true;
        
        if (*(pattern + 1) == '*') {
            if ((*str == *pattern) || (*pattern == '.' && *str != '\0'))		// 注意：此处。不能匹配'\0'
                return matchCore(str, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str + 1, pattern + 2);
            else
                return matchCore(str, pattern + 2);
        }
        if ((*str == *pattern) || (*pattern == '.' && *str != '\0'))
            return  matchCore(str+1, pattern + 1);
        return false;
    }

};
*/