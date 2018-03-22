#include "offer_38_1.h"

/*
	�ַ��������
*/

void Combination(char* str, int number, string &result, vector<string> &resultList);

void Combination(char* str) 
{
	if (str == nullptr)
		return;
	vector<string> resultList;
	int length = strlen(str);
	string result = "";
	for (int i = 1;i <= length;++i) {
		Combination(str, i, result, resultList);
	}
	for (int i = 0;i < resultList.size();++i) {
		cout << resultList[i] << "\t";
	}
}

void Combination(char* str, int number, string &result, vector<string> &resultList)
{
	if (str == nullptr)
		return;
	if (number == 0) {
		resultList.push_back(result);
		return;
	}

	if (*str == '\0')
		return;

	result.push_back(*str);
	Combination(str+1, number - 1, result, resultList);
	result.pop_back();
	Combination(str+1, number, result, resultList);
}

void offer_38_1_test()
{
	char s[] = "abc";
	Combination(s);
}

// �����㷨 ���� ����֮��ȥ��