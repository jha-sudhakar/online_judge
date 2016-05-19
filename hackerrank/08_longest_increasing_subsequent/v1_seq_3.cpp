
#include<vector>
#include<iostream>
using namespace std;

#define MAX 1000001
struct num
{
	unsigned int index;
	unsigned int l;
	num(unsigned int _index, unsigned int _l) { index=_index; l=_l;}
	num() { }
};
num seq_v[MAX];
unsigned int seq_vlen = 0;
unsigned int arr[MAX];//, seq[MAX];
unsigned int lval[MAX];
class seq_3
{
	private:
		unsigned int T, N, L;

	public:
		void process_input();
		void print_min_seq_3_end();
		void clean_array();
};

void seq_3::clean_array()
{
	unsigned int w=0;
	for(unsigned int i=0; i<N; i++)
	{
		if((lval[seq_v[i].l] == seq_v[i].index) && (lval[seq_v[i].l] != MAX))
		{
			if( w != i)
				seq_v[w] = seq_v[i];
			w++;	
		}
	}
	seq_vlen = w;
}
void seq_3::process_input()
{
	cin >> T;
	for(unsigned int i=0; i<T; i++)
	{
		cin >> N;
		seq_vlen = 0;
		unsigned int min_ele = MAX;
		for(unsigned int j=0; j<N; j++)
		{
			cin >> arr[j];
			if(min_ele > arr[j])
				min_ele = arr[j];

			lval[j] = MAX;
		}
		cin >> L;
		if(L == 1)
		{
			cout << min_ele << endl;
			continue;//return;
		}	
		else if( L > N)
		{
			cout << -1 << endl;
			continue; //return;
		}
		print_min_seq_3_end();
	}
	
}

void seq_3::print_min_seq_3_end()
{
	seq_v[seq_vlen++] = num(arr[0],1);
	lval[1] = arr[0];
	unsigned int min_end = MAX, cur_len=0;;
	for(unsigned int i=0; i<N; i++)
	{
		if(min_end <= arr[i]) // min_end is anyway smaller so skip this value.
		{
			continue;
		}
		if(i > 1000 && i%1000 == 0)
		{
			clean_array();
		}
		unsigned int max_len_i=1;
		for(unsigned int j=0; j<seq_vlen; j++)
		{
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
			}
		}

		if(max_len_i <L)
		{
				if(lval[max_len_i] > arr[i])
				{
					seq_v[seq_vlen++] = num(arr[i], max_len_i);
					lval[max_len_i] = arr[i];
				}	
		}
	}


	if(min_end == MAX)
			cout << -1 << endl;
	else
		cout << min_end << endl;
}


int main()
{
seq_3 obj;
obj.process_input();
return 0;
}
