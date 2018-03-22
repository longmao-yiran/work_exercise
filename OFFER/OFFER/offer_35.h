#ifndef OFFER_35_H
#define OFFER_35_H

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

void offer_35_test();

struct ComplexListNode
{
	int                 m_nValue;
	ComplexListNode*    m_pNext;
	ComplexListNode*    m_pSibling;
};

#endif // !OFFER_35_H