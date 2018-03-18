//Sam and sub-string
#include<assert.h>
#include<string>
#include<iostream>
using namespace std;

#define MAX 200001
unsigned long long int ten_arr[MAX];
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

	unsigned long long int P = 1000 * 1000 * 1000 + 7;
	unsigned long long int sum = 0;
	cin >> str;
	N = str.size();

	unsigned int val = 1;
	ten_arr[0] = 1;
	unsigned long long int mul = 1;
	for(unsigned int i=1;i<=N; i++)
	{
		mul *= 10;
		mul = mul% P;

		ten_arr[i] = mul + ten_arr[i-1];
		ten_arr[i] = ten_arr[i] % P;
	}


	for(unsigned int k=1; k<=N; k++)
	{
		sum += (k * (str[k-1]-'0') * ten_arr[N-k]);
		sum  = sum % P;
	}

	cout << sum << endl;
}


int main()
{
	Substr obj;
	obj.execute();
	return 0;
}