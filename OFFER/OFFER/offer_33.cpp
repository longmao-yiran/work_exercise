#include "offer_33.h"

/*
	�����������ĺ����������
	����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
	����������Yes,�������No���������������������������ֶ�������ͬ��
*/

bool VerifySquenceOfBST(int sequence[], int length)
{
	if (sequence == nullptr || length <= 0)
		return false;
	
	if (length == 1)
		return true;

	int rootValue = sequence[length - 1];
	int i = 0;
	for (;i < length -1;++i) {						// ע�⣺�˴�Ӧ��Ϊlength - 1 �޳����ڵ�
		if (sequence[i] > rootValue)
			break;
	}

	int j = i;
	for (j;j < length - 1;++j) {
		if (sequence[j] < rootValue)
			return false;
	}
	if (i > 0)
		bool left = VerifySquenceOfBST(sequence, i);
	if (i<length-1)
		bool right = VerifySquenceOfBST(sequence+i, length -i -1);

	return left&&right;
}

// ====================���Դ���====================
void Test_33(const char* testName, int sequence[], int length, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (VerifySquenceOfBST(sequence, length) == expected)
		printf("passed.\n");
	else
		printf("failed.\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test_33_1()
{
	int data[] = { 4, 8, 6, 12, 16, 14, 10 };
	Test_33("Test_33_1", data, sizeof(data) / sizeof(int), true);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test_33_2()
{
	int data[] = { 4, 6, 7, 5 };
	Test_33("Test_33_2", data, sizeof(data) / sizeof(int), true);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test_33_3()
{
	int data[] = { 1, 2, 3, 4, 5 };
	Test_33("Test_33_3", data, sizeof(data) / sizeof(int), true);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test_33_4()
{
	int data[] = { 5, 4, 3, 2, 1 };
	Test_33("Test_33_4", data, sizeof(data) / sizeof(int), true);
}

// ����ֻ��1�����
void Test_33_5()
{
	int data[] = { 5 };
	Test_33("Test_33_5", data, sizeof(data) / sizeof(int), true);
}

void Test_33_6()
{
	int data[] = { 7, 4, 6, 5 };
	Test_33("Test_33_6", data, sizeof(data) / sizeof(int), false);
}

void Test_33_7()
{
	int data[] = { 4, 6, 12, 8, 16, 14, 10 };
	Test_33("Test_33_7", data, sizeof(data) / sizeof(int), false);
}

void Test_33_8()
{
	Test_33("Test_33_8", nullptr, 0, false);
}

void offer_33_test()
{
	Test_33_1();
	Test_33_2();
	Test_33_3();
	Test_33_4();
	Test_33_5();
	Test_33_6();
	Test_33_7();
	Test_33_8();

	cout << "offer_33 success" << endl;
}

// ţ����ac
/*
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {

        int length = sequence.size();
        if (length <= 0)
            return false;

        if (length == 1)
            return true;
        vector<int> leftVector;
        vector<int> rightVector;

        int rootValue = sequence[length - 1];
        int i = 0;
        for (;i < length - 1;++i) {						// ע�⣺�˴�Ӧ��Ϊlength - 1 �޳����ڵ�
            if (sequence[i] > rootValue)
                break;
            leftVector.push_back(sequence[i]);
        }

        int j = i;
        for (j;j < length - 1;++j) {
            if (sequence[j] < rootValue)
                return false;
            rightVector.push_back(sequence[i]);
        }
        if (i > 0)
            bool left = VerifySquenceOfBST(leftVector);
        if (i<length - 1)
            bool right = VerifySquenceOfBST(rightVector);

        return left&&right;
    }
};
*/