
#include<iostream>
using namespace std;

#if JHA
// 114_flat_tree_to_linked_list.
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution
{
	public:
		void fix(TreeNode* node, TreeNode** last_node);
		void flatten(TreeNode* root)
		{
			TreeNode** last_node = &root;
			fix(root, last_node);
		}
};

void Solution::fix(TreeNode* node, TreeNode** last_node)
{
	if(node == NULL)
	{
		return;
	}
	
	if(node->left == NULL && node->right == NULL)
	{
		*last_node = node;
		return;
	}

	if(node->left == NULL)
	{
		fix(node->right, last_node);
		return;
	}
	
	fix(node->left, last_node);
	TreeNode* l_last_node = *last_node;
	
	if(node->right == NULL)
	{
		node->right = node->left;
		node->left = NULL;
		return;
	}
	fix(node->right, last_node);
	l_last_node->right = node->right;
	node->right = node->left;
	node->left = NULL;
}