#include "offer_27.h"
#include "Utilities\BinaryTree.h"

/*
	�������ľ���
	���������Ķ�����������任ΪԴ�������ľ���
	�������ľ����壺Դ������
	   8
	 /  \
	6   10
	/ \  / \
   5   7 9 11
	���������
	   8
	 /  \
	10   6
	/ \  / \
   11 9 7   5
*/

// �ݹ鷽��
void MirrorRecursively(BinaryTreeNode *pNode)
{
	if (pNode == nullptr)
		return;

	// ע�⣺�˴��ĵݹ��������� ��дҲ�� ���ǻ������εݹ�
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

// �ǵݹ�汾
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

// ====================���Դ���====================
// ������ȫ������������Ҷ�ӽڵ㣬�����ڵ㶼�������ӽڵ�
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

// ���Զ���������Ҷ�ӽ��֮�⣬���ҵĽ�㶼����ֻ��һ�����ӽ��
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

// ���Զ���������Ҷ�ӽ��֮�⣬���ҵĽ�㶼����ֻ��һ�����ӽ��
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

// ���Կն������������Ϊ��ָ��
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

// ����ֻ��һ�����Ķ�����
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

// ţ����ac
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

		// ע�⣺�˴��ĵݹ��������� ��дҲ�� ���ǻ������εݹ�
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