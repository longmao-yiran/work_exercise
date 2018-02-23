#include "offer_3_1.h"

/*
	��һ������Ϊn����������������ֶ���0��n - 1�ķ�Χ�ڡ�
	������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�
	Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡� 
	���磬������볤��Ϊ7������{ 2,3,1,0,2,5,3 }����ô��Ӧ������ǵ�һ���ظ�������2��
*/

// ʱ�临�Ӷ�ΪO��n�� �ռ临�Ӷ�Ϊ1  
// ע���������hashmap ��ռ临�Ӷȴ���1 ʱ�临�Ӷ�ΪO��n��
bool duplicate(int numbers[], int length, int *duplication)
{
	// �ж��Ƿ�Ϊ��Ч���루��ָ�룬���ֳ�����Χ��
	if (numbers == nullptr || length <= 0)
		return false;
	
	for (int i = 0;i < length;++i) {
		if (numbers[i] < 0 || numbers[i] >= length)
			return false;
	}

	// ��һ��ѭ�� ɨ����������
	for (int i = 0;i < length;++i) {
		// �ڶ���ѭ�� ͨ��λ�ý�����ʹ�õ�i����Ϊi
		while (numbers[i] != i)
		{
			int int_tmp = numbers[i];
			// ���int_tmp�ϵ�����Ҳ��int_tmp֤����λ������������ ���ظ� ��������н��� ֱ����i��λ��Ϊi  
			// ע�����ֽ���ʹ��ÿ��λ�õ�������ཻ�����Σ�һ�ε�i һ�ε���ȷλ�ã����ܵ���ȷ��λ�� 
			if (int_tmp == numbers[int_tmp]) {
				*duplication = int_tmp;
				return true;
			}
			// ���н���
			numbers[i] = numbers[int_tmp];
			numbers[int_tmp] = int_tmp;
			// �����鿴�������
			//for (int j = 0;j < length;++j)
			//	cout << numbers[j] << "\t";
			//cout << endl;
		}
	}
	return false;
}

// ====================���Դ���====================
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

// �ظ�����������������С������
void Test_3_1_1()
{
	int numbers[] = { 2, 1, 3, 1, 4 };
	int duplications[] = { 1 };
	Test_3_1("Test_3_1_1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// �ظ�����������������������
void Test_3_1_2()
{
	int numbers[] = { 2, 4, 3, 1, 4 };
	int duplications[] = { 4 };
	Test_3_1("Test_3_1_2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// �����д��ڶ���ظ�������
void Test_3_1_3()
{
	int numbers[] = { 2, 4, 2, 1, 4 };
	int duplications[] = { 2, 4 };
	Test_3_1("Test_3_1_3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// û���ظ�������
void Test_3_1_4()
{
	int numbers[] = { 2, 1, 3, 0, 4 };
	int duplications[] = { -1 }; // not in use in the Test_3_1_ function
	Test_3_1("Test_3_1_4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// û���ظ�������
void Test_3_1_5()
{
	int numbers[] = { 2, 1, 3, 5, 4 };
	int duplications[] = { -1 }; // not in use in the Test_3_1_ function
	Test_3_1("Test_3_1_5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// ��Ч������
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