#include "offer_42.h"

/*
	连续子数组的最大和
	在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
	但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
	例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
	(子向量的长度至少是1)
*/

int FindGreatestSumOfSubArray(int *pData, int nLength)
{
	if (pData == nullptr || nLength <= 0)
		return 0;

	int nPreSum = 0;
	int nMaxSum = 0x80000000;

	// 比剑指offer简洁
	for (int i = 0;i < nLength;++i) {
		nPreSum += pData[i];

		// 替换最大值
		if (nMaxSum < nPreSum)
			nMaxSum = nPreSum;

		// 如果前面加和为负数 则为0
		if (nPreSum < 0)
			nPreSum = 0;
	}
	return nMaxSum;
}

// ====================测试代码====================
void Test_42(char* testName, int* pData, int nLength, int expected, bool expectedFlag)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	int result = FindGreatestSumOfSubArray(pData, nLength);
	if (result == expected )
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test_42_1()
{
	int data[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	Test_42("Test_42_1", data, sizeof(data) / sizeof(int), 18, false);
}

// 所有数字都是负数
// -2, -8, -1, -5, -9
void Test_42_2()
{
	int data[] = { -2, -8, -1, -5, -9 };
	Test_42("Test_42_2", data, sizeof(data) / sizeof(int), -1, false);
}

// 所有数字都是正数
// 2, 8, 1, 5, 9
void Test_42_3()
{
	int data[] = { 2, 8, 1, 5, 9 };
	Test_42("Test_42_3", data, sizeof(data) / sizeof(int), 25, false);
}

// 无效输入
void Test_42_4()
{
	Test_42("Test_42_4", nullptr, 0, 0, true);
}

void offer_42_test()
{
	Test_42_1();
	Test_42_2();
	Test_42_3();
	Test_42_4();

	cout << "offer_42 success" << endl;
}

// 牛客网ac
/*
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int nLength = array.size();
        if (nLength <= 0)
            return 0;

        int nPreSum = 0;
        int nMaxSum = 0x80000000;

        for (int i = 0;i < nLength;++i) {
            nPreSum += array[i];

            if (nMaxSum < nPreSum)
                nMaxSum = nPreSum;

            if (nPreSum < 0)
                nPreSum = 0;
        }
        return nMaxSum;
    }
};
*/

