#include<iostream>
using namespace std;

#if 1

// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution
{
public:
	TreeNode* flatten(TreeNode* A);
};
#endif


void flat_tree(TreeNode* n, TreeNode* &last)
{
	if(n == NULL)
		return ;
	if(n->left == NULL && n->right == NULL)
	{
		last = n;
		return;
	}
	flat_tree(n->left, last);
	TreeNode* buf = n->right;;
	if(n->left != NULL)
	{
		n->right = n->left;
		n->left = NULL;
		last->right = buf;
	}
	flat_tree(buf, last);
}

TreeNode* Solution::flatten(TreeNode* A) 
{
// Do not write main() function.
// Do not read input, instead use the arguments to the function.
// Do not print the output, instead return values as specified
// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	TreeNode* last=NULL;
	flat_tree(A, last);
	return A;
}

