#include "offer_3_1.h"

/*
	在一个长度为n的数组里的所有数字都在0到n - 1的范围内。
	数组中某些数字是重复的，但不知道有几个数字是重复的。
	也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
	例如，如果输入长度为7的数组{ 2,3,1,0,2,5,3 }，那么对应的输出是第一个重复的数字2。
*/

// 时间复杂度为O（n） 空间复杂度为1  
// 注：如果采用hashmap 则空间复杂度大于1 时间复杂度为O（n）
bool duplicate(int numbers[], int length, int *duplication)
{
	// 判断是否为无效输入（空指针，数字超出范围）
	if (numbers == nullptr || length <= 0)
		return false;
	
	for (int i = 0;i < length;++i) {
		if (numbers[i] < 0 || numbers[i] >= length)
			return false;
	}

	// 第一重循环 扫描整个数组
	for (int i = 0;i < length;++i) {
		// 第二重循环 通过位置交换，使得第i个数为i
		while (numbers[i] != i)
		{
			int int_tmp = numbers[i];
			// 如果int_tmp上的数字也是int_tmp证明该位置有两个数字 则重复 否则则进行交换 直到第i个位置为i  
			// 注：这种交换使得每个位置的数字最多交换两次（一次到i 一次到正确位置）就能到正确的位置 
			if (int_tmp == numbers[int_tmp]) {
				*duplication = int_tmp;
				return true;
			}
			// 进行交换
			numbers[i] = numbers[int_tmp];
			numbers[int_tmp] = int_tmp;
			// 帮助查看输出代码
			//for (int j = 0;j < length;++j)
			//	cout << numbers[j] << "\t";
			//cout << endl;
		}
	}
	return false;
}

// ====================测试代码====================
bool contains(int array[], int length, int number)
{
	for (int i = 0; i < length; ++i)
	{
		if (array[i] == number)
			return true;
	}

	return false;
}

void Test_3_1(char* Test_3_1_Name, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
	printf("%s begins: ", Test_3_1_Name);

	int duplication;
	bool validInput = duplicate(numbers, lengthNumbers, &duplication);

	if (validArgument == validInput)
	{
		if (validArgument)
		{
			if (contains(expected, expectedExpected, duplication))
				printf("Passed.\n");
			else
				printf("FAILED.\n");
		}
		else
			printf("Passed.\n");
	}
	else
		printf("FAILED.\n");
}

// 重复的数字是数组中最小的数字
void Test_3_1_1()
{
	int numbers[] = { 2, 1, 3, 1, 4 };
	int duplications[] = { 1 };
	Test_3_1("Test_3_1_1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 重复的数字是数组中最大的数字
void Test_3_1_2()
{
	int numbers[] = { 2, 4, 3, 1, 4 };
	int duplications[] = { 4 };
	Test_3_1("Test_3_1_2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 数组中存在多个重复的数字
void Test_3_1_3()
{
	int numbers[] = { 2, 4, 2, 1, 4 };
	int duplications[] = { 2, 4 };
	Test_3_1("Test_3_1_3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 没有重复的数字
void Test_3_1_4()
{
	int numbers[] = { 2, 1, 3, 0, 4 };
	int duplications[] = { -1 }; // not in use in the Test_3_1_ function
	Test_3_1("Test_3_1_4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 没有重复的数字
void Test_3_1_5()
{
	int numbers[] = { 2, 1, 3, 5, 4 };
	int duplications[] = { -1 }; // not in use in the Test_3_1_ function
	Test_3_1("Test_3_1_5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void Test_3_1_6()
{
	int* numbers = nullptr;
	int duplications[] = { -1 }; // not in use in the Test_3_1_ function
	Test_3_1("Test_3_1_6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}


void offer_3_1_test()
{
	Test_3_1_1();
	Test_3_1_2();
	Test_3_1_3();
	Test_3_1_4();
	Test_3_1_5();
	Test_3_1_6();
	cout << "offer_3_1 success" << endl;
}