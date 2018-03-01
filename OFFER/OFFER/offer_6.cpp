#include "offer_6.h"
#include "Utilities\List.h"

/*
	从头到尾打印链表
	输入一个链表，从尾到头打印链表每个节点的值。
*/

void PrintListReversingly_Iteratively(ListNode* pHead)
{
	if (pHead == nullptr)
		return;
	stack<ListNode*>nodes;
	ListNode* pNode = pHead;
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

void PrintListReversingly_Recursively(ListNode* pHead)
{
	if (pHead != nullptr) {
		if (pHead->m_pNext != nullptr) {
			PrintListReversingly_Recursively(pHead->m_pNext);
		}
		cout << pHead->m_nValue << "\t";
	}
}

// ====================测试代码====================
void Test_6(ListNode* pHead)
{
	PrintList(pHead);
	PrintListReversingly_Iteratively(pHead);
	printf("\n");
	PrintListReversingly_Recursively(pHead);
}

// 1->2->3->4->5
void Test_6_1()
{
	printf("\nTest_6_1 begins.\n");

	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test_6(pNode1);

	DestroyList(pNode1);
}

// 只有一个结点的链表: 1
void Test_6_2()
{
	printf("\nTest_6_2 begins.\n");

	ListNode* pNode1 = CreateListNode(1);

	Test_6(pNode1);

	DestroyList(pNode1);
}

// 空链表
void Test_6_3()
{
	printf("\nTest_6_3 begins.\n");

	Test_6(nullptr);
}

void offer_6_test()
{
	Test_6_1();
	Test_6_2();
	Test_6_3();
	cout << "offer_1 success" << endl;
	//ListNode* pHead = new ListNode();
	//pHead->m_nValue = 0;
	//ListNode* pNdoe = pHead;
	//for (int i = 0;i < 10;++i) {
	//	pNdoe->m_pNext = new ListNode();
	//	pNdoe->m_pNext->m_nValue = i;
	//	pNdoe->m_pNext->m_pNext = nullptr;
	//	pNdoe = pNdoe->m_pNext;
	//}
	//PrintListReversingly_Iteratively(nullptr);
	//PrintListReversingly_Iteratively(pNdoe);
	//PrintListReversingly_Iteratively(pHead);

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
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> result;
		if (head == nullptr)
			return result;
		stack<ListNode*>nodes;
		ListNode* pNode = head;
		while (pNode != nullptr) {
			nodes.push(pNode);
			pNode = pNode->next;
		}
		while (!nodes.empty()) {
			pNode = nodes.top();
			result.push_back(pNode->val);
			nodes.pop();
		}
		return result;
	}
};
*/
