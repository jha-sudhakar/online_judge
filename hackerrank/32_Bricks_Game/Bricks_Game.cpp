#include<limits.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

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
		cout << "\n\n";
	}
}

void KnapSack::read_testcase()
{
	delete arr;
	cin >> N;
	arr = new unsigned int[N+1];
	for(unsigned int i=1; i<=N; i++)
	{
		cin >> arr[i];
	}
	arr[0] = 0;
}

void KnapSack::get_max_sum()
{
	unsigned long long int fval = 0;
	if(N<=3)
	{

		while(N != 0)
		{
			fval += arr[N];
			N--;
		}
		cout << fval << endl;
		return;
	}

	unsigned long long int* A = new unsigned long long int[N+1];
	unsigned long long int* B = new unsigned long long int[N+1];
	
	unsigned int* a_pos = new unsigned int[N+1];
	unsigned int* b_pos = new unsigned int[N+1];
	
	for(unsigned int i=0; i<=N; i++)
	{
		A[i] = B[i] = 0;
		a_pos[i] = b_pos[i] = 0;
	}
	
	A[1] = arr[1];
	A[2] = arr[1] + arr[2];
	A[3] = arr[1] + arr[2] + arr[3];
	a_pos[1] = 0;
	a_pos[2] = 0;
	a_pos[3] = 0;

	B[1] = 0;	
	B[2] = arr[2];
	B[3] = arr[2] + arr[3];
	b_pos[1] = 0;
	b_pos[2] = 1;
	b_pos[3] = 1;

	cout << "A[" << 1 << "] = " << A[1] << endl;	
	cout << "B[" << 1 << "] = " << B[1] << endl;	
		
	for(int i=4; i<=N; i++)
	{
		unsigned long long int sum_max3 = 0;
		for(int j=1; j<=3; j++)
		{
			if(i-j == 1) continue; // B can't be at position 1 as A selects first always.
			
			sum_max3 += arr[i-j+1];
			if(A[i] < A[b_pos[i-j]] + sum_max3)
			{
				A[i] = A[b_pos[i-j]] + sum_max3;
				a_pos[i] = i-j;
			}
		}

		sum_max3 = 0;
		for(int j=1; j<=3; j++)
		{
			//if(i-j <= 0) continue;// Not applicable now; i-j == 0 ensures that B never selects first as A[0] case is never evaluated.

			sum_max3 += arr[i-j+1];
			if(B[i] < B[a_pos[i-j]] + sum_max3)
			{
				B[i] = B[a_pos[i-j]] + sum_max3;
				b_pos[i] = i-j;
			}
		}

		cout << "A[" << i << "] = " << A[i] << " with B index " << a_pos[i] << endl;	
		cout << "B[" << i << "] = " << B[i] << " with A index " << b_pos[i] << endl;	
	}

	cout << "A-MAX = " << A[N] << endl;

	delete [] A; delete [] B;
}


int main()
{
	KnapSack obj;
	obj.execute();
	return 0;
}
