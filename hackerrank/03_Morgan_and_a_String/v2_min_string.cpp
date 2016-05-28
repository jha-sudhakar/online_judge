#include <assert.h>

#include<vector>
#include <string>
#include <iostream>
using namespace std;


enum CMP
{
UNDEF,
LEFT,
RIGHT
};

struct pos
{
	unsigned int l,r,index;
	CMP cmp_e;
	pos(unsigned int _l, unsigned int _r, CMP  _cmp_e) { l=_l; r=_r; cmp_e=_cmp_e; index=0;}
};

class Min_str
{
	private:
		unsigned int T;
		string str1;
		string str2;
		string str;
		vector<pos> diff_v;
		bool is_same_val;
		void read_intermediate_values(unsigned int& l, unsigned int& l1, unsigned int& l2,
			const unsigned int tmp_l1, const unsigned int tmp_l2);
	public:
		void process_input();
		void print_min_string();
};

void Min_str::process_input()
{
	cin >> T;
	unsigned int i=0;
	for(i=0; i<T; i++)
	{	
		str.clear();
		cin >> str1 >> str2;
		str1.push_back('z'+1);
		str2.push_back('z'+1);
		str.resize(str1.size() + str2.size());
		//cout<<"T = " << i+1 << " str1= " << str1 << ", str2= " << str2 << endl;
		print_min_string();
		str.pop_back();
		str.pop_back();
		cout << str << endl;
	}
}


void Min_str::print_min_string()
{
	unsigned int l=0,l1=0, l2=0;
	while((l1 < str1.size()) && (l2 < str2.size()))
	{
		if(str1[l1] < str2[l2])
		{
			str[l] = str1[l1];
			l++; l1++;
			continue;
		} else if(str1[l1] > str2[l2])
		{
			str[l] = str2[l2];
			l++; l2++;
			continue;
		} 

		diff_v.clear();
		unsigned int LOOKUP_SIZE = 50;
		diff_v.push_back(pos(l1, l2, UNDEF));	
		// Both values are same.

		is_same_val = true;
		unsigned int tmp_l1 = l1, tmp_l2 = l2;
		while((tmp_l1 <str1.size() && tmp_l2<str2.size()) && 
				(str1[tmp_l1] == str2[tmp_l2]) && (str1[l1] >= str1[tmp_l1] && str2[l2] >= str2[tmp_l2]))
		{
			
			if(str1[tmp_l1] != str1[l1])
			{
				is_same_val = false;
				for(int mm=0; mm<diff_v.size(); mm++)
				{
					if(diff_v[mm].cmp_e != UNDEF)
						continue; // Already found the sorted order.

					(diff_v[mm].index)++;
					if(str1[diff_v[mm].l + diff_v[mm].index] < str2[diff_v[mm].r + diff_v[mm].index])
					{
						diff_v[mm].cmp_e = LEFT;
					} 
					else if(str1[diff_v[mm].l + diff_v[mm].index] >  str2[diff_v[mm].r + diff_v[mm].index])
					{
						diff_v[mm].cmp_e = RIGHT;
					}
				}
			}
			
			if(str1[tmp_l1] == str1[l1] && diff_v.size() < LOOKUP_SIZE)
			{
				const int cur_size = diff_v.size();
				for(int mm=0; mm<cur_size; mm++)
				{
					diff_v.push_back(pos(tmp_l1,    diff_v[mm].r, UNDEF));	
					diff_v.push_back(pos(diff_v[mm].l, tmp_l2,    UNDEF));
				}
			}
			
			tmp_l1++;
			tmp_l2++;
		}

		read_intermediate_values(l, l1, l2, tmp_l1, tmp_l2);
		diff_v.clear();
	}
	while(l1<str1.size())
		str[l++] = str1[l1++];
	while(l2<str2.size())
		str[l++] = str2[l2++];
}


void Min_str::read_intermediate_values(unsigned int& l, unsigned int& l1, unsigned int& l2,
	const unsigned int tmp_l1, const unsigned int tmp_l2)
{

	// case 1:- If one of the str reached end.
	if(tmp_l1 == str1.size() || tmp_l2 == str2.size())
	{
		char ch = str1[l1];
		while(l1<tmp_l1 && l2<tmp_l2)
		{
			if(str1[l1] <= str2[l2])
			{
				str[l] = str1[l1];
				l++; l1++;
				if(str1[l1] == ch)
					return;
			} else
			{
				str[l] = str2[l2];
				l++; l2++;	
				if(str2[l2] == ch)
					return;
			}
		}
		while(l1<str1.size())
			str[l++] = str1[l1++];
		while(l2<str2.size())
			str[l++] = str2[l2++];
		return;	
	}
	else if(str1[tmp_l1] == str2[tmp_l2] && (str1[tmp_l1] > str[l1] && str2[tmp_l2] > str2[l2]))
	{
		if(is_same_val == true)
		{
			while(l1<tmp_l1) 
				str[l++] = str1[l1++];
			while(l2<tmp_l2) 
				str[l++] = str2[l2++];
			return;
		}
		//cout <<"Size of diff_v = " << diff_v.size() << endl;
		char ch = str1[l1];
		CMP dir = LEFT;
		bool is_start = true;
		unsigned int v_index=0;
		/*
		for(int i=0; i<diff_v.size(); i++)
		{
			if(diff_v[i].l == l1 && diff_v[i].r == l2)
			{	dir = diff_v[i].cmp_e; break; }
		}
		
		//if(dir == UNDEF) return;
		*/

		while(l1<tmp_l1 && l2<tmp_l2)
		{
			if(str1[l1] < str2[l2])
			{
				str[l] = str1[l1];
				l++; l1++;
			} else if(str1[l1] > str2[l2])
			{
				str[l] = str2[l2];
				l++; l2++;
			} else if(str1[l1] == str2[l2] && str1[l1] != ch)
			{
				if(dir == UNDEF)
					return;
				if(dir == LEFT)
				{
					str[l] = str1[l1]; 
					l++; l1++;
				}
				else
				{
					str[l] = str2[l2]; 
					l++; l2++;
				}

			} else if(str1[l1] == str2[l2] && str1[l1] == ch)
			{
				if(is_start == false)
				{
					dir = UNDEF;
					for( v_index=0; v_index <diff_v.size(); v_index++)
					{
						if(diff_v[v_index].l == l1 && diff_v[v_index].r == l2)
						{
							//cout <<"l= " << l1 <<", r= " << l2 <<", dir= " << diff_v[i].cmp_e << endl;
							dir = diff_v[v_index].cmp_e; 
							break;
						}
					}
				}

				is_start = false;
				if(dir == UNDEF)
					return;
				if(dir == LEFT)
				{
					str[l] = str1[l1]; 
					l++; l1++;
				}
				else
				{
					str[l] = str2[l2]; 
					l++; l2++;
				}
			}
			else
			{
				assert(false);

			}

		}
		while(l1<tmp_l1)
			str[l++] = str1[l1++];
		while(l2<tmp_l2)
			str[l++] = str2[l2++];
	}
	else if(str1[tmp_l1] < str2[tmp_l2])
	{
		char ch = str1[l1];
		while(l1<=tmp_l1)
		{
			str[l++] = str1[l1++];
			if(ch == str1[l1])
				break;
		}	
	}
	else if(str1[tmp_l1] > str2[tmp_l2])
	{
		char ch = str2[l2];
		while(l2<=tmp_l2)
		{
			str[l++] = str2[l2++];
			if(ch == str2[l2])
				break;
		}	
	}
	else
	{
		assert(false);
	}
}


int main()
{
	Min_str obj;
	obj.process_input();
	return 0;
}
