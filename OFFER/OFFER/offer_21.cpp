#include "offer_21.h"

/*
	��������˳��ʹ����λ��ż��ǰ��
	����һ���������飬ʵ��һ�����������������������ֵ�˳��
	ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ��λ������ĺ�벿��
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
		while (pBegin < pEnd && !func(*pBegin)){			//ע�⣺���������Ҫ�ж�pBegin < pEnd ��ֹԽ��
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

// ====================���Դ���====================
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

// ţ����ac ���ӣ�����֤������������ż����ż��֮������λ�ò��䡣
/*
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		if (array.size() <= 0)
			return;
		int length = array.size();

		// �ռ任ʱ��
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

// ���˵ĺ÷���
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


//����ͳ�������ĸ���,Ȼ���½�һ���ȳ����飬��������ָ�룬����ָ���0��ʼ��ż��ָ�������������ĩβ��ʼ ����������
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