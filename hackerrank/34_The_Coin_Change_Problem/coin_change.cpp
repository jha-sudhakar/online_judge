
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Ch
{
	private:
		unsigned long int N, M;
		vector<unsigned long int> cval;
		unsigned long int arr[251];
		unsigned int graph[251][251];

		void build_coin_change_sol();

	public:
		void execute();

};

void Ch::execute()
{
	cin >> N >> M;
	cval.reserve(M+1);
	cval.push_back(0);
	unsigned int in_val = 0, index = 0;
	for(unsigned int i=1; i<=M; i++)
	{
		cin >> in_val;
		if(in_val <=N)
		{
			cval.push_back(in_val);
			index++;
		}
	}
	M = index;
	sort(cval.begin(), cval.end());
#if JHA
	cout <<"Sorted coin values ==> [M=" << M <<"] -->  ";
	for(int i=0; i<=M; i++)
		cout << cval[i] << " ";
	cout << endl;
#endif
	build_coin_change_sol();
}


void Ch::build_coin_change_sol()
{
	for(int i=0; i<=N; i++)
		arr[i] = 0;
	for(unsigned int i=0; i<=N; i++)
		for(unsigned int j=0; j<=N; j++)
			graph[i][j] = 0;

	for(unsigned int c=1; c<=M; c++)
	{
		graph[cval[c]][cval[c]] = 1;
		arr[cval[c]] = 1;
	}
	
	for(unsigned int i=1; i<N; i++)
	{
		for(int j=1; j<=M; j++)
		{
			if(graph[i][cval[j]] == 0)
				continue;
			
			for(int k=j; k<=M; k++)
			{
				if(i+cval[k] > N)
					break;
				//graph[i+cval[k]][cval[k]]++;
				graph[i+cval[k]][cval[k]] += graph[i][cval[j]];
				arr[i+cval[k]] += graph[i][cval[j]];
				if(0 && i+cval[k] == N)
				{
					cout <<" At " << N <<" where start=" << i << ", prev= " << cval[j] <<"  offset=" << cval[k] << endl;
				}
			}
		}
	}
	//cout <<endl;
	cout << arr[N] << endl;
}

int main()
{
	Ch obj;
	obj.execute();	
	return 0;
}
