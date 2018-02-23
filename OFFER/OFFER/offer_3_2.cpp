#include "offer_3_2.h"

/*
	��һ������Ϊn+1����������������ֶ���1��n�ķ�Χ�ڣ�������������
	����һ���������ظ��ġ����ҳ�����������һ���ظ������֣��������޸������
	���顣���磬������볤��Ϊ8������{2, 3, 5, 4, 3, 2, 6, 7}����ô��Ӧ��
	������ظ�������2����3��
*/

// Ҫ���ܸı����� ��򵥵Ŀ��Կ��ٳ���Ϊn�ĸ���������
// �������ƶ��ַ���˼·��������ظ��� ��Χ��1~x�����ֳ��ֵĴ�������x
// �ǵݹ�ʵ��

int countRange(const int numbers[], int length, int start, int end) 
{
	// �ж��Ƿ�Ϊ��Ч���루��ָ�룬���ֳ�����Χ��
	if (numbers == nullptr || length <= 0 || start < 0 || end >= length)
		return 0;
	int count = 0;
	for (int i = 0;i < length;++i) {
		if (numbers[i] >= start && numbers[i] <= end)
			++count;
	}

	return count;
}

int getDuplication(const int numbers[], int length)		// ע�����ڲ��ܸı� ��������const��ֹ���ı�
{
	// �ж��Ƿ�Ϊ��Ч���루��ָ�룬���ֳ�����Χ��
	if (numbers == nullptr || length <= 0)
		return -1;

	for (int i = 0;i < length;++i) {
		if (numbers[i] <= 0 || numbers[i] > length)
			return -1;
	}
	int start = 1, end = length - 1;
	int middle = (start + end) / 2;
	int count = 0;
	while (start <= end)						// ע���˴���ֹ
	{
		count = countRange(numbers, length, start, middle);
		// ���ִ�����������
		if (count > (middle - start + 1)) {
			if (start == middle) {
				return middle;
			}
			end = middle;
			middle = (start + middle) / 2;
		}
		// ��������
		else {
			start = middle+1;
			middle = end;
		}
	}
	return -1;
}

// ��ָoffer�汾
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

// ====================���Դ���====================
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

// ����ظ�������
void Test_3_2_1()
{
	int numbers[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	int duplications[] = { 2, 3 };
	Test_3_2("Test_3_2_1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// һ���ظ�������
void Test_3_2_2()
{
	int numbers[] = { 3, 2, 1, 4, 4, 5, 6, 7 };
	int duplications[] = { 4 };
	Test_3_2("Test_3_2_2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// �ظ�����������������С������
void Test_3_2_3()
{
	int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 1, 8 };
	int duplications[] = { 1 };
	Test_3_2("Test_3_2_3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// �ظ�����������������������
void Test_3_2_4()
{
	int numbers[] = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };
	int duplications[] = { 8 };
	Test_3_2("Test_3_2_4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// ������ֻ����������
void Test_3_2_5()
{
	int numbers[] = { 1, 1 };
	int duplications[] = { 1 };
	Test_3_2("Test_3_2_5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// �ظ�������λ�����鵱��
void Test_3_2_6()
{
	int numbers[] = { 3, 2, 1, 3, 4, 5, 6, 7 };
	int duplications[] = { 3 };
	Test_3_2("Test_3_2_6", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// ����ظ�������
void Test_3_2_7()
{
	int numbers[] = { 1, 2, 2, 6, 4, 5, 6 };
	int duplications[] = { 2, 6 };
	Test_3_2("Test_3_2_7", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// һ�������ظ�����
void Test_3_2_8()
{
	int numbers[] = { 1, 2, 2, 6, 4, 5, 2 };
	int duplications[] = { 2 };
	Test_3_2("Test_3_2_8", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// û���ظ�������
void Test_3_2_9()
{
	int numbers[] = { 1, 2, 6, 4, 5, 3 };
	int duplications[] = { -1 };
	Test_3_2("Test_3_2_9", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// ��Ч������
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