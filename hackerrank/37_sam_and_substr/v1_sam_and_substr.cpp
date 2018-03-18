//Sam and sub-string
#include<string>
#include<iostream>
using namespace std;

#define MAX 200001
unsigned int arr[MAX][MAX];

class Substr
{
	private:
		unsigned int N;
		string str;
		
	public:
		void execute();
};

void Substr::execute()
{
	unsigned int P = 1000 * 1000 * 1000 + 7;
	unsigned long int sum = 0;
	cin >> str;
	N = str.size();
	
/*
	unsigned int* buf = NULL;
	unsigned int* prev = new unsigned int [N+1];
	unsigned int* cur = new unsigned int [N+1];
*/
	for(unsigned int i=0; i<N; i++)
	{
		arr[i][i] = (str[i] - '0');
		sum += arr[i][i];
	}
	sum  = sum % P;
	
	for(unsigned int i=0; i<N-1; i++)
	{
		arr[i][i+1] = (str[i] - '0') + (str[i+1] - '0');;
		sum += arr[i][i+1];
	}
	sum  = sum % P;
	
	for(unsigned int gap=2; gap<N; gap++)
	{
		for(unsigned int i=0; i<N-gap; i++)
		{
			unsigned int j=i+gap;
			arr[i][j] = (str[i] - '0') + (str[j] - '0') + arr[i+1][j-1];
			sum += arr[i][j];
			sum  = sum % P;
		}
	}
/*
	delete [] prev; delete [] cur;
*/
}


int main()
{
	Substr obj;
	obj.execute();
	return 0;
}