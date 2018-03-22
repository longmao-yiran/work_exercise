#include "offer_37.h"
#include "Utilities\BinaryTree.h"
#include <fstream>
#include <sstream>

/*
	序列化二叉树
	请实现两个函数，分别用来序列化和反序列化二叉树
*/

void Serialize(const BinaryTreeNode* pRoot, ostream& stream) 
{
	if (pRoot == nullptr) {
		stream << "$,";
		return;
	}

	stream << pRoot->m_nValue << ",";
	Serialize(pRoot->m_pLeft, stream);
	Serialize(pRoot->m_pRight, stream);
}

bool ReadStream(istream& stream, int* number)
{
	if (stream.eof())
		return false;

	char buffer[32];

	buffer[0] = '\0';
	char ch;
	stream >> ch;
	cout << ch << " ";
	int i = 0;
	// 取出数字
	while (!stream.eof() &&ch != ',')
	{
		buffer[i++] = ch;
		stream >> ch;
		cout << ch << " ";
	}

	bool isNumeric = false;

	if (i > 0 && buffer[0] != '$') {
		*number = atoi(buffer);
		isNumeric = true;
	}
	return isNumeric;
}

void Deserialize(BinaryTreeNode** pRoot, istream& stream)
{
	int number;
	if (ReadStream(stream, &number)) {
		*pRoot = new BinaryTreeNode();
		(*pRoot)->m_pLeft = nullptr;
		(*pRoot)->m_pRight = nullptr;
		(*pRoot)->m_nValue = number;

		Deserialize(&((*pRoot)->m_pLeft), stream);
		Deserialize(&((*pRoot)->m_pRight), stream);
	}
}


// ==================== Test_37_ Code ====================
bool isSameTree(const BinaryTreeNode* pRoot1, const BinaryTreeNode* pRoot2)
{
	if (pRoot1 == nullptr && pRoot2 == nullptr)
		return true;

	if (pRoot1 == nullptr || pRoot2 == nullptr)
		return false;

	if (pRoot1->m_nValue != pRoot2->m_nValue)
		return false;

	return isSameTree(pRoot1->m_pLeft, pRoot2->m_pLeft) &&
		isSameTree(pRoot1->m_pRight, pRoot2->m_pRight);
}

void Test_37(const char* testName, const BinaryTreeNode* pRoot)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	PrintTree(pRoot);

	char* fileName = "test.txt";
	ofstream fileOut;
	fileOut.open(fileName);

	Serialize(pRoot, fileOut);
	fileOut.close();

	// print the serialized file
	ifstream fileIn1;
	char ch;
	fileIn1.open(fileName);
	while (!fileIn1.eof())
	{
		fileIn1 >> ch;
		cout << ch;
	}
	fileIn1.close();
	cout << endl;

	ifstream fileIn2;
	fileIn2.open(fileName);
	BinaryTreeNode* pNewRoot = nullptr;
	Deserialize(&pNewRoot, fileIn2);
	fileIn2.close();

	PrintTree(pNewRoot);

	if (isSameTree(pRoot, pNewRoot))
		printf("The deserialized tree is same as the oritinal tree.\n\n");
	else
		printf("The deserialized tree is NOT same as the oritinal tree.\n\n");

	DestroyTree(pNewRoot);
}

//            8
//        6      10
//       5 7    9  11
void Test_37_1()
{
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);

	Test_37("Test_37_1", pNode8);

	DestroyTree(pNode8);
}

//            5
//          4
//        3
//      2
void Test_37_2()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNode5, pNode4, nullptr);
	ConnectTreeNodes(pNode4, pNode3, nullptr);
	ConnectTreeNodes(pNode3, pNode2, nullptr);

	Test_37("Test_37_2", pNode5);

	DestroyTree(pNode5);
}

//        5
//         4
//          3
//           2
void Test_37_3()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNode5, nullptr, pNode4);
	ConnectTreeNodes(pNode4, nullptr, pNode3);
	ConnectTreeNodes(pNode3, nullptr, pNode2);

	Test_37("Test_37_3", pNode5);

	DestroyTree(pNode5);
}

void Test_37_4()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

	Test_37("Test_37_4", pNode5);

	DestroyTree(pNode5);
}

void Test_37_5()
{
	Test_37("Test_37_5", nullptr);
}

//        5
//         5
//          5
//         5
//        5
//       5 5
//      5   5
void Test_37_6()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode61 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode62 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode71 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode72 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode1, nullptr, pNode2);
	ConnectTreeNodes(pNode2, nullptr, pNode3);
	ConnectTreeNodes(pNode3, pNode4, nullptr);
	ConnectTreeNodes(pNode4, pNode5, nullptr);
	ConnectTreeNodes(pNode5, pNode61, pNode62);
	ConnectTreeNodes(pNode61, pNode71, nullptr);
	ConnectTreeNodes(pNode62, nullptr, pNode72);

	Test_37("Test_37_6", pNode1);

	DestroyTree(pNode1);
}

void offer_37_test()
{
	Test_37_1();
	Test_37_2();
	Test_37_3();
	Test_37_4();
	Test_37_5();
	Test_37_6();

	cout << "offer_37 success" << endl;
}

// 牛客网ac
/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};

class Solution {
public:
	char* Serialize(const TreeNode *pRoot) {
		if (pRoot == nullptr) {
			return "#,";
		}
		string str = to_string(pRoot->val);
		str.push_back(',');
		char* left = Serialize(pRoot->left);
		char* right = Serialize(pRoot->right);
		char* ret = new char[strlen(left) + strlen(right) + str.size()];

		strcpy(ret, str.c_str());				// 注意：此处将str转为char* 的方法
		strcat(ret, left);
		strcat(ret, right);
		return ret;
	}

	bool ReadStream(char* &str, int* number)
	{
		if (*str == '\0')
			return false;

		char buffer[32];

		buffer[0] = '\0';
		char ch;
		ch = (*str);
		str++;
		int i = 0;
		// 取出数字
		while (ch != '\0' && ch != ',')
		{
			buffer[i++] = ch;
			ch = (*str);
			str++;
		}

		bool isNumeric = false;

		if (i > 0 && buffer[0] != '#') {
			*number = atoi(buffer);
			isNumeric = true;
		}
		return isNumeric;
	}
	TreeNode* Deserialize(char* &str) {
		int number;
		if (ReadStream(str, &number)) {
			TreeNode *pRoot = new TreeNode((pRoot)->val);
			(pRoot)->left = nullptr;
			(pRoot)->right = nullptr;
			(pRoot)->val = number;

			(pRoot)->left = Deserialize(str);
			(pRoot)->right = Deserialize(str);
			return pRoot;
		}
		return nullptr;
	}
};

// 字符串转数字的另一种写法：
while(*str != ',')
	num = num*10 + (*(str++)-'0');
*/