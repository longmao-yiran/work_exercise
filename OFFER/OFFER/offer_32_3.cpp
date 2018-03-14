#include "offer_32_3.h"
#include "Utilities\BinaryTree.h"
#include <deque>

/*
	按之字形顺序打印二叉树
	请实现一个函数按照之字形打印二叉树，
	即第一行按照从左到右的顺序打印，
	第二层按照从右至左的顺序打印，
	第三行按照从左到右的顺序打印，其他行以此类推。
*/

// 用两个栈实现
void Print_32_3(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;

	stack<BinaryTreeNode*> stack1;			// 注意：此处要用两个栈
	stack<BinaryTreeNode*> stack2;
	int current = 0;				// 层数
	stack1.push(pRoot);

	while (!stack1.empty()||!stack2.empty())
	{
		if (current == 0) {
			while (!stack1.empty()){
				BinaryTreeNode* pNode = stack1.top();
				stack1.pop();
				printf("%d ", pNode->m_nValue);

				if (pNode->m_pLeft != nullptr)
					stack2.push(pNode->m_pLeft);

				if (pNode->m_pRight != nullptr)
					stack2.push(pNode->m_pRight);
			}
			current = 1;
			printf("\n");
			continue;
		}
		else {
			while (!stack2.empty()) {
				BinaryTreeNode* pNode = stack2.top();
				stack2.pop();
				printf("%d ", pNode->m_nValue);

				if (pNode->m_pRight != nullptr)
					stack1.push(pNode->m_pRight);

				if (pNode->m_pLeft != nullptr)
					stack1.push(pNode->m_pLeft);
			}
			printf("\n");
			current = 0;
			continue;
		}
	}
}

// ====================测试代码====================
//            8
//        6      10
//       5 7    9  11
void Test_32_3(char* testName, BinaryTreeNode* pRoot)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	PrintTree(pRoot);

	printf("The nodes from top to bottom, from left to right are: \n");
	Print_32_3(pRoot);
	printf("\n\n");
}

// ====================测试代码====================
//            8
//        6      10
//       5 7    9  11
void Test_32_3_1()
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

	Test_32_3("Test_32_3__1", pNode8);

	DestroyTree(pNode8);
}

//            5
//          4
//        3
//      2
void Test_32_3_2()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNode5, pNode4, nullptr);
	ConnectTreeNodes(pNode4, pNode3, nullptr);
	ConnectTreeNodes(pNode3, pNode2, nullptr);

	Test_32_3("Test_32_3__2", pNode5);

	DestroyTree(pNode5);
}

//        5
//         4
//          3
//           2
void Test_32_3_3()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNode5, nullptr, pNode4);
	ConnectTreeNodes(pNode4, nullptr, pNode3);
	ConnectTreeNodes(pNode3, nullptr, pNode2);

	Test_32_3("Test_32_3__3", pNode5);

	DestroyTree(pNode5);
}

void Test_32_3_4()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

	Test_32_3("Test_32_3__4", pNode5);

	DestroyTree(pNode5);
}

void Test_32_3_5()
{
	Test_32_3("Test_32_3__5", nullptr);
}

//        100
//        /
//       50   
//         \
//         150
void Test_32_3_6()
{
	BinaryTreeNode* pNode100 = CreateBinaryTreeNode(100);
	BinaryTreeNode* pNode50 = CreateBinaryTreeNode(50);
	BinaryTreeNode* pNode150 = CreateBinaryTreeNode(150);

	ConnectTreeNodes(pNode100, pNode50, nullptr);
	ConnectTreeNodes(pNode50, nullptr, pNode150);

	Test_32_3("Test_32_3__6", pNode100);

	DestroyTree(pNode100);
}

//                8
//        4              12
//     2     6       10      14
//   1  3  5  7     9 11   13  15
void Test_32_3_7()
{
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);
	BinaryTreeNode* pNode13 = CreateBinaryTreeNode(13);
	BinaryTreeNode* pNode15 = CreateBinaryTreeNode(15);

	ConnectTreeNodes(pNode8, pNode4, pNode12);
	ConnectTreeNodes(pNode4, pNode2, pNode6);
	ConnectTreeNodes(pNode12, pNode10, pNode14);
	ConnectTreeNodes(pNode2, pNode1, pNode3);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);
	ConnectTreeNodes(pNode14, pNode13, pNode15);

	Test_32_3("Test_32_3__7", pNode8);

	DestroyTree(pNode8);
}

void offer_32_3_test()
{
	Test_32_3_1();
	Test_32_3_2();
	Test_32_3_3();
	Test_32_3_4();
	Test_32_3_5();
	Test_32_3_6();
	Test_32_3_7();

	cout << "offer_32_3 success" << endl;
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > result;
        vector<int> resultTemp;
        if (pRoot == nullptr)
            return result;

        stack<TreeNode*> stack1;			// 注意：此处要用两个栈
        stack<TreeNode*> stack2;
        int current = 0;				// 层数
        stack1.push(pRoot);

        while (!stack1.empty() || !stack2.empty())
        {
            resultTemp.clear();
            if (current == 0) {
                while (!stack1.empty()) {
                    TreeNode* pNode = stack1.top();
                    stack1.pop();
                    resultTemp.push_back(pNode->val);

                    if (pNode->left != nullptr)
                        stack2.push(pNode->left);

                    if (pNode->right != nullptr)
                        stack2.push(pNode->right);
                }
                current = 1;
                result.push_back(resultTemp);
                continue;
            }
            else {
                while (!stack2.empty()) {
                    TreeNode* pNode = stack2.top();
                    stack2.pop();
                    resultTemp.push_back(pNode->val);

                    if (pNode->right != nullptr)
                        stack1.push(pNode->right);

                    if (pNode->left != nullptr)
                        stack1.push(pNode->left);
                }
                result.push_back(resultTemp);
                current = 0;
                continue;
            }
        }
        return result;
    }
    
};
*/