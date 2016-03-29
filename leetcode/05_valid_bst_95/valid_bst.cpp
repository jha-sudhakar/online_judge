#include <stdio.h>
#include <limits.h>

#if 1
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
	bool is_bst(TreeNode* node, long int& prev);

	public:
		bool isValidBST(TreeNode* root)
		{
			long int buf = LLONG_MIN;
			bool ret = is_bst(root,buf);
		}

};

bool Solution::is_bst(TreeNode* node, long int&  prev)
{
	if(node == NULL)
		return true;
	bool ret = false;

	if(node->left != NULL)
	{
		ret = is_bst(node->left, prev);
		if(ret == false)
			return ret;
	}

	long int cur_val = node->val;
	if(cur_val <= prev)
	{
		return false;
	} else
	{
		prev = node->val;
	}

	if(node->right != NULL)
	{
		ret = is_bst(node->right, prev);
		if(ret == false)
			return ret;
	}
	return true;
}

