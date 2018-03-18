#include<iostream>
using namespace std;

#if LOCAL
	//tree_diameter
	//Definition for a binary tree node.
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
#endif

class Solution {
public:
	int dmtr(TreeNode* node, int& max_d);
    int diameterOfBinaryTree(TreeNode* root) {
		int max_d = 0;
        dmtr(root, max_d);
		if(max_d >0)
			max_d--;
		return max_d;
    }
};

int Solution::dmtr(TreeNode* node, int& max_d)
{
	if(node == NULL)
		return 0;
	
	int left_max_d  = dmtr(node->left, max_d);
	int right_max_d = dmtr(node->right, max_d);
	int local_max_d = 1 + left_max_d + right_max_d;
	
	if(local_max_d > max_d)
		max_d = local_max_d;

	return 1 + max(left_max_d, right_max_d);
}