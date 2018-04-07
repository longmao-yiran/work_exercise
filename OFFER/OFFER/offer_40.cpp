#include "offer_40.h"
#include "Utilities\Array.h"

/*
	最小的K个数
	输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/

void GetLeastNumbers_Solution1(int* input, int n, int* output, int k)
{
	if (input == nullptr | output == nullptr || n <= 0 || k <= 0 || k>n)
		return;

	int start = 0;
	int end = n - 1;
	int index = Partition_longmao(input, n, start, end);
	while (index != k -1){
		if (index < k -1) {
			start = index + 1;
			index = Partition_longmao(input, n, start, end);
		}
		else{
			end = index - 1;
			index = Partition_longmao(input, n, start, end);
		}
	}
	for (int i = 0;i < k;++i)
		output[i] = input[i];
}

typedef multiset<int, std::greater<int> >            intSet;
typedef multiset<int, std::greater<int> >::iterator  setIterator;
void GetLeastNumbers_Solution2(const vector<int>& data, intSet& leastNumbers, int k) {
	if (k <= 0 || data.size() < k)
		return;
	vector<int>::const_iterator iter = data.begin();
	leastNumbers.clear();
	for (;iter != data.end();iter++) {
		if (leastNumbers.size() < k) {
			leastNumbers.insert(*iter);
		}
		else{
			setIterator iterGreatest = leastNumbers.begin();
			if (*iter <= *iterGreatest) {
				leastNumbers.erase(iterGreatest);
				leastNumbers.insert(*iter);
			}
		}
	}
}

struct  compare_40
{
	bool operator()(const int &i1, const int &i2) const {
		if (i1 > i2)
			return false;
		return true;
	}
};

void GetLeastNumbers_Solution3(vector<int> input, int k) {
	multiset<int, compare_40> leastNumbers;
	vector<int> result;
	if (k <= 0 || input.size() < k)
		return ;
	vector<int>::const_iterator iter = input.begin();
	multiset<int, compare_40>::iterator iterGreatest = leastNumbers.begin();
	leastNumbers.clear();
	for (;iter != input.end();iter++) {
		if (leastNumbers.size() < k) {
			leastNumbers.insert(*iter);
		}
		else {
			iterGreatest = leastNumbers.begin();
			if (*iter >= *iterGreatest) {
				leastNumbers.erase(iterGreatest);
				leastNumbers.insert(*iter);
			}
		}
	}
	iterGreatest = leastNumbers.begin();
	for (;iterGreatest != leastNumbers.end();iterGreatest++) {
		result.push_back(*iterGreatest);
	}
	return;
}

// ====================测试代码====================
void Test_40(char* testName, int* data, int n, int* expectedResult, int k)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	vector<int> vectorData;
	for (int i = 0; i < n; ++i)
		vectorData.push_back(data[i]);

	if (expectedResult == nullptr)
		printf("The input is invalid, we don't expect any result.\n");
	else
	{
		printf("Expected result: \n");
		for (int i = 0; i < k; ++i)
			printf("%d\t", expectedResult[i]);
		printf("\n");
	}

	printf("Result for solution1:\n");
	int* output = new int[k];
	GetLeastNumbers_Solution1(data, n, output, k);
	if (expectedResult != nullptr)
	{
		for (int i = 0; i < k; ++i)
			printf("%d\t", output[i]);
		printf("\n");
	}

	delete[] output;

	printf("Result for solution2:\n");
	intSet leastNumbers;
	GetLeastNumbers_Solution2(vectorData, leastNumbers, k);
	GetLeastNumbers_Solution3(vectorData, k);
	printf("The actual output numbers are:\n");
	for (setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); ++iter)
		printf("%d\t", *iter);
	printf("\n\n");
}

// k小于数组的长度
void Test_40_1()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int expected[] = { 1, 2, 3, 4 };
	Test_40("Test_40_1", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k等于数组的长度
void Test_40_2()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int expected[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	Test_40("Test_40_2", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k大于数组的长度
void Test_40_3()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int* expected = nullptr;
	Test_40("Test_40_3", data, sizeof(data) / sizeof(int), expected, 10);
}

// k等于1
void Test_40_4()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int expected[] = { 1 };
	Test_40("Test_40_4", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// k等于0
void Test_40_5()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	int* expected = nullptr;
	Test_40("Test_40_5", data, sizeof(data) / sizeof(int), expected, 0);
}

// 数组中有相同的数字
void Test_40_6()
{
	int data[] = { 4, 5, 1, 6, 2, 7, 2, 8 };
	int expected[] = { 1, 2 };
	Test_40("Test_40_6", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

// 输入空指针
void Test_40_7()
{
	int* expected = nullptr;
	Test_40("Test_40_7", nullptr, 0, expected, 0);
}

void offer_40_test()
{
	Test_40_1();
	Test_40_2();
	Test_40_3();
	Test_40_4();
	Test_40_5();
	Test_40_6();
	Test_40_7();

	cout << "offer_40 success" << endl;
}

// 牛客网ac
/*
class Solution {
public:
    typedef multiset<int, std::greater<int> >            intSet;
    typedef multiset<int, std::greater<int> >::iterator  setIterator;
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        intSet leastNumbers;
        vector<int> result;
        if (k <= 0 || input.size() < k)
            return result;
        vector<int>::const_iterator iter = input.begin();
        setIterator iterGreatest = leastNumbers.begin();
        leastNumbers.clear();
        for (;iter != input.end();iter++) {
            if (leastNumbers.size() < k) {
                leastNumbers.insert(*iter);
            }
            else{
                iterGreatest = leastNumbers.begin();
                if (*iter <= *iterGreatest) {
                    leastNumbers.erase(iterGreatest);
                    leastNumbers.insert(*iter);
                }
            }
        }
        iterGreatest = leastNumbers.begin();
        for (;iterGreatest != leastNumbers.end();iterGreatest++) {
            result.push_back(*iterGreatest);
        }
        return result;
    }
};
*/