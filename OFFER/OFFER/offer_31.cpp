#include "offer_31.h"

/*
	栈的压入、弹出序列
	输入两个整数序列，第一个序列表示栈的压入顺序，
	请判断第二个序列是否为该栈的弹出顺序。
	假设压入栈的所有数字均不相等。
	例如序列1,2,3,4,5是某栈的压入顺序，
	序列4，5,3,2,1是该压栈序列对应的一个弹出序列，
	但4,3,5,1,2就不可能是该压栈序列的弹出序列。
	（注意：这两个序列的长度是相等的）
*/

bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
{
	if (pPush == nullptr || pPop == nullptr)
		return false;

	stack<int> stackTemp;
	const int* pushIndex = pPush;
	const int* popIndex = pPop;
	while (popIndex - pPop < nLength && pushIndex - pPush <nLength)
	{
		while (pushIndex - pPush < nLength && *pushIndex != *popIndex)
		{
			stackTemp.push(*pushIndex);
			pushIndex++;
		}
		if (*pushIndex == *popIndex) {
			stackTemp.push(*pushIndex);
			pushIndex++;
		}

		while (popIndex - pPop < nLength && stackTemp.top() == *popIndex && !stackTemp.empty()) {
			stackTemp.pop();
			popIndex++;
		}
	}
	if (stackTemp.empty() && popIndex - pPop == nLength)
		return true;
	else
		return false;
}

// ====================测试代码====================
void Test_31(const char* testName, const int* pPush, const int* pPop, int nLength, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (IsPopOrder(pPush, pPop, nLength) == expected)
		printf("Passed.\n");
	else
		printf("failed.\n");
}

void Test_31_1()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 4, 5, 3, 2, 1 };

	Test_31("Test_31_1", push, pop, nLength, true);
}

void Test_31_2()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 3, 5, 4, 2, 1 };

	Test_31("Test_31_2", push, pop, nLength, true);
}

void Test_31_3()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 4, 3, 5, 1, 2 };

	Test_31("Test_31_3", push, pop, nLength, false);
}

void Test_31_4()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 3, 5, 4, 1, 2 };

	Test_31("Test_31_4", push, pop, nLength, false);
}

// push和pop序列只有一个数字
void Test_31_5()
{
	const int nLength = 1;
	int push[nLength] = { 1 };
	int pop[nLength] = { 2 };

	Test_31("Test_31_5", push, pop, nLength, false);
}

void Test_31_6()
{
	const int nLength = 1;
	int push[nLength] = { 1 };
	int pop[nLength] = { 1 };

	Test_31("Test_31_6", push, pop, nLength, true);
}

void Test_31_7()
{
	Test_31("Test_31_7", nullptr, nullptr, 0, false);
}

void offer_31_test()
{
	Test_31_1();
	Test_31_2();
	Test_31_3();
	Test_31_4();
	Test_31_5();
	Test_31_6();
	Test_31_7();

	cout << "offer_31 success" << endl;
}

// 牛客网ac
/*
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.empty() || popV.empty())
			return false;

		stack<int> stackTemp;
		int pushIndex = 0;
		int popIndex = 0;
		while (popIndex - 0 < pushV.size() && pushIndex - 0 < pushV.size())
		{
			while (pushIndex - 0 < pushV.size() && pushV[pushIndex] != popV[popIndex])
			{
				stackTemp.push(pushV[pushIndex]);
				pushIndex++;
			}
			if (pushV[pushIndex] == popV[popIndex]) {
				stackTemp.push(pushV[pushIndex]);
				pushIndex++;
			}

			while (popIndex - 0 < pushV.size() && stackTemp.top() == popV[popIndex] && !stackTemp.empty()) {
				stackTemp.pop();
				popIndex++;
			}
		}
		if (!stackTemp.empty())
			return false;
		else
			return true;
	}
};
*/