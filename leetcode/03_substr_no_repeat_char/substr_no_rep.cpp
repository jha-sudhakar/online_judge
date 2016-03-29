#include <string>
#include <iostream>
using namespace std;

class unq_str
{
	private:
		string str;
		int arr[256];

	public:
		string find_unique_sub_str();
		void read_input();
		void read_input(string& _s);
};

void unq_str::read_input()
{
	cin >> str;
	for(int i=0; i<256; i++)
		arr[i] = 0;
}

void unq_str::read_input(string& _s)
{
    str = _s;
	for(int i=0; i<256; i++)
		arr[i] = 0;
}

string unq_str::find_unique_sub_str()
{
	unsigned int unq_str_len = 0, unq_str_index = 0;;
	unsigned int prev = 0, cur = 0;
	while(cur < str.size())
	{
		if(arr[str[cur]] == 0)
		{
			arr[str[cur]] = 1;
			cur++;
		} else
		{
			// 1:- Is it longer str than prev.
			if(unq_str_len < (cur-prev))
			{
				unq_str_len = cur-prev;
				unq_str_index = prev;
			}
			// 2:-   
			while(str[prev] != str[cur])
			{
				arr[str[prev]] = 0;
				prev++;
			}
			prev++;
			cur++;
		}
	}
	if(unq_str_len < (cur-prev))
	{
		unq_str_len = cur-prev;
		unq_str_index = prev;
	}

	return str.substr(unq_str_index, unq_str_len);
}

class Solution 
{
public:
    int lengthOfLongestSubstring(string s)
	{
		unq_str obj1;
		obj1.read_input(s);
		return obj1.find_unique_sub_str().size();
	}
};

int main()
{
unq_str obj1;
obj1.read_input();
cout << obj1.find_unique_sub_str() << endl;
return 0;
}
