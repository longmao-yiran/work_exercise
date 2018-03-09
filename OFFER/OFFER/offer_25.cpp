#include "offer_25.h"
#include "Utilities\List.h"

/*
	�ϲ��������������
	���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
*/

// �ǵݹ鷽��
ListNode* Merge_1(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr && pHead2 == nullptr)
		return nullptr;
	if (pHead1 == nullptr)
		return pHead2;
	if (pHead2 == nullptr)
		return pHead1;

	ListNode* pNewListHead = nullptr;
	ListNode* pNode = nullptr;

	ListNode* pNode1 = pHead1;
	ListNode* pNode2 = pHead2;
	// �ȸ㶨ͷ���
	if (pHead1->m_nValue < pHead2->m_nValue) {
		pNewListHead = pHead1;
		pNode1 = pNode1->m_pNext;
	}
	else {
		pNewListHead = pHead2;
		pNode2 = pNode2->m_pNext;
	}
	pNode = pNewListHead;
	
	while (pNode1 != nullptr && pNode2 != nullptr)
	{
		if (pNode1->m_nValue < pNode2->m_nValue) {
			pNode->m_pNext = pNode1;
			pNode1 = pNode1->m_pNext;
			pNode = pNode->m_pNext;
		}
		else {
			pNode->m_pNext = pNode2;
			pNode2 = pNode2->m_pNext;
			pNode = pNode->m_pNext;
		}
	}
	if (pNode1 != nullptr)
		pNode->m_pNext = pNode1;
	else
		pNode->m_pNext = pNode2;

	return pNewListHead;
}

// �ݹ鷽��
ListNode* Merge_2(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr)
		return pHead2;
	if (pHead2 == nullptr)
		return pHead1;

	ListNode* pNewHead = nullptr;
	if (pHead1->m_nValue < pHead2->m_nValue) {
		pNewHead = pHead1;
		pNewHead->m_pNext = Merge_2(pHead1->m_pNext, pHead2);
	}
	else {
		pNewHead = pHead2;
		pNewHead->m_pNext = Merge_2(pHead1, pHead2->m_pNext);
	}
	return pNewHead;
}

// ====================���Դ���====================
ListNode* Test_25(char* testName, ListNode* pHead1, ListNode* pHead2)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	printf("The first list is:\n");
	PrintList(pHead1);

	printf("The second list is:\n");
	PrintList(pHead2);

	printf("The Merge_1 list is:\n");
	ListNode* pMergedHead = Merge_1(pHead1, pHead2);
	PrintList(pMergedHead);

	//printf("The Merge_2 list is:\n");
	//ListNode* pMergedHead_2 = Merge_2(pHead1, pHead2);
	//PrintList(pMergedHead_2);

	printf("\n\n");

	return pMergedHead;
}

// list1: 1->3->5
// list2: 2->4->6
void Test_25_1()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode3);
	ConnectListNodes(pNode3, pNode5);

	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode6 = CreateListNode(6);

	ConnectListNodes(pNode2, pNode4);
	ConnectListNodes(pNode4, pNode6);

	ListNode* pMergedHead = Test_25("Test_25_1", pNode1, pNode2);

	DestroyList(pMergedHead);
}

// �������������ظ�������
// list1: 1->3->5
// list2: 1->3->5
void Test_25_2()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode3);
	ConnectListNodes(pNode3, pNode5);

	ListNode* pNode2 = CreateListNode(1);
	ListNode* pNode4 = CreateListNode(3);
	ListNode* pNode6 = CreateListNode(5);

	ConnectListNodes(pNode2, pNode4);
	ConnectListNodes(pNode4, pNode6);

	ListNode* pMergedHead = Test_25("Test_25_2", pNode1, pNode2);

	DestroyList(pMergedHead);
}

// ��������ֻ��һ������
// list1: 1
// list2: 2
void Test_25_3()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);

	ListNode* pMergedHead = Test_25("Test_25_3", pNode1, pNode2);

	DestroyList(pMergedHead);
}

// һ������Ϊ������
// list1: 1->3->5
// list2: ������
void Test_25_4()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode3);
	ConnectListNodes(pNode3, pNode5);

	ListNode* pMergedHead = Test_25("Test_25_4", pNode1, nullptr);

	DestroyList(pMergedHead);
}

// ��������Ϊ������
// list1: ������
// list2: ������
void Test_25_5()
{
	ListNode* pMergedHead = Test_25("Test_25_5", nullptr, nullptr);
}

void offer_25_test()
{
	Test_25_1();
	Test_25_2();
	Test_25_3();
	Test_25_4();
	Test_25_5();

	cout << "offer_25 success" << endl;
}

// ţ����ac
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == nullptr && pHead2 == nullptr)
            return nullptr;
        if (pHead1 == nullptr)
            return pHead2;
        if (pHead2 == nullptr)
            return pHead1;

        ListNode* pNewListHead = nullptr;
        ListNode* pNode = nullptr;

        ListNode* pNode1 = pHead1;
        ListNode* pNode2 = pHead2;
        // �ȸ㶨ͷ���
        if (pHead1->val < pHead2->val) {
            pNewListHead = pHead1;
            pNode1 = pNode1->next;
        }
        else {
            pNewListHead = pHead2;
            pNode2 = pNode2->next;
        }
        pNode = pNewListHead;

        while (pNode1 != nullptr && pNode2 != nullptr)
        {
            if (pNode1->val < pNode2->val) {
                pNode->next = pNode1;
                pNode1 = pNode1->next;
                pNode = pNode->next;
            }
            else {
                pNode->next = pNode2;
                pNode2 = pNode2->next;
                pNode = pNode->next;
            }
        }
        if (pNode1 != nullptr)
            pNode->next = pNode1;
        else
            pNode->next = pNode2;

        return pNewListHead;
    }
};
*/