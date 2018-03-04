#include "offer_3.h"

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

bool duplicate2(const int numbers[], int length, int *duplication)		// 注意由于不能改变 因此数组加const防止被改变
{
	// 判断是否为无效输入（空指针，数字超出范围）
	if (numbers == nullptr || length <= 0)
		return false;

	for (int i = 0;i < length;++i) {
		if (numbers[i] < 0 || numbers[i] >= length)
			return false;
	}
	int start = 0, end = length - 1;
	int middle = (start + end) / 2;
	int count = 0;
	while (start <= end)						// 注：此处防止
	{
		count = countRange(numbers, length, start, middle);
		// 出现次数大于区间
		if (count > (middle - start + 1)) {
			if (start == middle) {
				*duplication = middle;
				return true;
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
	return false;
}



void offer_3_test()
{
	bool resunt = false;
	int duplication = -1;
	// 无效输入
	int test_num[] = { 2,3,1,0,2,10,3 };
	int len = sizeof(test_num) / 4;						// 32位系统 sizeof(int) = 4
	resunt = duplicate(nullptr, len, &duplication);
	resunt = duplicate(test_num, -1, &duplication);
	resunt = duplicate(test_num, len, &duplication);
	resunt = duplicate2(nullptr, len, &duplication);
	resunt = duplicate2(test_num, -1, &duplication);
	resunt = duplicate2(test_num, len, &duplication);

	// 有重复
	int test_num1[] = { 2,3,1,0,2,5,3 };
	int len1 = sizeof(test_num1) / 4;
	resunt = duplicate(test_num1, len1, &duplication);
	resunt = duplicate2(test_num1, len1, &duplication);

	// 无重复
	int test_num2[] = { 2,3,1,4,6,5,0};
	int len2 = sizeof(test_num2) / 4;
	resunt = duplicate(test_num2, len2, &duplication);
	resunt = duplicate2(test_num2, len2, &duplication);


	cout << "offer_3 success" << endl;
}