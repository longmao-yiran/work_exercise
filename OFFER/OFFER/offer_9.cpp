#include "offer_9.h"

/*
	������ջʵ�ֶ���
	������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
*/

template <typename T>
class CQueue
{
public:
	CQueue();
	~CQueue();

	// �ڶ���ĩβ���һ�����
	void appendTail(const T& node);

	// ɾ�����е�ͷ���
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};

template <typename T>
CQueue<T>::CQueue()
{
}

template <typename T>
CQueue<T>::~CQueue()
{
}



template <typename T>
void CQueue<T>::appendTail(const T& node)					// ע��˴�ģ���ඨ��
{
	stack1.push(node);
}

template <typename T>
T CQueue<T>::deleteHead()
{
	if (stack1.empty() && stack2.empty())
		throw new exception("queue is empty");

	if (stack2.empty()) {
		while (!stack1.empty()) {
			T head = stack1.top();
			stack2.push(head);
			stack1.pop();
		}
	}

	if (!stack2.empty()) {
		T head = stack2.top();
		stack2.pop();
		return head;
	}
}

// ====================���Դ���====================
void Test_9(char actual, char expected)
{
	if (actual == expected)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}

void offer_9_test()
{
	CQueue<char> queue;

	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');

	char head = queue.deleteHead();
	Test_9(head, 'a');

	head = queue.deleteHead();
	Test_9(head, 'b');

	queue.appendTail('d');
	head = queue.deleteHead();
	Test_9(head, 'c');

	queue.appendTail('e');
	head = queue.deleteHead();
	Test_9(head, 'd');

	head = queue.deleteHead();
	Test_9(head, 'e');

	cout << "offer_9 success" << endl;
}

// ţ���� ac
/*
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack1.empty() && stack2.empty())
			return 0;

		if (stack2.empty()) {
			while (!stack1.empty()) {
				int head = stack1.top();
				stack2.push(head);
				stack1.pop();
			}
		}

		if (!stack2.empty()) {
			int head = stack2.top();
			stack2.pop();
			return head;
		}
		return 0;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
*/