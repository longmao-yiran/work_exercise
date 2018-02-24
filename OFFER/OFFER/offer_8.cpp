#include "offer_8.h"

/*
	给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
	注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/

struct BinaryTreeWihtParentNode
{
	int m_nValue;
	BinaryTreeWihtParentNode* m_pLeft;
	BinaryTreeWihtParentNode* m_pRight;
	BinaryTreeWihtParentNode* m_pParent;
};

/*
	分三种情况：
		1.有右节点，右节点一路找左节点，如果没有就是右节点
		2.没有右节点，是父亲节点的左节点，则父亲节点为下一个
		3.没有右节点，同时是父亲节点的右节点，一路找父亲节点，知道有父亲节点是爷爷节点的左节点，则爷爷节点为下一个 如果没有则没有下一个节点
*/
BinaryTreeWihtParentNode* GetNext(BinaryTreeWihtParentNode* pNode)
{
	if (pNode != nullptr) {
		BinaryTreeWihtParentNode* pNext = nullptr;
		// 情况1
		if (pNode->m_pRight != nullptr) {
			pNext = pNode->m_pRight;
			while (pNext->m_pLeft != nullptr){
				pNext = pNext->m_pLeft;
			}
			return pNext;
		}
		if (pNode->m_pParent != nullptr) {					// 注意此处如果是根节点 可能存在没有父节点的情况
			// 情况2
			if (pNode->m_pParent->m_pLeft == pNode) {
				return pNode->m_pParent;
			}
			// 情况3
			if (pNode->m_pParent->m_pRight == pNode) {
				pNext = pNode->m_pParent;
				while (pNext->m_pParent != nullptr && pNext->m_pParent->m_pRight == pNext)
				{
					pNext = pNext->m_pParent;
				}
				if (pNext->m_pParent != nullptr) {
					pNext = pNext->m_pParent;
				}else {
					pNext = nullptr;
				}
				return pNext;
			}
		}
	}
	return nullptr;
}

// ==================== 辅助代码用来构建二叉树 ====================
BinaryTreeWihtParentNode* CreateBinaryTreeWihtParentNode(int value)
{
	BinaryTreeWihtParentNode* pNode = new BinaryTreeWihtParentNode();
	pNode->m_nValue = value;
	pNode->m_pLeft = nullptr;
	pNode->m_pRight = nullptr;
	pNode->m_pParent = nullptr;
	
	return pNode;
}

void ConnectTreeNodes(BinaryTreeWihtParentNode* pParent, BinaryTreeWihtParentNode* pLeft, BinaryTreeWihtParentNode* pRight)
{
	if (pParent != nullptr) {
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;

		if (pLeft != nullptr) {
			pLeft->m_pParent = pParent;
		}
		if (pRight != nullptr) {
			pRight->m_pParent = pParent;
		}
	}
}

void PrintTreeNode(BinaryTreeWihtParentNode* pNode)
{
	if (pNode != nullptr)
	{
		printf("value of this node is: %d\n", pNode->m_nValue);

		if (pNode->m_pLeft != nullptr)
			printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
		else
			printf("left child is null.\n");

		if (pNode->m_pRight != nullptr)
			printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
		else
			printf("right child is null.\n");
	}
	else
	{
		printf("this node is null.\n");
	}

	printf("\n");
}

void PrintTree(BinaryTreeWihtParentNode* pRoot)
{
	PrintTreeNode(pRoot);

	if (pRoot != nullptr)
	{
		if (pRoot->m_pLeft != nullptr)
			PrintTree(pRoot->m_pLeft);

		if (pRoot->m_pRight != nullptr)
			PrintTree(pRoot->m_pRight);
	}
}

void DestroyTree(BinaryTreeWihtParentNode* pRoot)
{
	if (pRoot != nullptr) {
		BinaryTreeWihtParentNode* pLeft = pRoot->m_pLeft;
		BinaryTreeWihtParentNode* pRight = pRoot->m_pRight;

		delete pRoot;
		pRoot = nullptr;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}

// ====================测试代码====================
void Test_8(char* testName, BinaryTreeWihtParentNode* pNode, BinaryTreeWihtParentNode* expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	BinaryTreeWihtParentNode* pNext = GetNext(pNode);
	if (pNext == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

//            8
//        6      10
//       5 7    9  11
void Test_8_1()
{
	BinaryTreeWihtParentNode* pNode8 = CreateBinaryTreeWihtParentNode(8);
	BinaryTreeWihtParentNode* pNode6 = CreateBinaryTreeWihtParentNode(6);
	BinaryTreeWihtParentNode* pNode10 = CreateBinaryTreeWihtParentNode(10);
	BinaryTreeWihtParentNode* pNode5 = CreateBinaryTreeWihtParentNode(5);
	BinaryTreeWihtParentNode* pNode7 = CreateBinaryTreeWihtParentNode(7);
	BinaryTreeWihtParentNode* pNode9 = CreateBinaryTreeWihtParentNode(9);
	BinaryTreeWihtParentNode* pNode11 = CreateBinaryTreeWihtParentNode(11);

	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);

	Test_8("Test1", pNode8, pNode9);
	Test_8("Test2", pNode6, pNode7);
	Test_8("Test3", pNode10, pNode11);
	Test_8("Test4", pNode5, pNode6);
	Test_8("Test5", pNode7, pNode8);
	Test_8("Test6", pNode9, pNode10);
	Test_8("Test7", pNode11, nullptr);

	DestroyTree(pNode8);
}

//            5
//          4
//        3
//      2
void Test_8_2()
{
	BinaryTreeWihtParentNode* pNode5 = CreateBinaryTreeWihtParentNode(5);
	BinaryTreeWihtParentNode* pNode4 = CreateBinaryTreeWihtParentNode(4);
	BinaryTreeWihtParentNode* pNode3 = CreateBinaryTreeWihtParentNode(3);
	BinaryTreeWihtParentNode* pNode2 = CreateBinaryTreeWihtParentNode(2);

	ConnectTreeNodes(pNode5, pNode4, nullptr);
	ConnectTreeNodes(pNode4, pNode3, nullptr);
	ConnectTreeNodes(pNode3, pNode2, nullptr);

	Test_8("Test8", pNode5, nullptr);
	Test_8("Test9", pNode4, pNode5);
	Test_8("Test10", pNode3, pNode4);
	Test_8("Test11", pNode2, pNode3);

	DestroyTree(pNode5);
}

//        2
//         3
//          4
//           5
void Test_8_3()
{
	BinaryTreeWihtParentNode* pNode2 = CreateBinaryTreeWihtParentNode(2);
	BinaryTreeWihtParentNode* pNode3 = CreateBinaryTreeWihtParentNode(3);
	BinaryTreeWihtParentNode* pNode4 = CreateBinaryTreeWihtParentNode(4);
	BinaryTreeWihtParentNode* pNode5 = CreateBinaryTreeWihtParentNode(5);

	ConnectTreeNodes(pNode2, nullptr, pNode3);
	ConnectTreeNodes(pNode3, nullptr, pNode4);
	ConnectTreeNodes(pNode4, nullptr, pNode5);

	Test_8("Test12", pNode5, nullptr);
	Test_8("Test13", pNode4, pNode5);
	Test_8("Test14", pNode3, pNode4);
	Test_8("Test15", pNode2, pNode3);

	DestroyTree(pNode2);
}

void Test_8_4()
{
	BinaryTreeWihtParentNode* pNode5 = CreateBinaryTreeWihtParentNode(5);

	Test_8("Test16", pNode5, nullptr);

	DestroyTree(pNode5);
}

void offer_8_test()
{
	Test_8_1();
	Test_8_2();
	Test_8_3();
	Test_8_4();
	cout << "offer_8 success" << endl;

}

// 牛客网 ac
/*
struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
	}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode != nullptr) {
			TreeLinkNode* pNext = nullptr;
			// 情况1
			if (pNode->right != nullptr) {
				pNext = pNode->right;
				while (pNext->left != nullptr) {
					pNext = pNext->left;
				}
				return pNext;
			}
			if (pNode->next != nullptr) {					// 注意此处如果是根节点 可能存在没有父节点的情况
																// 情况2
				if (pNode->next->left == pNode) {
					return pNode->next;
				}
				// 情况3
				if (pNode->next->right == pNode) {
					pNext = pNode->next;
					while (pNext->next != nullptr && pNext->next->right == pNext)
					{
						pNext = pNext->next;
					}
					if (pNext->next != nullptr) {
						pNext = pNext->next;
					}
					else {
						pNext = nullptr;
					}
					return pNext;
				}
			}
		}
		return nullptr;
	}
};
*/