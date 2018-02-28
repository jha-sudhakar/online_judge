#include<limits.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

/*
Note
	Each element of  can be selected multiple times.
	If no element is selected then the sum is 0.

Input Format
	The first line contains  the number of test cases. 
	Each test case comprises of two lines. First line contains two integers,  , representing the length of list  and expected sum, respectively. 
	Second line consists of  space separated integers, , representing the elements of list .

Constraints 
	1<= T <= 10
	1<= n <= 2000
	1<= k <= 2000
	1<= a[i] <= 2000   ==> for i (1 to n)
	
Output Format
	Output  lines, the maximum sum for each test case which is as near as possible, but not exceeding, to the expected sum (k).
*/

class KnapSack
{
	private:
		unsigned int T, N;
		unsigned int* arr;
		
	public:
		KnapSack() { arr = NULL;}
		void execute();
		void read_testcase();
		void get_max_sum();
};

void KnapSack::execute()
{
	cin >> T;
	for(unsigned int i=0; i<T; i++)
	{
		read_testcase();
		get_max_sum();
	}
}

void KnapSack::read_testcase()
{
	delete arr;
	cin >> N;
	arr = new unsigned int[N+1];
	for(unsigned int i=N; i>=1; i--)
	{
		cin >> arr[i];
	}
	arr[0] = 0;
}

void KnapSack::get_max_sum()
{
	 int* index = new int[N+1];

	unsigned long long int* sum = new unsigned long long int[N+1];
	for(unsigned int i=0; i<=N; i++)
	{
		sum[i] = 0;
		index[i] = 0;
	}
	
	sum[1] = arr[1];
	sum[2] = arr[1] + arr[2];
	sum[3] = arr[1] + arr[2] + arr[3];
	
	for(unsigned int n=4; n<=N; n++)
	{
		unsigned long long int cur_sum = 0;
		for(unsigned int j=0; j<3; j++)
		{
			unsigned long long int cur_val = arr[n-j];
			cur_sum += cur_val;
			
			if(sum[n] < sum[n-j-1] + cur_sum)
			{
				sum[n] = sum[n-j-1] + cur_sum;
				index[n] = j;
			}
		}
		cout <<"At " << n <<" subset-size = " << index[n] << endl;
	}

	unsigned long long int sum_a = 0;
	long int pos = N;
	while(pos > 0)
	{
		cout <<"At pos " << pos << endl;
		for(int i=0; i<=index[pos]; i++)
		{
			unsigned long long int cur_val = arr[pos-i];
			sum_a += cur_val;
		}
		long int pos_b = pos - index[pos]-1; // start position of 2nd persion.
		pos = pos_b - index[pos_b] -1; // next start of 1st persion;
	}
	
	cout << sum_a << endl;
	delete [] sum;
	delete [] index;

}


int main()
{
	KnapSack obj;
	obj.execute();
	return 0;
}
