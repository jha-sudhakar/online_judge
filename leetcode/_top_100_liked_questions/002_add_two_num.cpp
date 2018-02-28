You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8





/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
		ListNode *retNode = new ListNode(0);
		ListNode *cur_node = retNode;

		unsigned int sum = 0, carry = 0;
		unsigned int v = 0, v1=0, v2=0;
		while(l1 != NULL || l2 != NULL || carry != 0)
		{

			v = v1 = v2 = 0;
			if(l1 != NULL)
			{
				v1 = l1->val;
				l1 = l1->next;
			}
			if(l2 != NULL)
			{
				v2 = l2->val;
				l2 = l2->next;
			}
			sum = v1 + v2 + carry;
			carry = sum/10;
			v = sum%10;
			cur_node->next = new ListNode(v);
			cur_node = cur_node->next;
		}

		cur_node = retNode->next;
		delete retNode;
		return cur_node;
    }
};