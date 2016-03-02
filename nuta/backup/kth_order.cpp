#include<assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
using namespace std;

class Kth_order
{
	private:
		string _in;
		unsigned int Q;
		uint64_t K;
		long int table[256];
		uint64_t total_sum;
		unsigned char k_th_val(const uint64_t k);
		void build_sorted_index();
	public:
		void read_input();
		

};

void Kth_order::read_input()
{
	cin >> _in;
	cin >> Q;
	build_sorted_index();
	//cout<<"str= " << _in <<", Q= " <<Q <<endl;
	
	for(int i=0; i<Q; i++)
	{
		cin >> K;
		if(K > total_sum)
		{
			cout<< -1 << endl;
		} else
		{
			unsigned char ch = k_th_val(K);
			printf("%c\n", ch); //cout<< ch << endl;
		}
	}


}

void Kth_order::build_sorted_index()
{
	for(int i=0; i<256; i++)
	{
		table[i] = 0;
	}

	total_sum = 0;
	for(int i=0; i<_in.size(); )
	{
		unsigned char ch = _in[i];
		i++;
		string buf;
		while(_in[i]>='0' && _in[i]<= '9')
		{
			buf.push_back(_in[i]);
			i++;
		}
		long int num = atol(buf.c_str());
		//printf("%c --> %ld\n", ch, num);
		table[ch] +=num;
		total_sum += num;
	}
}

unsigned char Kth_order::k_th_val(const uint64_t k)
{
	uint64_t index = 0;
	for(int i=0; i<256; i++)
	{
		index += table[i];
		if(index >= k)
		{
			return i;
		}
	}
	assert(false); //Impossible case.
	return 'a';
}

int main()
{
Kth_order obj;
obj.read_input();

return 0;
}
