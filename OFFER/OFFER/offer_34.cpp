#include "offer_34.h"
#include "Utilities\BinaryTree.h"

/*
	二叉树中和为某一值的路径
	输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
	路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
*/

void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int& currentSum);

void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
	if (pRoot == nullptr)
		return;

	vector<int> path;
	int currentSum = 0;
	FindPath(pRoot, expectedSum, path, currentSum);
}

void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int& currentSum)
{
	if (pRoot == nullptr)
		return;

	path.push_back(pRoot->m_nValue);
	currentSum += pRoot->m_nValue;
	// 判断符合条件 跳出
	if (expectedSum == currentSum && pRoot->m_pLeft == nullptr&&pRoot->m_pRight == nullptr)
	{
		printf("A path is found: ");
		std::vector<int>::iterator iter = path.begin();
		for (; iter != path.end(); ++iter)
			printf("%d\t", *iter);

		printf("\n");
	}
	if (pRoot->m_pLeft != nullptr)
		FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
	if (pRoot->m_pRight != nullptr)
		FindPath(pRoot->m_pRight, expectedSum, path, currentSum);
	currentSum -= pRoot->m_nValue;
	path.pop_back();
}

// ====================测试代码====================
void Test_34(char* testName, BinaryTreeNode* pRoot, int expectedSum)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	FindPath(pRoot, expectedSum);

	printf("\n");
}

//            10
//         /      \
//        5        12
//       /\        
//      4  7     
// 有两条路径上的结点和为22
void Test_34_1()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode10, pNode5, pNode12);
	ConnectTreeNodes(pNode5, pNode4, pNode7);

	printf("Two paths should be found in Test_34_1.\n");
	Test_34("Test_34_1", pNode10, 22);

	DestroyTree(pNode10);
}

//            10
//         /      \
//        5        12
//       /\        
//      4  7     
// 没有路径上的结点和为15
void Test_34_2()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode10, pNode5, pNode12);
	ConnectTreeNodes(pNode5, pNode4, pNode7);

	printf("No paths should be found in Test_34_2.\n");
	Test_34("Test_34_2", pNode10, 15);

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
// 有一条路径上面的结点和为15
void Test_34_3()
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

	printf("One path should be found in Test_34_3.\n");
	Test_34("Test_34_3", pNode5, 15);

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
// 没有路径上面的结点和为16
void Test_34_4()
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

	printf("No paths should be found in Test_34_4.\n");
	Test_34("Test_34_4", pNode1, 16);

	DestroyTree(pNode1);
}

// 树中只有1个结点
void Test_34_5()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

	printf("One path should be found in Test_34_5.\n");
	Test_34("Test_34_5", pNode1, 1);

	DestroyTree(pNode1);
}

// 树中没有结点
void Test_34_6()
{
	printf("No paths should be found in Test_34_6.\n");
	Test_34("Test_34_6", nullptr, 0);
}

void offer_34_test()
{
	Test_34_1();
	Test_34_2();
	Test_34_3();
	Test_34_4();
	Test_34_5();
	Test_34_6();

	cout << "offer_34 success" << endl;
}

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
    
    vector<vector<int> > FindPath(TreeNode* pRoot, int expectNumber)
    {
        vector<vector<int> > result;
        if (pRoot == nullptr)
            return result;

        vector<int> path;
        int currentSum = 0;
        FindPath(pRoot, expectNumber, path, currentSum, result);
        return result;
    }

    void FindPath(TreeNode* pRoot, int expectedSum, std::vector<int>& path, int& currentSum, vector<vector<int>>& result)
    {
        if (pRoot == nullptr)
            return;

        path.push_back(pRoot->val);
        currentSum += pRoot->val;
        // 判断符合条件 跳出
        if (expectedSum == currentSum && pRoot->left == nullptr&&pRoot->right == nullptr)
        {
            vector<int> resultTemp;
            std::vector<int>::iterator iter = path.begin();
            for (; iter != path.end(); ++iter)
                resultTemp.push_back(*iter);

            result.push_back(resultTemp);
        }
        if (pRoot->left != nullptr)
            FindPath(pRoot->left, expectedSum, path, currentSum,result);
        if (pRoot->right != nullptr)
            FindPath(pRoot->right, expectedSum, path, currentSum,result);
        currentSum -= pRoot->val;
        path.pop_back();
    }
};
*/