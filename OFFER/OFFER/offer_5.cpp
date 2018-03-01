#include "offer_5.h"

/*
	替换空格
	请实现一个函数，将一个字符串中的空格替换成“%20”。
	例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

void ReplaceBlank(char str[], int length)
{
	// 输入判断
	if (str == nullptr || length <= 0)
		return;
	int originalLength = 0;
	int numOfBlank = 0;
	// 计算原有字符串数量及空格数量
	while (str[originalLength] != '\0')
	{
		if (str[originalLength] == ' ')
			++numOfBlank;
		++originalLength;
	}
	int newLength = originalLength + numOfBlank * 2;
	// 判断字符是否会越界
	if (length < (newLength + 1))
		return;
	char replaceChar[4] = "%20";
	// 替换
	while (newLength >= 0){
		if (str[originalLength] == ' ') {
			for (int i = 2;i >= 0;--i)
				str[newLength--] = replaceChar[i];
			--originalLength;
		}
		else {
			str[newLength--] = str[originalLength--];
		}
	}
	cout << str << endl;
	return;
}

// ====================测试代码====================
void Test_5(char* testName, char str[], int length, char expected[])
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	ReplaceBlank(str, length);

	if (expected == nullptr && str == nullptr)
		printf("passed.\n");
	else if (expected == nullptr && str != nullptr)
		printf("failed.\n");
	else if (strcmp(str, expected) == 0)
		printf("passed.\n");
	else
		printf("failed.\n");
}

// 空格在句子中间
void Test_5_1()
{
	const int length = 100;

	char str[length] = "hello world";
	Test_5("Test_5_1", str, length, "hello%20world");
}

// 空格在句子开头
void Test_5_2()
{
	const int length = 100;

	char str[length] = " helloworld";
	Test_5("Test_5_2", str, length, "%20helloworld");
}

// 空格在句子末尾
void Test_5_3()
{
	const int length = 100;

	char str[length] = "helloworld ";
	Test_5("Test_5_3", str, length, "helloworld%20");
}

// 连续有两个空格
void Test_5_4()
{
	const int length = 100;

	char str[length] = "hello  world";
	Test_5("Test_5_4", str, length, "hello%20%20world");
}

// 传入nullptr
void Test_5_5()
{
	Test_5("Test_5_5", nullptr, 0, nullptr);
}

// 传入内容为空的字符串
void Test_5_6()
{
	const int length = 100;

	char str[length] = "";
	Test_5("Test_5_6", str, length, "");
}

//传入内容为一个空格的字符串
void Test_5_7()
{
	const int length = 100;

	char str[length] = " ";
	Test_5("Test_5_7", str, length, "%20");
}

// 传入的字符串没有空格
void Test_5_8()
{
	const int length = 100;

	char str[length] = "helloworld";
	Test_5("Test_5_8", str, length, "helloworld");
}

// 传入的字符串全是空格
void Test_5_9()
{
	const int length = 100;

	char str[length] = "   ";
	Test_5("Test_5_9", str, length, "%20%20%20");
}

void offer_5_test()
{
	Test_5_1();
	Test_5_2();
	Test_5_3();
	Test_5_4();
	Test_5_5();
	Test_5_6();
	Test_5_7();
	Test_5_8();
	Test_5_9();
	cout << "offer_5 success" << endl;
}

// 牛客网 ac
/*
class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == nullptr || length <= 0)
			return;
		int originalLength = 0;
		int numOfBlank = 0;
		while (str[originalLength] != '\0')
		{
			if (str[originalLength] == ' ')
				++numOfBlank;
			++originalLength;
		}
		int newLength = originalLength + numOfBlank * 2;
		if (length < (newLength + 1))
			return;
		char replaceChar[4] = "%20";
		while (newLength >= 0) {
			if (str[originalLength] == ' ') {
				for (int i = 2; i >= 0; --i)
					str[newLength--] = replaceChar[i];
				--originalLength;
			}
			else {
				str[newLength--] = str[originalLength--];
			}
		}
		cout << str << endl;
		return;
	}
};
*/