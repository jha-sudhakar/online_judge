#include<assert.h>
#include<stdlib.h>
#include<math.h>

#include<vector>
#include<iostream>
#include<map>
using namespace std;

#define K 5

class arr_op
{
	private:
		unsigned int N, Q;
		vector<unsigned int> max_v;
		vector<unsigned int> arr;
		void op_0(const unsigned int index, const unsigned int new_val);
		void op_1(const unsigned int query_val);
		void print_log();
	public:
		arr_op() { srand(time(NULL)); }
		void process_input();
		void process_input_random();
};

void arr_op::print_log()
{
	for(unsigned int i=1; i<=N; i++)
	{
		cout << arr[i];
		if (i%5 == 0)
			cout<< " -  ";
		else
			cout <<" ";
	}	
	cout << endl;
	for(unsigned int i=1; i<max_v.size(); i++)
		cout << max_v[i] <<" ";
	cout << endl;	

}

void arr_op::process_input_random()
{
	N = 1+ rand()%20;
	Q = 10+ rand()%10;
	arr.clear(); max_v.clear();

	arr.resize(N+1);
	max_v.push_back(0); arr[0] = -1;
	unsigned int max = 0, count=1;;
	for(unsigned int i=1; i<=N; i++)
	{
		if(count >  K)
		{
			max_v.push_back(max);
			max = 0;count = 2;
		}
		else
			count++;
			
		arr[i] = rand()%1000;;
		if(arr[i] > max)
			max = arr[i];
	}
	
	max_v.push_back(max);

	int op_code;
	unsigned int index, new_val;
	unsigned int query_val;
	print_log();
	cout<<"**********Starting value above\n\n";
	for(unsigned int i=0; i<Q; i++)
	{
		op_code = rand()%2;;
		if(op_code == 0)
		{
			index = 1+rand()%N;
			new_val = rand()%1000;
			op_0(index, new_val);
		}
		else
		{
			query_val = arr[1+rand()%N];
			op_1(query_val);
		}
		print_log();
	}



}


void arr_op::process_input()
{
	cin >> N >> Q;
	arr.resize(N+1);
	max_v.push_back(0); arr[0] = -1;
	unsigned int max = 0, count=1;;
	for(unsigned int i=1; i<=N; i++)
	{
		if(count >  K)
		{
			max_v.push_back(max);
			max = 0;count = 1;
		}
		else
			count++;
			
		cin >> arr[i];
		if(arr[i] > max)
			max = arr[i];
	}
	
	max_v.push_back(max);

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

void arr_op::op_0(const unsigned int index, const unsigned int new_val)
{
	const unsigned int old_val = arr[index];
	arr[index] = new_val;
	
	const unsigned int high= ceil((double(index))/(double(K)));
	unsigned int low = index/K;
	if(low == high)
		low--;

	if(max_v[high] <= new_val)
	{
		max_v[high] = new_val;
	}	
	else if(max_v[high] == old_val)
	{
		unsigned int tmp_max = 0;
		for(unsigned int i=low*K+1; i<=high*K && i<=N; i++)
		{
			if(arr[i]>tmp_max)
				tmp_max = arr[i];
		}
		max_v[high] = tmp_max;
	}
}


void arr_op::op_1(const unsigned int query_val)
{
	unsigned int i=0;
	long int ret_val1 = 0, ret_val2 = 0;
	for(i=1; i<max_v.size(); i++)
	{
		if(max_v[i] >= query_val)
			break;

	}
	if(i == max_v.size())
	{ 	
		ret_val1 = -1; 
	}
	else
	{
		for(unsigned int k=(i-1)*K+1; k<=i*K && k<=N; k++)
		{
			if(arr[k] >= query_val) 
			{ 
				ret_val1 = k; 
				break;; 
			}
		}
	}
	
	ret_val2 = -1;
	for(unsigned int i=1; i<=N; i++)
	{
		if(arr[i] >= query_val)
		{
			ret_val2 = i;
			break;
		}	
	}
	if(ret_val1 != ret_val2)
	{
		cout<<"ret_val1 = " << ret_val1 <<", ret_val2= " << ret_val2 << endl;
		assert(false);
	}
	cout <<"\tN= " << N <<", Q= " << Q << ",query_val= " << query_val <<", Index= " << ret_val1 << endl;
}


int main(int argc, char* argv[])
{
	arr_op obj1;
	for(int i=0; i<atoi(argv[1]); i++)
	{
		cout <<"Running loop " << i+1 << endl;
		obj1.process_input_random();
	}	
	return 0;
}
