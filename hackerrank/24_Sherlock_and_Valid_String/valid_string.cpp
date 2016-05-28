#include<assert.h>

#include<cmath>
#include<string>
#include<iostream>
#include<vector>
using namespace std;


class str
{
	private:
		string s;
		unsigned int N, count[26];

	public:
		void process_input();
		string is_valid();


};

void str::process_input()
{
	cin >> s;
	N = s.size();

	for(int i=0; i<26; i++)
		count[i] = 0;

	for(unsigned int i=0; i<N; i++)
	{
		count[s[i]- 'a']++;
	}

	cout << is_valid() << endl;
}
		
		
string str::is_valid()
{
	vector<unsigned int> unq_val;

	for(int i=0; i<26; i++)
	{
		if(count[i] == 0)
			continue;

		unsigned int j=0;
		for(j=0; j<unq_val.size(); j++)
		{
			if(unq_val[j] == count[i])
			break;
		}
		if(j == unq_val.size())
			unq_val.push_back(count[i]);
	}

	if(unq_val.size() > 2)
	{return string("NO"); }
	else if(unq_val.size() == 1)
	{	return string("YES");}
	else if(unq_val.size() == 2) 
	{
		unsigned int val=0;
		if(unq_val[0] > unq_val[1])
			val = (unq_val[0]-unq_val[1]) * (unq_val[0]-unq_val[1]);
		else
			val = (unq_val[1]-unq_val[0]) * (unq_val[1]-unq_val[0]);

		if((val != 1)  && !((unq_val[0] == 1 || unq_val[1] == 1)))
			return string("NO");
	}	
	
	unsigned int count0=0, count1=0;
	for(int i=0; i<26; i++)
	{
		if(count[i] == 0)
			continue;

		if(count[i] == unq_val[0])
			count0++;
		else if(count[i] == unq_val[1])
			count1++;
		else
			assert(false);
	}
	if((count0 == 1) || (count1 == 1))
		return string("YES");

	return string("NO");
}


int main()
{
	str obj1;
	obj1.process_input();
	return 0;
}
