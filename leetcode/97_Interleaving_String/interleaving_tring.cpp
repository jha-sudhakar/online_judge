#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


class Str
{
	private:
		string str1, str2, mxstr;
		int M,N,L;
	public:
		void read_input(string& _s1, string& _s2, string& _s12);
		bool is_str_interleaving();

};
void Str::read_input(string& _s1, string& _s2, string& _s12)
{
	str1 = _s1;   M = str1.size();
	str2 = _s2;   N = str2.size();
	mxstr = _s12; L = mxstr.size();
}

bool Str::is_str_interleaving()
{
	if(M+N != L)
		return false;

	int table[M+1][N+1];
	for(int i=0; i<=M; i++)
		for(int j=0; j<=N; j++)
			table[i][j] = 0;

	for(int i=1; i<=M; i++)
	{
		if(str1[i-1] == mxstr[i-1])
			table[i][0] = table[i-1][0] + 1;
		else
			table[i][0] = table[i-1][0];
	}

	for(int j=1; j<=N; j++)
	{
		if(str2[j-1] == mxstr[j-1])
			table[0][j] = table[0][j-1] + 1;
		else
			table[0][j] = table[0][j-1];
	}

	for(int sizei=1; sizei<=M; sizei++)
	{

		for(int sizej=1; sizej<=N; sizej++)
		{
			int val1 = table[sizei-1][sizej];
			int val2 = table[sizei][sizej-1];
			if(mxstr[sizei+sizej-1] == str1[sizei-1]  && mxstr[sizei+sizej-1] != str2[sizej-1])
			{
				table[sizei][sizej] = val1+1;

			} else if(mxstr[sizei+sizej-1] != str1[sizei-1]  && mxstr[sizei+sizej-1] == str2[sizej-1])
			{
				table[sizei][sizej] = val2+1;
			} else if (mxstr[sizei+sizej-1] == str1[sizei-1]  && mxstr[sizei+sizej-1] == str2[sizej-1])
			{
				if(val1 > val2)
					table[sizei][sizej] = val1 +1;
				else
					table[sizei][sizej] = val2 +1;
			}
			else
			{
				if(val1 > val2)
					table[sizei][sizej] = val1;
				else
					table[sizei][sizej] = val2;
			}
		}

	}
	cout<<"table[M][N] = " << table[M][N] << endl;
	bool result;
	if(table[M][N] == L)
		result = true;
	else
		result = false;

	return result;	
}

int main()
{
	Str obj1;
	string s1("aabcc");
	string s2("dbbca");
	string s3("aadbbbaccc"); 
	//string s3("aadbbcbcac");

	obj1.read_input(s1, s2, s3);
	cout <<"\ns1= " << s1 <<", s2= " << s2 <<", s3= " << s3 << endl;
	cout<<"\n Found = " << obj1.is_str_interleaving() << endl;
	return 0;
}
