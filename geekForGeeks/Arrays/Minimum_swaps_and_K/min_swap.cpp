#include <iostream>
using namespace std;

int T, N, K;
int* arr;

void get_min_swap()
{
	int i=0, j=N;
	while(i<=j)
	{
		
	}
	
}
		
int main()
{
	cin >> T;
	for(int i=0; i<T; i++)
	{
		cin >> N;
		arr = new int[N];
		for(int j=0; j<N; j++)
			cin >> arr[j];
		cin >> K;
		get_min_swap();
		delete [] arr;
	}

	return 0;
}