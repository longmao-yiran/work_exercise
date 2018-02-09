#include "offer_5.h"

/*
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
	char replaceChar[4] = "#20";
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

void offer_5_test()
{
	// 正常空格
	char testChar[20] = "we are happy.";
	int length = 18;
	ReplaceBlank(nullptr, length);
	ReplaceBlank(testChar, 0);
	ReplaceBlank(testChar, 16);
	ReplaceBlank(testChar, length);

	// 连续空格 前后有空格
	char testChar1[20] = " we  are happy. ";
	ReplaceBlank(testChar1, 27);
	// 没有空格
	char testChar2[20] = "wearehappy.";
	ReplaceBlank(testChar2, length);
	cout << "offer_5 success" << endl;
}