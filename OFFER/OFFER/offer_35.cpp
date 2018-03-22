#include "offer_35.h"

/*
	复杂链表的复制
	输入一个复杂链表（每个节点中有节点值，以及两个指针，
	一个指向下一个节点，另一个特殊指针指向任意一个节点），
	返回结果为复制后复杂链表的head。
	（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/

ComplexListNode* CreateNode_35(int nValue)
{
	ComplexListNode* pNode = new ComplexListNode();

	pNode->m_nValue = nValue;
	pNode->m_pNext = nullptr;
	pNode->m_pSibling = nullptr;

	return pNode;
}

void BuildNodes_35(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling)
{
	if (pNode != nullptr)
	{
		pNode->m_pNext = pNext;
		pNode->m_pSibling = pSibling;
	}
}

void PrintList_35(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		printf("The value of this node is: %d.\n", pNode->m_nValue);

		if (pNode->m_pSibling != nullptr)
			printf("The value of its sibling is: %d.\n", pNode->m_pSibling->m_nValue);
		else
			printf("This node does not have a sibling.\n");

		printf("\n");

		pNode = pNode->m_pNext;
	}
}


void CloneNodes(ComplexListNode* pHead);
void ConnectSiblingNodes(ComplexListNode* pHead);
ComplexListNode* ReconnectNodes(ComplexListNode* pHead);

ComplexListNode* Clone(ComplexListNode* pHead)
{
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}

void CloneNodes(ComplexListNode* pHead)
{
	if (pHead == nullptr)
		return;
	ComplexListNode* pNode = pHead;
	while (pNode != nullptr){
		ComplexListNode* newNode = new ComplexListNode();
		newNode->m_nValue = pNode->m_nValue;
		newNode->m_pNext = pNode->m_pNext;
		pNode->m_pNext = newNode;
		pNode = newNode->m_pNext;
	}
}

void ConnectSiblingNodes(ComplexListNode* pHead)
{
	if (pHead == nullptr)
		return;
	ComplexListNode* pNode = pHead;
	while (pNode != nullptr) {
		ComplexListNode* nextNode = pNode->m_pNext;
		if (pNode->m_pSibling != nullptr)
			nextNode->m_pSibling = pNode->m_pSibling->m_pNext;
		else
			nextNode->m_pSibling = nullptr;
		pNode = nextNode->m_pNext;
	}
}

ComplexListNode* ReconnectNodes(ComplexListNode* pHead) 
{
	if (pHead == nullptr)
		return nullptr;
	ComplexListNode* pNode = pHead;
	ComplexListNode* newHead = pNode->m_pNext;
	while (pNode != nullptr) {
		ComplexListNode* nextNode = pNode->m_pNext;
		if (pNode->m_pNext != nullptr)
			pNode->m_pNext = nextNode->m_pNext;
		else
			pNode->m_pNext = nullptr;
		if (pNode->m_pNext != nullptr)
			nextNode->m_pNext = pNode->m_pNext->m_pNext;
		pNode = pNode->m_pNext;
	}
	return newHead;
}

// ====================测试代码====================
void Test_35(const char* testName, ComplexListNode* pHead)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	printf("The original list is:\n");
	PrintList_35(pHead);

	ComplexListNode* pClonedHead = Clone(pHead);

	printf("The cloned list is:\n");
	PrintList_35(pClonedHead);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test_35_1()
{
	ComplexListNode* pNode1 = CreateNode_35(1);
	ComplexListNode* pNode2 = CreateNode_35(2);
	ComplexListNode* pNode3 = CreateNode_35(3);
	ComplexListNode* pNode4 = CreateNode_35(4);
	ComplexListNode* pNode5 = CreateNode_35(5);

	BuildNodes_35(pNode1, pNode2, pNode3);
	BuildNodes_35(pNode2, pNode3, pNode5);
	BuildNodes_35(pNode3, pNode4, nullptr);
	BuildNodes_35(pNode4, pNode5, pNode2);

	Test_35("Test_35_1", pNode1);
}

// m_pSibling指向结点自身
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void Test_35_2()
{
	ComplexListNode* pNode1 = CreateNode_35(1);
	ComplexListNode* pNode2 = CreateNode_35(2);
	ComplexListNode* pNode3 = CreateNode_35(3);
	ComplexListNode* pNode4 = CreateNode_35(4);
	ComplexListNode* pNode5 = CreateNode_35(5);

	BuildNodes_35(pNode1, pNode2, nullptr);
	BuildNodes_35(pNode2, pNode3, pNode5);
	BuildNodes_35(pNode3, pNode4, pNode3);
	BuildNodes_35(pNode4, pNode5, pNode2);

	Test_35("Test_35_2", pNode1);
}

// m_pSibling形成环
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
void Test_35_3()
{
	ComplexListNode* pNode1 = CreateNode_35(1);
	ComplexListNode* pNode2 = CreateNode_35(2);
	ComplexListNode* pNode3 = CreateNode_35(3);
	ComplexListNode* pNode4 = CreateNode_35(4);
	ComplexListNode* pNode5 = CreateNode_35(5);

	BuildNodes_35(pNode1, pNode2, nullptr);
	BuildNodes_35(pNode2, pNode3, pNode4);
	BuildNodes_35(pNode3, pNode4, nullptr);
	BuildNodes_35(pNode4, pNode5, pNode2);

	Test_35("Test_35_3", pNode1);
}

// 只有一个结点
void Test_35_4()
{
	ComplexListNode* pNode1 = CreateNode_35(1);
	BuildNodes_35(pNode1, nullptr, pNode1);

	Test_35("Test_35_4", pNode1);
}

// 鲁棒性测试
void Test_35_5()
{
	Test_35("Test_35_5", nullptr);
}

void offer_35_test()
{
	Test_35_1();
	Test_35_2();
	Test_35_3();
	Test_35_4();
	Test_35_5();

	cout << "offer_35 success" << endl;
}

// 牛客网ac
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNodes(pHead);
        ConnectSiblingNodes(pHead);
        return ReconnectNodes(pHead);
    }

    void CloneNodes(RandomListNode* pHead)
    {
        if (pHead == nullptr)
            return;
        RandomListNode* pNode = pHead;
        while (pNode != nullptr){
            RandomListNode* newNode = new RandomListNode(pNode->label);
            newNode->label = pNode->label;
            newNode->next = pNode->next;
            pNode->next = newNode;
            pNode = newNode->next;
        }
    }

    void ConnectSiblingNodes(RandomListNode* pHead)
    {
        if (pHead == nullptr)
            return;
        RandomListNode* pNode = pHead;
        while (pNode != nullptr) {
            RandomListNode* nextNode = pNode->next;
            if (pNode->random != nullptr)
                nextNode->random = pNode->random->next;
            else
                nextNode->random = nullptr;
            pNode = nextNode->next;
        }
    }

    RandomListNode* ReconnectNodes(RandomListNode* pHead) 
    {
        if (pHead == nullptr)
            return nullptr;
        RandomListNode* pNode = pHead;
        RandomListNode* newHead = pNode->next;
        while (pNode != nullptr) {
            RandomListNode* nextNode = pNode->next;
            if (pNode->next != nullptr)
                pNode->next = nextNode->next;
            else
                pNode->next = nullptr;
            if (pNode->next != nullptr)
                nextNode->next = pNode->next->next;
            pNode = pNode->next;
        }
        return newHead;
    }
};
*/