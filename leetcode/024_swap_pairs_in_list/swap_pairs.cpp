#include<iostream>
using namespace std;

#if JHA
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
#endif

class Solution
{
	public:
		ListNode* swapPairs(ListNode* head);
};

ListNode* Solution::swapPairs(ListNode* head)
{
	if(head == NULL || head->next == NULL)
		return head;
	ListNode* tmp_head = new ListNode(0);
	tmp_head->next = head;
	
	ListNode *p1 = tmp_head;
	ListNode *p2 = head;
	ListNode *p3 = head->next;
	
	while(p2!= NULL && p3!= NULL)
	{
		p1->next = p3;
		p2->next = p3->next;
		p3->next = p2;
		
		p1 = p2;
		p2 = p1->next;
		if(p2)
			p3 = p2->next;
		else
			p3 = NULL;
	}
	head = tmp_head->next;
	delete tmp_head;
	return head;
}