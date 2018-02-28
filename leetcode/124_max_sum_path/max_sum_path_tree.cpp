/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
	public:
		int maxPathSum(TreeNode* root)
		{
			int max_path_sum = 0;
			max_sum(root, max_path_sum);
			return max_path_sum;

		}

		int max_sum(TreeNode* n, int& max_val)
		{
			if(n == NULL)
				return 0;

			int l_sum = max_sum(n->left, max_val);

			int r_sum = max_sum(n->right, max_val);

			int tmp = n->val + l_sum + r_sum;
			if(tmp > max_val)
				max_val = tmp;

			return n->val + max(l_sum, r_sum);

		}
};