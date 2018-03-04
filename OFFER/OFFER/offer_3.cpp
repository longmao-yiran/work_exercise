#include "offer_3.h"

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

bool duplicate2(const int numbers[], int length, int *duplication)		// ע�����ڲ��ܸı� ��������const��ֹ���ı�
{
	// �ж��Ƿ�Ϊ��Ч���루��ָ�룬���ֳ�����Χ��
	if (numbers == nullptr || length <= 0)
		return false;

	for (int i = 0;i < length;++i) {
		if (numbers[i] < 0 || numbers[i] >= length)
			return false;
	}
	int start = 0, end = length - 1;
	int middle = (start + end) / 2;
	int count = 0;
	while (start <= end)						// ע���˴���ֹ
	{
		count = countRange(numbers, length, start, middle);
		// ���ִ�����������
		if (count > (middle - start + 1)) {
			if (start == middle) {
				*duplication = middle;
				return true;
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
	return false;
}



void offer_3_test()
{
	bool resunt = false;
	int duplication = -1;
	// ��Ч����
	int test_num[] = { 2,3,1,0,2,10,3 };
	int len = sizeof(test_num) / 4;						// 32λϵͳ sizeof(int) = 4
	resunt = duplicate(nullptr, len, &duplication);
	resunt = duplicate(test_num, -1, &duplication);
	resunt = duplicate(test_num, len, &duplication);
	resunt = duplicate2(nullptr, len, &duplication);
	resunt = duplicate2(test_num, -1, &duplication);
	resunt = duplicate2(test_num, len, &duplication);

	// ���ظ�
	int test_num1[] = { 2,3,1,0,2,5,3 };
	int len1 = sizeof(test_num1) / 4;
	resunt = duplicate(test_num1, len1, &duplication);
	resunt = duplicate2(test_num1, len1, &duplication);

	// ���ظ�
	int test_num2[] = { 2,3,1,4,6,5,0};
	int len2 = sizeof(test_num2) / 4;
	resunt = duplicate(test_num2, len2, &duplication);
	resunt = duplicate2(test_num2, len2, &duplication);


	cout << "offer_3 success" << endl;
}