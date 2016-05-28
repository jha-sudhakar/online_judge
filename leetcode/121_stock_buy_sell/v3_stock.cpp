#include<assert.h>
#include<stdlib.h>

#include <limits.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
	private:
		vector<int> pf, pb; //Profit in forward and backward directions.
		void max_profit_forward(vector<int>& p, const int low, const int high, int& max_profit);
		void max_profit_reverse(vector<int>& p, const int low, const int high, int& max_profit);
		void max_profit_brute_force(vector<int>& p, const int low, const int high, int& min_v, int& max_v);
	public:
    	int maxProfit(vector<int>& prices);
		void test(unsigned int loop);
};

// low and high inclusive in array index;
void Solution::max_profit_forward(vector<int>& p, const int low, const int high, int& max_profit) 
{
	if(low == high)
	{
		max_profit = 0;
		return;
	} else if(low+1 == high)
	{
		if(p[high]-p[low]> 0)
			max_profit = p[high]-p[low];
		else
			max_profit = 0;
		return;	
	}

	int diff_arr[p.size()];	diff_arr[0] = 0;
	for(int i=1; i<p.size(); i++)
	{
		diff_arr[i] = p[i] - p[i-1];
	}

	pf.resize(p.size());
	int max_sum = pf[1] = diff_arr[1];
	int start = 1, max_start=0, max_end=0;
	for(int i=2; i<p.size(); i++)
	{
		int val = pf[i-1]+diff_arr[i];

		while((start <= i) && (pf[i-1]+diff_arr[i] - diff_arr[start] > val))
		{
			val = pf[i-1]+ diff_arr[i] - diff_arr[start];
			start++;
		}
		pf[i] = val;
		if(val > max_sum)
		{
			max_sum = val;
			max_end = i;
			max_start = start-1;
		}
		if(diff_arr[i] > max_sum)
		{
			max_sum = diff_arr[i];
			max_end = i;
			max_start = i-1;

		}

	}
	max_profit = p[max_end] - p[max_start];
	cout <<"O(n) found max at " << max_end <<"', min at= " << max_start <<", Max= " << max_profit <<  endl;
	return;
}

void Solution::max_profit_reverse(vector<int>& p, const int low, const int high, int& max_profit) 
{
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

	int max_profit_f = 0;
	int min_index, max_index;

	max_profit_forward(prices, 0, prices.size()-1, max_profit_f);

	int min_g2=0, max_g2=0;
	max_profit_brute_force(prices, 0, prices.size(), min_g2, max_g2);

	if((max_g2-min_g2 >0) && (max_g2-min_g2 != max_profit_f))
	{
		for(int i=0; i<prices.size(); i++)
		{
			cout <<prices[i] <<" ";
		}
		cout << endl;
		//cout<<"O(n):- Max= " << max_g  <<", Min= " << min_g << ", Diff= " << max_g-min_g   << endl;
		cout <<"O(n):- Max= " << max_profit_f << endl;
		cout<<"BF   :- Max= " << max_g2 <<", Min= " << min_g2 <<", Diff= " << max_g2-min_g2 << endl;
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
