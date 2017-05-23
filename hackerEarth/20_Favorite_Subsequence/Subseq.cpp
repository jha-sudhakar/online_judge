#include<vector>
#include<iostream>
using namespace std;
const unsigned long long int P = 1000000007;

unsigned long long int count_arr[100004];

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
	unsigned long long int total_count = 0;
	unsigned long long int s=0, e=str.size()-1;
	
	while(str[s] != 'a' && s<str.size())
		s++;
	while(str[e] != 'c' && e>0)
		e--;

	if(s == str.size() || e == 0)
	{
		cout << (total_count%P) << endl;
		return;
	}
#if 0
	vector<unsigned long long int> count_arr;
	count_arr.resize(str.size());
	
	for(unsigned long long int i=0; i<count_arr.size(); i++)
	{
		count_arr[i] = 0;
	}
#endif

	count_arr[s] = 1;
	for(unsigned long long int i=s+1; i<=e; i++)
	{
		count_arr[i] = 0;
		for(unsigned long long int k=i; k>s; k--)
		{
			unsigned long long int j=k-1;			
			if(str[i] == 'a' && str[j] == 'a')
			{
				count_arr[i] += count_arr[j];
				count_arr[i] = count_arr[i]%P;
			}
			else if(str[i] == 'b' && (str[j] == 'a' || str[j] == 'b'))
			{
				count_arr[i] += count_arr[j];
				count_arr[i] = count_arr[i]%P;
			}
			else if(str[i] == 'c' && (str[j] == 'b' || str[j] == 'c'))
			{
				count_arr[i] += count_arr[j];
				count_arr[i] = count_arr[i]%P;
			}

			if(str[i] == str[j])
			{
				count_arr[i] += count_arr[j];
				count_arr[i] = count_arr[i]%P;
				break;
			}
		}
		if(str[i] == 'c')
		{
			total_count += count_arr[i];
			total_count = total_count%P;
			//cout <<"Index= " << i <<", count= " << count_arr[i] << endl;
		}
		//cout <<"Index= " << i <<",char= " << char(str[i]) <<",  count= " << count_arr[i] << endl;
	}

	cout << (total_count%P) << endl;
}


int main()
{
	Sseq obj;
	obj.execute();
	return 0;
}
