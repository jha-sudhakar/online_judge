#include <vector>
#include<iostream>
using namespace std;

class lcs
{
	private:
		int max_val;
		int min_val;

	public:
		int get_lcs(vector<int>& nums);



};

int lcs::get_lcs(vector<int>& nums)
{
	max_val = nums[0];
	min_val = nums[0];
	for(int i=1; i<nums.size(); i++)
	{
		if(nums[i] > max_val)
			max_val = nums[i];

		if(nums[i] < min_val)
			min_val = nums[i];
	}

	int buf = 0;
	if(max_val >= 0 && min_val >= 0)
		buf = 1 + max_val - min_val;
	else if(max_val <=0 && min_val <= 0)
		buf = -1 *(max_val - min_val) + 1;
	else if(max_val >=0 && min_val < 0)
		buf = max_val + 1 + -1 * min_val;

	int offset = 0; 
	if(min_val < 0) 
		offset = (-1 * min_val);
	long int hash[buf];

	for(int i=0; i<buf; i++)
		hash[i] = 0;;

	for(int i=0; i<nums.size(); i++)
	{
		hash[offset+nums[i]] = 1;
	}

	int count=1, max_count=1;;
	for(int i=1; i<buf; i++)
	{
		
		if(hash[i] > hash[i-1]+1)
			count++;
		else
		{
			if(count > max_count)
				max_count = count;
			count=0;	
		}
	}
	if(count > max_count)
		max_count = count;
	return max_count;	
}


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        lcs obj1;
		return obj1.get_lcs(nums);
    }
};


