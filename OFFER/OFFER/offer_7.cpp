#include "offer_7.h"
#include "Utilities\BinaryTree.h"

/*
	�ؽ�������
	����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
	���������ǰ���������������Ľ���ж������ظ������֡�
	��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}��
	���ؽ������������ء�
*/

BinaryTreeNode* ConstructCore(int* stratPreoder, int* endPreoder, int *stratInorder, int* endInorder)
{
	int rootValue = *stratPreoder;
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = nullptr;
	root->m_pRight = nullptr;

	// ��������Ϊ1
	if (stratPreoder == endPreoder) {
		if (stratInorder == endInorder && *stratPreoder == *stratInorder)
			return root;
		else
			throw std::exception("Invalid input");				// ��������Ϊ1 �������������Ĳ�һ��
	}
	int* rootInInoeder = stratInorder;
	while (rootInInoeder <= endInorder&&*rootInInoeder != rootValue)
		++rootInInoeder;
	if (rootInInoeder == endInorder && *rootInInoeder != rootValue)
		throw std::exception("Invalid input");

	int leftLength = rootInInoeder - stratInorder;
	int* leftPreoderEnd = stratPreoder + leftLength;
	if (leftLength > 0)
		root->m_pLeft = ConstructCore(stratPreoder + 1, leftPreoderEnd, stratInorder, rootInInoeder - 1);
	if (leftLength < endPreoder - stratPreoder)
		root->m_pRight = ConstructCore(leftPreoderEnd + 1, endPreoder, rootInInoeder + 1, endInorder);
	return root;

}

BinaryTreeNode* Construct(int* perorder, int*inorder, int length) 
{
	if (perorder == nullptr || inorder == nullptr || length <= 0)
		return nullptr;
	else
		return ConstructCore(perorder, perorder + length - 1, inorder, inorder + length - 1);
}

void PreorderTraverse(BinaryTreeNode* tree) 
{
	if (tree != nullptr) {
		cout << tree->m_nValue << "\t";
		PreorderTraverse(tree->m_pLeft);
		PreorderTraverse(tree->m_pRight);
	}
}

// ====================���Դ���====================
void Test_7(char* testName, int* preorder, int* inorder, int length)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	printf("The preorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", preorder[i]);
	printf("\n");

	printf("The inorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", inorder[i]);
	printf("\n");

	try
	{
		BinaryTreeNode* root = Construct(preorder, inorder, length);
		PrintTree(root);

		DestroyTree(root);
	}
	catch (std::exception& exception)
	{
		printf("Invalid Input.\n");
	}
}

// ��ͨ������
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test_7_1()
{
	const int length = 8;
	int preorder[length] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inorder[length] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	Test_7("Test_7_1", preorder, inorder, length);
}

// ���н�㶼û�����ӽ��
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test_7_2()
{
	const int length = 5;
	int preorder[length] = { 1, 2, 3, 4, 5 };
	int inorder[length] = { 5, 4, 3, 2, 1 };

	Test_7("Test_7_2", preorder, inorder, length);
}

// ���н�㶼û�����ӽ��
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test_7_3()
{
	const int length = 5;
	int preorder[length] = { 1, 2, 3, 4, 5 };
	int inorder[length] = { 1, 2, 3, 4, 5 };

	Test_7("Test_7_3", preorder, inorder, length);
}

// ����ֻ��һ�����
void Test_7_4()
{
	const int length = 1;
	int preorder[length] = { 1 };
	int inorder[length] = { 1 };

	Test_7("Test_7_4", preorder, inorder, length);
}

// ��ȫ������
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test_7_5()
{
	const int length = 7;
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 5, 1, 6, 3, 7 };

	Test_7("Test_7_5", preorder, inorder, length);
}

// �����ָ��
void Test_7_6()
{
	Test_7("Test_7_6", nullptr, nullptr, 0);
}

// ������������в�ƥ��
void Test_7_7()
{
	const int length = 7;
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 8, 1, 6, 3, 7 };

	Test_7("Test_7_7: for unmatched input", preorder, inorder, length);
}


void offer_7_test()
{
	Test_7_1();
	Test_7_2();
	Test_7_3();
	Test_7_4();
	Test_7_5();
	Test_7_6();
	Test_7_7();
	cout << "offer_7 success" << endl;

}

// ţ���� ac
/*
//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* ConstructCore(vector<int>::iterator stratPreoder, vector<int>::iterator endPreoder, vector<int>::iterator stratInorder, vector<int>::iterator endInorder) {
		int rootValue = *stratPreoder;								// ��ȡ���ڵ�
		TreeNode *root = new TreeNode(rootValue);

		// ����������ֻʣ��һ������
		if (stratPreoder == endPreoder) {
			if (stratInorder == endInorder && *stratInorder == *stratPreoder)
				return root;
			else
				return nullptr;// throw std::exception("Invalid input");				// ��������Ϊ1 �������������Ĳ�һ��
		}

		// ������������и��ڵ��λ�ã�������������
		vector<int>::iterator rootInorder = stratInorder;
		while (*rootInorder != rootValue && rootInorder != endInorder)
			++rootInorder;
		if (*rootInorder != rootValue && rootInorder == endInorder)
			return nullptr;// throw std::exception("Invalid input");
		int leftLenght = rootInorder - stratInorder;
		vector<int>::iterator leftPreoderEnd = stratPreoder + leftLenght;
		if (leftLenght > 0)
			root->left = ConstructCore(stratPreoder + 1, leftPreoderEnd, stratInorder, rootInorder - 1);
		if (rootInorder != endInorder)
			root->right = ConstructCore(stratPreoder + leftLenght + 1, endPreoder, rootInorder + 1, endInorder);
		return root;
	}

	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
	{
		if (pre.size() == 0 || vin.size() == 0 || pre.size() != vin.size()) {
			return nullptr;
		}
		else {
			return ConstructCore(pre.begin(), pre.end() - 1, vin.begin(), vin.end() - 1);
		}
	}
};

TreeNode* ConstructCore(vector<int>::iterator stratPreoder, vector<int>::iterator endPreoder, vector<int>::iterator stratInorder, vector<int>::iterator endInorder) {
	int rootValue = *stratPreoder;								// ��ȡ���ڵ�
	TreeNode *root = new TreeNode(rootValue);

	// ����������ֻʣ��һ������
	if (stratPreoder == endPreoder) {
		if (stratInorder == endInorder && *stratInorder == *stratPreoder)
			return root;
		else
			throw std::exception("Invalid input");				// ��������Ϊ1 �������������Ĳ�һ��
	}

	// ������������и��ڵ��λ�ã�������������
	vector<int>::iterator rootInorder = stratInorder;
	while (*rootInorder != rootValue && rootInorder != endInorder)
		++rootInorder;
	if (*rootInorder != rootValue && rootInorder == endInorder)
		throw std::exception("Invalid input");
	int leftLenght = rootInorder - stratInorder;
	vector<int>::iterator leftPreoderEnd = stratPreoder + leftLenght;
	if (leftLenght > 0)
		root->left = ConstructCore(stratPreoder + 1, leftPreoderEnd, stratInorder, rootInorder - 1);
	if (rootInorder != endInorder)
		root->right = ConstructCore(stratPreoder + leftLenght + 1, endPreoder, rootInorder + 1, endInorder);
	return root;
}

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
	if (pre.size() == 0 || vin.size() == 0 || pre.size() != vin.size()) {
		return nullptr;
	}
	else {
		return ConstructCore(pre.begin(), pre.end() - 1, vin.begin(), vin.end() - 1);
	}
}

void PreorderTraverse(TreeNode* tree)
{
	if (tree != nullptr) {
		cout << tree->val << "\t";
		PreorderTraverse(tree->left);
		PreorderTraverse(tree->right);
	}
}
*/