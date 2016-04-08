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
	//list<struct diff> l;
	vector<struct diff> cur;

public:
    int maxProfit(vector<int>& prices)
	{

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
				if(max-min > 0)
					cur.push_back(buf);
				min = max = prices[i];

			}
		}
		if(max-min > 0)
		{
			struct diff buf; buf.u = min; buf.v = max;
			cur.push_back(buf);
		}

		if(cur.size() == 0)
			return 0;
#if 1
		cout<<"\n Filtered list= \n";
		for(int i=0; i<cur.size(); i++)
			cout<< cur[i].u <<", " << cur[i].v << endl;
#endif
		bool is_merging = true;
		while(1)
		{
			if(cur.size() <= 2)
				break;

			int min_diff = INT_MAX;
			int min_diff_index=0 ;
			struct diff cur_t, prev_t = cur[0];
			for (int i=1; i<cur.size(); i++)
			{
				cur_t = cur[i];
				prev_t = cur[i-1];
				int tmp = cur_t.v-prev_t.u;
				if(tmp > 0 && (tmp > cur_t.v-cur_t.u) && (tmp > prev_t.v - prev_t.u))
				{
					if(tmp <min_diff)
					{
						min_diff = tmp;
						min_diff_index = i;
					}	

				}
			}

#if 0
			int max_diff_local = 0;
			for (int i=0; i<cur.size(); i++)
			{
                if((cur[i].v - cur[i].u) > max_diff_local)
                {
                    max_diff_local = cur[i].v - cur[i].u;
                }
			}
#endif
	
			if(min_diff > 0 && min_diff != INT_MAX) //if(max_diff > 0 && max_diff > max_diff_local)
			{
				cur[min_diff_index-1].v =  cur[min_diff_index].v;
				cout <<"\n Merging " << cur[min_diff_index].u <<" and " <<  cur[min_diff_index].v << endl;
				cur.erase(cur.begin()+min_diff_index);
			}
			else
				break;
		}

		int final_val = 0;
		int max_diff_index = 0;
		int mp=0;
		for(int i=0; i<cur.size(); i++)
		{
			struct diff buf = cur[i];
			if(buf.v-buf.u > mp)
			{
				mp = buf.v-buf.u;
				max_diff_index=i;
			}
		}
		if(mp > 0)
		{
			cur.erase(cur.begin()+max_diff_index);
		}	
			
		final_val = mp;
		mp = 0;
        for(int i=0; i<cur.size(); i++)
        {
            struct diff buf = cur[i];
            if(buf.v-buf.u > mp)
            {
                mp = buf.v-buf.u;
            }
        }

		return final_val+mp;
    }
};

int main()
{

Solution obj1;
//int arr[] = {1,2,4,2,5,7,2,4,9,0};  
//int arr[] = {6,1,3,2,4,7};
//int arr[] = {8,6,4,3,3,2,3,5,8,3,8,2,6};
int arr[] = {2,6,8,7,8,7,9,4,1,2,4,5,8};
vector<int> in_vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
cout<<"\n Profit = " << obj1.maxProfit(in_vec)<< endl;
return 0;
}

