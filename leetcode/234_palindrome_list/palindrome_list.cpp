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
    bool isPalindrome(ListNode* head);
};

bool Solution::isPalindrome(ListNode* head)
{
	if(head == NULL || head->next == NULL)
		return true;
	
	int N=0;
	ListNode* ptr = head;
	while(ptr != NULL)
	{
		ptr = ptr->next;
		N++;
	}
	int mid = N/2;
	ptr = head;
	ListNode* prev_ptr = NULL;
	ListNode* next_ptr = ptr;
	for(int i=1; i<=mid; i++)
	{
		ptr = next_ptr;
		next_ptr = next_ptr->next;
		ptr->next = prev_ptr;
		prev_ptr = ptr;
	}
	
	if(N%2) // Odd no of nodes
		next_ptr = next_ptr->next;
	while(ptr != NULL && next_ptr != NULL)
	{
		if(ptr->val != next_ptr->val)
			return false;

		ptr = ptr->next;
		next_ptr = next_ptr->next;
	}
	return true;
}