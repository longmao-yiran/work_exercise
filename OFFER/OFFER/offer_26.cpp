#include "offer_26.h"

/*
	树的子结构
	输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/
struct BinaryTreeNode_26
{
	double                 m_dbValue;
	BinaryTreeNode_26*        m_pLeft;
	BinaryTreeNode_26*        m_pRight;
};

bool DoesTree1HaveTree2(BinaryTreeNode_26* pRoot1, BinaryTreeNode_26* pRoot2);
bool Equal(double num1, double num2);

bool HasSubtree(BinaryTreeNode_26* pRoot1, BinaryTreeNode_26* pRoot2)
{
	if (pRoot1 == nullptr || pRoot2 == nullptr)
		return false;

	bool result = false;

	if (Equal(pRoot1->m_dbValue, pRoot2->m_dbValue))
		result = DoesTree1HaveTree2(pRoot1, pRoot2);

	if (!result)
		result = HasSubtree(pRoot1->m_pLeft, pRoot2);

	if (!result)
		result = HasSubtree(pRoot1->m_pRight, pRoot2);

	return result;
}

bool DoesTree1HaveTree2(BinaryTreeNode_26* pRoot1, BinaryTreeNode_26* pRoot2)
{
	if (pRoot2 == nullptr)					// 注意 ：此处先判断pRoot2
		return true;

	if (pRoot1 == nullptr)
		return false;

	if (!Equal(pRoot1->m_dbValue, pRoot2->m_dbValue))
		return false;

	return DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}

bool Equal(double num1, double num2)
{
	if ((num1 - num2 > -0.00001) && (num1 - num2 < 0.00001))
		return true;
	else
		return false;
}

// ====================辅助测试代码====================
BinaryTreeNode_26* CreateBinaryTreeNode_26(double dbValue)
{
    BinaryTreeNode_26* pNode = new BinaryTreeNode_26();
    pNode->m_dbValue = dbValue;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;

    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode_26* pParent, BinaryTreeNode_26* pLeft, BinaryTreeNode_26* pRight)
{
    if(pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
    }
}

void DestroyTree(BinaryTreeNode_26* pRoot)
{
    if(pRoot != nullptr)
    {
        BinaryTreeNode_26* pLeft = pRoot->m_pLeft;
        BinaryTreeNode_26* pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

// ====================测试代码====================
void Test_26(char* testName, BinaryTreeNode_26* pRoot1, BinaryTreeNode_26* pRoot2, bool expected)
{
    if(HasSubtree(pRoot1, pRoot2) == expected)
        printf("%s passed.\n", testName);
    else
        printf("%s failed.\n", testName);
}

// 树中结点含有分叉，树B是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     2
//               / \
//              4   7
void Test_26_1()
{
    BinaryTreeNode_26* pNodeA1 = CreateBinaryTreeNode_26(8);
    BinaryTreeNode_26* pNodeA2 = CreateBinaryTreeNode_26(8);
    BinaryTreeNode_26* pNodeA3 = CreateBinaryTreeNode_26(7);
    BinaryTreeNode_26* pNodeA4 = CreateBinaryTreeNode_26(9);
    BinaryTreeNode_26* pNodeA5 = CreateBinaryTreeNode_26(2);
    BinaryTreeNode_26* pNodeA6 = CreateBinaryTreeNode_26(4);
    BinaryTreeNode_26* pNodeA7 = CreateBinaryTreeNode_26(7);

    ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
    ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
    ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

    BinaryTreeNode_26* pNodeB1 = CreateBinaryTreeNode_26(8);
    BinaryTreeNode_26* pNodeB2 = CreateBinaryTreeNode_26(9);
    BinaryTreeNode_26* pNodeB3 = CreateBinaryTreeNode_26(2);

    ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

    Test_26("Test_26_1", pNodeA1, pNodeB1, true);

    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

// 树中结点含有分叉，树B不是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     3
//               / \
//              4   7
void Test_26_2()
{
    BinaryTreeNode_26* pNodeA1 = CreateBinaryTreeNode_26(8);
    BinaryTreeNode_26* pNodeA2 = CreateBinaryTreeNode_26(8);
    BinaryTreeNode_26* pNodeA3 = CreateBinaryTreeNode_26(7);
    BinaryTreeNode_26* pNodeA4 = CreateBinaryTreeNode_26(9);
    BinaryTreeNode_26* pNodeA5 = CreateBinaryTreeNode_26(3);
    BinaryTreeNode_26* pNodeA6 = CreateBinaryTreeNode_26(4);
    BinaryTreeNode_26* pNodeA7 = CreateBinaryTreeNode_26(7);

    ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
    ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
    ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

    BinaryTreeNode_26* pNodeB1 = CreateBinaryTreeNode_26(8);
    BinaryTreeNode_26* pNodeB2 = CreateBinaryTreeNode_26(9);
    BinaryTreeNode_26* pNodeB3 = CreateBinaryTreeNode_26(2);

    ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

    Test_26("Test_26_2", pNodeA1, pNodeB1, false);

    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

// 树中结点只有左子结点，树B是树A的子结构
//                8                  8
//              /                   / 
//             8                   9   
//           /                    /
//          9                    2
//         /      
//        2        
//       /
//      5
void Test_26_3()
{
    BinaryTreeNode_26* pNodeA1 = CreateBinaryTreeNode_26(8);
    BinaryTreeNode_26* pNodeA2 = CreateBinaryTreeNode_26(8);
    BinaryTreeNode_26* pNodeA3 = CreateBinaryTreeNode_26(9);
    BinaryTreeNode_26* pNodeA4 = CreateBinaryTreeNode_26(2);
    BinaryTreeNode_26* pNodeA5 = CreateBinaryTreeNode_26(5);

    ConnectTreeNodes(pNodeA1, pNodeA2, nullptr);
    ConnectTreeNodes(pNodeA2, pNodeA3, nullptr);
    ConnectTreeNodes(pNodeA3, pNodeA4, nullptr);
    ConnectTreeNodes(pNodeA4, pNodeA5, nullptr);

    BinaryTreeNode_26* pNodeB1 = CreateBinaryTreeNode_26(8);
    BinaryTreeNode_26* pNodeB2 = CreateBinaryTreeNode_26(9);
    BinaryTreeNode_26* pNodeB3 = CreateBinaryTreeNode_26(2);

    ConnectTreeNodes(pNodeB1, pNodeB2, nullptr);
    ConnectTreeNodes(pNodeB2, pNodeB3, nullptr);

    Test_26("Test_26_3", pNodeA1, pNodeB1, true);

    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

// 树中结点只有左子结点，树B不是树A的子结构
//                8                  8
//              /                   / 
//             8                   9   
//           /                    /
//          9                    3
//         /      
//        2        
//       /
//      5
void Test_26_4()
{
    BinaryTreeNode_26* pNodeA1 = CreateBinaryTreeNode_26(8);
    BinaryTreeNode_26* pNodeA2 = CreateBinaryTreeNode_26(8);
    BinaryTreeNode_26* pNodeA3 = CreateBinaryTreeNode_26(9);
    BinaryTreeNode_26* pNodeA4 = CreateBinaryTreeNode_26(2);
    BinaryTreeNode_26* pNodeA5 = CreateBinaryTreeNode_26(5);

    ConnectTreeNodes(pNodeA1, pNodeA2, nullptr);
    ConnectTreeNodes(pNodeA2, pNodeA3, nullptr);
    ConnectTreeNodes(pNodeA3, pNodeA4, nullptr);
    ConnectTreeNodes(pNodeA4, pNodeA5, nullptr);

    BinaryTreeNode_26* pNodeB1 = CreateBinaryTreeNode_26(8);
    BinaryTreeNode_26* pNodeB2 = CreateBinaryTreeNode_26(9);
    BinaryTreeNode_26* pNodeB3 = CreateBinaryTreeNode_26(3);

    ConnectTreeNodes(pNodeB1, pNodeB2, nullptr);
    ConnectTreeNodes(pNodeB2, pNodeB3, nullptr);

    Test_26("Test_26_4", pNodeA1, pNodeB1, false);

    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

// 树中结点只有右子结点，树B是树A的子结构
//       8                   8
//        \                   \ 
//         8                   9   
//          \                   \
//           9                   2
//            \      
//             2        
//              \
//               5
void Test_26_5()
{
    BinaryTreeNode_26* pNodeA1 = CreateBinaryTreeNode_26(8);
    BinaryTreeNode_26* pNodeA2 = CreateBinaryTreeNode_26(8);
    BinaryTreeNode_26* pNodeA3 = CreateBinaryTreeNode_26(9);
    BinaryTreeNode_26* pNodeA4 = CreateBinaryTreeNode_26(2);
    BinaryTreeNode_26* pNodeA5 = CreateBinaryTreeNode_26(5);

    ConnectTreeNodes(pNodeA1, nullptr, pNodeA2);
    ConnectTreeNodes(pNodeA2, nullptr, pNodeA3);
    ConnectTreeNodes(pNodeA3, nullptr, pNodeA4);
    ConnectTreeNodes(pNodeA4, nullptr, pNodeA5);

    BinaryTreeNode_26* pNodeB1 = CreateBinaryTreeNode_26(8);
    BinaryTreeNode_26* pNodeB2 = CreateBinaryTreeNode_26(9);
    BinaryTreeNode_26* pNodeB3 = CreateBinaryTreeNode_26(2);

    ConnectTreeNodes(pNodeB1, nullptr, pNodeB2);
    ConnectTreeNodes(pNodeB2, nullptr, pNodeB3);

    Test_26("Test_26_5", pNodeA1, pNodeB1, true);

    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

// 树A中结点只有右子结点，树B不是树A的子结构
//       8                   8
//        \                   \ 
//         8                   9   
//          \                 / \
//           9               3   2
//            \      
//             2        
//              \
//               5
void Test_26_6()
{
    BinaryTreeNode_26* pNodeA1 = CreateBinaryTreeNode_26(8);
    BinaryTreeNode_26* pNodeA2 = CreateBinaryTreeNode_26(8);
    BinaryTreeNode_26* pNodeA3 = CreateBinaryTreeNode_26(9);
    BinaryTreeNode_26* pNodeA4 = CreateBinaryTreeNode_26(2);
    BinaryTreeNode_26* pNodeA5 = CreateBinaryTreeNode_26(5);

    ConnectTreeNodes(pNodeA1, nullptr, pNodeA2);
    ConnectTreeNodes(pNodeA2, nullptr, pNodeA3);
    ConnectTreeNodes(pNodeA3, nullptr, pNodeA4);
    ConnectTreeNodes(pNodeA4, nullptr, pNodeA5);

    BinaryTreeNode_26* pNodeB1 = CreateBinaryTreeNode_26(8);
    BinaryTreeNode_26* pNodeB2 = CreateBinaryTreeNode_26(9);
    BinaryTreeNode_26* pNodeB3 = CreateBinaryTreeNode_26(3);
    BinaryTreeNode_26* pNodeB4 = CreateBinaryTreeNode_26(2);

    ConnectTreeNodes(pNodeB1, nullptr, pNodeB2);
    ConnectTreeNodes(pNodeB2, pNodeB3, pNodeB4);

    Test_26("Test_26_6", pNodeA1, pNodeB1, false);

    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

// 树A为空树
void Test_26_7()
{
    BinaryTreeNode_26* pNodeB1 = CreateBinaryTreeNode_26(8);
    BinaryTreeNode_26* pNodeB2 = CreateBinaryTreeNode_26(9);
    BinaryTreeNode_26* pNodeB3 = CreateBinaryTreeNode_26(3);
    BinaryTreeNode_26* pNodeB4 = CreateBinaryTreeNode_26(2);

    ConnectTreeNodes(pNodeB1, nullptr, pNodeB2);
    ConnectTreeNodes(pNodeB2, pNodeB3, pNodeB4);

    Test_26("Test_26_7", nullptr, pNodeB1, false);

    DestroyTree(pNodeB1);
}

// 树B为空树
void Test_26_8()
{
    BinaryTreeNode_26* pNodeA1 = CreateBinaryTreeNode_26(8);
    BinaryTreeNode_26* pNodeA2 = CreateBinaryTreeNode_26(9);
    BinaryTreeNode_26* pNodeA3 = CreateBinaryTreeNode_26(3);
    BinaryTreeNode_26* pNodeA4 = CreateBinaryTreeNode_26(2);

    ConnectTreeNodes(pNodeA1, nullptr, pNodeA2);
    ConnectTreeNodes(pNodeA2, pNodeA3, pNodeA4);

    Test_26("Test_26_8", pNodeA1, nullptr, false);

    DestroyTree(pNodeA1);
}

// 树A和树B都为空
void Test_26_9()
{
    Test_26("Test_26_9", nullptr, nullptr, false);
}

void offer_26_test()
{
    Test_26_1();
    Test_26_2();
    Test_26_3();
    Test_26_4();
    Test_26_5();
    Test_26_6();
    Test_26_7();
    Test_26_8();
    Test_26_9();

	cout << "offer_26 success" << endl;
}

// 牛客网ac
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot1 == nullptr || pRoot2 == nullptr)
            return false;

        bool result = false;

        if (Equal(pRoot1->val, pRoot2->val))
            result = DoesTree1HaveTree2(pRoot1, pRoot2);

        if (!result)
            result = HasSubtree(pRoot1->left, pRoot2);

        if (!result)
            result = HasSubtree(pRoot1->right, pRoot2);

        return result;
    }

    bool DoesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot2 == nullptr)					// 注意 ：此处先判断pRoot2
            return true;

        if (pRoot1 == nullptr)
            return false;

        if (!Equal(pRoot1->val, pRoot2->val))
            return false;

        return DoesTree1HaveTree2(pRoot1->left, pRoot2->left) && DoesTree1HaveTree2(pRoot1->right, pRoot2->right);
    }

    bool Equal(int num1, int num2)
    {
        if ((num1 - num2 > -0.00001) && (num1 - num2 < 0.00001))
            return true;
        else
            return false;
    }
};
*/