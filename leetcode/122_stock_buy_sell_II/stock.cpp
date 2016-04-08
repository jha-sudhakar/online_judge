#include <limits.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
	{
		//vector<int> trade;
		int total_profit = 0;
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
			} else if (prices[i] < max)
			{
				//if(prev_profit < max-min) prev_profit = max-min;
				total_profit += (max-min);
				min = max = prices[i];

			}
		}

		return (total_profit += (max-min));
    }
};
