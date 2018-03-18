#include<assert.h>
#include<string>
#include<iostream>
using namespace std;

enum DIR
{
	EQ,
	LFT,
	RGT,
	DAG
};

class Solution
{
	private:
		string str;
		string palin_str;
		unsigned int N;
		unsigned int** arr;
		DIR** index;

	public:
		int longestPalindromeSubseq(string s);
		void build_data(unsigned int _N);
		void release_data();		
		void print_palindrome(int i, int j);
};

void Solution::build_data(unsigned int _N)
{
	N = _N;
	arr = new unsigned int* [N+1];
	index = new DIR* [N+1];
	for(unsigned int i=0; i<=N; i++)
	{
		arr[i] = new unsigned int[N+1];
		index[i] = new DIR[N+1];
	}
}


void Solution::release_data()
{
	for(unsigned int i=0; i<=N; i++)
	{
		delete [] index[i];
		delete [] arr[i];
	}
	delete [] arr; delete [] index;
	N = 0;
}


int Solution::longestPalindromeSubseq(string _s)
{
	if(_s.size() <= 1)
		return _s.size();

	str = "a" + _s; // To have index start at 1;
	build_data(_s.size());
	
	for(unsigned int i=0; i<=N; i++)
		for(unsigned int j=0; j<=N; j++)
			arr[i][j] = 0;
	
	for(unsigned int i=1; i<=N; i++)
	{
		arr[i][i] = 1;
		index[i][i] = EQ;
	}
	for(unsigned int i=1; i<N; i++)
	{
		arr[i][i+1] = 1;
		index[i][i+1] = RGT;
		if(str[i] == str[i+1])
		{
			arr[i][i+1]++;
			index[i][i+1] = EQ;
		}
	}
	
	for(unsigned int gap=2; gap<=N-1; gap++)
	{
		for(unsigned int i=1; i<=N-gap; i++)
		{
			unsigned int j = i+gap;
			int val_max = 0;
			int val1 = arr[i+1][j];
			int val2 = arr[i][j-1];
			int val3 = arr[i+1][j-1];
			if(str[i] == str[j])
				val3+=2;
			if(val_max< val1)
			{
				val_max= val1;
				index[i][j] = RGT;
			}
			if(val_max < val2)
			{
				val_max = val2;
				index[i][j] = LFT;
			}
			if(val_max < val3)
			{	
				val_max = val3;
				if(str[i] == str[j])
					index[i][j] = EQ;
				else
					index[i][j] = DAG;
			}
			arr[i][j] = val_max;
			//cout<<"\npalindrome at " << i << " and " << j <<" = " << arr[i][j] << endl;
		}
	}
	int ret_val = arr[1][N];
	palin_str.clear();
	//cout <<"\nLength of palindrome = " << arr[1][N] << endl;
	//cout <<"\n palindrome string = "; print_palindrome(1, N);	cout << endl;
	release_data();
	//return palin_str;
	return ret_val;
}

void Solution::print_palindrome(int i, int j)
{
	if(i>j)
		return;
	else if( i == j)
	{
		cout << str[i];
		palin_str  += str[i];
		return;
	}
	
	if(index[i][j] == EQ)
	{
		cout << str[i];
		palin_str  += str[i];
		
		print_palindrome(i+1, j-1);
		
		cout << str[j];
		palin_str  += str[j];
	}
	else if(index[i][j] == DAG)
	{
		print_palindrome(i+1, j-1);
	}
	else if(index[i][j] == RGT)
	{
		print_palindrome(i+1, j);
	}
	else if(index[i][j] == LFT)
	{
		print_palindrome(i, j-1);
	}
	else
		assert(false);

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
	int max_palindrome = obj.longestPalindromeSubseq(input_str);
	cout << "\n Input string = " << input_str;
	cout << " ==> max-palindrom = " << max_palindrome << endl;
return 0;
}

#endif
