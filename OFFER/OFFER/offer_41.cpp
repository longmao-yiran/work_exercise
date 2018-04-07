#include "offer_41.h"

/*
	数据流中的中位数
	如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
	那么中位数就是所有数值排序之后位于中间的数值。
	如果从数据流中读出偶数个数值，
	那么中位数就是所有数值排序之后中间两个数的平均值。
*/

template<typename T> class DynamicArray_41
{
private:
	vector<T> min;
	vector<T> max;
public:
	void Insert(T num) {
		if (((min.size() + max.size()) & 1) == 0) {				// 第偶数个数字放在最大堆，奇数个数字放在最小堆
			// 放入最小堆
			if (max.size() > 0 && num < max[0]) {
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<T>());

				num = max[0];

				pop_heap(max.begin(), max.end(), less<T>());
				max.pop_back();
			}
			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<T>());
		}
		else {
			if (min.size() > 0 && num > min[0]) {
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<T>());

				num = min[0];

				pop_heap(min.begin(), min.end(), greater<T>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<T>());
		}
	}

	T GetMedian()
	{
		int size = min.size() + max.size();
		if (size == 0)
			throw exception("No numbers are available");

		T median = 0;
		if ((size & 1) == 1)
			median = min[0];
		else
			median = (min[0] + max[0]) / 2;

		return median;
	}
};

// ====================测试代码====================
void Test_41(char* testName, DynamicArray_41<double>& numbers, double expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (abs(numbers.GetMedian() - expected) < 0.0000001)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

void offer_41_test()
{
	DynamicArray_41<double> numbers;

	printf("Test_41_1 begins: ");
	try
	{
		numbers.GetMedian();
		printf("FAILED.\n");
	}
	catch (const exception&)
	{
		printf("Passed.\n");
	}

	numbers.Insert(5);
	Test_41("Test_41_2", numbers, 5);

	numbers.Insert(2);
	Test_41("Test_41_3", numbers, 3.5);

	numbers.Insert(3);
	Test_41("Test_41_4", numbers, 3);

	numbers.Insert(4);
	Test_41("Test_41_6", numbers, 3.5);

	numbers.Insert(1);
	Test_41("Test_41_5", numbers, 3);

	numbers.Insert(6);
	Test_41("Test_41_7", numbers, 3.5);

	numbers.Insert(7);
	Test_41("Test_41_8", numbers, 4);

	numbers.Insert(0);
	Test_41("Test_41_9", numbers, 3.5);

	numbers.Insert(8);
	Test_41("Test_41_10", numbers, 4);

	cout << "offer_41 success" << endl;
}

// 牛客网 ac
/*
class Solution {
public:
    vector<int> min;
	vector<int> max;
    void Insert(int num)
    {
        if (((min.size() + max.size()) & 1) == 0) {				// 第偶数个数字放在最大堆，奇数个数字放在最小堆
			// 放入最小堆
			if (max.size() > 0 && num < max[0]) {
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<int>());

				num = max[0];

				pop_heap(max.begin(), max.end(), less<int>());
				max.pop_back();
			}
			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<int>());
		}
		else {
			if (min.size() > 0 && num > min[0]) {
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<int>());

				num = min[0];

				pop_heap(min.begin(), min.end(), greater<int>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<int>());
		}
    }

    double GetMedian()
    { 
        int size = min.size() + max.size();
		if (size == 0)
			return 0;

		double median = 0;
		if ((size & 1) == 1)
			median = min[0];
		else
			median = (double(min[0]) + double(max[0])) / 2;

		return median;
    }

};
*/