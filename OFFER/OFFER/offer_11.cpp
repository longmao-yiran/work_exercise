#include "offer_11.h"

/*
	旋转数组
	把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
	输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
	例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
	NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/

int MinOrder(int number[], int index1, int index2);

int Min(int number[], int length)
{
	if (number == nullptr || length <=0)
		throw new std::exception("Invalid parameters");

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while (number[index1]>= number[index2])
	{
		if (index2 - index1 == 1) {
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2) / 2;
		// 应对特殊情况
		if (number[index1] == number[indexMid] && number[indexMid] == number[index2])
			return MinOrder(number,index1,index2);

		// 注意此处 为了防止 31345 这种情况 比较要加等于 
		// 由于while已经判断index1>=index2 若想下面两个if同时都成立，则需要index1>=indexMid<=index2 则index1==indexMid==index2 的特殊情况
		if (number[index1] <= number[indexMid]) {
			index1 = indexMid;
		}
		else if (number[index2] >= number[indexMid]) {
			index2 = indexMid;
		}
	}
	return number[indexMid];
}

int MinOrder(int number[], int index1, int index2)
{
	int result = number[index1];
	for (int i = index1; i <= index2; ++i) {
		if (result > number[i]) {
			result = number[i];
			break;
		}
	}
	return result;
}

// ====================测试代码====================
void Test_11(int* numbers, int length, int expected)
{
	int result = 0;
	try
	{
		result = Min(numbers, length);

		for (int i = 0; i < length; ++i)
			printf("%d ", numbers[i]);

		if (result == expected)
			printf("\tpassed\n");
		else
			printf("\tfailed\n");
	}
	catch (...)
	{
		if (numbers == nullptr)
			printf("Test passed.\n");
		else
			printf("Test failed.\n");
	}
}

// 典型输入，单调升序的数组的一个旋转
void Test_11_1()
{
	int array1[] = { 3, 4, 5, 1, 2 };
	Test_11(array1, sizeof(array1) / sizeof(int), 1);
}

// 有重复数字，并且重复的数字刚好的最小的数字
void Test_11_2()
{
	int array2[] = { 3, 4, 5, 1, 1, 2 };
	Test_11(array2, sizeof(array2) / sizeof(int), 1);
}

// 有重复数字，但重复的数字不是第一个数字和最后一个数字
void Test_11_3()
{
	int array3[] = { 3, 4, 5, 1, 2, 2 };
	Test_11(array3, sizeof(array3) / sizeof(int), 1);
}

// 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
void Test_11_4()
{
	int array4[] = { 1, 0, 1, 1, 1 };
	Test_11(array4, sizeof(array4) / sizeof(int), 0);
}

// 单调升序数组，旋转0个元素，也就是单调升序数组本身
void Test_11_5()
{
	int array5[] = { 1, 2, 3, 4, 5 };
	Test_11(array5, sizeof(array5) / sizeof(int), 1);
}

// 数组中只有一个数字
void Test_11_6()
{
	int array6[] = { 2 };
	Test_11(array6, sizeof(array6) / sizeof(int), 2);
}

// 输入nullptr
void Test_11_7()
{
	Test_11(nullptr, 0, 0);
}


void offer_11_test()
{
	Test_11_1();
	Test_11_2();
	Test_11_3();
	Test_11_4();
	Test_11_5();
	Test_11_6();
	Test_11_7();

	cout << "offer_11 success" << endl;
}

// 牛客网 ac
/*
class Solution {
public:
	int MinOrder(vector<int> number, int index1, int index2)
	{
		int result = number[index1];
		for (int i = index1; i <= index2; ++i) {
			if (result > number[i]) {
				result = number[i];
				break;
			}
		}
		return result;
	}


	int minNumberInRotateArray(vector<int> rotateArray) {
		int length = rotateArray.size();
		if (length <= 0)
			return 0;

		int index1 = 0;
		int index2 = length - 1;
		int indexMid = index1;
		while (rotateArray[index1] >= rotateArray[index2])
		{
			if (index2 - index1 == 1) {
				indexMid = index2;
				break;
			}
			indexMid = (index1 + index2) / 2;
			// 应对特殊情况
			if (rotateArray[index1] == rotateArray[indexMid] && rotateArray[indexMid] == rotateArray[index2])
				return MinOrder(rotateArray, index1, index2);

			if (rotateArray[index1] <= rotateArray[indexMid]) {
				index1 = indexMid;
			}
			if (rotateArray[index2] >= rotateArray[indexMid]) {
				index2 = indexMid;
			}
		}
		return rotateArray[indexMid];
	}
};
*/