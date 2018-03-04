#include "offer_18_1.h"
#include "Utilities\List.h"

/*
	在O(1)时间删除链表结点
	给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该结点。
*/
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)					// 注意此处用的是ListNode** pListHead 而不是* 是为了防止头结点被删除后为nullptr
{
	if (pListHead == nullptr || *pListHead == nullptr) {
		return;
	}

	// 指向头结点
	if (*pListHead == pToBeDeleted) {
		*pListHead = pToBeDeleted->m_pNext;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		return;
	}

	// 指向非尾节点
	if (pToBeDeleted->m_pNext != nullptr) {
		ListNode *pTempListNode = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pTempListNode->m_nValue;
		pToBeDeleted->m_pNext = pTempListNode->m_pNext;
		delete pTempListNode;
		pTempListNode = nullptr;
		return;
	}
	// 指向尾节点
	if (pToBeDeleted->m_pNext == nullptr) {
		ListNode *pTempListNode = (*pListHead)->m_pNext;
		while (pTempListNode->m_pNext != pToBeDeleted)
			pTempListNode = pTempListNode->m_pNext;
		pTempListNode->m_pNext = nullptr;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		return;
	}
	return;
}

// ====================测试代码====================
void Test_18_1(ListNode* pListHead, ListNode* pNode)
{
	printf("The original list is: \n");
	PrintList(pListHead);

	printf("The node to be deleted is: \n");
	PrintListNode(pNode);

	DeleteNode(&pListHead, pNode);

	printf("The result list is: \n");
	PrintList(pListHead);
}

// 链表中有多个结点，删除中间的结点
void Test_18_1_1()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test_18_1(pNode1, pNode3);

	DestroyList(pNode1);
}

// 链表中有多个结点，删除尾结点
void Test_18_1_2()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test_18_1(pNode1, pNode5);

	DestroyList(pNode1);
}

// 链表中有多个结点，删除头结点
void Test_18_1_3()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test_18_1(pNode1, pNode1);

	DestroyList(pNode1);
}

// 链表中只有一个结点，删除头结点
void Test_18_1_4()
{
	ListNode* pNode1 = CreateListNode(1);

	Test_18_1(pNode1, pNode1);
}

// 链表为空
void Test_18_1_5()
{
	Test_18_1(nullptr, nullptr);
}

void offer_18_1_test()
{
	Test_18_1_1();
	Test_18_1_2();
	Test_18_1_3();
	Test_18_1_4();
	Test_18_1_5();

	cout << "offer_18_1 success" << endl;
}