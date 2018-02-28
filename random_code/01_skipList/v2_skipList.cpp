#include<assert.h>
#include<time.h>
#include<stdlib.h>

#include<set>
#include<vector>
#include<iostream>
using namespace std;

struct node
{
	int data;
	unsigned int count;
	struct node* next;
	struct node* down;

	//node() { data = count = 0; next = down = NULL;}
	node(const int _data) { data = _data; count = 1; next = down = NULL;}
	node(const int _data, const int _count) { data = _data; count = _count; next = down = NULL;}
};

class Sklist
{
	private:
		const int MIN_VAL;
		struct node* root;
		multiset<int> sorted_arr;
		multiset<int>::iterator sorted_arr_itr;

	public:
		Sklist();
		~Sklist();
		void test_execute(int loop, int max_test_size);
		void destry_skip_list();
		void print_skip_list();
		void print_multi_set();
		void add(int ele);
		void add_min_val();
		//void remove(int ele);
		bool search(int ele);
	
};

Sklist::Sklist() :MIN_VAL(0)
{
	srand(time(NULL));
	root = new node(MIN_VAL);
}

Sklist::~Sklist()
{
	delete root;
}

void Sklist::print_skip_list()
{
	node* cur_root = root;
	int height = 1;
	while(cur_root)
	{
		struct node* ptr = root;
		cur_root = cur_root->down;
		cout <<" Height " << height << " => ";
		while(ptr != NULL)
		{
			cout << ptr->data << "/" << ptr->count;
			cout <<" ";
			ptr = ptr->next;
		}
		cout << endl;
		height++;
	}
	cout << endl;
}

void Sklist::print_multi_set()
{
	if(sorted_arr.size() == 0)
		return;
	
	sorted_arr_itr = sorted_arr.begin();
	int count = 0;
	int cur_val = *sorted_arr_itr;
	cout <<" Multiset " << " => ";
	for(; sorted_arr_itr != sorted_arr.end(); sorted_arr_itr++)
	{
		if(*sorted_arr_itr == cur_val)
		{
			count++;
		}
		else
		{
			cout << cur_val << "/" << count << " ";
			count = 1;
			cur_val = *sorted_arr_itr;
		}
	}
	cout << cur_val << "/" << count << " ";
	cout << endl;
}


void Sklist::test_execute(int loop, int max_test_size)
{
	int cur_loop = 1;
	while(cur_loop <= loop)
	{
		sorted_arr.clear();
		destry_skip_list();
		int test_size = 10 + rand()% max_test_size;
		for(int i=0; i<test_size; i++)
		{
			int ele = rand()% max_test_size;
			if(rand()%4)
			{
				cout << "Inserting " << ele << endl;
				add(ele);
				sorted_arr.insert(ele);
				//print_skip_list();
			}
			else
			{
				cout << "\tSearching " << ele << endl;
				bool ret1 = search(ele);
				bool ret2 = true;
				sorted_arr_itr = sorted_arr.find(ele);
				if(sorted_arr_itr == sorted_arr.end())
					ret2 = false;
				
				if(ret1 != ret2)
				{
					cout <<"\n There is mismatch between skip-list and multi-set" << endl;
					print_skip_list();
					print_multi_set();
					assert(false);
				}
			}
		}
		cout << "********************* Completed loop " << cur_loop << endl << endl;
		cur_loop++;
	}
}

void Sklist::destry_skip_list()
{
	while(root)
	{
		struct node* ptr = root;
		root = root->down;
		while(ptr != NULL)
		{
			struct node* next_ptr = ptr->next;
			delete ptr;
			ptr = next_ptr;
		}
	}
	root = new node(MIN_VAL);
	cout << "skip list destroyed\n";
}

void Sklist::add_min_val()
{
	node* ptr = root;
	while(ptr != NULL)
	{
		ptr->count++;
		ptr = ptr->down;
	}
}

void Sklist::add(const int ele)
{
	if(ele == MIN_VAL)
	{
		add_min_val();
		return;
	}

	vector<node*> node_path;
	node* ptr = root;
	do
	{
		while(ptr->next != NULL && ptr->next->data <=ele)
		{
			ptr = ptr->next;
		}
		node_path.push_back(ptr);
		ptr = ptr->down;

	} while(ptr != NULL);

	node* down_ptr = NULL;
	int height = 0;
	do
	{
		node* up_ptr = NULL;
		if(height < node_path.size())
		{
			up_ptr = node_path[node_path.size()-1 -height];
		}
		else
		{
			struct node* new_root = new node(MIN_VAL);
			new_root->down = root;
			new_root->count = root->count;
			root = new_root;

			up_ptr = new node(ele, 0);
			new_root->next = up_ptr;
		}
		if(up_ptr->data == ele)
		{
			up_ptr->count++;
			up_ptr->down = down_ptr;
			down_ptr = up_ptr;
		}
		else
		{
			struct node* new_node = new node(ele);
			new_node->next = up_ptr->next;
			up_ptr->next = new_node;
			new_node->down = down_ptr;
			down_ptr = new_node;
		}
		
		height++;
	}while(rand()%2);
}


bool Sklist::search(int ele)
{
	if(root == NULL)
	{
		return false;
	}

	node* ptr = root;
	do
	{
		while(ptr->next != NULL && ptr->next->data <=ele)
		{
			ptr = ptr->next;
		}

		if(ptr->data == ele)
		{
			if(ele != MIN_VAL)
				return true;
			else
			{
				if(ptr->count > 1)
					return true;
				else
					return false;
			}
		}
		ptr = ptr->down;

	} while(ptr != NULL);

	return false;
}

int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		cout <<"Usage: exe test_iteration test_size\n";
		exit(0);
	}
	Sklist obj;
	obj.test_execute(atoi(argv[1]), atoi(argv[2]));
	return 0;
}

