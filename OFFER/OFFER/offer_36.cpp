#include "offer_36.h"
#include "Utilities\BinaryTree.h"

/*
	������������˫������
	����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
*/

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList);

BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
	if (pRootOfTree == nullptr)
		return nullptr;

	BinaryTreeNode *pListNodeInList = nullptr;
	ConvertNode(pRootOfTree, &pListNodeInList);

	BinaryTreeNode *pHeadOfList = pListNodeInList;
	while (pHeadOfList != nullptr && pHeadOfList->m_pLeft != nullptr){
		pHeadOfList = pHeadOfList->m_pLeft;
	}
	return pHeadOfList;
}

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList) {
	if (pNode == nullptr)
		return;

	BinaryTreeNode * pCurren = pNode;
	// ����������
	if (pCurren->m_pLeft != nullptr)
		ConvertNode(pCurren->m_pLeft, pLastNodeInList);
	// ǰ��ָ�����������ĵ�		ǰ���������ĺ�����Ҫ����
	pCurren->m_pLeft = *pLastNodeInList;
	// �������������ָ�� ע��˴�Ҫ�ж��Ƿ�Ϊnull
	if (*pLastNodeInList != nullptr)
		(*pLastNodeInList)->m_pRight = pCurren;

	*pLastNodeInList = pCurren;							// �˴���ֹû��������

	// ����������
	if (pCurren->m_pRight != nullptr)
		ConvertNode(pCurren->m_pRight, pLastNodeInList);
}


// ====================���Դ���====================
void PrintDoubleLinkedList(BinaryTreeNode* pHeadOfList)
{
	BinaryTreeNode* pNode = pHeadOfList;

	printf("The nodes from left to right are:\n");
	while (pNode != nullptr)
	{
		printf("%d\t", pNode->m_nValue);

		if (pNode->m_pRight == nullptr)
			break;
		pNode = pNode->m_pRight;
	}

	printf("\nThe nodes from right to left are:\n");
	while (pNode != nullptr)
	{
		printf("%d\t", pNode->m_nValue);

		if (pNode->m_pLeft == nullptr)
			break;
		pNode = pNode->m_pLeft;
	}

	printf("\n");
}

void DestroyList(BinaryTreeNode* pHeadOfList)
{
	BinaryTreeNode* pNode = pHeadOfList;
	while (pNode != nullptr)
	{
		BinaryTreeNode* pNext = pNode->m_pRight;

		delete pNode;
		pNode = pNext;
	}
}

void Test_36(char* testName, BinaryTreeNode* pRootOfTree)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	PrintTree(pRootOfTree);

	BinaryTreeNode* pHeadOfList = Convert(pRootOfTree);

	PrintDoubleLinkedList(pHeadOfList);
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test_36_1()
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

	Test_36("Test_36_1", pNode10);

	DestroyList(pNode4);
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
void Test_36_2()
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

	Test_36("Test_36_2", pNode5);

	DestroyList(pNode1);
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
void Test_36_3()
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

	Test_36("Test_36_3", pNode1);

	DestroyList(pNode1);
}

// ����ֻ��1�����
void Test_36_4()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	Test_36("Test_36_4", pNode1);

	DestroyList(pNode1);
}

// ����û�н��
void Test_36_5()
{
	Test_36("Test_36_5", nullptr);
}

void offer_36_test()
{
	Test_36_1();
	Test_36_2();
	Test_36_3();
	Test_36_4();
	Test_36_5();

	cout << "offer_36 success" << endl;
}

// ţ����ac
/*
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == nullptr)
            return nullptr;

        TreeNode *pListNodeInList = nullptr;
        ConvertNode(pRootOfTree, &pListNodeInList);

        TreeNode *pHeadOfList = pListNodeInList;
        while (pHeadOfList != nullptr && pHeadOfList->left != nullptr){
            pHeadOfList = pHeadOfList->left;
        }
        return pHeadOfList;
    }
    void ConvertNode(TreeNode* pNode, TreeNode** pLastNodeInList) {
        if (pNode == nullptr)
            return;

        TreeNode * pCurren = pNode;
        // ����������
        if (pCurren->left != nullptr)
            ConvertNode(pCurren->left, pLastNodeInList);
        // ǰ��ָ�����������ĵ�
        pCurren->left = *pLastNodeInList;
        // �������������ָ�� ע��˴�Ҫ�ж��Ƿ�Ϊnull
        if (*pLastNodeInList != nullptr)
            (*pLastNodeInList)->right = pCurren;

        *pLastNodeInList = pCurren;							// �˴���ֹû��������

        // ����������
        if (pCurren->right != nullptr)
            ConvertNode(pCurren->right, pLastNodeInList);
    }

};
*/