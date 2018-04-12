#include "offer_45.h"

/*
	�������ų���С����
	����һ�����������飬����������������ƴ�������ų�һ������
	��ӡ��ƴ�ӳ���������������С��һ����
	������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��
*/

bool compare(const int strNumber1,const int strNumber2)
{
	string str1 = to_string(strNumber1);
	string str2 = to_string(strNumber2);

	if (atoi((str1 + str2).c_str()) < atoi((str2 + str1).c_str()))
		return true;

	return false;
}

void PrintMinNumber(const int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		return;

	int *numberList = new int[length + 1];
	for (int i = 0;i < length;++i) {
		numberList[i] = numbers[i];
	}

	sort(numberList, numberList + length, compare);
	for (int i = 0;i < length;++i) {
		cout << numberList[i];
	}
	cout << endl;
}

// ====================���Դ���====================
void Test_45(const char* testName, int* numbers, int length, const char* expectedResult)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	if (expectedResult != nullptr)
		printf("Expected result is: \t%s\n", expectedResult);

	printf("Actual result is: \t");
	PrintMinNumber(numbers, length);

	printf("\n");
}

void Test_45_1()
{
	int numbers[] = { 3, 5, 1, 4, 2 };
	Test_45("Test_45_1", numbers, sizeof(numbers) / sizeof(int), "12345");
}

void Test_45_2()
{
	int numbers[] = { 3, 32, 321 };
	Test_45("Test_45_2", numbers, sizeof(numbers) / sizeof(int), "321323");
}

void Test_45_3()
{
	int numbers[] = { 3, 323, 32123 };
	Test_45("Test_45_3", numbers, sizeof(numbers) / sizeof(int), "321233233");
}

void Test_45_4()
{
	int numbers[] = { 1, 11, 111 };
	Test_45("Test_45_4", numbers, sizeof(numbers) / sizeof(int), "111111");
}

// ������ֻ��һ������
void Test_45_5()
{
	int numbers[] = { 321 };
	Test_45("Test_45_5", numbers, sizeof(numbers) / sizeof(int), "321");
}

void Test_45_6()
{
	Test_45("Test_45_6", nullptr, 0, "Don't print anything.");
}


void offer_45_test()
{
	Test_45_1();
	Test_45_2();
	Test_45_3();
	Test_45_4();
	Test_45_5();
	Test_45_6();

	cout << "offer_45 success" << endl;
}

// ţ����ac
/*
// ע�⣺�˴�����sort �����Զ��������д��
struct  compare
{
    bool operator()(const int strNumber1,const int strNumber2) const 
        {
            string str1 = to_string(strNumber1);
            string str2 = to_string(strNumber2);

            if (atoi((str1 + str2).c_str()) < atoi((str2 + str1).c_str()))
                return true;

            return false;
        }
};

class Solution {
public:
    string PrintMinNumber(vector<int> numbers)
    {
        if (numbers.size() <= 0)
            return "";

        sort(numbers.begin(), numbers.end(), compare());
        string result = "";
        for (int i = 0;i < numbers.size();++i) {
            result += to_string(numbers[i]);
        }
        return result;
    }

};
*/