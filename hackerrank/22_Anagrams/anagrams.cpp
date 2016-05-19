#include<string>
#include<iostream>
using namespace std;

class agm
{
	private:
		unsigned int T;
		string str;

	public:
		void process_input();
		unsigned int count_anagrams();
};

void agm::process_input()
{
	cin >> T;
	for(unsigned int i=0; i<T; i++)
	{
		cin >> str;
		cout << count_anagrams() << endl;
	}
}

unsigned int agm::count_anagrams()
{
	unsigned int match_count = 0;
	for(unsigned int start=0; start <str.size(); start++)
	{
		for(unsigned int offset=0; offset<str.size(); offset++)
		{
			if(start+offset>=str.size())
				continue;
			for(unsigned int next = start+1; next<str.size(); next++)
			{
				if(next+offset >= str.size())
					continue;

				unsigned char cur_str[256], next_str[256];
				for(unsigned int i=0; i<256; i++)
					cur_str[i] = next_str[i] = 0;
				for(unsigned int index=0; index<= offset; index++)
				{
					cur_str[str[start+index]]++;
					next_str[str[next+index]]++;
				}
				unsigned int kk=0;
				for(kk=0; kk<256; kk++)
				{
					if(cur_str[kk] != next_str[kk])
						break;
				}
				if(kk == 256)
					match_count++;
			}		
		}

	}

	return match_count;
}

int main()
{
agm obj;
obj.process_input();
return 0;
}
