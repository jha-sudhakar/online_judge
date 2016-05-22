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
		int count[27];
		int count_ref[27];
	public:
		void process_input();
		string get_the_min_str();
};

void rev_str::process_input()
{
	cin >> str;
	N = str.size();

	for(int i=0; i<N; i++)
		str[i] = str[i]-96;

	for(int i=0; i<27; i++)
		count_ref[i] = count[i] = 0;

	for(int i=0; i<N; i++) 
	{
		count[str[i]]++; 
		count_ref[str[i]]++;
	}	

	for(int i=0; i<27; i++)
	{
		count[i] = count[i]/2;
		count_ref[i] = count_ref[i]/2;
	}	

	cout << get_the_min_str() << endl;
}


string rev_str::get_the_min_str()
{
	list<char> r_str;
	unsigned int val_count=0;
	int index=-1;
	while(val_count != N/2)
	{
		int i=index+1;
		unsigned char max_ch = 0;
		while (i <= N/2 + val_count)
		{
			if((count[str[i]] != 0) && (max_ch < str[i]))
			{
				max_ch = str[i];
				index=i;
			}
			i++;
		}

		if(index == N/2 + val_count)
		{
			while(index < N)
			{	
				r_str.push_front(str[index]+96); index++;
			}	
			break;
		}
		else
		{
			r_str.push_front(max_ch+96);
			count[max_ch]--;
			val_count++;
		}
	}

	string str_ret(r_str.begin(), r_str.end());
	return str_ret;
}

int main()
{
rev_str obj;
obj.process_input();
return 0;
}
