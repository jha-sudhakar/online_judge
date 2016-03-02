#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

typedef unsigned int myint;

class SPA
{
private:
	myint T;
	string str;
	myint w[27];

public:
	void process_input();
	void calculate_spa_val();

};

void SPA::process_input()
{
	cin >> T;
	for(myint i=0; i<T; i++)
	{
		cin >> str;
		for(int j=0; j<26; j++)
		{
			cin >> w[j];
		}

		calculate_spa_val();
	}
}

void SPA::calculate_spa_val()
{
myint arr[256];
for(int i=0; i<256; i++)
{
	arr[i] = 0;
}

for(myint i=0; i<str.size(); i++)
{
	arr[str[i]]++;
}

myint TL = str.size();
myint TW=0;
for(int i=0; i<26; i++)
{
    if(arr[i+'a'])
        TW += w[i];
}
long double TL_TW = TL*TW;

long double result=0.0;
for(int i=0; i<26; i++)
{
	long double tmp = arr[i+'a'] * w[i];
	tmp = tmp/TL_TW;
	tmp = tmp* 10.0;
	result += tmp ;
}

cout<< fixed << setprecision(2)  << result << endl;

}

int main()
{
	SPA obj;
	obj.process_input();

	return 0;
}
