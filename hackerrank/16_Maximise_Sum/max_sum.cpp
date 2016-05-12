#include<stdint.h>

#include<iostream>
using namespace std;

#define MAX 100000

uint64_t arr[MAX];
uint64_t buf1[MAX], buf2[MAX];
class max_sum
{
	private:
		uint64_t T, N, M;
		uint64_t *prev, *cur;
	public:
		void process_input();		
		void print_max_modulo();		
};

void max_sum::process_input()
{
	cin >> T;
	for(unsigned int k=0; k<T; k++)
	{
		cin >> N >> M;
		for(unsigned int i=0; i<N; i++)
			cin >> arr[i];


		print_max_modulo();		
	}
}

void max_sum::print_max_modulo()
{
	uint64_t max_modulo = 0;
	prev = buf1, cur = buf2;

	for(unsigned int i=0; i<N; i++)
	{
		prev[i] = arr[i]; // Fill the entries for len-0 sub-array.

		if( arr[i]%M > max_modulo)
			max_modulo = arr[i]%M;
		if(max_modulo == M-1) { cout << M-1 << endl; return; }
	}

	for(unsigned int dist=1; dist<N; dist++)
	{
		
		for(unsigned int start=0; start<N; start++)
		{
			uint64_t sum = 0;
			unsigned int cur_index = start+dist;
			if(cur_index >= N)
			{
				break;
			}
			
			sum = prev[start]+ arr[cur_index];
			cur[start] = sum;
			sum = sum%M;
			if(sum == M-1) { cout << M-1 << endl; return; }
			if(sum > max_modulo)
				max_modulo = sum;
		}
		uint64_t *buf = prev;
		prev = cur;
		cur = buf;
	}
	cout << max_modulo << endl;
}

int main()
{
max_sum obj;
obj.process_input();

return 0;
}
