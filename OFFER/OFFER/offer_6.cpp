#include "offer_6.h"

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

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
		while (pNode->m_pNext != nullptr){
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
		while (pNode->m_nValue != value && pNode->m_pNext != nullptr){
			pPrevious = pNode;			// ʼ��ָ����һ��ָ��
			pNode = pNode->m_pNext;
		}
		// �����п��ܴ���û��value����� �˴�ɾ��ָ��Ҫ�����ж�
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

/*
	����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ��
*/
void PrintListReversingly_Iteratively(ListNode** pHead)
{
	if (pHead == nullptr)
		return;
	stack<ListNode*>nodes;
	ListNode* pNode = *pHead;
	while (pNode != nullptr){
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	while (!nodes.empty()){
		pNode = nodes.top();
		cout << pNode->m_nValue << '\t';
		nodes.pop();
	}
	cout << endl;
}

void offer_6_test()
{
	ListNode* pHead = new ListNode();
	pHead->m_nValue = 0;
	ListNode* pNdoe = pHead;
	for (int i = 0;i < 10;++i) {
		pNdoe->m_pNext = new ListNode();
		pNdoe->m_pNext->m_nValue = i;
		pNdoe->m_pNext->m_pNext = nullptr;
		pNdoe = pNdoe->m_pNext;
	}
	PrintListReversingly_Iteratively(nullptr);
	PrintListReversingly_Iteratively(&pNdoe);
	PrintListReversingly_Iteratively(&pHead);

	cout << "offer_6_test success" << endl;

}

