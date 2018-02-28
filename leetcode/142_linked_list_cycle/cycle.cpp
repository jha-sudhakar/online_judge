#include<stdio.h>

#if JHA
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution
{
	public:
	ListNode *detectCycle(ListNode *head);
	ListNode * get_circle_start(ListNode *head, const int k);
	bool hasCycle(ListNode *head, ListNode **circle_ptr);
	int get_circle_length(ListNode *cnode);
};

ListNode *Solution::detectCycle(ListNode *head)
{
	ListNode* circle_ptr = NULL;
	bool iscycle = hasCycle(head, &circle_ptr);
	if(false == iscycle)
		return NULL;
	
	int k = get_circle_length(circle_ptr);
	ListNode *cstart = get_circle_start(head, k);
	return cstart;
	
}

bool Solution::hasCycle(ListNode *head, ListNode ** circle_ptr)
{
	ListNode* ptr1  = head;
	ListNode* ptr2  = head;
	
	while(ptr1!= NULL && ptr2 != NULL)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
		if(ptr2)
		{
			ptr2 = ptr2->next;
		}
		else
			return false;
		
		if(ptr1 == ptr2)
		{
			*circle_ptr = ptr1;
			return true;
		}
	}

	return false;	
}

int Solution::get_circle_length(ListNode* circle_ptr)
{
	ListNode* dup = circle_ptr;
	int count = 0;
	do
	{
		count++;
		circle_ptr = circle_ptr->next;
	} while(circle_ptr != dup);
	return count;
}

ListNode* Solution::get_circle_start(ListNode* head, const int k)
{
	ListNode* c_ptr = head;
	for(int i=0; i<k; i++)
		c_ptr = c_ptr->next;

	ListNode* l_ptr = head;
	while(l_ptr != c_ptr)
	{
		l_ptr = l_ptr->next;
		c_ptr = c_ptr->next;
	}
	return l_ptr;
}
