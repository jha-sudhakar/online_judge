#include <stdio.h>
#include <limits.h>

#if 1
 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
#endif
ass Solution
{
        bool is_bst(TreeNode* node, int& prev, bool& prev_is_def);

		        public:
				        bool isValidBST(TreeNode* root)
						        {
								                int buf = INT_MIN;
												                bool prev_is_def = true;
																                if(root == NULL || (root->left == NULL && root->right == NULL))
																				                    return true;
																									                bool ret = is_bst(root,buf, prev_is_def);
																													        }

																															};

																															bool Solution::is_bst(TreeNode* node, int&  prev, bool& prev_is_def)
																															{
																															        if(node == NULL)
																																	                return true;
																																					        bool ret = false;

																																							        if(node->left != NULL)
																																									        {
																																											                ret = is_bst(node->left, prev, prev_is_def);
																																															                if(ret == false)
																																																			                        return ret;
																																																									        }

																																																											        if(node->val <= prev)
																																																													        {
																																																															                if(prev_is_def == true)
																																																																			                {
																																																																							                    prev_is_def = false;
																																																																												                    if(prev != INT_MIN)
																																																																																	                        return false;
																																																																																							                } else
																																																																																											                    return false;
																																																																																																        }
																																																																																																		        else
																																																																																																				        {
																																																																																																						                prev = node->val;
																																																																																																										        }

																																																																																																												        if(     node->right != NULL)
																																																																																																														        {
																																																																																																																                ret = is_bst(node->right, prev, prev_is_def);
																																																																																																																				                if(ret == false)
																																																																																																																								                        return ret;
																																																																																																																														        }

																																																																																																																																        return true;
																																																																																																																																		}

