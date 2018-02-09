#include "offer_5.h"

/*
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
	char replaceChar[4] = "#20";
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

void offer_5_test()
{
	// �����ո�
	char testChar[20] = "we are happy.";
	int length = 18;
	ReplaceBlank(nullptr, length);
	ReplaceBlank(testChar, 0);
	ReplaceBlank(testChar, 16);
	ReplaceBlank(testChar, length);

	// �����ո� ǰ���пո�
	char testChar1[20] = " we  are happy. ";
	ReplaceBlank(testChar1, 27);
	// û�пո�
	char testChar2[20] = "wearehappy.";
	ReplaceBlank(testChar2, length);
	cout << "offer_5 success" << endl;
}