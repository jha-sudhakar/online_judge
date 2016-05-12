
#include<vector>
#include<iostream>
using namespace std;

#define BRK 5000
#define MAX 1000001
unsigned int arr[MAX], seq[MAX];
struct num
{
	unsigned int index;
	unsigned int l;
	num(unsigned int _index, unsigned int _l) { index=_index; l=_l;}
};
vector<num> seq_v;

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
		seq_v.clear();
		seq_v.reserve(BRK);
	}
	
}

void seq_3::print_min_seq_3_end()
{
	unsigned int min_ele = MAX;
	for(unsigned int i=0; i<N; i++)
	{
		seq[i] = 1;
		if(arr[i] < min_ele)
			min_ele = arr[i];
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
	for(unsigned int i=1; i<N && i<BRK; i++)
	{
		if(min_end <= arr[i]) // min_end is anyway smaller so skip this value.
		{
			seq[i] = L+1; 
			continue;
		}
		for(unsigned int j=0; j<i; j++)
		{
			if(seq[j] >= L)
				continue;

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

	seq_v.reserve(BRK);
	for(unsigned int i=0; i<BRK; i++)
	{
		if(seq[i] < L)
		{
			seq_v.push_back((num(arr[i], seq[i])));
		}

	}
	for(unsigned int i=BRK; i<N; i++)
	{
		if(min_end <= arr[i]) // min_end is anyway smaller so skip this value.
		{
			continue;
		}
		unsigned int max_len_i=0;
		for(unsigned int j=0; j<seq_v.size(); j++)
		{
			if(seq_v[j].l >= L)
				continue;
			
			if(arr[i] > seq_v[j].index)
			{
				cur_len = seq_v[j].l+1;
				if(cur_len > max_len_i)
					max_len_i = cur_len;

				if(cur_len == L)
				{
					if(min_end > arr[i])
					{
						min_end = arr[i];
						break;
					}
				}
				if(max_len_i <L)
				{
					seq_v.push_back(num(arr[i], max_len_i));
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
