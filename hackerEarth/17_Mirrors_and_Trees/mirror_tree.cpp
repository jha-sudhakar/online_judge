#include<vector>
#include<list>
#include<iostream>
using namespace std;

//2^18 = 262144
#define SIZE 262145

unsigned int arr[SIZE];

class mirror_tree
{

	private:
		unsigned int T, N;

	public:
		void process_input();
		void print_the_tree();
};

void mirror_tree::process_input()
{
	cin >> T;
	for(unsigned int i=0; i<T; i++)
	{
		cin >> N;
		arr[0] = 0;
		for(unsigned int j=1; j<=N; j++)
		{
			cin >> arr[j];
		}
		print_the_tree();
		//cout<<"**** Executed " << i+1 << "  test-case\n";
		cout<< endl;
	}
}

void mirror_tree::print_the_tree()
{
	list<unsigned int>  *tmp_list;
	list<unsigned int>  *next = new list<unsigned int>;
	list<unsigned int>  *cur  = new list<unsigned int>;
	vector<unsigned int> left_mval;

	cur->clear();
	cur->push_back(1); // Push the root;
	while(!cur->empty())
	{
		next->clear();
		if(cur->size() == 1)
		{
			cout << arr[cur->front()] << endl;
		} else
		{
			cout << arr[cur->back()] << endl;
			left_mval.push_back(arr[cur->front()]);
		}

		while(!cur->empty())
		{
			unsigned int cur_pos = cur->front(); 
			if(arr[cur_pos*2] != 0)
				next->push_back(cur_pos*2); //Left child.
			if(arr[cur_pos*2+1] != 0)
				next->push_back(cur_pos*2+1); //Right child.

			cur->pop_front();
		}
		tmp_list = cur;
		cur = next;
		next = tmp_list;
	}

	for(unsigned k=0; k<left_mval.size(); k++)
		cout << left_mval[k] << endl;

	delete cur;
	delete next;
}

int main()
{
	mirror_tree obj;
	obj.process_input();
	return 0;
}
