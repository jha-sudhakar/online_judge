#include<assert.h>
#include<stdio.h>

#include<vector>
#include<iostream>
using namespace std;


class Arr
{
	private:
		vector<int> a;
		int T, N;
	public:
		void print_frequency();
		void read_input();
};

void Arr::read_input()
{
	cin >> T;
	for(int i=0; i<T; i++)
	{
		cin >> N;
		a.clear();
		a.resize(N+1);
		a.push_back(0);
		for(int i=1; i<=N; i++)
			cin >> a[i];
		
		print_frequency();
	}
}

void Arr::print_frequency()
{
	for(int i=1; i<=N; i++)
	{
		if(a[i] == i)
		{
			a[i] = -1;
		} else if (a[i] > 0) // Val at wrong position.
		{
			if(a[a[i]] < 0)   // Its currect position is already set as counter.
			{
				a[a[i]] --;
				a[i] = 0;
			} else if(a[a[i]] == 0)
			{
				a[a[i]] = -1;
				a[i]=0;

			} else if (a[a[i]] > 0)	
			{
				int buf = a[a[i]];
				a[a[i]] = -1;
				a[i] = buf;
				i--;
			}
		}
	}

	for(int i=1; i<=N; i++)
	{
		if(a[i] == 0)
		{
			cout << a[i] ;
		} else if (a[i] < 0)
		{
			cout << -1* a[i];
		}
		else
		{
			assert(false);
		}
		if(i != N)
			cout<<" ";
	}
	cout << endl;
}


int main()
{

Arr obj1;
obj1.read_input();
return 0;
}

