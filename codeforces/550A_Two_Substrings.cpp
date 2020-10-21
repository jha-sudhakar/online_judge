#include<string>
#include <iostream>
using namespace std;

string str;
long int string_pos (long int N, long int s, const char ch[3])
{

	while(s+1 < N)
	{
		if(str[s] == ch[0] && str[s+1] == ch[1])
		{
			break;
		}
		s++;
	}

	if(s+1 >= N) // In main() function calling with __ start+2 __  can be bigger than N
	{
		return -1;
	}
	return s;
}

int main()
{
	//cin >> str;
	getline(cin, str);
	long int N = str.size();
	if(N < 4)
	{
		cout << "NO";
		return 0;
	}

	long int start_index = string_pos(N, 0, "AB");
	if(start_index == -1)
	{
		cout <<"NO";
		return 0;
	}

	start_index = string_pos(N, start_index + 2, "BA");
	if(start_index != -1)
	{
		cout <<"YES";
		return 0;
	}

	start_index = string_pos(N, 0, "BA");
	if(start_index == -1)
	{
		cout <<"NO";
		return 0;
	}

	start_index = string_pos(N, start_index + 2, "AB");
	if(start_index == -1)
	{
		cout <<"NO";
		return 0;
	}


	cout << "YES";
	return 0;
}