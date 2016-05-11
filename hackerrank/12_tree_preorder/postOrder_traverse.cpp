#include<string>
#include<list>
#include<iostream>
using namespace std;

// you only have to complete the function given below.  Node is defined as  

struct node
{
int data;
node* left;
node* right;
};



void postOrder(node *root) 
{
	string spc;
	if(root == NULL)
		return;
	list<node*> lst;
	lst.push_back(root);
	node* last_popped_node = NULL;
	while(!lst.empty())
	{
		//cout << spc;
		node* tmp = lst.front();
		if((last_popped_node != NULL && (last_popped_node == tmp->left || last_popped_node == tmp->right))
			|| (tmp->left == NULL && tmp->right == NULL))
		{
			lst.pop_front();
			last_popped_node = tmp;
			cout << tmp->data << " ";;
		}
		else
		{
		if(tmp->right != NULL)
			lst.push_front(tmp->right);
		if(tmp->left != NULL)
			lst.push_front(tmp->left);
		}	
		//spc = string(" ");	
	}
	cout << endl;
}
