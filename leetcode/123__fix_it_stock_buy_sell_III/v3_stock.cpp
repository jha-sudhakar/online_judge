#include <limits.h>
#include <vector>
#include <iostream>

using namespace std;

class stock
{
	private:
		int N;

	public:
		int maxProfit_in_range(vector<int>& prices, int s,int e, int& min_index, int& max_index);
		int get_maxProfit(vector<int>& p);

};



int stock::maxProfit_in_range(vector<int>& prices, int s,int e, int& min_index, int& max_index)
{
	if(e-s+1< 2)
		return 0;
		
	int prev_profit = 0;
	int min = prices[s];
	int max = prices[s];
	min_index = max_index = s;
	int cur_min=s, cur_max= s;
	for(int i=s+1; i<=e; i++)
	{
		if(prices[i] > max)
		{
			max = prices[i]; cur_max = i;
		} else if (prices[i] < min)
		{
			if(prev_profit < max-min)
			{
				prev_profit = max-min;
				min_index = cur_min; max_index = cur_max;
			}	
				
			min = max = prices[i]; 
			cur_min = cur_max = i;
		}
	}
	if(prev_profit > max-min)
		return prev_profit;
	else
	{
		min_index = cur_min; max_index = cur_max;
		return max-min;
	}	
}




int stock::get_maxProfit(vector<int>& p)
{
	int min_index=0, min_index_b=0;;
	int max_index=0, max_index_b=0;;
	int max1 =  maxProfit_in_range(p, 0, p.size()-1, min_index, max_index);
	int val1=0, val2=0;
	if(min_index-1 > 0)
		val1 = maxProfit_in_range(p, 0, min_index-1, min_index_b, max_index_b);

	if(max_index+1 < p.size()-1)
		val2 = maxProfit_in_range(p, max_index+1, p.size()-1, min_index_b, max_index_b);

	if(val1 > val2)
		return max1+val1;
	else
		return max1+val2;
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
