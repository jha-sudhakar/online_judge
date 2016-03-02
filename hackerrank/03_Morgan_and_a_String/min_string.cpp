#include <assert.h>

#include <string>
#include <iostream>
using namespace std;

class Min_str
{
	private:
		unsigned int T;
		string str1;
		string str2;
		unsigned int differ1, differ2, winner;
		//vector<unsigned int> bptr1; vector<unsigned int> bptr2;
	public:
		void read_input();
		void print_min_string();
		//void build_loop_up();
		unsigned int find_min(unsigned int index1, unsigned int index2);
};

void Min_str::read_input()
{
	cin >> T;
	for(unsigned int i=0; i<T; i++)
	{
		cin >> str1 >> str2;
		//cout<<"T = " << i+1 << " str1= " << str1 << ", str2= " << str2 << endl;
		print_min_string();
	}
}

#if 0
void Min_str::build_loop_up()
{
	unsigned int len_max = (str1.size() > str2.size())? str1.size() : str2.size();
	unsigned int len_min = (str1.size() > str2.size())? str2.size() : str1.size();
	unsigned int len1 = str1.size();
	unsigned int len2 = str2.size();
	if(str1[len_min-1] == str2[len_min-1]
	{
		for( )
		{
			

		}
	}
	vector<unsigned int> val; val.resize(len_min);
	for(unsigned int 
	

}
#endif

unsigned int Min_str::find_min(unsigned int index1, unsigned int index2)
{
	const unsigned int _arg1 = index1;
	const unsigned int _arg2 = index2;
	unsigned int result = 0;
	bool reached_end = false;
	while(index1<str1.size() && index2<str2.size())
	{
		if(str1[index1] < str2[index2])
		{
			result= 1; break;
		} else if (str1[index1] > str2[index2])
		{
			result= 2; break;
		} else
		{
			index1++; index2++;
			if((index1 == str1.size()) && (index2 != str2.size()) && (reached_end == false))
			{
				index1 = _arg1; reached_end = true;
			} else if((index1 != str1.size()) && (index2 == str2.size()) && (reached_end == false))
			{
				index2 = _arg2; reached_end = true;
			}
		}
	}

	differ1 = index1-1;
	differ2 = index2-1;
	if(index1 >= str2.size())
	{
		differ1 = differ2 = str2.size()-1;
	} else if(index2 >= str1.size())
	{
		differ1 = differ2 = str1.size()-1;
	}
	if(result == 0) { result = 1; }

	winner = result;
	return result;
}

void Min_str::print_min_string()
{
	differ1 = 0; differ2 = 0;
	unsigned int i=0; const unsigned int l1 = str1.size();
	unsigned int j=0; const unsigned int l2 = str2.size();

	//string s; s.resize(l1+l2);
	char s[l1+l2+4];
	unsigned int index = 0;

	while(i<l1  && j<l2)
	{
		if(str1[i] < str2[j])
		{
			s[index] = str1[i]; i++;
		} else if(str1[i] > str2[j])
		{
			s[index] = str2[j]; j++;
		} else
		{
			unsigned int result = 0;
#if 1
			if(differ1>i && differ2>j)
			{ 
				result = winner;
			} else
			{
				result = find_min(i+1,j+1);
			}
#endif
			//result = find_min(i+1,j+1);

			if(1 == result)
			{
				s[index] = str1[i]; i++;
			} else
			{
				s[index] = str2[j]; j++;
			}
		}
		index++;
	}

	while(i<l1)
	{ 
		s[index] = str1[i]; 
		i++; index++;
	}
	while(j<l2)
	{
		s[index] = str2[j];
		j++; index++;
	}
	if(index != (l1+l2))
		assert(false);
	s[index] = '\0';
	cout << s << endl;
}

int main()
{
Min_str obj;
obj.read_input();
return 0;
}
