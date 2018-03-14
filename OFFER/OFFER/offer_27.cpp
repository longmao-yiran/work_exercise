#include "offer_27.h"
#include "Utilities\BinaryTree.h"

/*
	二叉树的镜像
	操作给定的二叉树，将其变换为源二叉树的镜像。
	二叉树的镜像定义：源二叉树
	   8
	 /  \
	6   10
	/ \  / \
   5   7 9 11
	镜像二叉树
	   8
	 /  \
	10   6
	/ \  / \
   11 9 7   5
*/

// 递归方法
void MirrorRecursively(BinaryTreeNode *pNode)
{
	if (pNode == nullptr)
		return;

	// 注意：此处的递归跳出条件 不写也行 但是会多进几次递归
	//if (pNode->m_pLeft == nullptr && pNode->m_pRight == nullptr)
	//	return;
	BinaryTreeNode* pTmp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = pTmp;

	if (pNode->m_pRight != nullptr)
		MirrorRecursively(pNode->m_pRight);
	if (pNode->m_pLeft != nullptr)
		MirrorRecursively(pNode->m_pLeft);
}

// 非递归版本
void MirrorIteratively(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;

	std::stack<BinaryTreeNode*> stackTreeNode;
	stackTreeNode.push(pRoot);

	while (stackTreeNode.size() > 0)
	{
		BinaryTreeNode *pNode = stackTreeNode.top();
		stackTreeNode.pop();

		BinaryTreeNode *pTemp = pNode->m_pLeft;
		pNode->m_pLeft = pNode->m_pRight;
		pNode->m_pRight = pTemp;

		if (pNode->m_pLeft)
			stackTreeNode.push(pNode->m_pLeft);

		if (pNode->m_pRight)
			stackTreeNode.push(pNode->m_pRight);
	}
}

// ====================测试代码====================
// 测试完全二叉树：除了叶子节点，其他节点都有两个子节点
//            8
//        6      10
//       5 7    9  11
void Test_27_1()
{
	printf("=====Test_27_1 starts:=====\n");
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

	PrintTree(pNode8);

	printf("=====Test_27_1: MirrorRecursively=====\n");
	MirrorRecursively(pNode8);
	PrintTree(pNode8);

	printf("=====Test_27_1: MirrorIteratively=====\n");
	MirrorIteratively(pNode8);
	PrintTree(pNode8);

	DestroyTree(pNode8);
}

// 测试二叉树：出叶子结点之外，左右的结点都有且只有一个左子结点
//            8
//          7   
//        6 
//      5
//    4
void Test_27_2()
{
	printf("=====Test_27_2 starts:=====\n");
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

	ConnectTreeNodes(pNode8, pNode7, nullptr);
	ConnectTreeNodes(pNode7, pNode6, nullptr);
	ConnectTreeNodes(pNode6, pNode5, nullptr);
	ConnectTreeNodes(pNode5, pNode4, nullptr);

	PrintTree(pNode8);

	printf("=====Test_27_2: MirrorRecursively=====\n");
	MirrorRecursively(pNode8);
	PrintTree(pNode8);

	printf("=====Test_27_2: MirrorIteratively=====\n");
	MirrorIteratively(pNode8);
	PrintTree(pNode8);

	DestroyTree(pNode8);
}

// 测试二叉树：出叶子结点之外，左右的结点都有且只有一个右子结点
//            8
//             7   
//              6 
//               5
//                4
void Test_27_3()
{
	printf("=====Test_27_3 starts:=====\n");
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

	ConnectTreeNodes(pNode8, nullptr, pNode7);
	ConnectTreeNodes(pNode7, nullptr, pNode6);
	ConnectTreeNodes(pNode6, nullptr, pNode5);
	ConnectTreeNodes(pNode5, nullptr, pNode4);

	PrintTree(pNode8);

	printf("=====Test_27_3: MirrorRecursively=====\n");
	MirrorRecursively(pNode8);
	PrintTree(pNode8);

	printf("=====Test_27_3: MirrorIteratively=====\n");
	MirrorIteratively(pNode8);
	PrintTree(pNode8);

	DestroyTree(pNode8);
}

// 测试空二叉树：根结点为空指针
void Test_27_4()
{
	printf("=====Test_27_4 starts:=====\n");
	BinaryTreeNode* pNode = nullptr;

	PrintTree(pNode);

	printf("=====Test_27_4: MirrorRecursively=====\n");
	MirrorRecursively(pNode);
	PrintTree(pNode);

	printf("=====Test_27_4: MirrorIteratively=====\n");
	MirrorIteratively(pNode);
	PrintTree(pNode);
}

// 测试只有一个结点的二叉树
void Test_27_5()
{
	printf("=====Test_27_5 starts:=====\n");
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);

	PrintTree(pNode8);

	printf("=====Test_27_4: MirrorRecursively=====\n");
	MirrorRecursively(pNode8);
	PrintTree(pNode8);

	printf("=====Test_27_4: MirrorIteratively=====\n");
	MirrorIteratively(pNode8);
	PrintTree(pNode8);
}

void offer_27_test()
{
	Test_27_1();
	Test_27_2();
	Test_27_3();
	Test_27_4();
	Test_27_5();

	cout << "offer_27 success" << endl;
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
	void Mirror(TreeNode *pRoot) {
		if (pRoot == nullptr)
			return;

		// 注意：此处的递归跳出条件 不写也行 但是会多进几次递归
		//if (pNode->m_pLeft == nullptr && pNode->m_pRight == nullptr)
		//	return;
		TreeNode* pTmp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = pTmp;

		if (pRoot->right != nullptr)
			Mirror(pRoot->right);
		if (pRoot->left != nullptr)
			Mirror(pRoot->left);
	}
};
*/