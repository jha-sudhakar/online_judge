#include<limits.h>
#include<iostream>
using namespace std;
#if 1
/**
 Definition for binary tree
*/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution
{
	public:
		int minDepth(TreeNode* A);
};

#endif

//int min_leaf_height = INT_MAX;
void get_min_depth(TreeNode* n, int h, int& min_leaf_height)
{

	if(n == NULL)
		return ;
	h++;	
	if(n->left == NULL && n->right == NULL)
	{
		if(min_leaf_height > h)
			min_leaf_height = h;
	}

	get_min_depth(n->left, h, min_leaf_height);
	get_min_depth(n->right, h, min_leaf_height);
}


int Solution::minDepth(TreeNode* A) 
{
// Do not write main() function.
// Do not read input, instead use the arguments to the function.
// Do not print the output, instead return values as specified
// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
int height =0;
int min_leaf_height = INT_MAX;
get_min_depth(A, height, min_leaf_height);
return min_leaf_height;

}

int main()
{
Solution obj;
TreeNode* root = new TreeNode(1);
//root->left = new TreeNode(2);
root->right = new TreeNode(2);

int val = obj.minDepth(root);
cout<<"\n Min height = " << val << endl;
return 0;
}
