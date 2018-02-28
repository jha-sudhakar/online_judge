#include<time.h>
#include<stdlib.h>


#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

class Dset
{
	private:
		unsigned int size;		
		vector<int> in_vec; // This is not modified and it is immutable input.

		int* arr, *set_size;
	public:
		Dset();
		
		void execute();
		void init_set();
		void build_input();
		void test_automation_run();

		void merge_set(int val1, int val2);
		int  get_set(int key);

};

Dset::Dset()
{
	srand(time(NULL));
	arr = NULL;
	dset = NULL;
}

void Dset::execute()
{
	// 1. build_input.
	build_input();
	
	// 2. Initialize the set where each element represents new set. 
	init_set();

	//3. merge
	test_automation_run();

}

void Dset::build_input()
{
	in_vec.clear();
	size = rand()%100;
	for(int i=0; i<size; i++)
	{
		in_vec.push_back(i+1);
	}
}


void Dset::init_set()
{
	if(arr != NULL)
		delete [] arr;

	if(dset != NULL)
		delete [] dset;

	arr = new int[size];
	dset = new struct node[size];
	for(int i=0; i<in_vec.size(); i++)
	{
		arr[i] = in_vec[i];
		dset[i].init(in_vec[i]);
		set_size[i] = 1;
	}
}
		

void Dset::test_automation_run()
{

	


}

void Dset::merge_set(int val1, int val2)
{
	int key1 = get_set(val1);
	int key2 = get_set(val2);
	
	if(set_size[key1] > set_size[key2])
	{
		set_size[key1] += set_size[key2];
		node[key2].par = key1;		
	}	
	else
	{
		set_size[key2] += set_size[key1];
		node[key1].par = key2;
	}
}

int  Dset::get_set(int key)
{
	while(key != node[key].par)
		key = node[key].par;
 
	return key;
}
