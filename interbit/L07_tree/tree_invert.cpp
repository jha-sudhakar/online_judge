#include<iostream>
using namespace std;

#if 0

//  Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution
{
public:
	TreeNode* invertTree(TreeNode* root);
};
#endif

TreeNode* Solution::invertTree(TreeNode* root) 
{
	if(root == NULL)
		return;

	TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	invertTree(root->left);
	invert(root->right);
}

