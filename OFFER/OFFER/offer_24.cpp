#include "offer_24.h"
#include "Utilities\List.h"

/*
	反转链表
	输入一个链表，反转链表后，输出链表的所有元素。
*/

ListNode* ReverseList(ListNode* pHead)
{
	if (pHead == nullptr)
		return nullptr;

	ListNode* pNodeFront = pHead;
	ListNode* pNode = pHead->m_pNext;
	ListNode* pNodeLater = nullptr;
	
	if (pNode != nullptr)
		pNodeLater = pNode->m_pNext;
	else
		return pHead;

	pNodeFront->m_pNext = nullptr;
	while (pNodeLater != nullptr){
		pNode->m_pNext = pNodeFront;
		pNodeFront = pNode;
		pNode = pNodeLater;
		pNodeLater = pNodeLater->m_pNext;
	}
	pNode->m_pNext = pNodeFront;
	pHead = pNode;

	return pHead;
}

// ====================测试代码====================
ListNode* Test_24(ListNode* pHead)
{
	printf("The original list is: \n");
	PrintList(pHead);

	ListNode* pReversedHead = ReverseList(pHead);

	printf("The reversed list is: \n");
	PrintList(pReversedHead);

	return pReversedHead;
}

// 输入的链表有多个结点
void Test_24_1()
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

	ListNode* pReversedHead = Test_24(pNode1);

	DestroyList(pReversedHead);
}

// 输入的链表只有一个结点
void Test_24_2()
{
	ListNode* pNode1 = CreateListNode(1);

	ListNode* pReversedHead = Test_24(pNode1);

	DestroyList(pReversedHead);
}

// 输入空链表
void Test_24_3()
{
	Test_24(nullptr);
}

void offer_24_test()
{
	Test_24_1();
	Test_24_2();
	Test_24_3();

	cout << "offer_24 success" << endl;
}

// 牛客网ac
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
    ListNode* ReverseList(ListNode* pHead) {
	    if (pHead == nullptr)
		    return nullptr;

        ListNode* pNodeFront = pHead;
        ListNode* pNode = pHead->next;
        ListNode* pNodeLater = nullptr;

        if (pNode != nullptr)
            pNodeLater = pNode->next;
        else
            return pHead;

        pNodeFront->next = nullptr;
        while (pNodeLater != nullptr){
            pNode->next = pNodeFront;
            pNodeFront = pNode;
            pNode = pNodeLater;
            pNodeLater = pNodeLater->next;
        }
        pNode->next = pNodeFront;
        pHead = pNode;

        return pHead;
    }
};
*/