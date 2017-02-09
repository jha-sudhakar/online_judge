#include<assert.h>

#include <algorithm> 
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct node
{
	unsigned int n;
	unsigned int key;
	node *left, *right;
	node(const unsigned int val) { n=val; key=0; left=right=NULL; }
};

class Upgrade
{
	private:
		node* tree;
		unsigned int N, Q, root, key_count;
		vector<unsigned int> w,nk,kn; 

		void path_sum(const unsigned int x, const unsigned int y);
		void path_reverse(const unsigned int x, const unsigned int y);
		void set_node_key_inorder(node* _node);
		void set_node_key();
		void destroy_tree() {   }
	public:
		void read_input();
		void execute();

};

void Upgrade::read_input()
{
	vector<unsigned int> c_to_p;
	vector<node*> ptr;

	root = 0;
	cin >> N >> Q;
	w.push_back(0);

	ptr.resize(N+1);
	c_to_p.resize(N+1);
	c_to_p[0] = 0;
	ptr[0] = NULL;

	unsigned int buf;
	for(unsigned int i=1; i<=N; i++)
	{
		cin >> buf;
		w.push_back(buf);
		ptr[i] = NULL;
	}

	unsigned int parent, child;
	node* p_ptr, *c_ptr;
	for(unsigned int j=1; j<N; j++)
	{
		cin >> parent >> child;
		c_to_p[child] = parent;

		if(ptr[parent] == NULL)
			ptr[parent] = new node(parent);
		if(ptr[child] == NULL)
			ptr[child] =  new node(child);

		if(ptr[parent]->left == NULL)
			ptr[parent]->left = ptr[child];
		else
			ptr[parent]->right = ptr[child];
	}
	
	for(unsigned int j=1; j<=N; j++)
	{
		if(c_to_p[j] == 0)
		{
			root = j;
			break;
		}
	}
	if(root == 0)
		assert(false);
	//cout << "Root= " << root << endl;
	tree = ptr[root];
	ptr.clear();
	c_to_p.clear();

	nk.resize(N+1);
	//kn.resize(N+1);
}


void Upgrade::set_node_key()
{
	key_count = 1;
	set_node_key_inorder(tree);
	if(key_count != N+1)
		assert(false);
}

void Upgrade::set_node_key_inorder(node* _node)
{
	if(_node == NULL) return;

	set_node_key_inorder(_node->left);

	_node->key = key_count;
	nk[_node->n] = key_count;
	//kn[key_count] = _node->n;

	key_count++;

	set_node_key_inorder(_node->right);
}

void Upgrade::path_sum(const unsigned int x, const unsigned int y)
{
	if(x == y) 
	{
		cout << w[x] << endl;
		return;
	}		
	
	unsigned int sum = 0;
	unsigned int k1 = min(nk[x],nk[y]);
	unsigned int k2 = max(nk[x],nk[y]);
	node* tmp = tree;
	if(tmp == NULL)
		assert(false);
	while(1)
	{
		if(tmp->key>k1 && tmp->key>k2)
			tmp = tmp->left;
		else if(tmp->key<k1 && tmp->key<k2)
			tmp = tmp->right;
		else 
			break;
		if(tmp == NULL)
			assert(false);
	}
	sum += w[tmp->n];
	node* n1 = tmp->left;
	node* n2 = tmp->right;
	
	if(tmp->key == k1)
	{
		n1 = NULL;
	} else if(tmp->key == k2)
	{
		n2 = NULL;
	}
	
	while(n1 != NULL)
	{
		sum +=w[n1->n];
		if(n1->key < k1)
			n1 = n1->right;
		else if(n1->key > k1)
			n1 = n1->left;
		else
			break;
	}

	while(n2 != NULL)
	{
		sum +=w[n2->n];
		if(n2->key < k2)
			n2 = n2->right;
		else if(n2->key > k2)
			n2 = n2->left;
		else
			break;
	}

	cout << sum << endl;
}

void Upgrade::path_reverse(const unsigned int x, const unsigned int y)
{
	if(x == y)
		return;

	vector<unsigned int> v_all, v1, v2;
	unsigned int mid_ele=0;
	unsigned int k1 = min(nk[x],nk[y]);
	unsigned int k2 = max(nk[x],nk[y]);
	node* tmp = tree;
	while(1)
	{
		if(tmp->key>k1 && tmp->key>k2)
			tmp = tmp->left;
		else if(tmp->key<k1 && tmp->key<k2)
			tmp = tmp->right;
		else 
			break;
		if(tmp == NULL)
			assert(false);
	}
	mid_ele = tmp->n;
	node* n1 = tmp->left;
	node* n2 = tmp->right;
	
	if(tmp->key == k1)
	{
		n1 = NULL;
	} else if(tmp->key == k2)
	{
		n2 = NULL;
	}

	while(n1 != NULL)
	{
		v1.push_back(n1->n);
		if(n1->key < k1)
			n1 = n1->right;
		else if(n1->key > k1)
			n1 = n1->left;
		else
			break;
	}

	while(n2 != NULL)
	{
		v2.push_back(n2->n);
		if(n2->key < k2)
			n2 = n2->right;
		else if(n2->key > k2)
			n1 = n1->left;
		else
			break;
	}

	unsigned int loop;
	for(loop = v1.size(); loop>0; loop--)
	{
		v_all.push_back(v1[loop-1]);
	}
	v_all.push_back(mid_ele);
	for(loop=0; loop<v2.size(); loop++)
	{
		v_all.push_back(v2[loop]);
	}
	unsigned int i=0, j=v_all.size()-1; // assuming that atleast one ele is present;
	while(i<j)
	{
		unsigned int tmp = w[v_all[i]];
		w[v_all[i]] = w[v_all[j]];
		w[v_all[j]] = tmp;;
		i++; j--;
	}
	
}

void Upgrade::execute()
{
	read_input();
	set_node_key();
	string str;
	unsigned int l1, l2;
	for(unsigned int i=0; i<Q; i++)
	{
		cin >> str;
		cin >> l1 >> l2;
#if DBG
		cout <<"Operation= #" << str << "#" << ", arg1= " << l1 << ", arg2= " << l2 << endl;
#endif
		if(str[0] == 'R')
		{
			path_reverse(l1, l2);
		}
		else
		{
			path_sum(l1, l2);
		}
	}
}

int main()
{
Upgrade obj;
obj.execute();
return 0;
}
