#include<assert.h>
#include<string>
#include<iostream>
using namespace std;

class Solution
{
	private:
		string str;
		unsigned int N;
		unsigned int** arr;

	public:
		string longestPalindrome(string s);
		void build_data(unsigned int _N);
		void release_data();		
};

void Solution::build_data(unsigned int _N)
{
	N = _N;
	arr = new unsigned int* [N+1];
	for(unsigned int i=0; i<=N; i++)
	{
		arr[i] = new unsigned int[N+1];
	}
}


void Solution::release_data()
{
	for(unsigned int i=0; i<=N; i++)
	{
		delete [] arr[i];
	}
	delete [] arr;
	N = 0;
}


string Solution::longestPalindrome(string _s)
{
	if(_s.size() <= 1)
		return _s;

	str = "a" + _s; // To have index start at 1;
	build_data(_s.size());

#if 0	
	for(unsigned int i=0; i<=N; i++)
		for(unsigned int j=0; j<=N; j++)
			arr[i][j] = 0;
#endif

	unsigned int max_len = 0;
	unsigned int start_index = 0;
	for(unsigned int i=1; i<=N; i++)
	{
		arr[i][i] = 1;
		max_len = 1;
	}

	for(unsigned int i=1; i<N; i++)
	{
		arr[i][i+1] = 0;
		if(str[i] == str[i+1])
		{
			arr[i][i+1] = 2;
			max_len = 2;
			start_index = i;
		}
	}

	for(unsigned int gap=2; gap<=N-1; gap++)
	{
		for(unsigned int i=1; i<=N-gap; i++)
		{
			unsigned int j = i+gap;
			if(str[i] != str[j])
			{
				arr[i][j] = 0;
				continue;
			}
			arr[i][j] = arr[i+1][j-1];
			//if(arr[i][j] && max_len < 1+j-i)
			if(arr[i][j])
			{
				max_len = 1+j-i;
				start_index = i;
			}
		}
	}
	release_data();

	string pstr;
	pstr.resize(max_len);
	for(unsigned int i = 0; i<max_len; i++)
		pstr[i] = str[start_index+i];

	return pstr;
}

#if JHA

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		cout <<"Usage: exe input-string\n";
		return 0;
	}
	string input_str(argv[1]);
	//string input_str = "dbabad";
	//string input_str = "cbabc";
	Solution obj;
	string max_palindrome = obj.longestPalindrome(input_str);
	cout << "\n Input string = " << input_str;
	cout << " ==> max-palindrom = " << max_palindrome << endl;
return 0;
}

#endif
