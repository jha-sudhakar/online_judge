
#include<time.h>
#include<stdlib.h>
#include<assert.h>


#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;


//Tree based disjounsigned int set code
struct node
{
	unsigned int val;
	unsigned int par;

	node() { val = par = 0; }
	node(unsigned int _val) { val = par = _val; }
	void init(unsigned int _val) { val = par = _val; }
};

class Dset
{
	private:
		unsigned int N, Q;

		unsigned int* arr, *set_size;
		struct node* dset;

	public:
		Dset();
		void execute();
		void init_set();

		void merge_set(unsigned int val1, unsigned int val2);
		unsigned int  get_set(unsigned int key);
		unsigned int get_size(unsigned int val);
		void execute_op();
};

Dset::Dset()
{
	srand(time(NULL));
	arr = NULL;
	dset = NULL;
	set_size = NULL;
}

void Dset::execute()
{
	// 1. Initialize the set where each element represents new set. 
	init_set();

	// 2. merge
	execute_op();

}

void Dset::init_set()
{
	cin >> N >> Q;
	arr = new unsigned int[1+N];
	set_size = new unsigned int[1+N];
	dset = new struct node[1+N];
	for(unsigned int i=0; i<=N; i++)
	{
		arr[i] = i;
		dset[i].init(i);
		set_size[i] = 1;
	}
}
		

void Dset::execute_op()
{
	string op_code;
	unsigned int val1, val2;
	for(unsigned int i=0; i<Q; i++)
	{
		cin >> op_code;
		if(op_code[0] == 'M')
		{
			cin >> val1 >> val2;
			merge_set(val1, val2);
		}
		else if(op_code[0] == 'Q')
		{
			cin >> val1;	
			unsigned int cur_set_size = get_size(val1);
			cout << cur_set_size << endl;
		}
		else
		{
			assert(false);
		}	
	}
}

void Dset::merge_set(unsigned int val1, unsigned int val2)
{
	unsigned int key1 = get_set(val1);
	unsigned int key2 = get_set(val2);

	if(key1 == key2)
		return;
	
	if(set_size[key1] > set_size[key2])
	{
		set_size[key1] += set_size[key2];
		dset[key2].par = key1;		
	}	
	else
	{
		set_size[key2] += set_size[key1];
		dset[key1].par = key2;
	}
}

unsigned int  Dset::get_set(unsigned int key)
{
	while(key != dset[key].par)
	{
		unsigned int parent = dset[key].par;
		dset[key].par = dset[parent].par;	
		key = parent;
	}
 
	return key;
}
		

unsigned int Dset::get_size(unsigned int val)
{
	unsigned int key = get_set(val);
	return set_size[key];
}


int main()
{
	Dset obj;
	obj.execute();
	return 0;
}
