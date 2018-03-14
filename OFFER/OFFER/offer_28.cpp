#include "offer_28.h"
#include "Utilities\BinaryTree.h"

/*
	对称的二叉树
	请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/

bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

bool isSymmetrical(BinaryTreeNode* pRoot)
{
	return isSymmetrical(pRoot, pRoot);
}

bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) 
{
	if (pRoot1 == nullptr &&pRoot2 == nullptr)
		return true;
	if (pRoot1 != nullptr &&pRoot2 != nullptr){
		if (pRoot1->m_nValue == pRoot2->m_nValue) {
			return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight) && isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
		}
	}
	return false;
}

// ====================测试代码====================
void Test_28(char* testName, BinaryTreeNode* pRoot, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (isSymmetrical(pRoot) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

//            8
//        6      6
//       5 7    7 5
void Test_28_1()
{
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode61 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode62 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode71 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode72 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode52 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode8, pNode61, pNode62);
	ConnectTreeNodes(pNode61, pNode51, pNode71);
	ConnectTreeNodes(pNode62, pNode72, pNode52);

	Test_28("Test_28_1", pNode8, true);

	DestroyTree(pNode8);
}

//            8
//        6      9
//       5 7    7 5
void Test_28_2()
{
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode61 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode71 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode72 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode52 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode8, pNode61, pNode9);
	ConnectTreeNodes(pNode61, pNode51, pNode71);
	ConnectTreeNodes(pNode9, pNode72, pNode52);

	Test_28("Test_28_2", pNode8, false);

	DestroyTree(pNode8);
}

//            8
//        6      6
//       5 7    7
void Test_28_3()
{
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode61 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode62 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode51 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode71 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode72 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode8, pNode61, pNode62);
	ConnectTreeNodes(pNode61, pNode51, pNode71);
	ConnectTreeNodes(pNode62, pNode72, nullptr);

	Test_28("Test_28_3", pNode8, false);

	DestroyTree(pNode8);
}

//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//        /             \
//       1               1
void Test_28_4()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode31 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode32 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode41 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode42 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode21 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode22 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(1);

	ConnectTreeNodes(pNode5, pNode31, pNode32);
	ConnectTreeNodes(pNode31, pNode41, nullptr);
	ConnectTreeNodes(pNode32, nullptr, pNode42);
	ConnectTreeNodes(pNode41, pNode21, nullptr);
	ConnectTreeNodes(pNode42, nullptr, pNode22);
	ConnectTreeNodes(pNode21, pNode11, nullptr);
	ConnectTreeNodes(pNode22, nullptr, pNode12);

	Test_28("Test_28_4", pNode5, true);

	DestroyTree(pNode5);
}


//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         6           2
//        /             \
//       1               1
void Test_28_5()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode31 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode32 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode41 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode42 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode22 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(1);

	ConnectTreeNodes(pNode5, pNode31, pNode32);
	ConnectTreeNodes(pNode31, pNode41, nullptr);
	ConnectTreeNodes(pNode32, nullptr, pNode42);
	ConnectTreeNodes(pNode41, pNode6, nullptr);
	ConnectTreeNodes(pNode42, nullptr, pNode22);
	ConnectTreeNodes(pNode6, pNode11, nullptr);
	ConnectTreeNodes(pNode22, nullptr, pNode12);

	Test_28("Test_28_5", pNode5, false);

	DestroyTree(pNode5);
}

//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//                      \
//                       1
void Test_28_6()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode31 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode32 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode41 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode42 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode21 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode22 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(1);

	ConnectTreeNodes(pNode5, pNode31, pNode32);
	ConnectTreeNodes(pNode31, pNode41, nullptr);
	ConnectTreeNodes(pNode32, nullptr, pNode42);
	ConnectTreeNodes(pNode41, pNode21, nullptr);
	ConnectTreeNodes(pNode42, nullptr, pNode22);
	ConnectTreeNodes(pNode21, nullptr, nullptr);
	ConnectTreeNodes(pNode22, nullptr, pNode12);

	Test_28("Test_28_6", pNode5, false);

	DestroyTree(pNode5);
}

// 只有一个结点
void Test_28_7()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	Test_28("Test_28_7", pNode1, true);

	DestroyTree(pNode1);
}

// 没有结点
void Test_28_8()
{
	Test_28("Test_28_8", nullptr, true);
}

// 所有结点都有相同的值，树对称
//               5
//              / \
//             5   5
//            /     \
//           5       5
//          /         \
//         5           5
void Test_28_9()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode21 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode22 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode31 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode32 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode41 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode42 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode1, pNode21, pNode22);
	ConnectTreeNodes(pNode21, pNode31, nullptr);
	ConnectTreeNodes(pNode22, nullptr, pNode32);
	ConnectTreeNodes(pNode31, pNode41, nullptr);
	ConnectTreeNodes(pNode32, nullptr, pNode42);
	ConnectTreeNodes(pNode41, nullptr, nullptr);
	ConnectTreeNodes(pNode42, nullptr, nullptr);

	Test_28("Test_28_9", pNode1, true);

	DestroyTree(pNode1);
}

// 所有结点都有相同的值，树不对称
//               5
//              / \
//             5   5
//            /     \
//           5       5
//          /       /
//         5       5
void Test_28_10()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode21 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode22 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode31 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode32 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode41 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode42 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode1, pNode21, pNode22);
	ConnectTreeNodes(pNode21, pNode31, nullptr);
	ConnectTreeNodes(pNode22, nullptr, pNode32);
	ConnectTreeNodes(pNode31, pNode41, nullptr);
	ConnectTreeNodes(pNode32, pNode42, nullptr);
	ConnectTreeNodes(pNode41, nullptr, nullptr);
	ConnectTreeNodes(pNode42, nullptr, nullptr);

	Test_28("Test_28_10", pNode1, false);

	DestroyTree(pNode1);
}

void offer_28_test()
{
	Test_28_1();
	Test_28_2();
	Test_28_3();
	Test_28_4();
	Test_28_5();
	Test_28_6();
	Test_28_7();
	Test_28_8();
	Test_28_9();
	Test_28_10();

	cout << "offer_28 success" << endl;
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
    bool isSymmetrical(TreeNode* pRoot)
    {
        return isSymmetrical(pRoot, pRoot);
    }

    bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2) 
    {
        if (pRoot1 == nullptr &&pRoot2 == nullptr)
            return true;
        if (pRoot1 != nullptr &&pRoot2 != nullptr){
            if (pRoot1->val == pRoot2->val) {
                return isSymmetrical(pRoot1->left, pRoot2->right) && isSymmetrical(pRoot1->right, pRoot2->left);
            }
        }
        return false;
    }

};
*/