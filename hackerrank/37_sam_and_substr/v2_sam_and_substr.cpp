//Sam and sub-string
#include<assert.h>
#include<string>
#include<iostream>
using namespace std;

#define MAX 200001
//unsigned int arr[MAX][MAX];
unsigned long int ten_arr[MAX];
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

	unsigned long int P = 1000 * 1000 * 1000 + 7;
	unsigned long int sum = 0;
	cin >> str;
	N = str.size();

	unsigned int val = 1;
	ten_arr[0] = 1;
	for(unsigned int i=1;i<=N; i++)
	{
		ten_arr[i] = 10* ten_arr[i-1];
		ten_arr[i] = ten_arr[i] % P;
	}

	unsigned long int* buf   = NULL;
	unsigned long int* prev2 = new unsigned long int [N+1];
	unsigned long int* prev1 = new unsigned long int [N+1];
	unsigned long int* cur   = new unsigned long int [N+1];

	for(unsigned int i=0; i<N; i++)
	{
		prev2[i] = (str[i] - '0');
		sum += prev2[i];
	}
	sum  = sum % P;
	
	for(unsigned int i=0; i<N-1; i++)
	{
		prev1[i] = 10 * (str[i] - '0') + (str[i+1] - '0');
		sum += prev1[i];
	}
	sum  = sum % P;
	unsigned long int tmp = 0;
	for(unsigned int gap=2; gap<N; gap++)
	{
		for(unsigned int i=0; i<N-gap; i++)
		{
			unsigned int j=i+gap;
			if(j >= N)
				assert(false);

			unsigned int ten_len = gap-1;
			tmp = ten_arr[1+ten_len] * (str[i] - '0'); tmp = tmp % P;
			tmp += 10 * prev2[i+1]; tmp = tmp % P;
			tmp += (str[j] - '0');

			cur[i] = tmp;
			sum += cur[i];
			sum  = sum % P;
			cur[i] = cur[i] % P;
		}
		buf = cur;
		cur = prev2;
		prev2 = prev1;
		prev1 = buf;
	}

	delete [] prev2;
	delete [] prev1;
	delete [] cur;
	cout << sum << endl;
}


int main()
{
	Substr obj;
	obj.execute();
	return 0;
}