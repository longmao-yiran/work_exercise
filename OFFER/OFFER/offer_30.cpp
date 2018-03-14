#include "offer_30.h"
#include <assert.h>

/*
	����min������ջ
	����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������
*/

template <typename T> class StackWithMin
{
public:
	StackWithMin(){}
	~StackWithMin(){}

	T& top();
	const T& top() const;

	void push(const T& value);
	void pop();

	const T& min() const;

	size_t size() const;
	bool empty() const;

private:
	stack<T> m_data;
	stack<T> m_min;
};

template<typename T>
size_t StackWithMin<T>::size() const {
	return m_data.size();
}

template<typename T>
bool StackWithMin<T>::empty() const{
	cout << size();
	return m_data.empty();
}

template<typename T>
const T& StackWithMin<T>::min() const {
	//if (m_min.size() > 0 )
	//	return m_min.top();
	//else
	//	return -1;
	assert(m_data.size() > 0);									// ע�⣺�˴�Ӧ�ü������ջ
	assert(m_min.size() > 0);

	return m_min.top();
}

template<typename T>
const T& StackWithMin<T>::top() const {
	if (!empty())
		return m_data.top();
}

template<typename T>
T& StackWithMin<T>::top()  {
	if (!empty())
		return m_data.top();
}

template <typename T>
void StackWithMin<T>::push(const T& value) {
	m_data.push(value);

	if (m_min.size() == 0 || value < m_min.top())				// ע�⣺�˴�Ҫ����m_minջΪ�յ����
		m_min.push(value);
	else
		m_min.push(m_min.top());
}

template <typename T>
void StackWithMin<T>::pop() {
	//if (!empty) {
	//	m_min.pop();
	//	m_data.pop();
	//}
	assert(m_data.size() > 0);
	assert(m_min.size() > 0);
	m_data.pop();
	m_min.pop();
}

// ====================���Դ���====================
void Test_30(const char* testName, const StackWithMin<int>& stack, int expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (stack.min() == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

void offer_30_test()
{
	StackWithMin<int> stack;

	stack.push(3);
	Test_30("Test_30_1", stack, 3);

	stack.push(4);
	Test_30("Test_30_2", stack, 3);

	stack.push(2);
	Test_30("Test_30_3", stack, 2);

	stack.push(3);
	Test_30("Test_30_4", stack, 2);

	stack.pop();
	Test_30("Test_30_5", stack, 2);

	stack.pop();
	Test_30("Test_30_6", stack, 3);

	stack.pop();
	Test_30("Test_30_7", stack, 3);

	stack.push(0);
	Test_30("Test_30_8", stack, 0);

	cout << "offer_30 success" << endl;
}

// ţ����ac
/*
class Solution {
public:
    stack<int> m_data;
	stack<int> m_min;
    void push(int value) {
        m_data.push(value);

        if (m_min.size() == 0 || value < m_min.top())				// ע�⣺�˴�Ҫ����m_minջΪ�յ����
            m_min.push(value);
        else
            m_min.push(m_min.top());
    }
    void pop() {
        if (m_data.size() > 0 && m_min.size() > 0){
            m_data.pop();
            m_min.pop();
        }
    }
    int top() {
		return m_data.top();
    }
    int min() {
        return m_min.top();
    }
};
*/