#include<vector>
#include<iostream>
#include<map>
using namespace std;

class arr_op
{
	private:
		unsigned int N, Q;
		vector<unsigned int> arr;
		map<unsigned int, unsigned int> dict;
		map<unsigned int, unsigned int>::iterator it;
		void op_0(unsigned int index, unsigned int new_val);
		void op_1(unsigned int query_val);
	public:
		void process_input();




};

void arr_op::process_input()
{
	cin >> N >> Q;
	arr.resize(N+1);
	for(unsigned int i=1; i<=N; i++)
	{
		cin >> arr[i];
		dict[arr[i]] = i;
	}
	
	int op_code;
	unsigned int index, new_val;
	unsigned int query_val;
	for(unsigned int i=0; i<Q; i++)
	{
		cin >> op_code;
		if(op_code == 0)
		{
			cin >> index >> new_val;
			op_0(index, new_val);
		}
		else
		{
			cin >> query_val;
			op_1(query_val);
		}
	}


}

void arr_op::op_0(unsigned int index, unsigned int new_val)
{
	unsigned int old_val = arr[index];
	arr[index] = new_val;

	it = dict.find(old_val);
	if(it != dict.end())
	{
		dict.erase(it);
	}
	dict[new_val] = index;
}


void arr_op::op_1(unsigned int query_val)
{
	it = dict.lower_bound(query_val);
	if(it == dict.end())
	{
		//cout << "Index is -1 for " << query_val << endl;
		cout << -1 << endl;
	}
	else
	{
		unsigned int min_index = it->second;
		while(it != dict.end())
		{

			//cout << "val= " << it->first <<", index= " << it->second << endl;
			if(min_index > it->second)
				min_index = it->second;
			it++;	

		}	
		cout << min_index << endl;
	}
}


int main()
{
	arr_op obj1;
	obj1.process_input();
	return 0;
}
