#include "offer_7.h"

/*
	����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
	���������ǰ���������������Ľ���ж������ظ������֡�
	��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}��
	���ؽ������������ء�
*/

struct BinaryTreeNode
{
	int m_nValuel;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* ConstructCore(int* stratPreoder, int* endPreoder, int *stratInorder, int* endInorder)
{
	int rootValue = *stratPreoder;
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValuel = rootValue;
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
		cout << tree->m_nValuel << "\t";
		PreorderTraverse(tree->m_pLeft);
		PreorderTraverse(tree->m_pRight);
	}
}

// ţ����
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* ConstructCore(vector<int>::iterator stratPreoder, vector<int>::iterator endPreoder, vector<int>::iterator stratInorder, vector<int>::iterator endInorder) {
	int rootValue = *stratPreoder;								// ��ȡ���ڵ�
	TreeNode *root = new TreeNode(rootValue);
	
	// ����������ֻʣ��һ������
	if (stratPreoder  == endPreoder) {
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

void offer_7_test()
{
	int predoer[9] = { 1,2,4,7,3,5,6,8 };
	int inorder[9] = { 4,7,2,1,5,3,8,6 };
	BinaryTreeNode* root = Construct(predoer, inorder, 8);
 	PreorderTraverse(root);

	// ţ����vector�ӿ�ʹ�÷���
	vector<int> predoerVector(&predoer[0], &predoer[8]);
	vector<int> inorderVector(&inorder[0], &inorder[8]);
	TreeNode* root2 = reConstructBinaryTree(predoerVector, inorderVector);
	PreorderTraverse(root2);

}