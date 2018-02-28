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
		unsigned int T, N, K;
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
	cin >> N >> K;
	arr = new unsigned int[N+1];
	for(unsigned int i=1; i<=N; i++)
	{
		cin >> arr[i];
	}
	arr[0] = 0;
}

void KnapSack::get_max_sum()
{
	unsigned int* sum = new unsigned int[K+1];
	for(unsigned int i=0; i<=K; i++)
		sum[i] = 0;

	for(unsigned int w=1; w<=K; w++)
	{
		for(unsigned int j=1; j<=N; j++)
		{
			if(arr[j] > w)
				continue;

			if(sum[w] < sum[w-arr[j]] + arr[j])
				sum[w] = sum[w-arr[j]] + arr[j];
		}
	}
	cout << sum[K] << endl;

	delete [] sum;
}


int main()
{
	KnapSack obj;
	obj.execute();
	return 0;
}
