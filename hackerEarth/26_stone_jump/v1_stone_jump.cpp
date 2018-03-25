#include<iostream>
#include<iomanip>
using namespace std;

class Jump
{
	private:
		unsigned int N, L, D;
		float pb[1004];
		unsigned int* stone_pos;
		long double* pval;
		

	public:
		void execute();
};

void Jump::execute()
{
	cin >> N >> L >> D;
	pb[0] = pb[N+1] = 1.0;
	for(unsigned int i=1; i<=N; i++) cin >> pb[i];

	stone_pos = new unsigned int[N+2];
	stone_pos[0] = 0; stone_pos[N+1] = D;
	for(unsigned int d=1; d<=N; d++)
	{
		cin >> stone_pos[d];	
		if(stone_pos[d] - stone_pos[d-1] > L)
		{
			cout <<"IMPOSSIBLE" << endl;
			return;
		}			
	}
	if(stone_pos[N+1] - stone_pos[N] > L)
	{
		cout <<"IMPOSSIBLE" << endl;
		return;
	}			


	pval = new long double[N+2];
	pval[0]= 1.0;
	for(unsigned int d=1; d<=D; d++)
		pval[d] = 0.0;

	for(unsigned int i=0; i<=N; i++)
	{
		unsigned int dist = stone_pos[i]+L;
		unsigned int k=i+1;
		while(k<=N+1 && stone_pos[k] <=dist)
		{
			long double cur_p = pb[k];
			long double tmp = cur_p * pval[i];
			if(tmp > pval[k])
				pval[k] = tmp;
			k++;
		}
	}
	
	if(pval[N+1] == 0.0)
	{
		cout <<"IMPOSSIBLE" << endl;
		return;
	}
	cout << std::fixed;
    cout << std::setprecision(6);
	cout << pval[N+1] << endl;
}


int main()
{
	Jump obj;
	obj.execute();
	return 0;
}