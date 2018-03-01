#include "offer_4.h"

/*
	��ά�����еĲ���
	��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������
	ÿһ�ж����մ��ϵ��µ�����˳�����������һ��������
	����������һ����ά�����һ���������ж��������Ƿ��и�������
*/
// �����Ͻǿ�ʼ ������������ ���������²� ����������С ������һ�����
bool Find(int* matrix, int rows, int columns, int number)
{
	// �����ж�
	if (matrix == nullptr || rows < 0 || columns < 0)
		return false;
	int row_tmp = 0;
	int col_tmp = columns - 1;
	while (row_tmp<rows && col_tmp >= 0){
		if (matrix[row_tmp*columns + col_tmp] == number)
			return true;
		if (matrix[row_tmp*columns + col_tmp] > number)
			--col_tmp;
		else
			++row_tmp;
	}
	return false;
}
// ţ�����ӿ� ac
bool Find(int target, vector<vector<int> > array) {
	// �����ж�
	int rows = array.size();
	int columns = array[0].size();
	int row_tmp = 0;
	int col_tmp = columns - 1;
	while (row_tmp<rows && col_tmp >= 0) {
		if (array[row_tmp][col_tmp] == target)
			return true;
		if (array[row_tmp][col_tmp] > target)
			--col_tmp;
		else
			++row_tmp;
	}
	return false;
}

// ====================���Դ���====================
void Test_4(char* testName, int* matrix, int rows, int columns, int number, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	bool result = Find(matrix, rows, columns, number);
	if (result == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�����������
void Test_4_1()
{
	int matrix[][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	Test_4("Test_4_1", (int*)matrix, 4, 4, 7, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������
void Test_4_2()
{
	int matrix[][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	Test_4("Test_4_2", (int*)matrix, 4, 4, 5, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������С������
void Test_4_3()
{
	int matrix[][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	Test_4("Test_4_3", (int*)matrix, 4, 4, 1, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������������
void Test_4_4()
{
	int matrix[][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	Test_4("Test_4_4", (int*)matrix, 4, 4, 15, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������С�����ֻ�С
void Test_4_5()
{
	int matrix[][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	Test_4("Test_4_5", (int*)matrix, 4, 4, 0, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ������������������ֻ���
void Test_4_6()
{
	int matrix[][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	Test_4("Test_4_6", (int*)matrix, 4, 4, 16, false);
}

// ³���Բ��ԣ������ָ��
void Test_4_7()
{
	Test_4("Test_4_7", nullptr, 0, 0, 16, false);
}

void offer_4_test()
{
	Test_4_1();
	Test_4_2();
	Test_4_3();
	Test_4_4();
	Test_4_5();
	Test_4_6();
	Test_4_7();
	cout << "offer_4 success" << endl;
}

// ţ���� ac
/*
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
	int rows = array.size();
	int columns = array[0].size();
	int row_tmp = 0;
	int col_tmp = columns - 1;
	while (row_tmp<rows && col_tmp >= 0) {
		if (array[row_tmp][col_tmp] == target)
			return true;
		if (array[row_tmp][col_tmp] > target)
			--col_tmp;
		else
			++row_tmp;
	}
	return false;
    }
};
*/