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
		bool isSymmetric(TreeNode* root)
		{
			return is_same(root, root);
		}

		bool is_same(TreeNode* node1, TreeNode* node2)
		{
			if(node1 == NULL || node2 == NULL)
			{
				if(node1 != node2)
					return false;
				else
					return true;
			}
			bool ret_val = is_same(node1->left, node2->right);
			if(ret_val == false) return false;
			
			if(node1->val != node2->val)
				return false;
			
			return is_same(node1->right, node2->left);
		}
};
