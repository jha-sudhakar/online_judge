//construct_the_array
#include<iostream>
using namespace std;

unsigned long long int arr[100001][2];

class Array
{
	unsigned long long int N, K, X;
	
	public:
		void execute();
		void calculate_count_eq();
		void calculate_count_df();
};

void Array::execute()
{
	cin >> N >> K >> X;
	if(1 == X)
		calculate_count_eq();
	else
		calculate_count_df();
}

void Array::calculate_count_eq()
{
	unsigned long long int P = 1000 * 1000 * 1000 + 7;
	arr[2][0] = K-1;
	arr[2][1] = 0;

	for(unsigned int i=3; i<=N; i++)
	{
		arr[i][0] = (K-1) * (arr[i-1][1])  + (K-2) * (arr[i-1][0]);
		arr[i][1] = arr[i-1][0];
		
		arr[i][0] = arr[i][0] % P; arr[i][1] = arr[i][1] % P;
		
		//cout <<"At " << i <<" [0] = " << arr[i][0] <<", [1] = " << arr[i][1] << endl;
	}
	cout << (arr[N][1] % P) << endl;
}

void Array::calculate_count_df()
{
	unsigned long long int P = 1000 * 1000 * 1000 + 7;
	arr[2][0] = K-2; // As 1st value can't be included and last value is handled next.
	arr[2][1] = 1;

	for(unsigned int i=3; i<=N; i++)
	{
		// There are K-1 options when prev value is last.
		arr[i][0] = (K-1) * (arr[i-1][1]);
		
		// There are K-2 options when prev value is not last and cur value is also not last.
		arr[i][0] += (K-2) * (arr[i-1][0]);

		arr[i][1] = arr[i-1][0];
		//cout <<"At " << i <<" [0] = " << arr[i][0] <<", [1] = " << arr[i][1] << endl;
		
		arr[i][0] = arr[i][0] % P; arr[i][1] = arr[i][1] % P;
	}
	cout << arr[N][1] << endl;
}

int main()
{
	Array obj;
	obj.execute();
	return 0;
}