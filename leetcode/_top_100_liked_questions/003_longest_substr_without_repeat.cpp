#include<iostream>
#include<string>
using namespace std;


class Solution
{
	public:
	int lengthOfLongestSubstring(string s)
	{
		if(s.size() < 2)
			return s.size();

		int pos[256];
		for(unsigned int i=0; i<256; i++)
		{
			pos[i] = -1;
		}

		int start = 0, end = 1, max_len = 1;
		pos[s[start]] = 0;

		while(end < s.size())
		{
			if(pos[s[end]] == -1)
			{
				pos[s[end]] = end;
			}
			else
			{

                int end_offset = pos[s[end]];
				for(int n=start; n<end_offset; n++)
					pos[s[n]] = -1;

				start = pos[s[end]] + 1;
				pos[s[end]] = end;
			}
			end++;
			if(max_len < (end-start))
				max_len = end-start;
		}
		return (max_len);
    }

};

int main()
{
	string str("abba");
	Solution obj;
	cout << "String = " << str <<",\t len = " << obj.lengthOfLongestSubstring(str) << endl;
	return 0;
}