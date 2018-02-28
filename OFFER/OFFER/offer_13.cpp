#include "offer_13.h"

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited);
bool check(int threshold, int rows, int cols, int row, int col, bool* visited);
int getDigitSum(int number);

int movingCount(int threshold, int rows, int cols)
{
	if (threshold < 0 || rows <= 0 || cols <= 0)
		return 0;

	bool *visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);

	int count = movingCountCore(threshold, rows, cols, 0, 0, visited);

	delete[] visited;
	return count;
}

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	int count = 0;
	if (check(threshold, rows, cols, row, col, visited)) {
		visited[row*cols + col] = true;
		count = 1 + movingCountCore(threshold, rows, cols, row + 1, col, visited) +
			movingCountCore(threshold, rows, cols, row - 1, col, visited) +
			movingCountCore(threshold, rows, cols, row, col + 1, visited) +
			movingCountCore(threshold, rows, cols, row, col - 1, visited);
	}
	return count;
}

bool check(int threshold, int rows, int cols, int row, int col, bool* visited) 
{
	if (row >= 0 && row < rows&&col >= 0 && col < cols && !visited[row*cols + col] && (getDigitSum(row) + getDigitSum(col) <= threshold))
		return true;
	return false;
}

int getDigitSum(int number)
{
	int result = 0;
	while (number > 0)
	{
		result += number % 10;
		number = number / 10;
	}
	
	return result;
}

// ====================测试代码====================
void Test_13(char* testName, int threshold, int rows, int cols, int expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (movingCount(threshold, rows, cols) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.  Your answer is %d ,the right answer is %d\n", movingCount(threshold, rows, cols), expected);
}

// 方格多行多列
void Test_13_1()
{
	Test_13("Test1", 5, 10, 10, 21);
}

// 方格多行多列
void Test_13_2()
{
	Test_13("Test2", 15, 20, 20, 359);
}

// 方格只有一行，机器人只能到达部分方格
void Test_13_3()
{
	Test_13("Test3", 10, 1, 100, 29);
}

// 方格只有一行，机器人能到达所有方格
void Test_13_4()
{
	Test_13("Test4", 10, 1, 10, 10);
}

// 方格只有一列，机器人只能到达部分方格
void Test_13_5()
{
	Test_13("Test5", 15, 100, 1, 79);
}

// 方格只有一列，机器人能到达所有方格
void Test_13_6()
{
	Test_13("Test6", 15, 10, 1, 10);
}

// 方格只有一行一列
void Test_13_7()
{
	Test_13("Test7", 15, 1, 1, 1);
}

// 方格只有一行一列
void Test_13_8()
{
	Test_13("Test8", 0, 1, 1, 1);
}

// 机器人不能进入任意一个方格
void Test_13_9()
{
	Test_13("Test9", -10, 10, 10, 0);
}

void offer_13_test()
{
	Test_13_1();
	Test_13_2();
	Test_13_3();
	Test_13_4();
	Test_13_5();
	Test_13_6();
	Test_13_7();
	Test_13_8();
	Test_13_9();

	cout << "offer_13 success" << endl;
}

// 牛客网 ac
/*
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if (threshold < 0 || rows <= 0 || cols <= 0)
            return 0;

        bool *visited = new bool[rows*cols];
        memset(visited, 0, rows*cols);

        int count = movingCountCore(threshold, rows, cols, 0, 0, visited);

        delete[] visited;
        return count;
    }

    int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
    {
        int count = 0;
        if (check(threshold, rows, cols, row, col, visited)) {
            visited[row*cols + col] = true;
            count = 1 + movingCountCore(threshold, rows, cols, row + 1, col, visited) +
                movingCountCore(threshold, rows, cols, row - 1, col, visited) +
                movingCountCore(threshold, rows, cols, row, col + 1, visited) +
                movingCountCore(threshold, rows, cols, row, col - 1, visited);
        }
        return count;
    }

    bool check(int threshold, int rows, int cols, int row, int col, bool* visited) 
    {
        if (row >= 0 && row < rows&&col >= 0 && col < cols && !visited[row*cols + col] && (getDigitSum(row) + getDigitSum(col) <= threshold))
            return true;
        return false;
    }

    int getDigitSum(int number)
    {
        int result = 0;
        while (number > 0)
        {
            result += number % 10;
            number = number / 10;
        }

        return result;
    }
};
*/