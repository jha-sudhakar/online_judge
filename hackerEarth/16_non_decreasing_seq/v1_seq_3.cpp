

#include<iostream>
using namespace std;

#define MAX 1000001
unsigned int arr[MAX], seq[MAX];

class seq_3
{
	private:
		unsigned int T, N, L;

	public:
		void process_input();
		void print_min_seq_3_end();
};

void seq_3::process_input()
{
	cin >> T;
	for(unsigned int i=0; i<T; i++)
	{
		cin >> N;
		for(unsigned int j=0; j<N; j++)
		{
			cin >> arr[j];
		}
		cin >> L;
		print_min_seq_3_end();
	}
	
}

void seq_3::print_min_seq_3_end()
{
	unsigned int min_ele = MAX;
	unsigned int min_qtr[4] = {MAX, MAX, MAX, MAX};
	for(unsigned int i=0; i<N; i++)
	{
		seq[i] = 1;
		if(arr[i] < min_ele)
			min_ele = arr[i];
		if(arr[i] < min_qtr[(i*4)/N])
		{
			min_qtr[(i*4)/N] = arr[i];
		}
	}

	if(L == 1)
	{
		cout << min_ele << endl;
		return;
	}	
	else if( L > N)
	{
		cout << -1 << endl;
		return;
	}

	unsigned int min_end = MAX, cur_len=0;;
	for(unsigned int i=1; i<N; i++)
	{
		unsigned int k=0;
		if(i > 10000)
		{
			for(k=(i*4)/N; k<4; k++)
			{
				if(arr[i] > min_qtr[k])
				{
					break;
				}
			}
			if(k == 4)
				break;
		}
		if(min_end <= arr[i]) // min_end is anyway smaller so skip this value.
		{
			seq[i] = L+1; 
			continue;
		}
		for(unsigned int j=0; j<i; j++)
		{
			if(arr[i] > arr[j])
			{
				cur_len = seq[j]+1;
				if(cur_len > seq[i])
					seq[i] = cur_len;

				if(cur_len == L)
				{
					if(min_end > arr[i])
					{
						min_end = arr[i];
						break;
					}	
				}
			}
		}

	}

	if(min_end == MAX)
	{
		if(L == 1)
			cout << min_ele << endl;
		else	
			cout << -1 << endl;
	}
	else
		cout << min_end << endl;
}


int main()
{
seq_3 obj;
obj.process_input();
return 0;
}
