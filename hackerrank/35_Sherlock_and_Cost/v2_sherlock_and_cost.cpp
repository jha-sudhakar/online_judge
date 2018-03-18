//Sherlock and Cost
#include<assert.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

unsigned int arr[100001][101];
unsigned int arr2[100001][101];

class MaxCost
{
	unsigned int T, N;
	unsigned int* B;
	public:
		MaxCost();
		~MaxCost();
		void execute();
		void find_max_sum_v1();
		void find_max_sum_v2();
		void compare_arr();
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
		find_max_sum_v1();
		//find_max_sum_v2();
		//compare_arr();
	}
}

void MaxCost::find_max_sum_v1()
{
	unsigned int debug_num = 0;
	if(N == 1)
	{
		cout << 0 << endl;
		return;
	}
	unsigned int max_diff = 0;
	unsigned int cmp_set[101], cmp_index[101], cmp_set_size=0;
	
	for(unsigned int i=2; i<=N; i++)
	{
		cmp_set_size=0;
		unsigned int max_prev = 0;
		for(unsigned int pval=1; pval<=B[i-1]; pval++)
		{
			if(max_prev < arr[i-1][pval])
				max_prev = arr[i-1][pval];
		}
		if(debug_num == i)
		{
			cout <<"max value = " << max_prev << ", B[i] = " << B[i] << endl;
		}
		unsigned int max_b_diff = max(B[i], B[i-1]);
		for(unsigned int pval=1; pval<=B[i-1]; pval++)
		{
			if(arr[i-1][pval] + max_b_diff >= max_prev)
			{
				if(cmp_set_size > 100) assert(false);
				cmp_set_size++;
				cmp_set[cmp_set_size] = arr[i-1][pval];
				cmp_index[cmp_set_size] = pval;
			}
		}

		if(cmp_set_size == 0)
		{
			assert(false);
		}

		for(unsigned int val=1; val<=B[i]; val++)
		{
			arr[i][val] = 0;
			for(unsigned int pval=1; pval<=cmp_set_size; pval++)
			{
				int val1 = val;
				int val2 = cmp_index[pval];
				max_diff = cmp_set[pval] + abs(val1-val2);

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

void MaxCost::find_max_sum_v2()
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
			arr2[i][val] = 0;
			for(unsigned int pval=1; pval<=B[i-1]; pval++)
			{
				int val1 = val, val2 = pval;
				max_diff = arr2[i-1][pval] + abs(val1-val2);

				if(max_diff > arr2[i][val])
				{
					arr2[i][val] = max_diff;
					//if(arr2[i][val] == 1121 && i == 14 && val == 1)
						if(0 && i == 14 && val == 1)
						cout <<"prev_val = " << arr2[i-1][pval] <<", value= " << arr2[i][val] <<", prev index= " << pval <<", prev B= " << B[i-1] << endl;
						
				}
			}
		}
	}

	max_diff = 0;
	for(unsigned int i=1; i<=B[N]; i++)
	{
		if(arr2[N][i] > max_diff)
			max_diff = arr2[N][i];
	}
	cout << max_diff << endl;
}

void MaxCost::compare_arr()
{
	for(unsigned int i=1; i<=N; i++)
	{
		for(unsigned int j=1; j<=B[i]; j++)
		{
			if(arr[i][j] != arr2[i][j])
			{
				cout <<"Mismatch at index= [" << i << ", " << j <<"] and B-Val-1= " << arr[i][j] <<", B-Val-2= " << arr2[i][j] << endl;
				cout <<" B[i-1]= " << B[i-1] <<", B[i]= " << B[i] << endl;
				assert(false);
			}
		}
	}
}

int main()
{
	MaxCost obj;
	obj.execute();
	return 0;
}