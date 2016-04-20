#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

class LIS
{
	private:
		unsigned int N;
		vector<unsigned int> arr;
		unsigned int** table;

	public:
		void process_input();
		unsigned int get_max_len_lis();
};


void LIS::process_input()
{
	cin >> N;
	table = new unsigned int* [N];
	unsigned int buf;
	for(unsigned int i=0; i<N; i++)
	{
		table[i] = new unsigned int [N];
		cin >> buf;
		arr.push_back(buf);
	}
		
	for(unsigned int i=0; i<N; i++)
		for(unsigned int j=0; j<N; j++)
			table[i][j] = 0;

	cout << get_max_len_lis() << endl;
	for(unsigned int i=0; i<N; i++)
		delete [] table[i];
	delete [] table;	
}

unsigned int LIS::get_max_len_lis()
{
	unsigned int index[N];
	for(unsigned int i=0; i<N; i++)
		index[i] = 0;

	for(unsigned int i=0; i<N; i++)
	{
		for(unsigned int j=0; j<N; j++)
		{
			if(index[j] == 0)
			{
				table[j][index[j]] = arr[i];
				index[j]++;
				break;
			} else if(table[j][index[j]-1] < arr[i])
			{
				table[j][index[j]] = arr[i];
				index[j]++;
			}
		}
	}
	unsigned int max = index[0];
	for(unsigned int k=1; k<N; k++)
	{
		if(index[k] > max)
			max = index[k];
	}
	return max;
}

int main()
{
LIS obj;
obj.process_input();
return 0;
}
