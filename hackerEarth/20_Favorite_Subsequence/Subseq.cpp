#include<vector>
#include<iostream>
using namespace std;
#define P 1000000007

class Sseq
{
	private:
		string str;

	public:
		void execute();
		void read_input();
		void get_count();


};

void Sseq::execute()
{
	read_input();
	get_count();
}


void Sseq::read_input()
{
	cin >> str;
}

void Sseq::get_count()
{
	unsigned int total_count = 0;
	unsigned int s=0, e=str.size()-1;
	
	while(str[s] != 'a' && s<str.size())
		s++;
	while(str[e] != 'c' && e>0)
		e--;

	if(s == str.size() || e == 0)
	{
		cout << (total_count%P) << endl;
		return;
	}

	vector<unsigned int> count_arr;
	count_arr.resize(str.size());
	for(unsigned int i=0; i<count_arr.size(); i++)
	{
		count_arr[i] = 0;
	}

	count_arr[s] = 1;
	for(unsigned int i=s+1; i<=e; i++)
	{
		for(unsigned int j=s; j<i; j++)
		{
			if(str[i] == 'a' && str[j] == 'a')
			{
				count_arr[i] += count_arr[j];
			}
			else if(str[i] == 'b' && (str[j] == 'a' || str[j] == 'b'))
			{
				count_arr[i] += count_arr[j];
			}
			else if(str[i] == 'c' && (str[j] == 'b' || str[j] == 'c'))
			{
				count_arr[i] += count_arr[j];
			}
		}
		if(str[i] == 'a')
			count_arr[i]++; // It can be starting point ignoring prefix.
		else if(str[i] == 'c')
		{
			total_count += count_arr[i];
			cout <<"Index= " << i <<", count= " << count_arr[i] << endl;
		}
	}

	cout << (total_count%P) << endl;
}


int main()
{
	Sseq obj;
	obj.execute();
	return 0;
}
