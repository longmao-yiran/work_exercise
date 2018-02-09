#include "offer_4.h"

/*
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

void offer_4_test()
{
	int matrix[] = { 1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15 };
	bool result = false;

	result = Find(nullptr, 4, 4, 7);
	result = Find(nullptr, -1, 4, 7);
	result = Find(nullptr, 4, -1, 7);

	result = Find(matrix, 4, 4, 7);
	result = Find(matrix, 4, 4, 3);

	cout << "offer_4 success" << endl;
}