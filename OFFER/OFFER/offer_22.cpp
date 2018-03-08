#include "offer_22.h"
#include "Utilities\List.h"

/*
	�����е�����k�����
	����һ����������������е�����k����㡣
*/

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	if (pListHead == nullptr || k == 0)
		return nullptr;

	ListNode* pNode = pListHead;
	for (int i = 0;i < k;++i) {
		if (pNode == nullptr)				// ע�⣺�˴�Ҫ����ǰ�� ��ֹ���һ��
			return nullptr;
		pNode = pNode->m_pNext;
	}

	ListNode* pResult = pListHead;
	while (pNode != nullptr){
		pResult = pResult->m_pNext;
		pNode = pNode->m_pNext;
	}

	return pResult;
}

// ====================���Դ���====================
// ����Ҫ�ҵĽ���������м�
void Test_22_1()
{
	printf("=====Test_22_1 starts:=====\n");
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	printf("expected result: 4.\n");
	ListNode* pNode = FindKthToTail(pNode1, 2);
	PrintListNode(pNode);

	DestroyList(pNode1);
}

// ����Ҫ�ҵĽ���������β���
void Test_22_2()
{
	printf("=====Test_22_2 starts:=====\n");
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	printf("expected result: 5.\n");
	ListNode* pNode = FindKthToTail(pNode1, 1);
	PrintListNode(pNode);

	DestroyList(pNode1);
}

// ����Ҫ�ҵĽ���������ͷ���
void Test_22_3()
{
	printf("=====Test_22_3 starts:=====\n");
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	printf("expected result: 1.\n");
	ListNode* pNode = FindKthToTail(pNode1, 5);
	PrintListNode(pNode);

	DestroyList(pNode1);
}

// ���Կ�����
void Test_22_4()
{
	printf("=====Test_22_4 starts:=====\n");
	printf("expected result: nullptr.\n");
	ListNode* pNode = FindKthToTail(nullptr, 100);
	PrintListNode(pNode);
}

// ��������ĵڶ���������������Ľ������
void Test_22_5()
{
	printf("=====Test_22_5 starts:=====\n");
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	printf("expected result: nullptr.\n");
	ListNode* pNode = FindKthToTail(pNode1, 6);
	PrintListNode(pNode);

	DestroyList(pNode1);
}

// ��������ĵڶ�������Ϊ0
void Test_22_6()
{
	printf("=====Test_22_6 starts:=====\n");
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	printf("expected result: nullptr.\n");
	ListNode* pNode = FindKthToTail(pNode1, 0);
	PrintListNode(pNode);

	DestroyList(pNode1);
}

void offer_22_test()
{
	Test_22_1();
	Test_22_2();
	Test_22_3();
	Test_22_4();
	Test_22_5();
	Test_22_6();

	cout << "offer_22 success" << endl;
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == nullptr || k == 0)
            return nullptr;

        ListNode* pNode = pListHead;
        for (int i = 0;i < k;++i) {
            if (pNode == nullptr)				// ע�⣺�˴�Ҫ����ǰ�� ��ֹ���һ��
                return nullptr;
            pNode = pNode->next;
        }

        ListNode* pResult = pListHead;
        while (pNode != nullptr){
            pResult = pResult->next;
            pNode = pNode->next;
        }

        return pResult;
        }
};
*/