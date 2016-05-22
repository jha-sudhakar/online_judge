
#include<iostream>
#include<string>
using namespace std;



class rev_str
{
	private:
		string str;
		int count[26];

	public:
		void process_input();
		string get_the_min_str();
};

void rev_str::process_input()
{
	cin >> str;
	for(int i=0; i<26; i++)
		count[i] = 0;

	for(int i=0; i<str.len(); i++)
	count[str[i]-97]++;

	for(int i=0; i<26; i++)
		count[i] = count[i]/2;

	cout << get_the_min_str() << endl;
}


string rev_str::get_the_min_str()
{
	int pos=0;
	vector<char> r_str;
	r_str.push_back(str[i]);
	for(int i=1; i<=str.size()/2; i++)
	{
		if(str[i] <= r_str[r_str.size()-1] && count[str[i]])
		{
			count[str[i]]--;
			r_str.push_back(str[i]);
		} else if(str[i] >  r_str[r_str.size()-1] && count[str[i]])
		{
			for(int k=0; k<r_str.size(); k++)
			{
				count[str[k]]++;
			}
			r_str.clear();
			r_str.push_back(str[i]);
			count[str[i]]--;
		}
	}

	for(int i=0; i<r_str.size(); i++)
	{
		count[r_str[i]-97]--;
	}

	for(int i=1+str.size()/2; i<str.size();i++)
	{
		if(str[i] == r_str[r_str.size()-1])
		{
			r_str.push_back(str[i]);
		} else if(str[i] >  r_str[r_str.size()-1])
		{
			r_str.clear();
			r_str.push_back(str[i]);
		}
	}
	
	

}
