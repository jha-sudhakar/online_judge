#include<iostream>
using namespace std;

#if JHA
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
#endif

class Solution {
public:
    ListNode* partition(ListNode* head, int x);
};

ListNode* Solution::partition(ListNode* head, int x)
{
	ListNode*root1 = new ListNode(0);
	ListNode*root2 = new ListNode(0);
	
	ListNode* prev_l1 = root1;
	ListNode* prev_l2 = root2;
	
	ListNode* ptr = head;
	while(ptr != NULL)
	{
		if(ptr->val <x)
		{
			prev_l1->next = ptr;
			prev_l1 = ptr;
		}
		else
		{
			prev_l2->next = ptr;
			prev_l2 = ptr;
		}
		ptr = ptr->next;
	}
	prev_l1->next = root2->next;
	prev_l2->next = NULL;

	head = root1->next;
	delete root1;
	delete root2;
	return head;
}