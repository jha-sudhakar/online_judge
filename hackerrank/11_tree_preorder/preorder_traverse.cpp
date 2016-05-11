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



void preOrder(node *root) 
{
	string spc;
	if(root == NULL)
		return;
	list<node*> lst;
	lst.push_back(root);
	while(!lst.empty())
	{
		cout << spc;
		node* tmp = lst.front();
		lst.pop_front();
		cout << tmp->data;
		
		if(tmp->right != NULL)
			lst.push_front(tmp->right);
		if(tmp->left != NULL)
			lst.push_front(tmp->left);
			
		spc = string(" ");	
	}
	cout << endl;
}
