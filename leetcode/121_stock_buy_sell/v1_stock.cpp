#include<assert.h>
#include<stdlib.h>

#include <limits.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
	private:
		void ret_max_in_pair(const int min1, const int max1, const int min2, const int max2, int& min, int& max);
		void set_max(const int cur_min, const int cur_max, int& min, int&max);
		void max_profit(vector<int>& p, const int low, const int high, int& min_v, int& max_v);
		void max_profit_brute_force(vector<int>& p, const int low, const int high, int& min_v, int& max_v);
	public:
    	int maxProfit(vector<int>& prices);
		void test(unsigned int loop);
};

void Solution::set_max(const int cur_max, const int cur_min, int& min, int& max)
{
	if(cur_max-cur_min > max-min)
	{
		max = cur_max;
		min = cur_min;
	} else if(cur_max-cur_min == max-min)
	{
		if(cur_min < min)
		{
			max = cur_max;
			min = cur_min;
		}
	}
}

void Solution::ret_max_in_pair(const int min1, const int max1, const int min2, const int max2, int& min, int& max)
{
	max = max1;
	min = min1;

	set_max(min2, min1, min, max);
	set_max(max2, min1, min, max);

	set_max(min2, max1, min, max);
	set_max(max2, max1, min, max);

	set_max(max2, min2, min, max);
}

void Solution::max_profit(vector<int>& p, const int low, const int high, int& min_v, int& max_v) // low and high inclusive in array index;
{
	if(low == high)
	{
		min_v = max_v = p[low];
		return;
	} else if(low+1 == high)
	{
		max_v = p[high];
		min_v = p[low];
		return;
	}

	int mid = (low+high)/2;
	int min1, max1, min2, max2;
	max_profit(p, low, mid, min1, max1);
	max_profit(p, mid, high, min2, max2);

	ret_max_in_pair(min1,max1, min2,max2,  min_v,max_v);
	cout <<"Between " << low <<" and " << high <<", Max= " << max_v <<", min= " << min_v << endl;
}

void Solution::max_profit_brute_force(vector<int>& p, const int low, const int high, int& min_v, int& max_v)
{
	min_v = INT_MAX/2 -100;
	max_v = INT_MIN/2 + 100;
	
	for(int i=low; i<high; i++)
	{
		for(int j=i+1; j<high; j++)
		{
			if(p[j]-p[i] > max_v-min_v)
			{
				max_v = p[j];
				min_v = p[i];
			}
		}
	}

}

int Solution::maxProfit(vector<int>& prices)
{
	int min_g=0, max_g=0;
	max_profit(prices, 0, prices.size()-1, min_g, max_g);
	
	int min_g2=0, max_g2=0;
	max_profit_brute_force(prices, 0, prices.size(), min_g2, max_g2);

	if(max_g2-min_g2 != max_g-min_g)
	{
		for(int i=0; i<prices.size(); i++)
		{
			cout <<prices[i] <<" ";
		}
		cout << endl;
		cout<<"DC:- Max= " << max_g  <<", Min= " << min_g << ", Diff= " << max_g-min_g   << endl;
		cout<<"BF:- Max= " << max_g2 <<", Min= " << min_g2 <<", Diff= " << max_g2-min_g2 << endl;
		assert(false);
	}

	return (max_g2-min_g2);
}


void Solution::test(unsigned int loop)
{
	srand(time(NULL));
	while(loop--)
	{
		vector<int> in_v;
		const int input_size = 5 + rand()%5;
		for(int i=0; i<input_size; i++)
		{
			int tmp = rand()%100;
			in_v.push_back(tmp);
		}
		cout << "Iteration " << loop << "\t " << maxProfit(in_v)  << endl;
	}
}

int main(int argc, char* argv[])
{
	int loop = atoi(argv[1]);
	Solution obj;
	obj.test(loop);
	return 0;
}
