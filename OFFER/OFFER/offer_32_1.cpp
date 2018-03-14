#include "offer_32_1.h"
#include "Utilities\BinaryTree.h"

#include <deque>

/*
	从上往下打印二叉树
	从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/

void PrintFromTopToBottom(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;

	deque<BinaryTreeNode*> dequeTreeNode;
	dequeTreeNode.push_back(pRoot);

	while (!dequeTreeNode.empty()){
		BinaryTreeNode* pNode = dequeTreeNode.front();
		printf("%d ", pNode->m_nValue);

		if (pNode->m_pLeft != nullptr)
			dequeTreeNode.push_back(pNode->m_pLeft);

		if (pNode->m_pRight != nullptr)
			dequeTreeNode.push_back(pNode->m_pRight);

		dequeTreeNode.pop_front();
	}
}

// ====================测试代码====================
void Test_32_1(char* testName, BinaryTreeNode* pRoot)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	PrintTree(pRoot);

	printf("The nodes from top to bottom, from left to right are: \n");
	PrintFromTopToBottom(pRoot);

	printf("\n\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test_32_1_1()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

	ConnectTreeNodes(pNode10, pNode6, pNode14);
	ConnectTreeNodes(pNode6, pNode4, pNode8);
	ConnectTreeNodes(pNode14, pNode12, pNode16);

	Test_32_1("Test_32_1_1", pNode10);

	DestroyTree(pNode10);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test_32_1_2()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

	ConnectTreeNodes(pNode5, pNode4, nullptr);
	ConnectTreeNodes(pNode4, pNode3, nullptr);
	ConnectTreeNodes(pNode3, pNode2, nullptr);
	ConnectTreeNodes(pNode2, pNode1, nullptr);

	Test_32_1("Test_32_1_2", pNode5);

	DestroyTree(pNode5);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test_32_1_3()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode1, nullptr, pNode2);
	ConnectTreeNodes(pNode2, nullptr, pNode3);
	ConnectTreeNodes(pNode3, nullptr, pNode4);
	ConnectTreeNodes(pNode4, nullptr, pNode5);

	Test_32_1("Test_32_1_3", pNode1);

	DestroyTree(pNode1);
}

// 树中只有1个结点
void Test_32_1_4()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	Test_32_1("Test_32_1_4", pNode1);

	DestroyTree(pNode1);
}

// 树中没有结点
void Test_32_1_5()
{
	Test_32_1("Test_32_1_5", nullptr);
}

void offer_32_1_test()
{
	Test_32_1_1();
	Test_32_1_2();
	Test_32_1_3();
	Test_32_1_4();
	Test_32_1_5();

	cout << "offer_32_1 success" << endl;
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        if (root == nullptr)
            return result;
        
        deque<TreeNode*> dequeTreeNode;
        dequeTreeNode.push_back(root);

        while (!dequeTreeNode.empty()){
            TreeNode* pNode = dequeTreeNode.front();
            result.push_back(pNode->val);

            if (pNode->left != nullptr)
                dequeTreeNode.push_back(pNode->left);

            if (pNode->right != nullptr)
                dequeTreeNode.push_back(pNode->right);

            dequeTreeNode.pop_front();
        }
        return result;
    }
};
*/