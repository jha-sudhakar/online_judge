#include<stdint.h>

#include<iostream>
using namespace std;

#define MAX 100000

uint64_t arr[MAX];
//uint64_t sum_arr[MAX][MAX];
class max_sum
{
	private:
		uint64_t T, N, M;

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
	for(unsigned int dist=0; dist<=N-1; dist++)
	{
		
		for(unsigned int start=0; start<N; start++)
		{
			uint64_t sum = 0;
			unsigned int cur_index = start;
			while((cur_index <=start+dist) && (cur_index <= N-1))
			{
				sum+= arr[cur_index];
				cur_index++;
			}
			
			sum  = sum%M;
			if(sum == M-1) { cout << M-1 << endl; return; }
			if(sum > max_modulo)
				max_modulo = sum;
		}
	}
	cout << max_modulo << endl;
}

int main()
{
max_sum obj;
obj.process_input();

return 0;
}
