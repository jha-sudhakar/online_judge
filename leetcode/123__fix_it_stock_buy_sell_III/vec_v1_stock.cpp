#include <limits.h>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

struct diff
{
int u;
int v;
};

class Solution
{
private:
	list<struct diff> l;
	vector<struct diff> *cur, *next;

public:
    int maxProfit(vector<int>& prices)
	{
		cur = new vector<struct diff>;
		next = new vector<struct diff>;
		if(prices.size() < 2)
			return 0;
		int min = prices[0];
		int max = prices[0];

    	for(int i=1; i<prices.size(); i++)
		{
			if(prices[i] > max)
			{
				max = prices[i];
			} else if (prices[i] < max)
			{
				struct diff buf; buf.u = min; buf.v = max;
				cur.push_back(buf);
				min = max = prices[i];

			}
		}
		if(max-min)
		{
			struct diff buf; buf.u = min; buf.v = max;
			cur.push_back(buf);
		}

		bool is_merging = true;
		while(1)
		{
			int max_diff = 0;
			int max_diff_itr = l.begin();
			for (; cur_it!=l.end(); ++cur_it, ++prev_it)
			{
				struct diff cur = *cur_it;
				struct diff prev = *prev_it;
				if((cur.v - prev.u) > (cur.v-cur.u + prev.v-prev.u))
				{
					if((cur.v - prev.u) > max_diff)
					{
						max_diff = cur.v - prev.u;
						max_diff_itr = prev_it;

					}
				}
			}
			if(max_diff > 0)
			{
				struct diff buf = *max_diff_itr;
				max_diff_itr = l.erase(max_diff_itr);
				struct diff cur_buf = *max_diff_itr;
				cur_buf.u = buf.u;
				*max_diff_itr = cur_buf;
			}
			else
				break;
		}

		int final_val = 0;
		int mp=0;
		list<struct diff>::iterator max_it;
		list<struct diff>::iterator cur_it= l.begin();
		for(;cur_it != l.end(); cur_it++);
		{
			struct diff buf = *cur_it;
			if(buf.v-buf.u > mp)
			{
				mp = buf.v-buf.u;
				max_it = cur_it;
			}
		}
		if(mp > 0)
		{
			l.erase(max_it);
		}	
			
		final_val = mp;
		mp = 0;
		for(list<struct diff>::iterator cur_it= l.begin();cur_it != l.end(); cur_it++);
		{
			struct diff buf = *cur_it;
			if(buf.v-buf.u > mp)
				mp = buf.v-buf.u;
		}
		return final_val+mp;
    }
};

int main()
{

Solution obj1;
int arr[] = {6,1,3,2,4,7};
vector<int> in_vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
return obj1.maxProfit(in_vec);
}

