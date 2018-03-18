#include<limits.h>

#include <iostream>
using namespace std;

long int arr[100000];
class Msa
{
	private:
		long int sub_arr_sum, sub_seq_sum;
		unsigned int T, N;		
	public:
		void execute();
		void get_sum();
};

void Msa::execute()
{
	cin >> T;
	for(unsigned int i=0; i<T; i++)
	{
		cin >> N;
		for(unsigned int j=0; j<N; j++)
		{
			cin >> arr[j];
		}
		get_sum();
	}
}

void Msa::get_sum()
{
	if(N == 1)
	{
		cout << arr[0] << " " << arr[0] << endl;
		return;
	}
	sub_arr_sum = sub_seq_sum = 0;
/*
	cout <<"Input N = " << N << " ==> arr[] = ";
	for(unsigned int i=0; i<N; i++)
		cout << arr[i] << " ";
	cout << endl;
*/
	long int max_val = arr[0];
	for(unsigned int i=0; i<N; i++)
	{
		if(max_val < arr[i])
			max_val = arr[i];

		if(arr[i] >0)
			sub_seq_sum += arr[i];
	}
	if(sub_seq_sum == 0)
		sub_seq_sum = max_val;
	
	long int max_sum = -10005;
	for(unsigned int i=0; i<N; i++)
	{
		if(arr[i] >= 0)
		{
			sub_arr_sum += arr[i];
			continue;
		}

		if(sub_arr_sum > max_sum)
		{
			max_sum = sub_arr_sum;
		}
		
		if(sub_arr_sum + arr[i] > 0)
			sub_arr_sum += arr[i];
		else
			sub_arr_sum = 0;
	}
	if(sub_arr_sum > max_sum)
		max_sum = sub_arr_sum;
	if(max_val > max_sum || max_sum == 0)
		max_sum = max_val;
	
	cout << max_sum << " " << sub_seq_sum << endl;
}

int main()
{
	Msa obj;
	obj.execute();
	return 0;
}