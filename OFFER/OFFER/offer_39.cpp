#include "offer_39.h"
#include "Utilities\Array.h"

/*
	数组中出现次数超过一半的数字
	数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
	例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
	由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/

bool CheckInvalidArray(int* numbers, int length) 
{
	if (numbers == nullptr || length <= 0)
		return true;
	return false;
}


bool CheckMoreThanHalf(int* numbers, int length, int number)
{
	int times = 0;
	for (int i = 0;i < length;++i) {
		if (numbers[i] == number)
			++times;
	}
	if (times * 2 <= length)
		return false;
	return true;
}

int MoreThanHalfNum_Solution1(int* numbers, int length)
{
	if (CheckInvalidArray(numbers,length))
		return 0;
	int middle = length >> 1;
	int start = 0;
	int end = length - 1;
	int index = Partition_longmao(numbers, length, start, end);
	while (index != middle){
		if (index > middle) {
			end = index - 1;
			index = Partition_longmao(numbers, length, start, end);
		}
		else {
			start = index + 1;
			index = Partition_longmao(numbers, length, start, end);
		}
	}
	int result = numbers[middle];

	if (!CheckMoreThanHalf(numbers, length, result))
		return 0;
	return result;
}

int MoreThanHalfNum_Solution2(int* numbers, int length)
{
	if (CheckInvalidArray(numbers, length))
		return 0;
	int result = 0;
	int times = 0;
	for (int i = 0;i < length;++i) {
		if (times == 0) {
			result = numbers[i];
			times++;
			continue;
		}
		if (numbers[i] == result)
			times++;
		else
			times--;
	}

	if (!CheckMoreThanHalf(numbers, length, result))
		return 0;
	return result;
}

// ====================测试代码====================
void Test_39(char* testName, int* numbers, int length, int expectedValue, bool expectedFlag)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	int* copy = new int[length];
	for (int i = 0; i < length; ++i)
		copy[i] = numbers[i];

	printf("Test_39_ for solution1: ");
	int result = MoreThanHalfNum_Solution1(numbers, length);
	if (result == expectedValue )
		printf("Passed.\n");
	else
		printf("Failed.\n");

	printf("Test_39_ for solution2: ");
	result = MoreThanHalfNum_Solution2(copy, length);
	if (result == expectedValue )
		printf("Passed.\n");
	else
		printf("Failed.\n");

	delete[] copy;
}

// 存在出现次数超过数组长度一半的数字
void Test_39_1()
{
	int numbers[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	Test_39("Test_39_1", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 不存在出现次数超过数组长度一半的数字
void Test_39_2()
{
	int numbers[] = { 1, 2, 3, 2, 4, 2, 5, 2, 3 };
	Test_39("Test_39_2", numbers, sizeof(numbers) / sizeof(int), 0, true);
}

// 出现次数超过数组长度一半的数字都出现在数组的前半部分
void Test_39_3()
{
	int numbers[] = { 2, 2, 2, 2, 2, 1, 3, 4, 5 };
	Test_39("Test_39_3", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 出现次数超过数组长度一半的数字都出现在数组的后半部分
void Test_39_4()
{
	int numbers[] = { 1, 3, 4, 5, 2, 2, 2, 2, 2 };
	Test_39("Test_39_4", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 输入空指针
void Test_39_5()
{
	int numbers[] = { 1 };
	Test_39("Test_39_5", numbers, 1, 1, false);
}

// 输入空指针
void Test_39_6()
{
	Test_39("Test_39_6", nullptr, 0, 0, true);
}


void offer_39_test()
{
	Test_39_1();
	Test_39_2();
	Test_39_3();
	Test_39_4();
	Test_39_5();
	Test_39_6();

	cout << "offer_39 success" << endl;
}

// 牛客网ac
/*
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size() == 0)
            return 0;
        int length = numbers.size();
        int result = 0;
        int times = 0;
        for (int i = 0;i < length;++i) {
            if (times == 0) {
                result = numbers[i];
                times++;
                continue;
            }
            if (numbers[i] == result)
                times++;
            else
                times--;
        }

        times = 0;
        for (int i = 0;i < length;++i) {
            if (numbers[i] == result)
                ++times;
        }
        if (times * 2 <= length)
            return 0;
        return result;
    }
};
*/