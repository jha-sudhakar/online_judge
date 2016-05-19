#include<assert.h>
#include<limits.h>

#include<iostream>
using namespace std;

class gene
{
	private:
		unsigned int N;
		string str;
		unsigned int count[4];
		unsigned int gap[4];
	public:
		void process_input();
		unsigned int get_substr_len();
};

void gene::process_input()
{
	cin >> N;
	cin >> str;
	
	count[0] = count[1] = count[2] = count[3] = 0;
	// Convert to string to have A, B, C, D so coding becomes simple.
	for(unsigned int i=0; i<N; i++)
	{
		// A, C, T, G
		/*
			A = 0
			G = 1
			C = 2
			T = 3


		*/
		if(str[i] == 'G')
		{
			str[i] = 1;
			count[1]++;
		}	
		else if(str[i] == 'T')
		{
			str[i] = 3;
			count[3]++;
		}
		else if(str[i] == 'A')
		{
			str[i] = 0;
			count[0]++;
		}
		else if(str[i] == 'C')
		{
			str[i] = 2;
			count[2]++;
		}
		else
		{
			assert(false);
		}	
	}

	cout << get_substr_len() << endl;	
}

unsigned int gene::get_substr_len()
{

	unsigned int diff_cur = 0, diff_total=0;
	long long int l_gap[4];
	unsigned int avg = N/4;
	for(int i=0; i<4; i++)
	{
		if(count[i] > avg)
		{
			l_gap[i] = gap[i] = count[i]-avg;
			diff_total += l_gap[i];
			//cout << i+1 << " gap= " << l_gap[i] << endl; 
		} else
		{
			l_gap[i] = gap[i] = 0;
		}
	}	

	//cout << "total-gap= " << diff_total << endl;

	unsigned int len=0, min_len=UINT_MAX;
	unsigned  int start = 0;
	diff_cur = diff_total;
	
	while(gap[str[start]] == 0)
	start++;

	for(unsigned int i=start; i<N; i++)
	{
		if(gap[str[i]]== 0)
		{
			len++;
			continue;
		} 
		else
		{
			len++;
			if(l_gap[str[i]] > 0)
			{
				if(diff_cur == 0)
					assert(false);
				diff_cur--;
			}
			l_gap[str[i]]--;

			while(diff_cur == 0 && l_gap[0]<1 && l_gap[1]<1 && l_gap[2]<1 && l_gap[3]<1) // Found all the matching entries.
			{
				if(len < min_len)
				{
					min_len = len;
					if(min_len == diff_total)
						return min_len;
				}		
				
				l_gap[str[start]]++;
				if(l_gap[str[start]] > 0)
					diff_cur++;

				start++;
				len--;
				while(start<i && gap[str[start]] == 0)
				{
					start++;
					len--;
				}
				if(start == i)
					break;
			}
			
			if(start+diff_total > N)
				break;
		}
	}
	if(min_len == UINT_MAX)
		min_len = 0;
	return min_len;
}


int main()
{
gene obj;
obj.process_input();
return 0;
}
