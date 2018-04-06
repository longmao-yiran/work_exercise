#include "offer_38.h"

/*
	字符串的排列
	输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
*/

void Permutation(char* pStr, char* pBegin);

void Permutation(char* pStr)
{
	if (pStr == nullptr)
		return;

	Permutation(pStr, pStr);
}

void Permutation(char* pStr, char* pBegin)
{
	if (pStr == nullptr || pBegin == nullptr)
		return;
	if (*pBegin == '\0') {
		cout << pStr << endl;
	}
	else {
		// 思路：列举所有可能出现第一个位置的情况，然后固定第一位，列举出现的第二个位置的情况 递归
		for (char* ch = pBegin;*ch != '\0';ch++) {
			// 注意：剑指offer没有考虑重复的情况 此处修复
			if (*pBegin == *ch && pBegin != ch)
				continue;
			char temp = *ch;
			*ch = *pBegin;
			*pBegin = temp;

			Permutation(pStr, pBegin+1);
			// 注意：此处要记得换回来
			temp = *ch;
			*ch = *pBegin;
			*pBegin = temp;
		}
	}
}

// ====================测试代码====================
void Test_38(char* pStr)
{
	if (pStr == nullptr)
		printf("Test_38_ for nullptr begins:\n");
	else
		printf("Test_38_ for %s begins:\n", pStr);

	Permutation(pStr);

	printf("\n");
}

void Test_38_1() {
	char string1[] = "";
	Test_38(string1);
}
void Test_38_2() {
	char string2[] = "a";
	Test_38(string2);
}
void Test_38_3() {
	char string3[] = "ab";
	Test_38(string3);
}
void Test_38_4() {
	char string4[] = "abc";
	Test_38(string4);
}
void Test_38_5() {
	Test_38(nullptr);
}
void Test_38_6() {
	char string6[] = "aab";
	Test_38(string6);
}

void offer_38_test()
{
	Test_38_1();
	Test_38_2();
	Test_38_3();
	Test_38_4();
	Test_38_5();
	Test_38_6();

	cout << "offer_38 success" << endl;
}

// 牛客网ac
/*
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;
        if (str.size() <= 0)
            return result;

        set<string> permutationSet;
        Permutation(str, 0, permutationSet);
        for (set<string>::iterator iter = permutationSet.begin(); iter != permutationSet.end(); ++iter)
        {
            result.push_back(*iter);
        }
        return result;
    }

    void Permutation(string str, int pBegin, set<string>& result)
    {
        if (str.size() <= 0 || pBegin < 0)
            return;
        if (pBegin == str.size()) {
            result.insert(str);			// 注意：此处set自动剔除重复数据
        }
        else {
            for (int i = pBegin;i < str.size();i++) {
                char temp = str[i];
                str[i] = str[pBegin];
                str[pBegin] = temp;

                Permutation(str, pBegin + 1, result);

                temp = str[i];
                str[i] = str[pBegin];
                str[pBegin] = temp;
            }
        }
    }
};
*/