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
		unsigned int differ1, differ2;
		vector<unsigned int> bptr1;
        vector<unsigned int> bptr2;
	public:
		void read_input();
		void print_min_string();
		void build_loop_up();
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


void Min_str::build_loop_up()
{
	unsigned int len_max = (str1.size() > str2.size())? str1.size() : str2.size();
/	unsigned int len_min = (str1.size() > str2.size())? str2.size() : str1.size();
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


unsigned int Min_str::find_min(unsigned int index1, unsigned int index2)
{
	const unsigned int start1 = index1;
	const unsigned int start2 = index2;
	bool is_end = false;
do
{
	while(index1<str1.size() && index2<str2.size())
	{
		if(str1[index1] < str2[index2])
		{
			if(!is_end)	{differ1 = index1; differ2 = index2;}
			return 1;
		} else if (str1[index1] > str2[index2])
		{
			if(!is_end) {differ1 = index1; differ2 = index2;}
			return 2;
		} else
		{
			index1++; index2++;
		}
	}
	if((index1 == str1.size()) && (index2 == str2.size()))
	{
		return 1;
	} else if(index1 == str1.size())
	{
		index1 = start1; differ1 = str1.size(); is_end = true;
	} else if (index2 == str2.size())
	{
		index2 = start2; differ2 = str2.size(); is_end = true;
	}

} while(1);

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
			if(differ1>i && differ2>j)
			{
				result = str1[differ1] < str2[differ2]? 1:2;
			} else
			{
				result = find_min(i+1,j+1);
			}

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
