#include "offer_39.h"
#include "Utilities\Array.h"


bool CheckInvalidArray(int* numbers, int length) 
{
	if (numbers == nullptr || length <= 0)
		return true;
	return false;
}


bool CheckMoreThanHalf(int* numbers, int length, int number)
{
	int times = 0;
	for (int i = 0;i < length;++i) {
		if (numbers[i] == number)
			++times;
	}
	if (times * 2 <= length)
		return false;
	return true;
}

int MoreThanHalfNum_Solution1(int* numbers, int length)
{
	int A[] = { 3,2,1,4,5,6,10,8,9 };
	int longmao = Partition(A, 9, 0, 8);
	return 0;
}

void offer_39_test()
{
	int A[] = { 3,2,1,4,5,6,10,8,9 };
	MoreThanHalfNum_Solution1(A, 9);
}