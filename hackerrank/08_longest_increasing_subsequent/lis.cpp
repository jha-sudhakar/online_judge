#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

unsigned int arr[1000000];
unsigned int count[1000000];

class LIS
{
	private:
		unsigned int N;
	public:
		void process_input();
		unsigned int get_max_len_lis();
};


void LIS::process_input()
{
	cin >> N;
	for(unsigned int i=0; i<N; i++)
	{
		cin >> arr[i];
	}

	cout << get_max_len_lis() << endl;
}

unsigned int LIS::get_max_len_lis()
{
	if(N  == 0)
	{
		return 0;
	}
	count[0] = 1;
	unsigned int max = 1;
	for(unsigned int i=1; i<N; i++)
	{
		unsigned int max_len = 1;
		for(unsigned int j=0; j<i; j++)
		{
			if(arr[j] < arr[i])
			{
			if(count[j]+1 > max_len)
				max_len = count[j]+1;
			}
		}
		count[i] = max_len;
		if(count[i] > max)
			max = count[i];
	}
	return max;
}

int main()
{
LIS obj;
obj.process_input();
return 0;
}
