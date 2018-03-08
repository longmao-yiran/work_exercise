#include "offer_23.h"
#include "Utilities\List.h"

/*
	链表中环的入口结点
	一个链表中包含环，请找出该链表的环的入口结点。
*/

// 找到环内节点
ListNode* MeetingNode(ListNode* pHead)
{
	if (pHead == nullptr)
		return nullptr;
	ListNode* pNode1 = pHead;
	ListNode* pNode2 = pHead;

	if (pNode2 != nullptr)
		pNode2 = pNode2->m_pNext;
	else
		return nullptr;
	if (pNode2 != nullptr)
		pNode2 = pNode2->m_pNext;
	else
		return nullptr;

	if (pNode1 != nullptr)
		pNode1 = pNode1->m_pNext;
	else
		return nullptr;

	while (pNode1 != pNode2)
	{
		if (pNode2 != nullptr)
			pNode2 = pNode2->m_pNext;
		else
			return nullptr;
		if (pNode2 != nullptr)
			pNode2 = pNode2->m_pNext;
		else
			return nullptr;

		if (pNode1 != nullptr)
			pNode1 = pNode1->m_pNext;
		else
			return nullptr;
	}
	return pNode1;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	if (pHead == nullptr)
		return nullptr;
	ListNode* pNode = MeetingNode(pHead);

	if (pNode == nullptr)
		return nullptr;

	int loopNum = 1;
	ListNode* pNodeTemp = pNode;
	pNode = pNode->m_pNext;
	while (pNode != pNodeTemp){
		pNode = pNode->m_pNext;
		++loopNum;
	}
	pNode = pHead;
	for (int i = 0;i < loopNum;++i) {
		pNode = pNode->m_pNext;
	}
	pNodeTemp = pHead;
	while (pNodeTemp != pNode){
		pNode = pNode->m_pNext;
		pNodeTemp = pNodeTemp->m_pNext;
	}
	return pNode;
}

// ==================== 测试代码 ====================
void Test_23(char* testName, ListNode* pHead, ListNode* entryNode)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (EntryNodeOfLoop(pHead) == entryNode)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

// A list has a node, without a loop
void Test_23_1()
{
	ListNode* pNode1 = CreateListNode(1);

	Test_23("Test_23_1", pNode1, nullptr);

	DestroyList(pNode1);
}

// A list has a node, with a loop
void Test_23_2()
{
	ListNode* pNode1 = CreateListNode(1);
	ConnectListNodes(pNode1, pNode1);

	Test_23("Test_23_2", pNode1, pNode1);

	delete pNode1;
	pNode1 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test_23_3()
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
	ConnectListNodes(pNode5, pNode3);

	Test_23("Test_23_3", pNode1, pNode3);

	delete pNode1;
	pNode1 = nullptr;
	delete pNode2;
	pNode2 = nullptr;
	delete pNode3;
	pNode3 = nullptr;
	delete pNode4;
	pNode4 = nullptr;
	delete pNode5;
	pNode5 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test_23_4()
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
	ConnectListNodes(pNode5, pNode1);

	Test_23("Test_23_4", pNode1, pNode1);

	delete pNode1;
	pNode1 = nullptr;
	delete pNode2;
	pNode2 = nullptr;
	delete pNode3;
	pNode3 = nullptr;
	delete pNode4;
	pNode4 = nullptr;
	delete pNode5;
	pNode5 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test_23_5()
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
	ConnectListNodes(pNode5, pNode5);

	Test_23("Test_23_5", pNode1, pNode5);

	delete pNode1;
	pNode1 = nullptr;
	delete pNode2;
	pNode2 = nullptr;
	delete pNode3;
	pNode3 = nullptr;
	delete pNode4;
	pNode4 = nullptr;
	delete pNode5;
	pNode5 = nullptr;
}

// A list has multiple nodes, without a loop 
void Test_23_6()
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

	Test_23("Test_23_6", pNode1, nullptr);

	DestroyList(pNode1);
}

// Empty list
void Test_23_7()
{
	Test_23("Test_23_7", nullptr, nullptr);
}

void offer_23_test()
{
	Test_23_1();
	Test_23_2();
	Test_23_3();
	Test_23_4();
	Test_23_5();
	Test_23_6();
	Test_23_7();

	cout << "offer_23 success" << endl;
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (pHead == nullptr)
                return nullptr;
        ListNode* pNode = MeetingNode(pHead);

        if (pNode == nullptr)
            return nullptr;

        int loopNum = 1;
        ListNode* pNodeTemp = pNode;
        pNode = pNode->next;
        while (pNode != pNodeTemp){
            pNode = pNode->next;
            ++loopNum;
        }
        pNode = pHead;
        for (int i = 0;i < loopNum;++i) {
            pNode = pNode->next;
        }
        pNodeTemp = pHead;
        while (pNodeTemp != pNode){
            pNode = pNode->next;
            pNodeTemp = pNodeTemp->next;
        }
        return pNode;
    }
    ListNode* MeetingNode(ListNode* pHead)
    {
        if (pHead == nullptr)
            return nullptr;
        ListNode* pNode1 = pHead;
        ListNode* pNode2 = pHead;

        if (pNode2 != nullptr)
            pNode2 = pNode2->next;
        else
            return nullptr;
        if (pNode2 != nullptr)
            pNode2 = pNode2->next;
        else
            return nullptr;

        if (pNode1 != nullptr)
            pNode1 = pNode1->next;
        else
            return nullptr;

        while (pNode1 != pNode2)
        {
            if (pNode2 != nullptr)
                pNode2 = pNode2->next;
            else
                return nullptr;
            if (pNode2 != nullptr)
                pNode2 = pNode2->next;
            else
                return nullptr;

            if (pNode1 != nullptr)
                pNode1 = pNode1->next;
            else
                return nullptr;
        }
        return pNode1;
    }
};	
*/