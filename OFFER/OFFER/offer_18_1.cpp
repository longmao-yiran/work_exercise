#include "offer_18_1.h"
#include "Utilities\List.h"

/*
	��O(1)ʱ��ɾ��������
	�������������ͷָ���һ�����ָ�룬����һ��������O(1)ʱ��ɾ���ý�㡣
*/
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)					// ע��˴��õ���ListNode** pListHead ������* ��Ϊ�˷�ֹͷ��㱻ɾ����Ϊnullptr
{
	if (pListHead == nullptr || *pListHead == nullptr) {
		return;
	}

	// ָ��ͷ���
	if (*pListHead == pToBeDeleted) {
		*pListHead = pToBeDeleted->m_pNext;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		return;
	}

	// ָ���β�ڵ�
	if (pToBeDeleted->m_pNext != nullptr) {
		ListNode *pTempListNode = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pTempListNode->m_nValue;
		pToBeDeleted->m_pNext = pTempListNode->m_pNext;
		delete pTempListNode;
		pTempListNode = nullptr;
		return;
	}
	// ָ��β�ڵ�
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

// ====================���Դ���====================
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

// �������ж����㣬ɾ���м�Ľ��
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

// �������ж����㣬ɾ��β���
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

// �������ж����㣬ɾ��ͷ���
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

// ������ֻ��һ����㣬ɾ��ͷ���
void Test_18_1_4()
{
	ListNode* pNode1 = CreateListNode(1);

	Test_18_1(pNode1, pNode1);
}

// ����Ϊ��
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