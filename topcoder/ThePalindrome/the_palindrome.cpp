#if 0

Problem Statement
John and Brus are studying string theory at the university. 
Brus likes palindromes very much. A palindrome is a word that reads the same forward and backward. 
John would like to surprise Brus by taking a string, and appending 0 or more characters to the end of s 
to obtain a palindrome. 

	He wants that palindrome to be as short as possible. 
Return the shortest possible length of a palindrome that John can generate.

Definition
	Class: ThePalindrome
	Method: find
	Parameters: string
	Returns: int
	Method signature: int find(string s)

#endif

#include<string>
#include<iostream>
using namespace std;

class ThePalindrome
{
	private:
		unsigned char arr[51][51];
	
	public:
		int find(string str);
};

int ThePalindrome::find(string str)
{
	unsigned int N = str.size();
	if(str.size() < 2)
		return 0;

#if 0	
	unsigned char **arr = new unsigned char* [N];
	for(unsigned int i=0; i<N; i++)
		arr[i] = new unsigned char[N];
#endif 

	for(unsigned int i=0; i<N; i++)
		arr[i][i] = 1;

	for(unsigned int i=0; i<N-1; i++)
	{
		if(str[i] == str[i+1])
			arr[i][i+1] = 1;
		else
			arr[i][i+1] = 0;
	}

	for(unsigned int gap=2; gap<=N-1; gap++)
	{
		for(unsigned int i=0; i<=N-1-gap; i++)
		{
			unsigned int j=i+gap;
			if(str[i] != str[j])
				arr[i][j] = 0;
			else
				arr[i][j] = arr[i+1][j-1];
			
		}
	}
	unsigned int start = 0;
	for(start=0; start<N; start++)
	{
		if(arr[start][N-1] == 1)
			break;
	}

#if 0	
	for(unsigned int i=0; i<N; i++)
		delete [] arr[i];
	delete [] arr;
#endif
	return start+N;
}

#if JHA

int main(int argc, char* argv[])
{
	ThePalindrome obj;
	cout << obj.find(argv[1]) << endl;
	return 0;
}

#endif