#include "offer_5.h"

/*
	�滻�ո�
	��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20����
	���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
*/

void ReplaceBlank(char str[], int length)
{
	// �����ж�
	if (str == nullptr || length <= 0)
		return;
	int originalLength = 0;
	int numOfBlank = 0;
	// ����ԭ���ַ����������ո�����
	while (str[originalLength] != '\0')
	{
		if (str[originalLength] == ' ')
			++numOfBlank;
		++originalLength;
	}
	int newLength = originalLength + numOfBlank * 2;
	// �ж��ַ��Ƿ��Խ��
	if (length < (newLength + 1))
		return;
	char replaceChar[4] = "%20";
	// �滻
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

// ====================���Դ���====================
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

// �ո��ھ����м�
void Test_5_1()
{
	const int length = 100;

	char str[length] = "hello world";
	Test_5("Test_5_1", str, length, "hello%20world");
}

// �ո��ھ��ӿ�ͷ
void Test_5_2()
{
	const int length = 100;

	char str[length] = " helloworld";
	Test_5("Test_5_2", str, length, "%20helloworld");
}

// �ո��ھ���ĩβ
void Test_5_3()
{
	const int length = 100;

	char str[length] = "helloworld ";
	Test_5("Test_5_3", str, length, "helloworld%20");
}

// �����������ո�
void Test_5_4()
{
	const int length = 100;

	char str[length] = "hello  world";
	Test_5("Test_5_4", str, length, "hello%20%20world");
}

// ����nullptr
void Test_5_5()
{
	Test_5("Test_5_5", nullptr, 0, nullptr);
}

// ��������Ϊ�յ��ַ���
void Test_5_6()
{
	const int length = 100;

	char str[length] = "";
	Test_5("Test_5_6", str, length, "");
}

//��������Ϊһ���ո���ַ���
void Test_5_7()
{
	const int length = 100;

	char str[length] = " ";
	Test_5("Test_5_7", str, length, "%20");
}

// ������ַ���û�пո�
void Test_5_8()
{
	const int length = 100;

	char str[length] = "helloworld";
	Test_5("Test_5_8", str, length, "helloworld");
}

// ������ַ���ȫ�ǿո�
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

// ţ���� ac
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