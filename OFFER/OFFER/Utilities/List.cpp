// list ��ز���
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// ����һ���ڵ�
ListNode* CreateListNode(int value)
{
    ListNode* pNode = new ListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = nullptr;

    return pNode;
}

// ���������ڵ�
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
    if(pCurrent == nullptr)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }

    pCurrent->m_pNext = pNext;
}

// ����ڵ��ֵ
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

// ������������ֵ
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

// ��������
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

// ��ĩβ���
void AddToTail(ListNode** pHead, int value)
{
	// pHead��ָ��ͷָ���ָ�� *pHead��ͷָ��
	if (pHead == nullptr)
		return;

	ListNode *pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;
	// �����ָ��ͷ
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
	// ���ͷָ��Ϊ�� ��û��ɾ�����ڴ�
	if (*pHead == nullptr)
		return;

	ListNode *pNode = *pHead;				// ��תָ��
	ListNode *pToBeDeleted = nullptr;		// Ҫɾ����ָ��
	// ����ɾ������ָ��ͷ ��ͷָ��ָ����һλ
	if (pNode->m_nValue == value) {
		pToBeDeleted = *pHead;
		*pHead = pNode->m_pNext;
	}
	else {
		ListNode *pPrevious = *pHead;
		while (pNode->m_nValue != value && pNode->m_pNext != nullptr) {
			pPrevious = pNode;			// ʼ��ָ����һ��ָ��
			pNode = pNode->m_pNext;
		}
		// �����п��ܴ���û��value����� �˴�ɾ��ָ��Ҫ�����ж�  �˴����׺���
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