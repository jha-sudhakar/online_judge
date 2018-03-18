//Sherlock and Cost
#include<assert.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

unsigned int arr[100001][2];

class MaxCost
{
	unsigned int T, N;
	int* B;
	public:
		MaxCost();
		~MaxCost();
		void execute();
		void find_max_sum_v1();
};

MaxCost::MaxCost()
{
	B = new int[100001];
	for(unsigned int val=0; val<2; val++)
	{
		arr[0][val] = 0;
		arr[1][val] = 0;
	}

}

MaxCost::~MaxCost()
{
	delete [] B;
}

void MaxCost::execute()
{
	cin >> T;
	for(unsigned int i=0; i<T; i++)
	{
		cin >> N;
		for(unsigned int j=1; j<=N; j++)
		{
			cin >> B[j];
		}
		find_max_sum_v1();
	}
}

void MaxCost::find_max_sum_v1()
{
	if(N == 1)
	{
		cout << 0 << endl;
		return;
	}
	for(unsigned int i=2; i<=N; i++)
	{
		arr[i][0] = arr[i-1][0];	// 0 means a=1
		if(arr[i][0] < arr[i-1][1]+B[i-1]-1) // 1 means a=b
			arr[i][0] = arr[i-1][1]+B[i-1]-1;

		arr[i][1] = arr[i-1][1] + abs(B[i]-B[i-1]);	// 0 means a=1
		if(arr[i][1] <  arr[i-1][0]+B[i]-1) // 1 means a=b
			arr[i][1] = arr[i-1][0]+B[i]-1;

	}
	cout << max(arr[N][0], arr[N][1]) << endl;
}

int main()
{
	MaxCost obj;
	obj.execute();
	return 0;
}