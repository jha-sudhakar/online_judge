#include<limits.h>
#include<vector>
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

struct ele
{
		TreeNode* ptr;
		int lpos, rpos;
		ele(TreeNode* _ptr) { ptr = _ptr; lpos = 0, rpos=0;}
		ele(TreeNode* _ptr, int _lpos, int _rpos) { ptr = _ptr; lpos=_lpos, rpos=_rpos;}
};

class Solution
{
    public:
        bool isSymmetric(TreeNode* root);
};


bool Solution::isSymmetric(TreeNode* node)
{
	if(node == NULL)
		return true;
	if(node->left == NULL && node->right == NULL)
		return true;
	else if(node->left == NULL && node->right != NULL)
		return false;
	else if(node->left != NULL && node->right == NULL)
		return false;

	vector<ele>* tmp_vec = NULL;
	vector<ele> *vec1 = new vector<ele>;
	vector<ele> *next_vec1  = new vector<ele>;

	vector<ele> *vec2 = new vector<ele>;
	vector<ele> *next_vec2 = new vector<ele>;
	
	vec1->push_back(ele(node->left, -1, 0));
	vec2->push_back(ele(node->right, 0, 1));
	
	while(vec1->size())
	{
		if(vec1->size() != vec2->size())
			return false;

		for(int i=0; i<vec1->size(); i++)
		{
			if((vec1->at(i).ptr->val != vec2->at(vec2->size()-1-i).ptr->val)
				|| (-1 * vec1->at(i).lpos != vec2->at(vec2->size()-1-i).rpos)
				|| (vec1->at(i).rpos != -1 * vec2->at(vec2->size()-1-i).lpos))
			{
				return false;				
			}
		}

		next_vec1->clear(); next_vec2->clear();
		for(int i=0; i<vec1->size(); i++)
		{
			if(vec1->at(i).ptr->left != NULL)
			{
				next_vec1->push_back(ele(vec1->at(i).ptr->left, vec1->at(i).lpos-1, vec1->at(i).rpos));
			}
			if(vec1->at(i).ptr->right != NULL)
			{
				next_vec1->push_back(ele(vec1->at(i).ptr->right, vec1->at(i).lpos, vec1->at(i).rpos+1));
			}
			
			if(vec2->at(i).ptr->left != NULL)
			{
				next_vec2->push_back(ele(vec2->at(i).ptr->left, vec2->at(i).lpos-1, vec2->at(i).rpos));
			}
			if(vec2->at(i).ptr->right != NULL)
			{
				next_vec2->push_back(ele(vec2->at(i).ptr->right, vec2->at(i).lpos, vec2->at(i).rpos+1));
			}
		}
		vec1->clear(); 
		tmp_vec = vec1;
		vec1 = next_vec1;
		next_vec1 = tmp_vec;
		
		vec2->clear(); 
		tmp_vec = vec2;
		vec2 = next_vec2;
		next_vec2 = tmp_vec;
	}
	return true;
}