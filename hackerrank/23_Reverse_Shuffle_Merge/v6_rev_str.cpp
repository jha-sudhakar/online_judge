#include<assert.h>

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
		int count[27];
		int count_ref[27];
		int const_count_ref[27];
	public:
		void process_input();
		void get_the_min_str();
};

void rev_str::process_input()
{
	cin >> str;
	N = str.size();

#if DEBUG_LOG
	for(int i=0; i<N; i++)
	{
		cout << char(str[i]) <<" at " << i << endl;
	}
#endif

	for(unsigned int i=0; i<N; i++)
		str[i] = str[i]-96;

	for(int i=0; i<27; i++)
		const_count_ref[i] = count_ref[i] = count[i] = 0;

	for(int i=0; i<N; i++) 
	{
		count[str[i]]++; 
		count_ref[str[i]]++;
		const_count_ref[str[i]]++;
	}	

	for(int i=0; i<27; i++)
	{
		count[i] = count[i]/2;
		//count_ref[i] = count_ref[i]/2;
	}	

	get_the_min_str();
}


void rev_str::get_the_min_str()
{
	//vector<struct pos> sorted_char;
	string final_str;  
	final_str.resize(N/2);

	unsigned int char_count = 0;
	bool used[N];
	for(unsigned int i=0; i<N; i++)
		used[i] = false;
	
	while(char_count != N/2)
	{
		char max = 0;
		int prev_max_index=-1, max_index = 0;
		
		for(int i=0; i<N; i++)
		{
			if(count[str[i]] == 0 || used[i] == true)
				continue;

			count_ref[str[i]]--;
			if(count_ref[str[i]] == 0 && i < prev_max_index)
				assert(false);
			
			if(i < prev_max_index) continue;

			if(count_ref[str[i]] <  count[str[i]])
			{
#if DEBUG_LOG
				cout <<" Count at " << i <<" for "<< char(str[i]+96) << "    ";
				cout<<" count= " << count_ref[str[i]] <<" count/2= " << count[str[i]] << endl;
				cout <<" Max at " << max_index <<" is  "<< char(str[max_index]+96) << endl;
#endif
				break;
			}

			if(max < str[i])
			{
				max = str[i]; 
				max_index = i;
			}
			if(count_ref[str[i]] == 0)
			{
#if DEBUG_LOG
				cout <<"****  Count 0 at " << i <<" for "<< char(str[i]+96) << "    ";
				cout <<" Max at " << max_index <<" is  "<< char(str[max_index]+96) << endl;
#endif				
				break;
			}	
		}
		
		for(unsigned int k=0; k<27; k++)
		{
			count_ref[k] = const_count_ref[k];
		}
		const_count_ref[max]--;
		count_ref[max]--;
		count[max]--;
		used[max_index] = true;
		prev_max_index = max_index;

		final_str[N/2-1-char_count] = max+96;
		//sorted_char.push_back(pos(max, max_index));

		char_count++;
	}

#if 0
	sort(sorted_char.begin(), sorted_char.end(), compare_pos);
	string ret_str;
	ret_str.resize(sorted_char.size());
	for(int m=0; m<sorted_char.size(); m++)
		ret_str[m] = sorted_char[m].ch + 96;
	return ret_str;	
#endif

	//cout << "len= " << final_str.size() <<", string= " << final_str << endl;
	cout << final_str << endl;
}




int main()
{
rev_str obj;
obj.process_input();
return 0;
}
