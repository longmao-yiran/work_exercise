#include "offer_21.h"

/*
	调整数组顺序使奇数位于偶数前面
	输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
	使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分
*/

bool isEven(int n);
void Reorder(int *pData, unsigned int length, bool(*func)(int));
void ReorderOddEven(int *pData, unsigned int length) 
{
	if (pData == nullptr || length <= 0)
		return;
	Reorder(pData, length, isEven);
}

void Reorder(int *pData, unsigned int length, bool(*func)(int))
{
	if (pData == nullptr || length <= 0)
		return;
	int *pBegin = pData;
	int *pEnd = pData + length - 1;
	while (pBegin < pEnd){
		while (pBegin < pEnd && !func(*pBegin)){			//注意：这里操作都要判断pBegin < pEnd 防止越界
			++pBegin;
		}

		while (pBegin < pEnd && func(*pEnd)) {
			--pEnd;
		}
		if (pBegin < pEnd){
			int intTemp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = intTemp;
		}
	}
}

bool isEven(int n)
{
	return (n & 1) == 0;
}

// ====================测试代码====================
void PrintArray(int numbers[], int length)
{
	if (length < 0)
		return;

	for (int i = 0; i < length; ++i)
		printf("%d\t", numbers[i]);

	printf("\n");
}

void Test_21(char* testName, int numbers[], int length)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	int* copy = new int[length];
	for (int i = 0; i < length; ++i)
	{
		copy[i] = numbers[i];
	}

	printf("Test_21_ for solution 1:\n");
	PrintArray(numbers, length);
	ReorderOddEven(numbers, length);
	PrintArray(numbers, length);

	delete[] copy;
}

void Test_21_1()
{
	int numbers[] = { 1, 2, 3, 4, 5, 6, 7 };
	Test_21("Test_21_1", numbers, sizeof(numbers) / sizeof(int));
}

void Test_21_2()
{
	int numbers[] = { 2, 4, 6, 1, 3, 5, 7 };
	Test_21("Test_21_2", numbers, sizeof(numbers) / sizeof(int));
}

void Test_21_3()
{
	int numbers[] = { 1, 3, 5, 7, 2, 4, 6 };
	Test_21("Test_21_3", numbers, sizeof(numbers) / sizeof(int));
}

void Test_21_4()
{
	int numbers[] = { 1 };
	Test_21("Test_21_4", numbers, sizeof(numbers) / sizeof(int));
}

void Test_21_5()
{
	int numbers[] = { 2 };
	Test_21("Test_21_5", numbers, sizeof(numbers) / sizeof(int));
}

void Test_21_6()
{
	Test_21("Test_21_6", nullptr, 0);
}

void offer_21_test()
{
	Test_21_1();
	Test_21_2();
	Test_21_3();
	Test_21_4();
	Test_21_5();
	Test_21_6();

	cout << "offer_21 success" << endl;
}

// 牛客网ac 增加：并保证奇数和奇数，偶数和偶数之间的相对位置不变。
/*
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		if (array.size() <= 0)
			return;
		int length = array.size();

		// 空间换时间
		vector<int> array1(length);
		vector<int> array2(length);

		int unevenNum = 0;
		int evenNum = 0;

		for (int i = 0;i < length;++i) {
			if (!isEven(array[i])) {
				array1[unevenNum] = array[i];
				++unevenNum;
			}
			else {
				array2[evenNum] = array[i];
				++evenNum;
			}
		}

		for (int i = 0;i < unevenNum;++i) {
			array[i] = array1[i];
		}
		for (int i = unevenNum;i < (unevenNum + evenNum);++i) {
			array[i] = array2[i - unevenNum];
		}
	}
	bool isEven(int n)
	{
		return (n & 1) == 0;
	}
};

// 别人的好方案
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> result;
        int num=array.size();
        for(int i=0;i<num;i++)
            {
            if(array[i]%2==1)
                result.push_back(array[i]);
        }
        for(int i=0;i<num;i++)
            {
            if(array[i]%2==0)
                result.push_back(array[i]);
        }
        array=result;
    }
};


//首先统计奇数的个数,然后新建一个等长数组，设置两个指针，奇数指针从0开始，偶数指针从奇数个数的末尾开始 遍历，填数
public class Solution {
    public void reOrderArray(int [] array) {
        if(array.length==0||array.length==1) return;
        int oddCount=0,oddBegin=0;
        int[] newArray=new int[array.length];
        for(int i=0;i<array.length;i++){
            if((array[i]&1)==1) oddCount++;
        }
        for(int i=0;i<array.length;i++){
            if((array[i]&1)==1) newArray[oddBegin++]=array[i];
            else newArray[oddCount++]=array[i];
        }
        for(int i=0;i<array.length;i++){
            array[i]=newArray[i];
        }
    }
}
*/