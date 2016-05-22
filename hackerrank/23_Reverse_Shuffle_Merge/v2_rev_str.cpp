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
		count_ref[i] = count_ref[i]/2;
	}	

	cout << get_the_min_str() << endl;
}


string rev_str::get_the_min_str()
{
	vector<char> r_str;
	vector<unsigned int> p_vec[26];
	
	for(unsigned int i=0; i<N; i++)
	{
		p_vec[str[i]].push_back(i);
	}

	list<struct pos> buf;
	list<struct pos>::iterator itr;
	for(int i=0; i<26; i++)
	{
		if(p_vec[i].size() == 0)
			continue;

		for(int j=p_vec[i].size()-1; j>-1; j--)
		{
			if(count[i] > 0)
			{
				/*for(int l=0; l<26; l++)
				{
						if(count[l])
							cout << "non-zero char= " << char(l+97) <<" -- count= " <<count[l] << endl;
				}*/

				cout <<"Non zero  -" << char(i+97) << endl;
				count[i] = count[i]-1;
				struct pos pos_obj(i, p_vec[i][j]);

				if(buf.size() == 0)
				{
					buf.push_back(pos_obj);
				}
				else
				{
					for(itr=buf.begin(); itr!=buf.end(); ++itr)
					{
						if(p_vec[i][j] <  (*itr).index)
						break;
					}
					buf.insert(itr, pos_obj);
				}
				cout <<"Adding -" << char(i+97) << endl;
			}
			else
				break;
		}
	}

	vector<char> v_ret;
	for(itr=buf.begin(); itr!=buf.end(); itr++)
	{
		v_ret.push_back(((*itr).ch)+97);
	}
	return string(v_ret.begin(), v_ret.end());
}




int main()
{
rev_str obj;
obj.process_input();
return 0;
}
