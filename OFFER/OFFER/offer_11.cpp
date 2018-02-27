#include "offer_11.h"

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
		// Ӧ���������
		if (number[index1] == number[indexMid] && number[indexMid] == number[index2])
			return MinOrder(number,index1,index2);

		if (number[index1] < number[indexMid]) {
			index1 = indexMid;
		}
		if (number[index1] > number[indexMid]) {
			index2 = indexMid;
		}
	}
	return number[indexMid];
}


// ====================���Դ���====================
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

// �������룬��������������һ����ת
void Test_11_1()
{
	int array1[] = { 3, 4, 5, 1, 2 };
	Test_11(array1, sizeof(array1) / sizeof(int), 1);
}

// ���ظ����֣������ظ������ָպõ���С������
void Test_11_2()
{
	int array2[] = { 3, 4, 5, 1, 1, 2 };
	Test_11(array2, sizeof(array2) / sizeof(int), 1);
}

// ���ظ����֣����ظ������ֲ��ǵ�һ�����ֺ����һ������
void Test_11_3()
{
	int array3[] = { 3, 4, 5, 1, 2, 2 };
	Test_11(array3, sizeof(array3) / sizeof(int), 1);
}

// ���ظ������֣������ظ������ָպ��ǵ�һ�����ֺ����һ������
void Test_11_4()
{
	int array4[] = { 1, 0, 1, 1, 1 };
	Test_11(array4, sizeof(array4) / sizeof(int), 0);
}

// �����������飬��ת0��Ԫ�أ�Ҳ���ǵ����������鱾��
void Test_11_5()
{
	int array5[] = { 1, 2, 3, 4, 5 };
	Test_11(array5, sizeof(array5) / sizeof(int), 1);
}

// ������ֻ��һ������
void Test_11_6()
{
	int array6[] = { 2 };
	Test_11(array6, sizeof(array6) / sizeof(int), 2);
}

// ����nullptr
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
}