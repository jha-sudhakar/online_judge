#include<iostream>
#include<vector>
using namespace std;

#if 1

 //Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution
{
public:
	vector<vector<int> > pathSum(TreeNode* root, int sum);
};	
#endif

vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) 
{
// Do not write main() function.
// Do not read input, instead use the arguments to the function.
// Do not print the output, instead return values as specified
// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details


	vector< vector<int> > ret;
	int path_sum = 0;
	vector<TreeNode*> stk;
	if(root == NULL)
		return ret;

	int prev_size = 0, cur_size=0;
	stk.push_back(root);
	path_sum = root->val;
	TreeNode* last_node = NULL;
	while(stk.size())
	{
		cur_size = stk.size();
		TreeNode* tmp = stk[stk.size()-1];
		if(cur_size > prev_size)
		{
			//TreeNode* tmp = stk[stk.size()-1];
			if(tmp->left) // Go left side
			{
				stk.push_back(tmp->left);
				path_sum += tmp->left->val;
			}	
			else if(tmp->right) //Go right side
			{
				stk.push_back(tmp->right);
				path_sum += tmp->right->val;
			}	
			else //Leaf node.
			{
				if(path_sum == sum)
				{
					vector<int> buf_vec;
					for(int i=0; i<stk.size(); i++)
					{
						buf_vec.push_back(stk[i]->val);
					}
					ret.push_back(buf_vec);
				}
				last_node = tmp;;
				path_sum -= last_node->val;
				stk.pop_back();
			}
		}
		else
		{
			if(tmp->left && tmp->left == last_node) // Left node is popped.
			{
				if(tmp->right)
				{
					stk.push_back(tmp->right);
				 	path_sum += tmp->right->val;
				 } else
				 {
					last_node = tmp;
					path_sum -= last_node->val;
					stk.pop_back();

				 }
			} else if(tmp->right && tmp->right == last_node) // Right node is popped.
			{
				last_node = tmp;
				path_sum -= last_node->val;
				stk.pop_back();
			}
		}
		prev_size = cur_size;
	}
}
