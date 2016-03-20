#include <stdint.h>
#include <iostream>
using namespace std;

class ch
{
	private:
		string str;
		uint64_t sum;

	public:
		void process_input();
		// bool find_sum(uint64_t& ret);
		uint64_t get_num(unsigned int start, unsigned int len);

};

uint64_t ch::get_num(unsigned int start, unsigned int len)
{
	uint64_t val = 0;
	for(int i=0; i<len; i++)
	{
		val = val*10+ (str[start+i]- '0');
	}
	return val;
}

void ch::process_input()
{
	int no_of_testcase;
	cin >> no_of_testcase;
	for(int i=0; i<no_of_testcase; i++)
	{
		uint64_t sum = 0;
		bool is_invalid = true;;
		cin >> str;
		//cout<<"\n Input= " << str << endl;
		if(str.size() < 4)
		{
			cout << "unlucky" << endl;
			continue;
		}
		unsigned int  max_sub_len = str.size()-3;
		if(max_sub_len > 12)
		{
			max_sub_len = 12;
		}
		int val[3]; int index = 0;
		for(int k=str.size()-3; k<str.size(); k++, index++)
		{
			val[index] = str[k] -'0';;
		}

		for(int j=0; j<4; j++)
		{
			if(j-1 >= 0)
			{
				val[j-1] = str[j-1] - '0';
			}

			if(str[j] == '0' && max_sub_len != 1)
			{
				continue; // Leading zero means invalid case;
			}
			is_invalid = false;
			uint64_t len_max = get_num(j, max_sub_len);
			uint64_t buf = val[0]+val[1]+val[2]+len_max;
			if(buf>sum)
				sum = buf;
		}

		if(is_invalid == false)
		{
			cout<< sum << endl;
		} else
		{
			cout<< "unlucky" << endl;
		}
	}	

}

int main()
{
ch obj;
obj.process_input();
return 0;
}
