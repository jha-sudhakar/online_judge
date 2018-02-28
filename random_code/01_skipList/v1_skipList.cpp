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
	struct node* next;
	struct node* down;

	node() { data = 0; next = down = NULL;}
	node(const int _data) { data = _data; next = down = NULL;}
};

class Sklist
{
	private:
		vector<struct node*> headers;
		multiset<int> sorted_arr;
		multiset<int>::iterator sorted_arr_itr;

	public:
		Sklist();
		~Sklist();
		void test_execute(int loop, int max_test_size);
		void destry_skip_list();
		void add(int ele);
		//void remove(int ele);
		bool search(int ele);
	
};

Sklist::Sklist()
{
	srand(time(NULL));

}

Sklist::~Sklist()
{

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
			if(rand()%3)
			{
				add(ele);
				sorted_arr.insert(ele);
			}
			else
			{
				
				bool ret1 = search(ele);
				bool ret2 = true;
				sorted_arr_itr = sorted_arr.find(ele);
				if(sorted_arr_itr == sorted_arr.end())
					ret2 = false;
				
				if(ret1 != ret2)
				{
					cout <<"\n There is mismatch between skip-list and multi-set" << endl;
					assert(false);
				}
			}
		}
		cout << "\n Completed loop " << cur_loop << endl;
		cur_loop++;
	}
}

void Sklist::destry_skip_list()
{
	for(int i=0; i<headers.size(); i++)
	{
		struct node* ptr = headers[i];
		while(ptr != NULL)
		{
			struct node* next_ptr = ptr->next;
			delete ptr;
			ptr = next_ptr;
		}
	}
	headers.clear();
}

void Sklist::add(const int ele)
{
	if(headers.size() == 0)
	{
		struct node* tmp = new node(ele);
		headers.push_back(tmp);
		return;
	}

	vector<node*> node_path;
	//vector<int> node_path_type;

	node* ptr = headers[headers.size()-1];
	do
	{
		while(ptr->next != NULL && ptr->next->data <ele)
		{
			ptr = ptr->next;
		}
		if(ptr->down)
		{
			node_path.push_back(ptr);
			ptr = ptr->down;
		}

	} while(ptr->down);

	while(ptr->next != NULL && ptr->next->data <ele)
	{
		ptr = ptr->next;
	}
	
	node* new_node = new node(ele);
	new_node->next = ptr->next;
	ptr->next = new_node;

	int height = 0;
	while(rand()%2)
	{
		node* up_ptr = NULL;
		if(height < node_path.size())
		{
			up_ptr = node_path[node_path.size()-1 -height];
			
		}
		else
		{
			up_ptr = new node(ele);
			headers.push_back(up_ptr);
		}
		up_ptr->down = ptr;
		
		ptr = up_ptr;
		height++;
	}
}


bool Sklist::search(int ele)
{
	if(headers.size() == 0)
	{
		return false;
	}

	node* ptr = headers[headers.size()-1];
	do
	{
		while(ptr->next != NULL && ptr->next->data <ele)
		{
			ptr = ptr->next;
		}
		if(ptr->data == ele)
			return true;
		if(ptr->down)
		{
			ptr = ptr->down;
		}

	} while(ptr->down);

	while(ptr->next != NULL && ptr->next->data <ele)
	{
		ptr = ptr->next;
	}

	if(ptr->data == ele)
		return true;

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

