#include<limits.h>

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


class Solution
{
	public:
		int coinChange(vector<int>& coins, int amount);
};

int Solution::coinChange(vector<int>& coins, int amount)
{
	sort(coins.begin(), coins.end());
	
	unsigned int* count = new unsigned int[amount+1];
	for(unsigned int i=0; i<=amount; i++)
		count[i] = INT_MAX;
	
	count[0] = 0;
	for(unsigned int i=0; i<coins.size(); i++)
	{
		for(unsigned int j=coins[i]; j<=amount; j++)
		{
			if(count[j] > 1+count[j-coins[i]])
				count[j] = 1+count[j-coins[i]];
		}
	}
	if(count[amount] == INT_MAX)
		return -1;
	else
		return count[amount];
}