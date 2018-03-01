#include "offer_14.h"

/*
	������
	����һ������Ϊn�����ӣ�������Ӽ���m�� (m��n����������n>1����m>1)ÿ�����ӵĳ��ȼ�Ϊk[0],k[1],...,k[m]��
	����k[0]*k[1]*...*k[m]���ܵ����˻��Ƕ��٣�
	���磬�����ӵĳ���Ϊ8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2,3,3�����Σ���ʱ�õ������˻���18.
*/

// ��̬�滮
int maxProductAfterCutting_solution1(int length) 
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	// �����ʼ�ļ�������
	int *products = new int[length + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	for (int i = 4; i <= length; ++i) {
		int max = 0;
		for (int j = 1; j <= (i / 2); ++j) {
			if (max < products[j] * products[i - j])
				max = products[j] * products[i - j];
		}
		products[i] = max;
	}
	int result = products[length];
	delete[] products;
	return result;

}

// ̰���㷨
int maxProductAfterCutting_solution2(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int timesOf3 = length / 3;
	if (length % 3 == 1)
		timesOf3 -= 1;

	int timesOf2 = (length - timesOf3 * 3) / 2;
	
	int result = pow(3, timesOf3) * pow(2, timesOf2);
	return result;
}

// ====================���Դ���====================
void Test_14(const char* testName, int length, int expected)
{
	int result1 = maxProductAfterCutting_solution1(length);
	if (result1 == expected)
		std::cout << "Solution1 for " << testName << " passed." << std::endl;
	else
		std::cout << "Solution1 for " << testName << " FAILED." << std::endl;

	int result2 = maxProductAfterCutting_solution2(length);
	if (result2 == expected)
		std::cout << "Solution2 for " << testName << " passed." << std::endl;
	else
		std::cout << "Solution2 for " << testName << " FAILED." << std::endl;
}

void Test_14_1()
{
	int length = 1;
	int expected = 0;
	Test_14("Test_14_1", length, expected);
}

void Test_14_2()
{
	int length = 2;
	int expected = 1;
	Test_14("Test_14_2", length, expected);
}

void Test_14_3()
{
	int length = 3;
	int expected = 2;
	Test_14("Test_14_3", length, expected);
}

void Test_14_4()
{
	int length = 4;
	int expected = 4;
	Test_14("Test_14_4", length, expected);
}

void Test_14_5()
{
	int length = 5;
	int expected = 6;
	Test_14("Test_14_5", length, expected);
}

void Test_14_6()
{
	int length = 6;
	int expected = 9;
	Test_14("Test_14_6", length, expected);
}

void Test_14_7()
{
	int length = 7;
	int expected = 12;
	Test_14("Test_14_7", length, expected);
}

void Test_14_8()
{
	int length = 8;
	int expected = 18;
	Test_14("Test_14_8", length, expected);
}

void Test_14_9()
{
	int length = 9;
	int expected = 27;
	Test_14("Test_14_9", length, expected);
}

void Test_14_10()
{
	int length = 10;
	int expected = 36;
	Test_14("Test_14_10", length, expected);
}

void Test_14_11()
{
	int length = 50;
	int expected = 86093442;
	Test_14("Test_14_11", length, expected);
}

void offer_14_test()
{
	Test_14_1();
	Test_14_2();
	Test_14_3();
	Test_14_4();
	Test_14_5();
	Test_14_6();
	Test_14_7();
	Test_14_8();
	Test_14_9();
	Test_14_10();
	Test_14_11();

	cout << "offer_14 success" << endl;
}