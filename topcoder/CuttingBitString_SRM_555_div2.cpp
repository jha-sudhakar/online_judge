/*
CuttingBitString ==>    Single Round Match 555 Round 1 - Division II, Level Two
CuttingBitString_SRM_555_div2.cpp

Class:	CuttingBitString
Method:	getmin
Parameters:	String
Returns:	int
Method signature:	int getmin(String S)
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class CuttingBitString
{
private:
	vector<unsigned long long> bits_5;
	bool is_set[51];
	int min_break[51];

public:
CuttingBitString();
void print_5_bit_index();
int getmin(string str);
};

CuttingBitString::CuttingBitString()
{
	for(int i=0; i<51; i++)
	{
		is_set[i] = false;
		min_break[i] = 100;
	}
	//min_break[1] = 1;
	//min_break[0] = 0;

	bits_5.resize(51);
	unsigned long long val_pow_2 = 2, bits_2 = 2, val_pow_5 = 5;
	bits_5[0] = 0;
	bits_5[1] = 1;


	is_set[1] = true;
	is_set[3] = true;
	while(bits_2 <51)
	{
		while(val_pow_2 < val_pow_5)
		{
			val_pow_2 *= 2;
			bits_2++;
		}
		if(bits_2>50)
			break;

		bits_5[bits_2-1] = val_pow_5;
		is_set[bits_2-1] = true;
		val_pow_5 *= 5;
		//cout <<"at bits" << bits_2 << ", 2-val = " << val_pow_2 <<", 5-val = " << val_pow_5 << endl;
	}
}
int CuttingBitString::getmin(string str)
{
	if (str.size() == 0 || (str.size() == 1 && str[0] == '0'))
		return -1;
	min_break[str.size()] = 0;
	for(int i=str.size()-1; i>=0; i--)
	{
		 unsigned long long val = 0, pow_2 = 1;
			for(int j=i; j>=0; j--)
			{
					if(str[j] == '1')
					{
						val = val + pow_2;
					}
					pow_2 *= 2;
					
					int len = 1 + i-j;
					if((false == is_set[len]) || (val  != bits_5[len]))
					{
					 	continue;
					}

					int min_break_len = std::min(min_break[i+1]+1, min_break[j]);
					min_break[j] = min_break_len;

			}
	}
	return min_break[0] >= 100 ? -1 : min_break[0];
}

void CuttingBitString::print_5_bit_index()
{
	cout << endl;
	for(unsigned int i=0; i<bits_5.size();i++)
	{
		cout <<"bits = " << i <<" ==> 5-val = " << bits_5[i] << endl;
	}
}

int main(int argc, char* argv[])
{
	CuttingBitString obj;
	//obj.print_5_bit_index();
	string str1 = string(argv[1]);
	int len = obj.getmin(str1);
	cout << "Result = " << len << endl;
	return 0;
}
