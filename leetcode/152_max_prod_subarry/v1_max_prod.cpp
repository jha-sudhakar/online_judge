#include <limits.h>
#include<iostream>
#include<vector>

using namespace std;


class max_prod
{
	private:
		vector<int> zm;
		
	public:
		int max_prod_sub_arry(const vector<int>& num);
		int return_max_in_range(const int neg_count, const int start_neg, const int end_neg);
};


int max_prod::max_prod_sub_arry(const vector<int>& num)
{
	if(num.size() == 1)
	{
		return num[0];
	}

	int max_prod = 0, cur_prod = 0;
	int neg_count=0;
	int start_neg=-1, end_neg=-1;

	for(int i=0; i<num.size(); i++)
	{
		if(num[i] == 0)
		{
			cur_prod = return_max_in_range(neg_count, start_neg, end_neg);
			if(cur_prod > max_prod)
			{
				max_prod = cur_prod;
			}
			zm.clear();
			neg_count = 0;
			start_neg = end_neg = -1;
		}
		else
		{
			zm.push_back(num[i]);
			if(num[i] < 0)
			{
				if(neg_count == 0)
				{
					start_neg = zm.size()-1;
				}	
				end_neg = zm.size()-1;
				neg_count++;
			}
		}
		
	}

	cout<<"\n Last calculation\n";
	cur_prod = return_max_in_range(neg_count, start_neg, end_neg);
	if(cur_prod > max_prod)  max_prod = cur_prod;

	return max_prod;
}


int max_prod::return_max_in_range(const int neg_count, const int start_neg, const int end_neg)
{
	if(zm.size() == 0)
	{
		return INT_MIN;
	}

	int full_prod, fst_prod, last_prod;
	full_prod = fst_prod = last_prod = INT_MIN;

	full_prod = zm[0];
	//1:- Get full length.
	for(int i=1; i<zm.size(); i++)
	{
		full_prod *= zm[i];
	}
	
	if(neg_count%2 == 0)
	{
		return full_prod;
	}
	// 2:- Calculate start_neg;
	if(end_neg > 0)
		fst_prod = zm[0];

	for(int i=1; i<end_neg; i++)
	{
		fst_prod *= zm[i];
	}


	// 3:- calculate end_neg;
	if(start_neg+1 < zm.size())
		last_prod = zm[start_neg+1];

	for(int i=start_neg+2; i<zm.size(); i++)
	{
		last_prod *= zm[i];
	}
	
	int max_prod_val = full_prod;
	if(max_prod_val < fst_prod)
		max_prod_val = fst_prod;

	if(max_prod_val < last_prod)
		max_prod_val = last_prod;

	cout<<"\n returning " << max_prod_val << endl;
	return max_prod_val;
}

class Solution {
public:
    int maxProduct(vector<int>& nums) {
		max_prod obj;
		return obj.max_prod_sub_arry(nums);
    }
};

int main()
{
//int arr[] = {-4, -3};
int arr[] = {-3,0,1,-2};//{2,3,-2,4}; 
vector<int> in_vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
cout<<"\n Array= [";
for(int i=0; i<in_vec.size(); i++)
	cout<<" " << in_vec[i];
cout<<"]" << endl;

max_prod obj;
cout<<"\n Max sub product= " << obj.max_prod_sub_arry(in_vec) << endl;
return 0;
}
