#include<limits.h>
#include<iostream>
using namespace std;

#if JHA
	//Definition for a binary tree node.
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
    bool isValidBST(TreeNode* root);
	bool is_bst(TreeNode* node, long int min_val, long int max_val);
};

bool Solution::isValidBST(TreeNode* root)
{
	long int min_val = INT_MIN;
	long int max_val = INT_MAX;
	min_val--; max_val++;
	return is_bst(root, min_val, max_val);
}

bool Solution::is_bst(TreeNode* node, long int min_val, long int max_val)
{
	if(node == NULL)
		return true;
	
	if(node->val <= min_val || node->val >= max_val)
		return false;
	
	bool ret_l = is_bst(node->left, min_val, node->val);
	if(ret_l == false) 
		return false;

	return is_bst(node->right, node->val, max_val);
}

