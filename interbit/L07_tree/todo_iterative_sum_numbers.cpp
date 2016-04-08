#include<vector>
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
		int sumNumbers(TreeNode* A);
};

#endif

//int min_leaf_height = INT_MAX;
void get_path_sum(TreeNode* n, long long int& sum, vector<int>& path)
{

	if(n == NULL)
		return ;
	
	path.push_back(n->val);
	if(n->left == NULL && n->right == NULL)
	{
		long long int val = 0;
		for(int i=0; i<path.size(); i++)
		{
			long long int buf = path[i];
			val = val*10 + buf;
			val = val%1003;
		}
		cout<<"No = " << val << endl;
		val = val%1003;
		sum+= val;
		sum = sum%1003;
		path.pop_back();
		return;
	}

	get_path_sum(n->left,  sum, path);
	get_path_sum(n->right, sum, path);
	path.pop_back();
}


int Solution::sumNumbers(TreeNode* A) 
{
// Do not write main() function.
// Do not read input, instead use the arguments to the function.
// Do not print the output, instead return values as specified
// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
vector<int> path;
long long int sum=0;
get_path_sum(A, sum, path);
return sum%1003;;

}

int main()
{
Solution obj;
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->right->left = new TreeNode(4);
root->right->left->right = new TreeNode(5);

int val = obj.sumNumbers(root);
cout<<"\n Path sum = " << val << endl;
return 0;
}
