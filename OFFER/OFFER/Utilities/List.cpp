// list 相关操作
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// 创建一个节点
ListNode* CreateListNode(int value)
{
    ListNode* pNode = new ListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = nullptr;

    return pNode;
}

// 链接两个节点
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
    if(pCurrent == nullptr)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }

    pCurrent->m_pNext = pNext;
}

// 输出节点的值
void PrintListNode(ListNode* pNode)
{ 
    if(pNode == nullptr)
    {
        printf("The node is nullptr\n");
    }
    else
    {
        printf("The key in node is %d.\n", pNode->m_nValue);
    }
}

// 输出整个链表的值
void PrintList(ListNode* pHead)
{
    printf("PrintList starts.\n");
    
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->m_nValue);
        pNode = pNode->m_pNext;
    }

    printf("\nPrintList ends.\n");
}

// 销毁链表
void DestroyList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        pHead = pHead->m_pNext;
        delete pNode;
        pNode = pHead;
    }
}

// 在末尾添加
void AddToTail(ListNode** pHead, int value)
{
	// pHead是指向头指针的指针 *pHead是头指针
	if (pHead == nullptr)
		return;

	ListNode *pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;
	// 如果在指针头
	if (*pHead == nullptr) {
		*pHead = pNew;
	}
	else
	{
		ListNode *pNode = *pHead;
		while (pNode->m_pNext != nullptr) {
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = pNew;
	}
}

void RemoveNode(ListNode** pHead, int value)
{
	if (pHead == nullptr)
		return;
	// 如果头指针为空 则没有删除的内存
	if (*pHead == nullptr)
		return;

	ListNode *pNode = *pHead;				// 中转指针
	ListNode *pToBeDeleted = nullptr;		// 要删除的指针
	// 若果删除的是指针头 则头指针指向下一位
	if (pNode->m_nValue == value) {
		pToBeDeleted = *pHead;
		*pHead = pNode->m_pNext;
	}
	else {
		ListNode *pPrevious = *pHead;
		while (pNode->m_nValue != value && pNode->m_pNext != nullptr) {
			pPrevious = pNode;			// 始终指向上一个指针
			pNode = pNode->m_pNext;
		}
		// 由于有可能存在没有value的情况 此处删除指针要进行判断  此处容易忽略
		if (pNode->m_nValue == value) {
			pToBeDeleted = pNode;
			pPrevious = pNode->m_pNext;
		}
	}

	if (pToBeDeleted != nullptr) {
		delete pToBeDeleted;
		pToBeDeleted == nullptr;
	}
}