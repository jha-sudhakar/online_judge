#include <queue>
#include <limits.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
	{

		priority_queue<int> pq;
		int ret_val = 0;
		if(prices.size() < 2)
			return 0;
		int min = prices[0];
		int max = prices[0];
    	for(int i=1; i<prices.size(); i++)
		{
			if(prices[i] > max)
			{
				max = prices[i];
			} else if (prices[i] < min)
			{
				pq.push(max-min);
				min = max = prices[i];
			} else
			{
				
				pq.push(max-min);
				min = max = prices[i];

			}
		}
		pq.push(max-min);

		for(int i=0; i<2 && pq.size(); i++)
		{
			ret_val += pq.top();
			pq.pop();;
		}
		return ret_val;
    }
};
