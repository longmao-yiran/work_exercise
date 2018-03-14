#include "offer_29.h"

/*
	顺时针打印矩阵
	输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
	例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
	则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

void printNumber(int number);

void PrintMatrixClockwisely(int** numbers, int columns, int rows)
{
	if (numbers == nullptr || columns <= 0 || rows <= 0)
		return;

	int startColums = 0;
	int startRows = 0;
	int endColums = columns-1;
	int endRows = rows-1;

	int rowIndex = 0;
	int colIndex = 0;
	while (rowIndex >= startRows && rowIndex <= endRows && colIndex >= startColums && colIndex <= endColums && rowIndex >= 0 && colIndex >= 0) {
		if (rowIndex >= startRows && rowIndex <= endRows && colIndex >= startColums && colIndex <= endColums && rowIndex >= 0 && colIndex >= 0) {
			for (int i = colIndex;i <= endColums && colIndex >= 0;++i)
				printNumber(numbers[rowIndex][i]);
			colIndex = endColums;
			rowIndex += 1;
			startRows += 1;
		}
		// 注意： 每次改变数值后都有可能造成判断条件不满足 省心写法
		if (rowIndex >= startRows && rowIndex <= endRows && colIndex >= startColums && colIndex <= endColums && rowIndex >= 0 && colIndex >= 0) {
			for (int i = rowIndex;i <= endRows;++i)
				printNumber(numbers[i][colIndex]);
			rowIndex = endRows;
			colIndex -= 1;
			endColums -= 1;
		}

		if (rowIndex >= startRows && rowIndex <= endRows && colIndex >= startColums && colIndex <= endColums && rowIndex >= 0 && colIndex >= 0) {
			for (int i = endColums;i >= startColums && endColums >= 0;--i)
				printNumber(numbers[rowIndex][i]);
			colIndex = startColums;
			rowIndex -= 1;
			endRows -= 1;
		}

		if (rowIndex >= startRows && rowIndex <= endRows && colIndex >= startColums && colIndex <= endColums && rowIndex >= 0 && colIndex >= 0) {
			for (int i = endRows;i >= startRows && endRows >= 0;--i)
				printNumber(numbers[i][colIndex]);
			rowIndex = startRows;
			colIndex += 1;
			startColums += 1;
		}
	}
	
}


void printNumber(int number)
{
	printf("%d\t", number);
}

// ====================测试代码====================
void Test_29(int columns, int rows)
{
	printf("Test_29 Begin: %d columns, %d rows.\n", columns, rows);

	if (columns < 1 || rows < 1)
		return;

	int** numbers = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		numbers[i] = new int[columns];
		for (int j = 0; j < columns; ++j)
		{
			numbers[i][j] = i * columns + j + 1;
		}
	}

	PrintMatrixClockwisely(numbers, columns, rows);
	printf("\n");

	for (int i = 0; i < rows; ++i)
		delete[](int*)numbers[i];

	delete[] numbers;
}
/*
1
*/
void Test_29_1()
{
	Test_29(1,1);
}

/*
1    2
3    4
*/
void Test_29_2()
{
	Test_29(2, 2);
}

/*
1    2    3    4
5    6    7    8
9    10   11   12
13   14   15   16
*/
void Test_29_3()
{
	Test_29(4, 4);
}

/*
1    2    3    4    5
6    7    8    9    10
11   12   13   14   15
16   17   18   19   20
21   22   23   24   25
*/
void Test_29_4()
{
	Test_29(5, 5);
}

/*
1
2
3
4
5
*/
void Test_29_5()
{
	Test_29(1, 5);
}

/*
1    2
3    4
5    6
7    8
9    10
*/
void Test_29_6()
{
	Test_29(2, 5);
}

/*
1    2    3
4    5    6
7    8    9
10   11   12
13   14   15
*/
void Test_29_7()
{
	Test_29(3, 5);
}

/*
1    2    3    4
5    6    7    8
9    10   11   12
13   14   15   16
17   18   19   20
*/
void Test_29_8()
{
	Test_29(4, 5);
}

/*
1    2    3    4    5
*/
void Test_29_9()
{
	Test_29(5, 1);
}

/*
1    2    3    4    5
6    7    8    9    10
*/
void Test_29_10()
{
	Test_29(5, 2);
}

/*
1    2    3    4    5
6    7    8    9    10
11   12   13   14    15
*/
void Test_29_11()
{
	Test_29(5, 3);
}

/*
1    2    3    4    5
6    7    8    9    10
11   12   13   14   15
16   17   18   19   20
*/
void Test_29_12()
{
	Test_29(5, 4);
}

void offer_29_test()
{
	Test_29_1();
	Test_29_2();
	Test_29_3();
	Test_29_4();
	Test_29_5();
	Test_29_6();
	Test_29_7();
	Test_29_8();
	Test_29_9();
	Test_29_10();
	Test_29_11();
	Test_29_12();

	cout << "offer_29 success" << endl;
}

// 牛客网ac
/*
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix )
    {
        vector<int> result;
        if (matrix.size() <= 0 || matrix[0].size() <= 0)
            return result;

        int rows = matrix.size();
        int columns = matrix[0].size();

        int startColums = 0;
        int startRows = 0;
        int endColums = columns - 1;
        int endRows = rows - 1;

        int rowIndex = 0;
        int colIndex = 0;
        while (rowIndex >= startRows && rowIndex <= endRows && colIndex >= startColums && colIndex <= endColums && rowIndex >= 0 && colIndex >= 0) {
            if (rowIndex >= startRows && rowIndex <= endRows && colIndex >= startColums && colIndex <= endColums && rowIndex >= 0 && colIndex >= 0) {
                for (int i = colIndex;i <= endColums && colIndex >= 0;++i)
                    result.push_back(matrix[rowIndex][i]);
                colIndex = endColums;
                rowIndex += 1;
                startRows += 1;
            }
            // 注意： 每次改变数值后都有可能造成判断条件不满足 省心写法
            if (rowIndex >= startRows && rowIndex <= endRows && colIndex >= startColums && colIndex <= endColums && rowIndex >= 0 && colIndex >= 0) {
                for (int i = rowIndex;i <= endRows;++i)
                    result.push_back(matrix[i][colIndex]);
                rowIndex = endRows;
                colIndex -= 1;
                endColums -= 1;
            }

            if (rowIndex >= startRows && rowIndex <= endRows && colIndex >= startColums && colIndex <= endColums && rowIndex >= 0 && colIndex >= 0) {
                for (int i = endColums;i >= startColums && endColums >= 0;--i)
                    result.push_back(matrix[rowIndex][i]);
                colIndex = startColums;
                rowIndex -= 1;
                endRows -= 1;
            }

            if (rowIndex >= startRows && rowIndex <= endRows && colIndex >= startColums && colIndex <= endColums && rowIndex >= 0 && colIndex >= 0) {
                for (int i = endRows;i >= startRows && endRows >= 0;--i)
                    result.push_back(matrix[i][colIndex]);
                rowIndex = startRows;
                colIndex += 1;
                startColums += 1;
            }
        }
        return result;
    }

};
*/
