#include "offer_3_2.h"

/*
	在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
	少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
	数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
	输出是重复的数字2或者3。
*/

// 要求不能改变数组 最简单的可以开辟长度为n的辅助数组解决
// 利用类似二分法的思路，如果有重复的 则范围在1~x的数字出现的次数大于x
// 非递归实现

int countRange(const int numbers[], int length, int start, int end) 
{
	// 判断是否为无效输入（空指针，数字超出范围）
	if (numbers == nullptr || length <= 0 || start < 0 || end >= length)
		return 0;
	int count = 0;
	for (int i = 0;i < length;++i) {
		if (numbers[i] >= start && numbers[i] <= end)
			++count;
	}

	return count;
}

int getDuplication(const int numbers[], int length)		// 注意由于不能改变 因此数组加const防止被改变
{
	// 判断是否为无效输入（空指针，数字超出范围）
	if (numbers == nullptr || length <= 0)
		return -1;

	for (int i = 0;i < length;++i) {
		if (numbers[i] <= 0 || numbers[i] > length)
			return -1;
	}
	int start = 1, end = length - 1;
	int middle = (start + end) / 2;
	int count = 0;
	while (start <= end)						// 注：此处防止
	{
		count = countRange(numbers, length, start, middle);
		// 出现次数大于区间
		if (count > (middle - start + 1)) {
			if (start == middle) {
				return middle;
			}
			end = middle;
			middle = (start + middle) / 2;
		}
		// 在区间内
		else {
			start = middle+1;
			middle = end;
		}
	}
	return -1;
}

// 剑指offer版本
int getDuplication2(const int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		return -1;

	int start = 1;
	int end = length - 1;
	while (end >= start)
	{
		int middle = ((end - start) >> 1) + start;
		int count = countRange(numbers, length, start, middle);
		if (end == start)
		{
			if (count > 1)
				return start;
			else
				break;
		}

		if (count > (middle - start + 1))
			end = middle;
		else
			start = middle + 1;
	}
	return -1;
}

// ====================测试代码====================
void Test_3_2(const char* Test_3_2_Name, int* numbers, int length, int* duplications, int dupLength)
{
	int result = getDuplication(numbers, length);
	for (int i = 0; i < dupLength; ++i)
	{
		if (result == duplications[i])
		{
			std::cout << Test_3_2_Name << " passed." << std::endl;
			return;
		}
	}
	std::cout << Test_3_2_Name << " FAILED." << std::endl;
}

// 多个重复的数字
void Test_3_2_1()
{
	int numbers[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	int duplications[] = { 2, 3 };
	Test_3_2("Test_3_2_1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 一个重复的数字
void Test_3_2_2()
{
	int numbers[] = { 3, 2, 1, 4, 4, 5, 6, 7 };
	int duplications[] = { 4 };
	Test_3_2("Test_3_2_2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 重复的数字是数组中最小的数字
void Test_3_2_3()
{
	int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 1, 8 };
	int duplications[] = { 1 };
	Test_3_2("Test_3_2_3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 重复的数字是数组中最大的数字
void Test_3_2_4()
{
	int numbers[] = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };
	int duplications[] = { 8 };
	Test_3_2("Test_3_2_4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 数组中只有两个数字
void Test_3_2_5()
{
	int numbers[] = { 1, 1 };
	int duplications[] = { 1 };
	Test_3_2("Test_3_2_5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 重复的数字位于数组当中
void Test_3_2_6()
{
	int numbers[] = { 3, 2, 1, 3, 4, 5, 6, 7 };
	int duplications[] = { 3 };
	Test_3_2("Test_3_2_6", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 多个重复的数字
void Test_3_2_7()
{
	int numbers[] = { 1, 2, 2, 6, 4, 5, 6 };
	int duplications[] = { 2, 6 };
	Test_3_2("Test_3_2_7", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 一个数字重复三次
void Test_3_2_8()
{
	int numbers[] = { 1, 2, 2, 6, 4, 5, 2 };
	int duplications[] = { 2 };
	Test_3_2("Test_3_2_8", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 没有重复的数字
void Test_3_2_9()
{
	int numbers[] = { 1, 2, 6, 4, 5, 3 };
	int duplications[] = { -1 };
	Test_3_2("Test_3_2_9", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 无效的输入
void Test_3_2_10()
{
	int* numbers = nullptr;
	int duplications[] = { -1 };
	Test_3_2("Test_3_2_10", numbers, 0, duplications, sizeof(duplications) / sizeof(int));
}

void offer_3_2_test()
{
	Test_3_2_1();
	Test_3_2_2();
	Test_3_2_3();
	Test_3_2_4();
	Test_3_2_5();
	Test_3_2_6();
	Test_3_2_7();
	Test_3_2_8();
	Test_3_2_9();
	Test_3_2_10();
	
	cout << "offer_3_2 success" << endl;
}