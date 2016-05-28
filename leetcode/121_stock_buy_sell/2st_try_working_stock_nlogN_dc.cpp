#include<assert.h>
#include<stdlib.h>

#include <limits.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
	private:
		void ret_max_in_pair( vector<int>&p, const int min1_pos, const int max1_pos, 
								const int post_min1_pos, const int pre_max2_pos, 
								const int min2_pos, const int max2_pos, 
								int& min_Pos, int& max_pos);

		//void ret_max_in_pair(const int min1, const int max1, const int min2, const int max2, int& min, int& max);
		void set_max(vector<int>& p, const int cur_min, const int cur_max, int& min, int&max);
		void max_profit(vector<int>& p, const int low, const int high, int& min_v, int& max_v);
		void max_profit_brute_force(vector<int>& p, const int low, const int high, int& min_v, int& max_v);
	public:
    	int maxProfit(vector<int>& prices);
		void test(unsigned int loop);
};

void Solution::set_max(vector<int>&p, const int cur_max, const int cur_min, int& min, int& max)
{
	if(p[cur_max]-p[cur_min] > p[max]-p[min])
	{
		max = cur_max;
		min = cur_min;
	} else if(p[cur_max]-p[cur_min] == p[max]-p[min])
	{
		if(p[cur_min] < p[min])
		{
			max = cur_max;
			min = cur_min;
		}
	}
}

void Solution::ret_max_in_pair( vector<int>&p, const int min1_pos, const int max1_pos, 
								const int post_min1_pos, const int pre_max2_pos, 
								const int min2_pos, const int max2_pos, 
								int& min_pos, int& max_pos)
{
	int tmp_pos;

	// min1 
	max_pos = max1_pos;
	min_pos = min1_pos;
	
	tmp_pos = min1_pos;
	set_max(p, pre_max2_pos, tmp_pos, min_pos, max_pos);
	set_max(p, min2_pos,     tmp_pos, min_pos, max_pos);
	set_max(p, max2_pos,     tmp_pos, min_pos, max_pos);

	// max1 	
	tmp_pos = max1_pos;
	set_max(p, pre_max2_pos, tmp_pos, min_pos, max_pos);
	set_max(p, min2_pos,     tmp_pos, min_pos, max_pos);
	set_max(p, max2_pos,     tmp_pos, min_pos, max_pos);


	tmp_pos = post_min1_pos;
	set_max(p, pre_max2_pos, tmp_pos, min_pos, max_pos);
	set_max(p, min2_pos,     tmp_pos, min_pos, max_pos);
	set_max(p, max2_pos,     tmp_pos, min_pos, max_pos);

	// post_min1
	tmp_pos = min2_pos;
	set_max(p, max2_pos,     tmp_pos, min_pos, max_pos);
}

void Solution::max_profit(vector<int>& p, const int low, const int high, int& min_pos, int& max_pos) // low and high inclusive in array index;
{
	if(low == high)
	{
		min_pos = max_pos = low;
		return;
	} else if(low+1 == high)
	{
		max_pos = high;
		min_pos = low;
		return;
	}

	int mid = (low+high)/2;
	int min1_pos, max1_pos, post_min1_pos,  pre_max2_pos, min2_pos, max2_pos;
	max_profit(p, low, mid,  min1_pos, max1_pos);

	post_min1_pos = min1_pos;
	for(int i=max1_pos+1; i<=mid; i++)
	{
		if(p[i] < p[post_min1_pos])
		{
			post_min1_pos = i;
		}
	}

	max_profit(p, mid+1, high, min2_pos, max2_pos);
	pre_max2_pos = max2_pos;
	for(int i=mid+1; i<min2_pos; i++)
	{
		if(p[i] > p[pre_max2_pos])
		{
			pre_max2_pos = i;
		}
	}


	ret_max_in_pair(p, min1_pos,max1_pos, post_min1_pos, pre_max2_pos, min2_pos,max2_pos,  min_pos,max_pos);

	//cout <<"Between " << low <<" and " << high <<", Max= " << p[max_pos] <<", min= " << p[min_pos] << endl;
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
	if(prices.size() <2)
	{
		return 0;
	}

	int min_g=0, max_g=0;
	int min_index, max_index;

	max_profit(prices, 0, prices.size()-1, min_index, max_index);

	min_g = prices[min_index];
	max_g = prices[max_index];

#if 0
if(max_g > min_g)
		return max_g-min_g;
	return 0;	
#endif

#if 1
	int min_g2=0, max_g2=0;
	max_profit_brute_force(prices, 0, prices.size(), min_g2, max_g2);

	if((max_g2-min_g2 >0) && (max_g2-min_g2 != max_g-min_g))
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
#endif
}


void Solution::test(unsigned int loop)
{
	srand(time(NULL));
	while(loop--)
	{
		vector<int> in_v;
		const int input_size = 5 + rand()%15;
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
