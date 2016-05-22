
#include<algorithm>
#include<vector>
#include<list>
#include<iostream>
#include<string>
using namespace std;

struct pos
{
	char ch;
	unsigned int index;

	pos(char _ch, unsigned int _index) { ch=_ch; index=_index; }
};
bool compare_pos(const pos& a, const pos& b)
{
	if(a.index >  b.index)
		true;
	else
		false;

	return true;
}


class rev_str
{
	private:
		unsigned int N;
		string str;
		int count[26];
		int count_ref[26];
	public:
		void process_input();
		string get_the_min_str();
};

void rev_str::process_input()
{
	cin >> str;
	N = str.size();

	for(int i=0; i<N; i++)
		str[i] = str[i]-97;

	for(int i=0; i<26; i++)
		count_ref[i] = count[i] = 0;

	for(int i=0; i<N; i++) 
	{
		count[str[i]]++; 
		count_ref[str[i]]++;
	}	

	for(int i=0; i<26; i++)
	{
		count[i] = count[i]/2;
		//count_ref[i] = count_ref[i]/2;
	}	

	cout << get_the_min_str() << endl;
}


string rev_str::get_the_min_str()
{
	vector<struct pos> sorted_char;
	vector<struct pos> stk;
	unsigned int char_count = 0;
	bool used[N];
	for(unsigned int i=0; i<N; i++)
		used[i] = false;
	while(char_count != N/2)
	{
	

		for(int i=0; i<N; i++)
		{
			if(count[str[i]] == 0 || used[i] == true)
				continue;
			stk.push_back(pos(str[i], i));
			count_ref[str[i]]--;
			if(count_ref[str[i]] == 0)
				break;
		}
		char max = stk[0].ch;
		unsigned int max_index = 0;
		for(unsigned int k=1; k<stk.size(); k++)
		{
			if(max < stk[k].ch)
			{
				max = stk[k].ch; 
				max_index = k;
			}
		}
		for(unsigned int k=0; k<stk.size(); k++)
		{
			if(k != max_index) 
				count_ref[stk[k].ch]++;
		}
		sorted_char.push_back(pos(max, max_index));
		count[max]--; 
		used[max_index] = true;

		stk.clear();
		char_count++;
	}

	sort(sorted_char.begin(), sorted_char.end(), compare_pos);
	
	string ret_str;
	ret_str.resize(sorted_char.size());
	for(int m=0; m<sorted_char.size(); m++)
		ret_str[m] = sorted_char[m].ch + 97;
	return ret_str;	
}




int main()
{
rev_str obj;
obj.process_input();
return 0;
}
