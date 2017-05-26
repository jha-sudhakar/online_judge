#include<assert.h>

#include<vector>
#include<iostream>
#include<string>
using namespace std;

#define H_NO 3
#define P_MAX 2000
unsigned int hash_val[50000][H_NO];

class Dstr
{
	private:
		unsigned int N, T;
		string str;
		vector<unsigned int> P;
		void read_input();
		unsigned int get_unq_count();
		bool is_same(unsigned int s1, unsigned int s2);
	public:
		void execute();


};

void Dstr::execute()
{
	read_input();
}

void Dstr::read_input()
{
	cin >> T;
	for(unsigned int i=0; i<T; i++)
	{
		cin >> str;
		N = str.size();
		cout << get_unq_count() << endl;
	}
}

bool Dstr::is_same(unsigned int s1, unsigned int s2)
{
	//cout <<__FUNCTION__ <<" called with index " << s1 <<", " << s2 << endl;
	for(unsigned int i=0; i<N; i++)
	{
		if(str[(s1+i)%N] != str[(s2+i)%N])
		return false;
	}
	return true;
}

unsigned int Dstr::get_unq_count()
{
	//cout <<"\nInput str= " << str << endl;
	vector<bool> unq_count;
	for(unsigned int i=0; i<N; i++)
	{
		unq_count.push_back(2);
	}
	P.clear();
	P.push_back(1511);
	P.push_back(1877);
	P.push_back(1999);
	unsigned int RM[3]={1,1,1};
	for(unsigned int i=0; i<N-1; i++)
	{
		for(unsigned int j=0; j<H_NO; j++)
		{
			RM[j] = RM[j]*256;
			RM[j]= RM[j]%P[j];
		}
	}
	
	vector<unsigned int> h_to_s[P_MAX];
	unsigned int cur_val[H_NO] = {0,0,0};
	for(unsigned int i=0; i<N; i++)
	{
		for(unsigned int k=0; k<H_NO; k++)
		{
			cur_val[k] = cur_val[k]*256 + str[i];
			cur_val[k] = cur_val[k] % P[k];
		}
	}	
	unsigned int min_hash = min(cur_val[0], cur_val[1]);
	min_hash = min(min_hash, cur_val[2]);
	h_to_s[min_hash].push_back(0);
	for(unsigned int k=0; k<H_NO; k++)
	{
		hash_val[0][k] = cur_val[k];
	}

	//cout <<"str pos= " << 0 <<" h1= " << cur_val[0] <<" h1= "<<cur_val[1]<<" h2= "<<cur_val[2] << endl;
	for(unsigned int i=0; i<N-1; i++)
	{
		for(unsigned int k=0; k<H_NO; k++)
		{
			cur_val[k] = (cur_val[k]+P[k]-(RM[k]*str[i])%P[k]) % P[k];
			cur_val[k] = cur_val[k] *256 + str[(i+N)%N];
			cur_val[k] = cur_val[k] % P[k];
		}
		unsigned int min_hash = min(cur_val[0], cur_val[1]);
		min_hash = min(min_hash, cur_val[2]);
		//cout <<"str pos= " << i <<" h1= " << cur_val[0] <<" h1= "<<cur_val[1]<<" h2= "<<cur_val[2] << endl;
		
		h_to_s[min_hash].push_back(i+1);
		for(unsigned int k=0; k<H_NO; k++)
		{
			hash_val[i+1][k] = cur_val[k];
			//h_to_s[cur_val[k]].push_back(i);
		}
	}

	for(unsigned int i=0; i<P_MAX; i++)
	{
		for(unsigned int j=0; j<h_to_s[i].size(); j++)
		{
			if(unq_count[h_to_s[i][j]] == 0) continue;
			for(unsigned int k=j+1; k<h_to_s[i].size(); k++)
			{
				if(unq_count[h_to_s[i][k]] == 0) continue;
				unsigned int str1_pos = h_to_s[i][j];
				unsigned int str2_pos = h_to_s[i][k];
				unsigned int p=H_NO;
				for(p=0;p<H_NO; p++)
				{
					if(hash_val[str1_pos][p] != hash_val[str2_pos][p])
					{
						break;			
					}
				}
				if(p != H_NO)
					continue;
				else if(true == is_same(str1_pos, str2_pos))
				{
					if(2 == unq_count[min(str1_pos, str2_pos)])
						unq_count[min(str1_pos, str2_pos)] = 1;
					//if(str1_pos != str2_pos)
						unq_count[max(str1_pos, str2_pos)] = 0;	

					//if(str1_pos == str2_pos) assert(false);
				}
			}
		}

	}

	unsigned int unq_str_count = 0;
	for(unsigned int i=0; i<N; i++)
	{
		if(unq_count[i])
			unq_str_count++;
	}
	return unq_str_count;
}

int main()
{
	Dstr obj;
	obj.execute();
	return 0;
}

