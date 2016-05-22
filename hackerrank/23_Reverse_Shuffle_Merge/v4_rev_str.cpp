#include<assert.h>

#include<map>
#include<vector>
#include<iostream>
#include<string>
using namespace std;

struct pos
{
	char ch;
	unsigned int index;

	pos(char _ch, unsigned int _index) { ch=_ch; index=_index; }
};

class rev_str
{
	private:
		unsigned int N;
		unsigned int w_len;
		string str;
		int count[26];
		bool is_valid(const string& s);
	public:
		void process_input();
		string get_the_min_str();
};

bool rev_str::is_valid(const string &s)
{
	int c[26];
	for(int i=0;i<26; i++)
		c[i] = 0;

	for(int i=0; i<s.size(); i++)
	{
		c[s[i]-97]++;
	}
	for(int i=0; i<26; i++)
	{
		if(count[i] != c[i])
		{
			cout <<" Invalid string " << s << endl;	
			return false;
		}	
	}
	return true;
}

void rev_str::process_input()
{
	cin >> str;
	for(int i=0;i<26; i++)
		count[i] = 0;

	for(int i=0; i<str.size(); i++)
	{
		count[str[i]-97]++;
	}

	for(int i=0;i<26; i++)
		count[i] = count[i]/2;

	str = str+str;
	w_len  = (str.size())/4;
	N = str.size();
	string rev_str = get_the_min_str();
	string cur_str = rev_str;
	for(int i=0; i<rev_str.size(); i++)
	{
		cur_str[rev_str.size()-1-i] = rev_str[i];
	}
	cout << cur_str << endl;
}


string rev_str::get_the_min_str()
{
	cout <<"Appended string = " << str << ", word-len= " << w_len << ", N= " << N << endl;
	map<string, int> str_map;
	map<string, int>::iterator  itr;
	for(unsigned int i=0; i<= N-2*w_len; i++) // SInce two ono-overlapping apirs have to be found so 2*w_len.
	{
		for(unsigned int j = i+w_len; j<= N-w_len; j++)
		{
			unsigned int  k=0;
			//cout <<" Looping i= " << i << ", j= " << j << endl;
			for(k=0; k<w_len; k++)
			{
				if(str[i+k] != str[j+k])
					break;
			}
			//cout << "compare exit at char " << (k+1) << endl;
			if(k == w_len) // Match found.
			{
				string buf = str.substr(i,w_len);
				//cout << "Match found--  " << buf << endl;
				itr = str_map.find(buf);
				if(itr == str_map.end())
				{
					cout <<"Inserting " << buf << endl;
					str_map[buf] = 1;
				} else //if(itr->second == 1)
				{
					(itr->second)++;
					cout <<"Increment count of  " << buf << endl;
				}
			}
		}
	}

	string ret_s;
	for(itr = str_map.begin(); itr != str_map.end(); ++itr)
	{
		if(is_valid(itr->first) == false)
		{
			continue;
		}
		if(ret_s.size() == 0)
			ret_s = itr->first;
		else
		{
			if(ret_s < itr->first)
				ret_s = itr->first;
		}
	}

	return ret_s;
}

int main()
{
rev_str obj;
obj.process_input();
return 0;
}
