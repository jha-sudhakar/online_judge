#include <limits.h>
#include <vector>
#include <iostream>

using namespace std;

class stock
{
	private:
		int N;

	public:
		int maxProfit_in_range(vector<int>& prices, int s,int e);
		int get_maxProfit(vector<int>& p);

};



int stock::maxProfit_in_range(vector<int>& prices, int s,int e)
{
	if(e-s+1< 2)
		return 0;
		
	int prev_profit = 0;
	int min = prices[s];
	int max = prices[s];
	for(int i=s+1; i<=e; i++)
	{
		if(prices[i] > max)
		{
			max = prices[i];
		} else if (prices[i] < min)
		{
			if(prev_profit < max-min)
				prev_profit = max-min;
			min = max = prices[i];

		}
	}
	if(prev_profit > max-min)
		return prev_profit;
	else
		return max-min;
}




int stock::get_maxProfit(vector<int>& p)
{
	N = p.size();
	int table[N][N];
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			table[i][j] = 0;
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(i>=j)
				continue;
			int max_val = 	
			table[i][j] = maxProfit_in_range(p,i,j);
		}
	}

	int max = INT_MIN;
	for(int j=0; j<p.size(); j++)
	{
		int val = table[0][j]+table[j+1][N-1];
		if(val > max)
			max = val;
	}
	return max;
}


class Solution
{
public:
    int maxProfit(vector<int>& prices)
	{
    	stock obj1;
		return obj1.get_maxProfit(prices);
	}
};
