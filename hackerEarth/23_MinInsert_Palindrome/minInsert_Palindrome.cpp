#include<math.h>

#include<string>
#include<iostream>
using namespace std;

class Mps
{
	private:
		string str;
		unsigned int N;
		
	public:
		void read_input();
		int execute();
};

void Mps::read_input()
{
	unsigned int T;
	cin >> T;
	for(unsigned int t=0; t<T; t++)
	{
		//cin >> N;
		cin >> str;
		N = str.size();
		cout << execute() << endl;
	}
}

int Mps::execute()
{
	if(N<2)
		return 0;
	unsigned int arr[41][41];
	for(unsigned int i=0; i<N; i++)
		arr[i][i] = 0;
	
	for(unsigned int i=0; i<N-1; i++)
	{
		arr[i][i+1] = 0;
		if(str[i] != str[i+1])
			arr[i][i+1] = 1;
	}
	
	for(unsigned int gap=2; gap<=N-1; gap++)
	{
		for(unsigned int i=0; i<=N-1-gap; i++)
		{
			unsigned int j = i+gap;
			if(str[i] == str[j])
				arr[i][j] = arr[i+1][j-1];
			else
			{
				arr[i][j] = 1 + min(arr[i+1][j], arr[i][j-1]);
			}
		}
	}
	return arr[0][N-1];
}


int main()
{
	Mps obj;
	obj.read_input();
	return 0;
}

