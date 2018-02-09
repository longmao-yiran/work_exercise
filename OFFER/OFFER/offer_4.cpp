#include "offer_4.h"

/*
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