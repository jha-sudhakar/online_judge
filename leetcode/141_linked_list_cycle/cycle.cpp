#include<stdio.h>

#if 1
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
    bool hasCycle(ListNode *head)
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
				return true;
		}

		return false;	
    }
};