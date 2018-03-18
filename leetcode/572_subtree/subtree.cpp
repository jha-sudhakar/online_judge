#include<iostream>
using namespace std;

#if LOCAL
	//tree_diameter
	//Definition for a binary tree node.
	struct TreeNode
	{
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
#endif

class Solution
{
	private:
		TreeNode* st;
		bool is_found;
		int lmost, rmost;
		void set_lr_most(TreeNode* );
	public:
		bool isSubtree_p(TreeNode* s, TreeNode* t);
		int  isSubtree_scan(TreeNode* s, bool is_left_child);
		bool isSubtree(TreeNode* s, TreeNode* t);
};

bool Solution::isSubtree(TreeNode* s, TreeNode* t)
{
	st = t;
	is_found = false;

	if(t == NULL) return true;
	set_lr_most(t);
	isSubtree_scan(s, true);
	return is_found;
}

void Solution::set_lr_most(TreeNode* t)
{
	TreeNode* lnode = t;
	while(lnode->left != NULL)
	{
		lnode = lnode->left;
	}
	lmost = lnode->val;

	TreeNode* rnode = t;
	while(rnode->right != NULL)
	{
		rnode = rnode->right;
	}
	rmost = rnode->val;
}

bool Solution::isSubtree_p(TreeNode* s, TreeNode* t)
{
	if(s == NULL && t == NULL)
		return true;
	if((s!= NULL && t ==NULL) || (s== NULL && t !=NULL))
		return false;

	if(s->val == t->val)
	{
		bool ret1 = false, ret2 = false;
		ret1 = isSubtree_p(s->left, t->left);
		if(ret1 == true)
		{
			ret2 = isSubtree_p(s->right, t->right);
			if(ret2 == true)
				return ret2;
		}
	}
	return false;
}

int Solution::isSubtree_scan(TreeNode* s, bool is_left_child)
{
	int lval, rval;
	if(s == NULL || is_found == true)
		return 0;
	if(s->left == NULL)
	{
		lval = s->val;
	}
	else
		lval = isSubtree_scan(s->left, true);
	if(s->right == NULL)
	{
		rval = s->val;
	}
	else
		rval = isSubtree_scan(s->right, false);

	bool ret = false;
	if(s->val == st->val && lval == lmost && rval == rmost)
			ret = isSubtree_p(s, st);
	if(ret == true)
			is_found = true;

	if(true == is_left_child)
		return lval;
	else
		return rval;
}