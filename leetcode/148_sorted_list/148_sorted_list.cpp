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
		ListNode* sortList(ListNode* head);
		void sort_merge_sort(ListNode* node, int N);
};

ListNode* Solution::sortList(ListNode* head)
{
	if(head == NULL)
		return head;
	int len = 0;
	ListNode* ptr = head;
	while(ptr != NULL)
	{
		len++;
		ptr = ptr->next;
	}
	sort_merge_sort(head, len);
	return head;
}

void Solution::sort_merge_sort(ListNode* node, int N)
{
#if JHA
	cout <<"Called with N= " << N << " ==> ";
	ListNode* cur = node;
	int start = 1;
	while(start <=N)
	{
		cout << cur->val << " ";
		cur = cur->next;
		start++;
	}
	cout << endl;
#endif
	
	if(N == 1 || node == NULL)
		return;
	int mid = N/2;

	ListNode* ptr = node;
	for(int i=0; i<mid; i++)
	{
		ptr = ptr->next;
	}

	sort_merge_sort(node, mid);
	sort_merge_sort(ptr, N-mid);
	
	int l1 = 1;
	int l2 = 1;
	ListNode* n1 = node;
	ListNode* n1_prev = NULL;
	ListNode* n2 = ptr;

	while(l1 <= mid && l2<= (N-mid))
	{
		if(n1->val <= n2->val)
		{
			n1_prev = n1;
			n1 = n1->next;
			l1++;
		}
		else
		{
			int cur_val = n1->val;
			n1->val = n2->val;
			ListNode* n2_next = n2->next;
			n2->next = n1->next;
			n1->next = n2;
			n2->val = cur_val;
			
			n2 = n2_next;
			n1_prev = n1;
			n1 = n1->next;
	
			l2++;
		}
	}

	if(l2 > mid)
	{
		
		while(n1 != NULL && n1->next != ptr)
			n1 = n1->next;

		if(n1 !=NULL)
			n1->next = n2;
	}
	else
	{
		n1_prev->next = n2;
	}
}

#if JHA
int main()
{
	ListNode *root = new ListNode(3);
	root->next = new ListNode(2);
	root->next->next = new ListNode(1);
	
	ListNode* ptr = root;
	cout <<"\n Before sort ";
	while(ptr != NULL)
	{
		cout << ptr->val << " ";
		ptr = ptr->next;
	}
	cout << endl;

	Solution obj;
	ptr = obj.sortList(root);
	cout <<"\n After sort ";
	while(ptr != NULL)
	{
		cout << ptr->val << " ";
		ptr = ptr->next;
	}
	
	return 0;
}
#endif