#include "offer_38_1.h"

/*
	字符串组合数
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

	// 思路：对于长度为n的组合分为两种情况：1.组合包括第一个字符，从生下n-1个中选m-1个 2.组合不包括第一个字符，从生下n-1中选m个
	// 注意：字符应该提前去重
	result.push_back(*str);
	Combination(str+1, number - 1, result, resultList);
	result.pop_back();
	Combination(str+1, number, result, resultList);
}

void offer_38_1_test()
{
	char s[] = "abc";
	Combination(s);

	cout << "offer_38_1 success" << endl;
}

// 其他算法 不好 排列之后去重