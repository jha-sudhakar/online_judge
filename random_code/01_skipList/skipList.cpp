#include<limits.h>
#include<assert.h>
#include<stdlib.h>


#include<iostream>
#include<vector>
using namespace std;

#define MIN INT_MIN
#define MAX	INT_MAX

typedef int myint;

struct node
{
	myint val;
	node *next, *down;
	node(const myint _val) { val=_val; next=down=NULL; }
};

class skipList
{
	private:
		vector< node* > roots; 
		vector<myint> arr;

	private:
		void init();
		void insert_null_list() {  }
		void insert(const myint key);
		bool  remove(const myint key);
		bool  search(const myint key);
		void print_list();
		void validate_list();
public:
		void test_automation();
};


void skipList::validate_list()
{
	for(unsigned int i=roots.size(); i>0; i--)
	{
		node* cur = roots[i-1];
		myint prev_val = INT_MIN;
		while(cur != NULL)
		{
			if(prev_val>cur->val)
			{
				print_list();
				assert(false);
			}
			prev_val = cur->val;
			cur = cur->next;
		}	
	}
}

void skipList::print_list()
{
	//return ;
	cout<<"\n Printing Skip List\n";
	for(unsigned int i=roots.size(); i>0; i--)
	{
		node* cur = roots[i-1];
		while(cur != NULL)
		{
			cout << cur->val << " ";
			cur = cur->next;
		}	
		cout << endl;
	}
	cout <<"--------------------------------------------------------------------------------------\n";
	for(unsigned int j=0; j<arr.size(); j++)
	cout << arr[j] << " ";
	cout << endl;
}


void skipList::init()
{
		srand(time(NULL));
		node* min_node = new node(MIN);
		node* max_node = new node(MAX);
		min_node->next = max_node;


		node* min_node2 = new node(MIN);
		node* max_node2 = new node(MAX);
		min_node2->next = max_node2;

		min_node->down = min_node2;
		max_node->down = max_node2;

		roots.push_back(min_node2);
		roots.push_back(min_node);
}

bool skipList::search(const myint key)
{
	node* cur = roots[roots.size()-1];
	node* prev = NULL;
	do
	{
		node* row_ptr = cur;
		prev = NULL;
		while(row_ptr->val <=key)
		{
			prev = row_ptr;
			row_ptr = row_ptr->next;
		}
		cur = prev;
		cur = cur->down;
	}while(cur->down != NULL);

	while(cur->next != NULL && cur->next->val <=key)
		cur = cur->next;
	if(cur->val == key)
		return true;
	else
		return false;
}

bool skipList::remove(const myint key)
{
	vector<node*>path;
	node* cur = roots[roots.size()-1];
	node* prev = NULL;
	do
	{
		node* row_ptr = cur;
		prev = NULL;
		while(row_ptr->val <key)
		{
			prev = row_ptr;
			row_ptr = row_ptr->next;
		}
		cur = prev;
		path.push_back(cur);
		cur = cur->down;
	}while(cur->down != NULL);

	while(cur->next != NULL && cur->next->val <key)
		cur = cur->next;
	if(cur->next == NULL || cur->next->val != key)
	{
		return false; // Not found the key;
	}
	
	node* deleted_node = cur->next;
	cur->next = cur->next->next;
	delete deleted_node; // Release the memory

	while(path.size())
	{
		node* path_node = path[path.size()-1];
		path.pop_back();
		if(path_node->next == NULL || path_node->next->val != key)
		{
			break;
		}
		deleted_node = path_node->next;
		path_node->next = path_node->next->next;
		delete deleted_node; // Release the memory
	}

	return true;
}


void skipList::insert(const myint key)
{
	vector<node*>path;
	node* cur = roots[roots.size()-1];
	node* prev = NULL;
	do
	{
		node* row_ptr = cur;
		prev = NULL;
		while(row_ptr->val <=key)
		{
			prev = row_ptr;
			row_ptr = row_ptr->next;
		}
		cur = prev;
		path.push_back(cur);
		cur = cur->down;
	}while(cur->down != NULL);

	while(cur->next != NULL && cur->next->val <=key)
		cur = cur->next;

	node* new_node = new node(key);
	new_node->next = cur->next;
	cur->next = new_node;

	while(1)
	{
		if(rand()%2)
			break;

		node* prev_new_node = new_node;
		new_node = new node(key);
	
		if(path.size())
		{ 
			node* node_at_cur_level = path[path.size()-1];
			path.pop_back();
			new_node->next = node_at_cur_level->next;
			node_at_cur_level->next = new_node;
			new_node->down = prev_new_node;
		}
		else
		{
			node* node_start_below = roots[roots.size()-1];
			node* node_end_below = node_start_below;
			while(node_end_below->next != NULL)
				node_end_below = node_end_below->next;
			
			node* min_node = new node(MIN);
			node* max_node = new node(MAX);
			min_node->next = new_node;
			new_node->next = max_node;

			min_node->down = node_start_below;
			max_node->down = node_end_below;
			new_node->down = prev_new_node;

			roots.push_back(min_node);
		}
	}

}

void skipList::test_automation()
{
	unsigned int op_count=220000, R=100;
	init();
	unsigned int op_num[3];op_num[0] = op_num[1] = op_num[2] = 0;
	while(op_count--)
	{
		cout << "op_count = " << op_count+1 << endl;
		int val = rand()%3;
		op_num[val]++;
		switch(val)
		{
			case 0:	// Insert
					{
					int val = rand()%R;
					arr.push_back(val);
					insert(val);
					validate_list();
					}
					break;

			case 1:	// Find;
					{
					bool v_ret = false, sl_ret=false;
					int val = rand()%R;
					for(unsigned int k=0; k<arr.size(); k++) { if(arr[k] == val) {v_ret = true; break;} }
					sl_ret  = search(val);
					validate_list();
					if(v_ret != sl_ret)
					{
						print_list();
						cout <<"Search key= " << val <<", vec_ret= " << v_ret <<", sl_ret= " << sl_ret << endl;
						assert(false);
					}
					}
					break;

			case 2:
					{
					bool v_ret = false, sl_ret=false;
					int val = rand()%R;
					for(unsigned int k=0; k<arr.size(); k++) 
					{ 
						if(arr[k] == val)
						{
							for(unsigned int j=k+1; j<arr.size(); j++)
								arr[j-1] = arr[j];
							arr.pop_back();
							v_ret = true; break;
						}

					}
					sl_ret  = remove(val);
					validate_list();
					if(v_ret != sl_ret)
					{
						print_list();
						cout <<"Remove key= " << val <<", vec_ret= " << v_ret <<", sl_ret= " << sl_ret << endl;
						assert(false);
					}
					}
					break;
		}
	}
	print_list();
	cout <<"Summary ==> Height= " << roots.size();
	cout<<", Insert= " << op_num[0] <<", Find= " << op_num[1] <<",Remove= " << op_num[2] << endl;
}

int main()
{
skipList obj;
obj.test_automation();
return 0;
}
