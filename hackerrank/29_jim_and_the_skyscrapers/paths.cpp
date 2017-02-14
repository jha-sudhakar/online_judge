#include<vector>
#include<iostream>
using namespace std;

class Paths
{
	private:
		unsigned int *arr, N;
		unsigned long long int count;
		vector<unsigned int> stk;
		void read_input();
		void count_paths();
		void calculate_and_pop( unsigned int new_val);
	public:
		Paths();
		void execute();
};

Paths::Paths()
{
	arr = NULL;
	count = 0;
}

void Paths::execute()
{
	read_input();
	count_paths();
}

void Paths::read_input()
{
	cin >> N;
	arr = new unsigned int[N];
	stk.reserve(N);
	for(unsigned int k=0; k<N; k++)
	{
		cin >> arr[k];
	}
}

void Paths::count_paths()
{
	unsigned int i=0;
	while(i<N)
	{
		if(stk.size() == 0 || stk[stk.size()-1] >= arr[i])
		{
			stk.push_back(arr[i]);
		}
		else if(stk[stk.size()-1] < arr[i])
		{
			calculate_and_pop(arr[i]);
			stk.push_back(arr[i]);
		}
		i++;
	}
	calculate_and_pop(1000001);
	cout << count << endl;
}

void Paths::calculate_and_pop(unsigned int new_val)
{
	unsigned int repeat=1;
	unsigned int cur_val = stk[stk.size()-1];
	stk.pop_back();
	
	while(stk.size() && stk[stk.size()-1] < new_val)
	{
		if(stk[stk.size()-1] == cur_val)
			repeat++;
		else
		{
			unsigned long long int count_buf = repeat;
			count += (count_buf * (count_buf-1));
			cur_val = stk[stk.size()-1];
			repeat = 1;
		}
		stk.pop_back();
	}
	unsigned long long int count_buf2 = repeat;
	count += (count_buf2 * (count_buf2-1));
}


int main()
{
Paths obj; 
obj.execute();
return 0;
}
