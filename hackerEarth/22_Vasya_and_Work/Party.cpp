#include<assert.h>
#include<iostream>
#include<string>
using namespace std;


unsigned int count[100000][26][2];

class Party
{
	private:
		unsigned int N, Q, l, r;
		unsigned long long int P;
		string S1, S2;
		void read_input();
		void build_index();
		void handle_queries();
		unsigned int party_count(unsigned int L, unsigned int R);
		void print_count_index();

	public:
		void execute();

};


void Party::execute()
{
		read_input();
		build_index();
		handle_queries();
}

void Party::read_input()
{
	cin >>  N;
	cin >> S1;
	cin >> S2;

	for(unsigned int i=0; i<N; i++)
	{
		S1[i] = S1[i]-'a';
	}
	for(unsigned int i=0; i<N; i++)
	{
		S2[i] = S2[i]-'0';
	}
}

void Party::build_index()
{
		P = 1;
		for(unsigned int i=1;i<10; i++)
		{
			P *= 10;
		}
		P += 7;

		unsigned int i=0;
		count[0][S1[0]][S2[0]] = 1;
		for(i=1; i<N; i++)
		{
			for(unsigned int j=0; j<26; j++)
			{
				for(unsigned int k=0; k<2; k++)
				{
					count[i][j][k] = count[i-1][j][k];
				}
			}

			if(S1[i] >=26 || S2[i] >=2)
				assert(false);
			count[i][S1[i]][S2[i]]++;
		}
		//print_count_index();
}

void Party::print_count_index()
{
	for(unsigned int i=0; i<N; i++)
	{
		cout << i << " -> ";
		for(unsigned int j=0; j<26; j++)
		{
			for(unsigned int k=0; k<2; k++)
			{
				cout << count[i][j][k] <<" ";
			}
		}
		cout << endl;
	}
}

void Party::handle_queries()
{
	cin >> Q;
	for(unsigned int i=0; i<Q; i++)
	{
		cin >> l >> r;
		unsigned int count_l_r = party_count(l-1, r-1);
		cout << count_l_r << endl;
	}
}

unsigned int Party::party_count(unsigned int L, unsigned int R)
{
	count[R][S1[L]][S2[L]]++;
	unsigned long long int total_count = 0;
	unsigned long long int tmp_count_0 = 0, tmp_count_1=0;
	unsigned long long int cur_count_0 = 0, cur_count_1=0;
	
	// Calculate all the values having 0|1 in common.
	for(unsigned int i=0; i<26; i++)
	{
		cur_count_0 = count[R][i][0] - count[L][i][0];
		cur_count_1 = count[R][i][1] - count[L][i][1];
		total_count += cur_count_0 * cur_count_1;
		
		tmp_count_0 += count[R][i][0] - count[L][i][0];
		tmp_count_1 += count[R][i][1] - count[L][i][1];
	}
	total_count += (tmp_count_0 * (tmp_count_0-1))/2;	
	total_count += (tmp_count_1 * (tmp_count_1-1))/2;	

	count[R][S1[L]][S2[L]]--;
	return total_count%P;
}

int main()
{
	Party obj;
	obj.execute();
	return 0;
}
