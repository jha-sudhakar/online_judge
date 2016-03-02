
#include <string>
#include<iostream>
using namespace std;

class Str2
{

	private:
		string str1;
		string str2;
		unsigned int arr1[256];
		unsigned int arr2[256];

	public:
		void read_input();
		bool is_substr_found();
};


void Str2::read_input()
{
	unsigned int t;
	while(cin >> t)
	{
		for(int i=0; i<t; i++)
		{
			cin >> str1;
			cin >> str2;
			if(is_substr_found())
			{
				cout<< "YES" <<endl;
			} else
			{
				cout<< "NO" << endl;
			}
		}
	}
}

bool Str2::is_substr_found()
{
	for(int i=0; i<256; i++)
	{
		arr1[i] = arr2[i] = 0;
	}

	for(int k=0; k<str1.size(); k++)
	{
		arr1[str1[k]] = 1;
	}

	for(int k=0; k< str2.size(); k++)
	{
		arr2[str2[k]] = 1;
	}

	for(unsigned int k='a'; k<='z'; k++)
	{
		if(arr1[k] == arr2[k])
			if(arr1[k] != 0)
				return true;
	}

	return false;
}


int main()
{
Str2 obj;
obj.read_input();
return 0;
}
