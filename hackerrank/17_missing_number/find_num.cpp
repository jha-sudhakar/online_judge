
#include<iostream>
using namespace std;

#define MAX 1000014
unsigned int a[MAX], b[MAX];

class find_num
{
	private:
		unsigned int la, lb;
		unsigned int min_val;
		unsigned int is_seen_a[101], is_seen_b[101];
	public:
		void process_input();
		void print_missing_numbers();
};

void find_num::process_input()
{
	cin >> la;
	for(unsigned int i=0; i<la; i++)
		cin >> a[i];
		
	min_val = 10000+100;
	cin >> lb;
	for(unsigned int i=0; i<lb; i++)
	{
		cin >> b[i];
		if(b[i] < min_val)
			min_val = b[i];
	}	

	print_missing_numbers();
}

void find_num::print_missing_numbers()
{
	for(int i=0; i<101; i++)
		is_seen_a[i] = is_seen_b[i] = 0;

	for(unsigned int i=0; i<la; i++)
	{
		is_seen_a[a[i]-min_val]++;
	}

	for(unsigned int i=0; i<lb; i++)
	{
		is_seen_b[b[i]-min_val]++;
	}

	for(int i=0; i<101; i++)
	{
		if(is_seen_a[i] != is_seen_b[i])
			cout << min_val+i << " ";
	}
	cout << endl;
}


int main()
{
find_num obj;
obj.process_input();
return 0;
}
