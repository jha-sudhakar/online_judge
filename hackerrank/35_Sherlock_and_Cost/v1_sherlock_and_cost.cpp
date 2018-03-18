//Sherlock and Cost
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

unsigned int arr[100001][101];

class MaxCost
{
	unsigned int T, N;
	unsigned int* B;
	public:
		MaxCost();
		~MaxCost();
		void execute();
		void find_max_sum();
};

MaxCost::MaxCost()
{
	B = new unsigned int[100001];
	for(unsigned int val=0; val<=100; val++)
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
		find_max_sum();
	}
}

void MaxCost::find_max_sum()
{
	if(N == 1)
	{
		cout << 0 << endl;
		return;
	}
	unsigned int max_diff = 0;
	for(unsigned int i=2; i<=N; i++)
	{
		for(unsigned int val=1; val<=B[i]; val++)
		{
			arr[i][val] = 0;
			for(unsigned int pval=1; pval<=B[i-1]; pval++)
			{
				int val1 = val, val2 = pval;
				max_diff = arr[i-1][pval] + abs(val1-val2);

				if(max_diff > arr[i][val])
					arr[i][val] = max_diff;
			}
		}
	}

	max_diff = 0;
	for(unsigned int i=1; i<=B[N]; i++)
	{
		if(arr[N][i] > max_diff)
			max_diff = arr[N][i];
	}
	cout << max_diff << endl;
}


int main()
{
	MaxCost obj;
	obj.execute();
	return 0;
}