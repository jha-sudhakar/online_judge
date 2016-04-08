#include <limits.h>
#include <vector>
#include <iostream>

using namespace std;

class stock
{
	private:
		int N;
		int* left;
	public:
		int maxProfit_in_range(vector<int>& prices, int s,int e);
		int get_maxProfit(vector<int>& p);

};


int stock::maxProfit_table(vector<int>& prices)
{

	if(prices.size() < 2)
		return 0;
	int prev_profit = 0;
	int min = prices[0];
	int max = prices[0];
	for(int i=1; i<prices.size(); i++)
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
		left[i] = prev_profit > (max-min) ? prev_profit:(max-min);
	}
	if(prev_profit > max-min)
		return prev_profit;
	else
		return max-min;
}



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
			{
				prev_profit = max-min;
			}	
				
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
	for(int i=0; i<p.size(); i++)
	{
		
		int val2 = maxProfit_in_range(
	}

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
