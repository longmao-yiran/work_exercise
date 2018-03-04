#include "offer_18_2.h"
#include "Utilities\List.h"

/*
	删除链表中重复的结点
	在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
	例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

void DeleteDuplication(ListNode** pHead)
{
	if (pHead == nullptr || *pHead == nullptr)
		return;

	ListNode* pNode = *pHead;
	ListNode* pPreNdoe = nullptr;

	while (pNode){
		bool isDelete = false;
		ListNode* pNext = pNode->m_pNext;
		if (pNext != nullptr && pNode->m_nValue == pNext->m_nValue)
			isDelete = true;
		if (!isDelete) {
			pPreNdoe = pNode;
			pNode = pNext;
		}
		else{
			int deleteVlaue = pNode->m_nValue;
			ListNode* pToDelete = nullptr;
			while (pNode != nullptr && pNode->m_nValue == deleteVlaue){
				pToDelete = pNode;
				pNode = pNode->m_pNext;
				delete pToDelete;
				pToDelete = nullptr;
			}
			if (pPreNdoe == nullptr)			// 注意：相当于删除了头结点
				*pHead = pNode;
			else
				pPreNdoe->m_pNext = pNode;
		}
	}
}

// ====================测试代码====================
void Test_18_2(char* testName, ListNode** pHead, int* expectedValues, int expectedLength)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	DeleteDuplication(pHead);

	int index = 0;
	ListNode* pNode = *pHead;
	while (pNode != nullptr && index < expectedLength)
	{
		if (pNode->m_nValue != expectedValues[index])
			break;

		pNode = pNode->m_pNext;
		index++;
	}

	if (pNode == nullptr && index == expectedLength)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

// 某些结点是重复的
void Test_18_2_1()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(3);
	ListNode* pNode5 = CreateListNode(4);
	ListNode* pNode6 = CreateListNode(4);
	ListNode* pNode7 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);

	ListNode* pHead = pNode1;

	int expectedValues[] = { 1, 2, 5 };
	Test_18_2("Test_18_2_1", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

	DestroyList(pHead);
}

// 没有重复的结点
void Test_18_2_2()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);
	ListNode* pNode6 = CreateListNode(6);
	ListNode* pNode7 = CreateListNode(7);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);

	ListNode* pHead = pNode1;

	int expectedValues[] = { 1, 2, 3, 4, 5, 6, 7 };
	Test_18_2("Test_18_2_2", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

	DestroyList(pHead);
}

// 除了一个结点之外其他所有结点的值都相同
void Test_18_2_3()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(1);
	ListNode* pNode4 = CreateListNode(1);
	ListNode* pNode5 = CreateListNode(1);
	ListNode* pNode6 = CreateListNode(1);
	ListNode* pNode7 = CreateListNode(2);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);

	ListNode* pHead = pNode1;

	int expectedValues[] = { 2 };
	Test_18_2("Test_18_2_3", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

	DestroyList(pHead);
}

// 所有结点的值都相同
void Test_18_2_4()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(1);
	ListNode* pNode4 = CreateListNode(1);
	ListNode* pNode5 = CreateListNode(1);
	ListNode* pNode6 = CreateListNode(1);
	ListNode* pNode7 = CreateListNode(1);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);

	ListNode* pHead = pNode1;

	Test_18_2("Test_18_2_4", &pHead, nullptr, 0);

	DestroyList(pHead);
}

// 所有结点都成对出现
void Test_18_2_5()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(2);
	ListNode* pNode4 = CreateListNode(2);
	ListNode* pNode5 = CreateListNode(3);
	ListNode* pNode6 = CreateListNode(3);
	ListNode* pNode7 = CreateListNode(4);
	ListNode* pNode8 = CreateListNode(4);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);
	ConnectListNodes(pNode7, pNode8);

	ListNode* pHead = pNode1;

	Test_18_2("Test_18_2_5", &pHead, nullptr, 0);

	DestroyList(pHead);
}

// 除了两个结点之外其他结点都成对出现
void Test_18_2_6()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(1);
	ListNode* pNode3 = CreateListNode(2);
	ListNode* pNode4 = CreateListNode(3);
	ListNode* pNode5 = CreateListNode(3);
	ListNode* pNode6 = CreateListNode(4);
	ListNode* pNode7 = CreateListNode(5);
	ListNode* pNode8 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);
	ConnectListNodes(pNode7, pNode8);

	ListNode* pHead = pNode1;

	int expectedValues[] = { 2, 4 };
	Test_18_2("Test_18_2_6", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

	DestroyList(pHead);
}

// 链表中只有两个不重复的结点
void Test_18_2_7()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);

	ConnectListNodes(pNode1, pNode2);

	ListNode* pHead = pNode1;

	int expectedValues[] = { 1, 2 };
	Test_18_2("Test_18_2_7", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

	DestroyList(pHead);
}

// 结点中只有一个结点
void Test_18_2_8()
{
	ListNode* pNode1 = CreateListNode(1);

	ConnectListNodes(pNode1, nullptr);

	ListNode* pHead = pNode1;

	int expectedValues[] = { 1 };
	Test_18_2("Test_18_2_8", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

	DestroyList(pHead);
}

// 结点中只有两个重复的结点
void Test_18_2_9()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(1);

	ConnectListNodes(pNode1, pNode2);

	ListNode* pHead = pNode1;

	Test_18_2("Test_18_2_9", &pHead, nullptr, 0);

	DestroyList(pHead);
}

// 空链表
void Test_18_2_10()
{
	ListNode* pHead = nullptr;

	Test_18_2("Test_18_2_10", &pHead, nullptr, 0);
}

void offer_18_2_test()
{
	Test_18_2_1();
	Test_18_2_2();
	Test_18_2_3();
	Test_18_2_4();
	Test_18_2_5();
	Test_18_2_6();
	Test_18_2_7();
	Test_18_2_8();
	Test_18_2_9();
	Test_18_2_10();

	cout << "offer_18_2 success" << endl;
}

// 牛客网 ac
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
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == nullptr)
			return pHead;

		ListNode* pNode = pHead;
		ListNode* pPreNdoe = nullptr;

		while (pNode) {
			bool isDelete = false;
			ListNode* pNext = pNode->next;
			if (pNext != nullptr && pNode->val == pNext->val)
				isDelete = true;
			if (!isDelete) {
				pPreNdoe = pNode;
				pNode = pNext;
			}
			else {
				int deleteVlaue = pNode->val;
				ListNode* pToDelete = nullptr;
				while (pNode != nullptr && pNode->val == deleteVlaue) {
					pToDelete = pNode;
					pNode = pNode->next;
					delete pToDelete;
					pToDelete = nullptr;
				}
				if (pPreNdoe == nullptr)			// 注意：相当于删除了头结点
					pHead = pNode;
				else
					pPreNdoe->next = pNode;
			}
		}
		return pHead;
	}
};
*/