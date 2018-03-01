#include "offer_4.h"

/*
	二维数组中的查找
	在一个二维数组中，每一行都按照从左到右递增的顺序排序，
	每一列都按照从上到下递增的顺序排序。请完成一个函数，
	输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/
// 从右上角开始 如果比这个数大 则在这行下侧 如果比这个数小 则在这一列左侧
bool Find(int* matrix, int rows, int columns, int number)
{
	// 输入判断
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
// 牛客网接口 ac
bool Find(int target, vector<vector<int> > array) {
	// 输入判断
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

// ====================测试代码====================
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
// 要查找的数在数组中
void Test_4_1()
{
	int matrix[][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	Test_4("Test_4_1", (int*)matrix, 4, 4, 7, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数不在数组中
void Test_4_2()
{
	int matrix[][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	Test_4("Test_4_2", (int*)matrix, 4, 4, 5, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最小的数字
void Test_4_3()
{
	int matrix[][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	Test_4("Test_4_3", (int*)matrix, 4, 4, 1, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最大的数字
void Test_4_4()
{
	int matrix[][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	Test_4("Test_4_4", (int*)matrix, 4, 4, 15, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最小的数字还小
void Test_4_5()
{
	int matrix[][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	Test_4("Test_4_5", (int*)matrix, 4, 4, 0, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最大的数字还大
void Test_4_6()
{
	int matrix[][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	Test_4("Test_4_6", (int*)matrix, 4, 4, 16, false);
}

// 鲁棒性测试，输入空指针
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

// 牛客网 ac
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