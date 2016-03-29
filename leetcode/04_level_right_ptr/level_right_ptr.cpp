#include <assert.h>
#include <stdio.h>
#include <list>
using namespace std;

#if 1
 //Definition for binary tree with next pointer.
 struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };
#endif
class Solution
{
	public:
		void connect(TreeLinkNode *root)
		{
			if(root == NULL) return;

			list<TreeLinkNode*> *next, *cur, *swap_buf;;
			cur = new list<TreeLinkNode*>;
			next = new list<TreeLinkNode*>;

			cur->push_back(root);
			TreeLinkNode* left_node = NULL;
			do
			{
				while(cur->size())
				{
					TreeLinkNode* cur_node = cur->front();
					cur->pop_front();
					
					if(left_node != NULL)
						left_node->next = cur_node;
					left_node = cur_node;

					if(cur_node->left != NULL)
						next->push_back(cur_node->left);
					if(cur_node->right != NULL)
						next->push_back(cur_node->right);
				}
				left_node = NULL;
				swap_buf = cur;
				cur = next;
				next = swap_buf;
				if(next->size()) assert(false);
				//if(cur == NULL) break;
			} while(cur->size());
		}
};


