#include "offer_12.h"

/*
	矩阵中的路径
	请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
	路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
	如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
	例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，
	但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited);

bool hasPath(const char* matrix, int rows, int cols, const char* str)
{
	if (matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr)
		return false;

	bool *visited = new bool[rows*cols];
	memset(visited, 0, rows*cols);

	int pathLength = 0;

	bool result = false;

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (matrix[i*cols + j] == str[pathLength]) {
				result = hasPathCore(matrix, rows, cols, i, j, str, pathLength, visited);
				// 注意：此处存在多个可能的起始节点
				if (result == true) {
					delete[] visited;
					return result;
				}
			}
		}
	}
	delete[] visited;
	return result;
}

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited) 
{
	if (str[pathLength] == '\0')
		return true;

	bool hasPath = false;
	// 不满足搜索条件 回溯
	if (row < 0 || row >= rows || col < 0 || col >= cols || matrix[row*cols + col] != str[pathLength] || visited[row*cols + col] == true)
		return hasPath;

	++pathLength;
	visited[row*cols + col] = true;

	hasPath = hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited) ||
		hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited) ||
		hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited) ||
		hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited);

	if (hasPath == false) {
		--pathLength;
		visited[row*cols + col] = false;
	}
	return hasPath;

	
}

// ====================测试代码====================
void Test_12(const char* testName, const char* matrix, int rows, int cols, const char* str, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (hasPath(matrix, rows, cols, str) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

//ABTG
//CFCS
//JDEH

//BFCE
void Test_12_1()
{
	const char* matrix = "ABTGCFCSJDEH";
	const char* str = "BFCE";

	Test_12("Test_12_1", (const char*)matrix, 3, 4, str, true);
}

//ABCE
//SFCS
//ADEE

//SEE
void Test_12_2()
{
	const char* matrix = "ABCESFCSADEE";
	const char* str = "SEE";

	Test_12("Test_12_2", (const char*)matrix, 3, 4, str, true);
}

//ABTG
//CFCS
//JDEH

//ABFB
void Test_12_3()
{
	const char* matrix = "ABTGCFCSJDEH";
	const char* str = "ABFB";

	Test_12("Test_12_3", (const char*)matrix, 3, 4, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SLHECCEIDEJFGGFIE
void Test_12_4()
{
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	const char* str = "SLHECCEIDEJFGGFIE";

	Test_12("Test_12_4", (const char*)matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEM
void Test_12_5()
{
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	const char* str = "SGGFIECVAASABCEHJIGQEM";

	Test_12("Test_12_5", (const char*)matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEEJIGOEM
void Test_12_6()
{
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	const char* str = "SGGFIECVAASABCEEJIGOEM";

	Test_12("Test_12_6", (const char*)matrix, 5, 8, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEMS
void Test_12_7()
{
	const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	const char* str = "SGGFIECVAASABCEHJIGQEMS";

	Test_12("Test_12_7", (const char*)matrix, 5, 8, str, false);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAA
void Test_12_8()
{
	const char* matrix = "AAAAAAAAAAAA";
	const char* str = "AAAAAAAAAAAA";

	Test_12("Test_12_8", (const char*)matrix, 3, 4, str, true);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAAA
void Test_12_9()
{
	const char* matrix = "AAAAAAAAAAAA";
	const char* str = "AAAAAAAAAAAAA";

	Test_12("Test_12_9", (const char*)matrix, 3, 4, str, false);
}

//A

//A
void Test_12_10()
{
	const char* matrix = "A";
	const char* str = "A";

	Test_12("Test_12_10", (const char*)matrix, 1, 1, str, true);
}

//A

//B
void Test_12_11()
{
	const char* matrix = "A";
	const char* str = "B";

	Test_12("Test_12_11", (const char*)matrix, 1, 1, str, false);
}

void Test_12_12()
{
	Test_12("Test_12_12", nullptr, 0, 0, nullptr, false);
}

void offer_12_test()
{
	Test_12_1();
	Test_12_2();
	Test_12_3();
	Test_12_4();
	Test_12_5();
	Test_12_6();
	Test_12_7();
	Test_12_8();
	Test_12_9();
	Test_12_10();
	Test_12_11();
	Test_12_12();

	cout << "offer_12 success" << endl;
}

// 牛客网 ac
/*
class Solution {
public:
    
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if (matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr)
            return false;

        bool *visited = new bool[rows*cols];
        memset(visited, 0, rows*cols);

        int pathLength = 0;

        bool result = false;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i*cols + j] == str[pathLength]) {
                    result = hasPathCore(matrix, rows, cols, i, j, str, pathLength, visited);
                    // 注意：此处存在多个可能的起始节点
                    if (result == true) {
                        delete[] visited;
                        return result;
                    }
                }
            }
        }
        delete[] visited;
        return result;
    }

    bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited) 
    {
        if (str[pathLength] == '\0')
            return true;

        bool hasPath = false;
        // 不满足搜索条件 回溯
        if (row < 0 || row >= rows || col < 0 || col >= cols || matrix[row*cols + col] != str[pathLength] || visited[row*cols + col] == true)
            return hasPath;

        ++pathLength;
        visited[row*cols + col] = true;

        hasPath = hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited) ||
            hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited) ||
            hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited) ||
            hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited);

        if (hasPath == false) {
            --pathLength;
            visited[row*cols + col] = false;
        }
        return hasPath;


    }

};
*/