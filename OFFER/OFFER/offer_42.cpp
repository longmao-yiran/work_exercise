#include "offer_42.h"

/*
	���������������
	�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý����
	����,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�
	����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)��
	(�������ĳ���������1)
*/

int FindGreatestSumOfSubArray(int *pData, int nLength)
{
	if (pData == nullptr || nLength <= 0)
		return 0;

	int nPreSum = 0;
	int nMaxSum = 0x80000000;

	// �Ƚ�ָoffer���
	for (int i = 0;i < nLength;++i) {
		nPreSum += pData[i];

		// �滻���ֵ
		if (nMaxSum < nPreSum)
			nMaxSum = nPreSum;

		// ���ǰ��Ӻ�Ϊ���� ��Ϊ0
		if (nPreSum < 0)
			nPreSum = 0;
	}
	return nMaxSum;
}

// ====================���Դ���====================
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

// �������ֶ��Ǹ���
// -2, -8, -1, -5, -9
void Test_42_2()
{
	int data[] = { -2, -8, -1, -5, -9 };
	Test_42("Test_42_2", data, sizeof(data) / sizeof(int), -1, false);
}

// �������ֶ�������
// 2, 8, 1, 5, 9
void Test_42_3()
{
	int data[] = { 2, 8, 1, 5, 9 };
	Test_42("Test_42_3", data, sizeof(data) / sizeof(int), 25, false);
}

// ��Ч����
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

// ţ����ac
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

