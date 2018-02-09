#include "offer_7.h"

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

	// 子树数量为1
	if (stratPreoder == endPreoder) {
		if (stratInorder == endInorder && *stratPreoder == *stratInorder)
			return root;
		else
			throw std::exception("Invalid input");				// 子树数量为1 但是先序和中序的不一样
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
		root->m_pLeft = ConstructCore(leftPreoderEnd + 1, endPreoder, rootInInoeder + 1, endInorder);
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

void offer_7_test()
{
	int predoer[9] = { 1,2,4,7,3,5,6,8 };
	int inorder[9] = { 4,7,2,1,5,3,8,6 };
	BinaryTreeNode* root = Construct(predoer, inorder, 9);
	PreorderTraverse(root);

}