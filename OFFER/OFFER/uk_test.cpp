#include "uk_test.h"


class Solution {
public:
	int MinOrder(vector<int> number, int index1, int index2)
	{
		int result = number[index1];
		for (int i = index1; i <= index2; ++i) {
			if (result > number[i]) {
				result = number[i];
				break;
			}
		}
		return result;
	}


	int minNumberInRotateArray(vector<int> rotateArray) {
		int length = rotateArray.size();
		if (length <= 0)
			return -1;

		int index1 = 0;
		int index2 = length - 1;
		int indexMid = index1;
		while (rotateArray[index1] >= rotateArray[index2])
		{
			if (index2 - index1 == 1) {
				indexMid = index2;
				break;
			}
			indexMid = (index1 + index2) / 2;
			// 应对特殊情况
			if (rotateArray[index1] == rotateArray[indexMid] && rotateArray[indexMid] == rotateArray[index2])
				return MinOrder(rotateArray, index1, index2);

			cout << "index1:" << rotateArray[index1] << "   indexMid:" << rotateArray[indexMid] << "   index2:" << rotateArray[index2] << endl;

			// 注意此处 为了防止 31345 这种情况 比较要加等于 
			// 由于while已经判断index1>=index2 若想下面两个if同时都成立，则需要index1>=indexMid<=index2 则index1==indexMid==index2 的特殊情况
 			if (rotateArray[index1] <= rotateArray[indexMid]) {
				index1 = indexMid;
			}
			else if (rotateArray[index2] >= rotateArray[indexMid]) {
				index2 = indexMid;
			}
		}
		return rotateArray[indexMid];
	}
};

void offer_uk_test()
{
	//int array3[] = { 6501,6828,6963,7036,7422,7674,8146,8468,8704,8717,9170,9359,9719,9895,9896,9913,9962,154,293,334,492,1323,1479,1539,1727,1870,1943,2383,2392,2996,3282,3812,3903,4465,4605,4665,4772,4828,5142,5437,5448,5668,5706,5725,6300,6335 };
	int array3[] = { 3,1,3 };
	vector<int> longmao(array3,array3+sizeof(array3)/sizeof(int));
	Solution so;
	int result = so.minNumberInRotateArray(longmao);
	cout << result << endl;

}