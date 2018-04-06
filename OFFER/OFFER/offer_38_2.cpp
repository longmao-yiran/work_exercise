#include "offer_38_2.h"

/*
	�˻ʺ�����
*/

void ColumnCombination(int columnIndex[], int iBegin, int& result);

void Eight_Queens() 
{
	int columnIndex[8] = { 0,1,2,3,4,5,6,7 };
	int iBegin = 0;
	int result = 0;
	ColumnCombination(columnIndex, iBegin, result);
	cout << "the result is " << result <<endl;
}

void ColumnCombination(int columnIndex[], int iBegin,int& result)
{
	if (columnIndex == nullptr)
		return;

	if (iBegin == 8) {
		for (int i = 0;i < 8;++i) {
			for (int j = i+1;j < 8;++j) {
				if ((i - j) == (columnIndex[i] - columnIndex[j]) || (i - j) == (columnIndex[j] - columnIndex[i]))
					return;
			}
		}
		++result;
	}

	// ע�⣺�����ǰ˻ʺ����� ���鳤�ȿ϶�Ϊ8
	for (int i = iBegin;i < 8;++i) {
		int iTemp = columnIndex[iBegin];
		columnIndex[iBegin] = columnIndex[i];
		columnIndex[i] = iTemp;
		ColumnCombination(columnIndex, iBegin + 1, result);

		iTemp = columnIndex[iBegin];
		columnIndex[iBegin] = columnIndex[i];
		columnIndex[i] = iTemp;
	}
}

void offer_38_2_test()
{
	Eight_Queens();

	cout << "offer_38_2 success" << endl;
}