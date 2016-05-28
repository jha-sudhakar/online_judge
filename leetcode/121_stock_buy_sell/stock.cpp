#include<assert.h>
#include<stdlib.h>

#include <limits.h>
#include <vector>
#include <iostream>

using namespace std;
struct pos
{
	int index;
	int val;
	pos(int _index, int _val) { index=_index; val=_val;}
};

class Solution
{
	private:
		vector<int> pf, pb; //Profit in forward and backward directions.
		void max_profit_forward(vector<int>& p, int& max_profit);
		void max_profit_reverse(vector<int>& p, int& max_profit);
		void max_profit_brute_force(vector<int>& p, const int low, const int high, int& min_v, int& max_v);
	public:
    	int maxProfit(vector<int>& prices);
		int maxProfit_2(vector<int>& prices);
		void test(unsigned int loop);
};

// low and high inclusive in array index;
void Solution::max_profit_forward(vector<int>& p, int& max_profit) 
{
	pf.clear(); pf.resize(p.size());
	for(int i=0; i<p.size(); i++)
	pf[i] = INT_MIN;

	vector<pos> stk;
	int min_ele = INT_MAX/2 -100;
	int cur_max_diff = INT_MIN;
	for(int i=0; i<p.size(); i++)
	{
		if(p[i] < min_ele) // Smaller than min seen so far so add it.
		{
			stk.push_back(pos(i,p[i]));
			min_ele = p[i];
		} else if(p[i] > stk[stk.size()-1].val) // Bigger than current max so over-write it.
		{
			if(stk[stk.size()-1].val != min_ele)
			{
				 pf[stk[stk.size()-1].index] = cur_max_diff;
				 
				 stk[stk.size()-1].val = p[i]; 
				 stk[stk.size()-1].index = i;
				 if(cur_max_diff < p[i]-min_ele)
					 cur_max_diff = p[i]-min_ele;
			}	
			else
			{
				stk.push_back(pos(i, p[i])); // Only one value and this is bigger than that so include it as well.
				 if(cur_max_diff < p[i]-min_ele)
					 cur_max_diff = p[i]-min_ele;
			}	
		} else
		{
			pf[i] = cur_max_diff;

		}
	}	

	max_profit = INT_MIN;
	int prev_index = 0;
	//cout <<"stk at " << 0 <<" Index= " << stk[0].index <<", val= " << stk[0].val << endl;	
	for(int i=1; i<stk.size(); i++)
	{
		//cout <<"stk at " << i <<" Index= " << stk[i].index <<", val= " << stk[i].val << endl;	
		if(stk[i].val-stk[i-1].val > max_profit)
		{
			for(int k=prev_index; k<stk[i].index; k++)
			{
				if(pf[k] != INT_MIN)
					continue;
				pf[k] = max_profit;
			}
			max_profit = stk[i].val - stk[i-1].val;
			prev_index = stk[i].index;
		}	
	}
	for(int k=prev_index; k<p.size(); k++)
		pf[k] = max_profit;

	if(max_profit<0)
		max_profit = 0;
	return;
}

void Solution::max_profit_reverse(vector<int>& p, int& max_profit) 
{
	vector<pos> stk;
	pb.clear(); pb.resize(p.size());
	for(int i=0; i<p.size(); i++)
		pb[i] = INT_MIN;

	int max_ele = INT_MIN;
	int cur_max_diff = INT_MIN;
	for(int i=p.size()-1; i>-1; i--)
	{
		if(p[i] >  max_ele) // Bigger than max seen so far so add it.
		{
			stk.push_back(pos(i,p[i]));
			max_ele = p[i];
			pb[i] = cur_max_diff;
		} else if(p[i] <  stk[stk.size()-1].val) // Bigger than current max so over-write it.
		{
			if(stk[stk.size()-1].val != max_ele)
			{
				//pb[stk[stk.size()-1].index] = cur_max_diff;
				stk[stk.size()-1].val = p[i];
				stk[stk.size()-1].index = i;
				if(cur_max_diff < max_ele-p[i])
					cur_max_diff = max_ele-p[i];
				pb[i] = cur_max_diff;	
			}	
			else
			{
				stk.push_back(pos(i,p[i])); // Only one value and this is bigger than that so include it as well.
				if(cur_max_diff < max_ele-p[i])
					cur_max_diff = max_ele-p[i];
				pb[i] = cur_max_diff;	
			}	 
		} else
		{
			pb[i] = cur_max_diff;
		}
	}	

/*
	max_profit = INT_MIN;
	int prev_index = p.size()-1;
	for(int i=stk.size()-1; i>0; i--)
	{
		cout <<"stk at " << i <<" Index= " << stk[i].index <<", val= " << stk[i].val << endl;	
		
		if(pb[i] != INT_MIN)
			continue;
		if(stk[i-1].val-stk[i].val > max_profit)
		{
			max_profit = stk[i-1].val - stk[i].val;
			for(int k=i; k<=prev_index; k++)
			{
				pb[k] = max_profit;
			}
			prev_index = stk[i].index-1;;
		}	
	}

	for(int k=0; k<=prev_index; k++)
		pb[k] = max_profit;
*/
	max_profit = cur_max_diff;
	if(max_profit<0)
		max_profit = 0;
	return;
}

int Solution::maxProfit_2(vector<int>& prices)
{
	if(prices.size() <2)
	{
		return 0;
	}

	int max_profit_f = 0, max_profit_b=0;
	int min_index, max_index;

	max_profit_forward(prices, max_profit_f);
	max_profit_reverse(prices, max_profit_b);


	if(max_profit_f != max_profit_b)
	{
		assert(false);	
	}
	
	int min_g2=0, max_g2=0;
	max_profit_brute_force(prices, 0, prices.size()-1, min_g2, max_g2);

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

	bool is_assert = false;
	for(int i=prices.size()-1; i>0; i--)
	{
		min_g2=0, max_g2=0;
		max_profit_brute_force(prices, 0, i, min_g2, max_g2);
		int val1= pf[i]>0 ?pf[i]:0;
		int val2= (max_g2-min_g2)>0 ?(max_g2-min_g2):0;
		// cout <<"0 to " << i <<" , On= " << val1 <<", bf= " << val2 << endl;
		if(val1 != val2)
		{
			is_assert = true;
		}	
	}	
	if(is_assert == true)
	{
		for(int i=0; i<prices.size(); i++)
		{
			cout <<prices[i] <<" ";
		}
		cout << endl;
		assert(false);
	}
	
	is_assert = false;
	for(int i=0; i<prices.size()-1; i++)
	{
		min_g2=0, max_g2=0;
		max_profit_brute_force(prices, i, prices.size()-1, min_g2, max_g2);
		int val1= pb[i]>0 ?pb[i]:0;
		int val2= (max_g2-min_g2)>0 ?(max_g2-min_g2):0;
		 cout << i <<" to "<< prices.size()-1 <<" , On= " << val1 <<", bf= " << val2 << endl;
		if(val1 != val2)
		{
			is_assert = true;
		}	
	}	
	if(is_assert == true)
	{
		for(int i=0; i<prices.size(); i++)
		{
			cout <<prices[i] <<" ";
		}
		cout << endl;
		assert(false);
	}
}


void Solution::max_profit_brute_force(vector<int>& p, const int low, const int high, int& min_v, int& max_v)
{
	min_v = INT_MAX/2 -100;
	max_v = INT_MIN/2 + 100;
	
	for(int i=low; i<=high; i++)
	{
		for(int j=i+1; j<=high; j++)
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

	int max_profit_f = 0, max_profit_b=0;
	int min_index, max_index;

	max_profit_forward(prices, max_profit_f);
	max_profit_reverse(prices, max_profit_b);

	if(max_profit_f != max_profit_b)
	{
		assert(false);	
	}

	int min_g2=0, max_g2=0;
	max_profit_brute_force(prices, 0, prices.size()-1, min_g2, max_g2);

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

	cout <<"\t O(n) :- Max= " << max_profit_f << endl;
	cout<<"\t  BF   :- Max= " << max_g2-min_g2 << endl;
	return (max_g2-min_g2);
}


void Solution::test(unsigned int loop)
{
	srand(time(NULL));
	while(loop--)
	{
		vector<int> in_v;
		const int input_size = 5 + rand()%25;
		for(int i=0; i<input_size; i++)
		{
			int tmp = rand()%100;
			in_v.push_back(tmp);
		}
		cout << "Iteration " << loop << "\t " << maxProfit_2(in_v)  << endl;
	}
}


int main(int argc, char* argv[])
{
	int loop = atoi(argv[1]);
	Solution obj;
	obj.test(loop);
	return 0;
}
