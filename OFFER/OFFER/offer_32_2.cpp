#include "offer_32_2.h"
#include "Utilities\BinaryTree.h"
#include <deque>

/*
	把二叉树打印成多行
	从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
*/

void Print_32_2(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;

	deque<BinaryTreeNode*> dequeTreeNode;
	dequeTreeNode.push_back(pRoot);
	int nextLevel = 0;
	int toBePrinted = 1;
	while (!dequeTreeNode.empty()){
		BinaryTreeNode* pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();
		--toBePrinted;
		printf("%d ", pNode->m_nValue);

		if (pNode->m_pLeft != nullptr){
			dequeTreeNode.push_back(pNode->m_pLeft);
			++nextLevel;
		}

		if (pNode->m_pRight != nullptr) {
			dequeTreeNode.push_back(pNode->m_pRight);
			++nextLevel;
		}

		if (toBePrinted == 0) {
			printf("\n");
			toBePrinted = nextLevel;
			nextLevel = 0;
		}
	}
}

// ====================测试代码====================
//            8
//        6      10
//       5 7    9  11
void Test_32_2(char* testName, BinaryTreeNode* pRoot)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	PrintTree(pRoot);

	printf("The nodes from top to bottom, from left to right are: \n");
	Print_32_2(pRoot);

	printf("\n\n");
}

void Test_32_2_1()
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

	Test_32_2("Test_32_2_1", pNode8);

	DestroyTree(pNode8);
}

//            5
//          4
//        3
//      2
void Test_32_2_2()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNode5, pNode4, nullptr);
	ConnectTreeNodes(pNode4, pNode3, nullptr);
	ConnectTreeNodes(pNode3, pNode2, nullptr);

	Test_32_2("Test_32_2_2", pNode5);

	DestroyTree(pNode5);
}

//        5
//         4
//          3
//           2
void Test_32_2_3()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

	ConnectTreeNodes(pNode5, nullptr, pNode4);
	ConnectTreeNodes(pNode4, nullptr, pNode3);
	ConnectTreeNodes(pNode3, nullptr, pNode2);

	Test_32_2("Test_32_2_3", pNode5);

	DestroyTree(pNode5);
}

// 只有一个
void Test_32_2_4()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

	Test_32_2("Test_32_2_4", pNode5);

	DestroyTree(pNode5);
}

// 空指针
void Test_32_2_5()
{
	Test_32_2("Test_32_2_5", nullptr);
}

//        100
//        /
//       50   
//         \
//         150
void Test_32_2_6()
{
	BinaryTreeNode* pNode100 = CreateBinaryTreeNode(100);
	BinaryTreeNode* pNode50 = CreateBinaryTreeNode(50);
	BinaryTreeNode* pNode150 = CreateBinaryTreeNode(150);

	ConnectTreeNodes(pNode100, pNode50, nullptr);
	ConnectTreeNodes(pNode50, nullptr, pNode150);

	Test_32_2("Test_32_2_6", pNode100);

	DestroyTree(pNode100);
}

void offer_32_2_test()
{
	Test_32_2_1();
	Test_32_2_2();
	Test_32_2_3();
	Test_32_2_4();
	Test_32_2_5();
	Test_32_2_6();

	cout << "offer_32_2 success" << endl;
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
        vector<vector<int>> result;
        vector<int> vectorTemp;
        if (pRoot == nullptr)
		    return result;

        deque<TreeNode*> dequeTreeNode;
        dequeTreeNode.push_back(pRoot);
        int nextLevel = 0;
        int toBePrinted = 1;
            
        while (!dequeTreeNode.empty()){
            TreeNode* pNode = dequeTreeNode.front();
            dequeTreeNode.pop_front();
            --toBePrinted;
            vectorTemp.push_back(pNode->val);

            if (pNode->left != nullptr){
                dequeTreeNode.push_back(pNode->left);
                ++nextLevel;
            }

            if (pNode->right != nullptr) {
                dequeTreeNode.push_back(pNode->right);
                ++nextLevel;
            }

            if (toBePrinted == 0) {
                result.push_back(vectorTemp);
                vectorTemp.clear();
                toBePrinted = nextLevel;
                nextLevel = 0;
            }
        }
        return result;
    }
    
};
*/