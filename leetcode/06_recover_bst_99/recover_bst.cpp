#include <iostream>
#include<limits.h>
#include<stdio.h>
#include <vector>
using namespace std;

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
private:
	void inorder_traversal(TreeNode* node, int& prev, TreeNode** prev_node, vector<TreeNode*>& vec);
public:
	void test();

public:
    void recoverTree(TreeNode* root)
	{
		vector<TreeNode*> vec;
		int prev = INT_MIN;
		TreeNode* prev_node = NULL;
		inorder_traversal(root, prev,&prev_node,vec);

		int swap1 = 0, swap2 = 0;

#if 0
		if(vec.size() == 1)
		{
			if(root != NULL && root->right != NULL && (root->val > root->right->val))
			{
				int buf = root->val;
				root->val = root->right->val;
				root->right->val = buf;
			} else if(vec[0]->left != NULL && vec[0]->val < vec[0]->left->val)
			{
				int buf = vec[0]->val;;
				vec[0]->val = vec[0]->left->val;
				vec[0]->left->val = buf;
			} else if(vec[0]->right != NULL && vec[0]->val >  vec[0]->right->val)
			{
				int buf = vec[0]->val;;
				vec[0]->val = vec[0]->right->val;
				vec[0]->right->val = buf;
			}
		}	
#endif

		for(int i=1; i<vec.size(); i++)
		{
			if(vec[i]->val < vec[i-1]->val)
			{
				swap1 = i-1;
				break;
			}
		}

		for(int i=vec.size()-1;i>0;  i--)
		{
			if(vec[i]->val <  vec[i-1]->val)
			{
				swap2 = i;
				break;
			}
		}
		int buf = vec[swap1]->val;
		vec[swap1]->val = vec[swap2]->val;
		vec[swap2]->val = buf;
    }
};

void Solution::inorder_traversal(TreeNode* node, int& prev, TreeNode** prev_node, vector<TreeNode*>& vec)
{
	if(node == NULL)
		return ;

	if(node->left != NULL)
		inorder_traversal(node->left, prev, prev_node, vec);
	
	if(node->val < prev)
	{
		vec.push_back(*prev_node);
		vec.push_back(node);
	}
	prev = node->val;
	*prev_node = node;
	
	if(node->right != NULL)
		inorder_traversal(node->right, prev, prev_node, vec);
}


void Solution::test()
{
	TreeNode* n = new TreeNode(0);
	n->left = new TreeNode(1);
	recoverTree(n);
}

int main()
{
	Solution obj1;
	obj1.test();
	return 0;
}
