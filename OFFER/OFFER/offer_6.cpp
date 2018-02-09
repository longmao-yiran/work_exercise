#include "offer_6.h"

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

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
		while (pNode->m_nValue != value && pNode->m_pNext != nullptr){
			pPrevious = pNode;			// 始终指向上一个指针
			pNode = pNode->m_pNext;
		}
		// 由于有可能存在没有value的情况 此处删除指针要进行判断
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
	输入一个链表，从尾到头打印链表每个节点的值。
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

