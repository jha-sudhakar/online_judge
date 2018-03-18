#include<string>
#include<iostream>
using namespace std;

class Solution
{
	public:
		int countSubstrings(string s);
};

int Solution::countSubstrings(string str)
{
	unsigned int N = str.size();
	if(N<2)
		return N;
	unsigned int count = 0;
	unsigned int**arr = new unsigned int* [N];
	for(unsigned int i=0; i<N; i++)
		arr[i] = new unsigned int[N];

	for(unsigned int i=0; i<N; i++)
	{
		arr[i][i] = 1;
	}
	count += N;

	for(unsigned int i=0; i<N-1; i++)
	{
		arr[i][i+1] = 0;
		if(str[i] == str[i+1])
		{
			arr[i][i+1] = 1;
			count++;
		}
	}

	for(unsigned int gap=2; gap<N; gap++)
	{
		for(unsigned int start=0; start<=N-1-gap; start++)
		{
			unsigned int end = start+gap;
			if(str[start] != str[end])
			{
				arr[start][end] = 0;
				continue;
			}
			arr[start][end] = arr[start+1][end-1];
			if(arr[start][end])
				count++;
		}
	}
	
	for(unsigned int i=0; i<N; i++)
		delete [] arr[i];
	delete[] arr;

	return count;
}

