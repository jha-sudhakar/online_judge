#include <limits.h>
#include <vector>
#include<iostream>
using namespace std;

//const unsigned long long int NG= UINT_MAX;
unsigned char hash_arr[4294967299];

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
	unsigned long long int N= UINT_MAX;
	N +=4;
	//unsigned char hash_arr[N];
	long long int offset = 0;

	for(unsigned long long int i=0; i<N; i++)
		hash_arr[i] = 0;;

	for(int i=0; i<nums.size(); i++)
	{
		offset = INT_MAX;
		offset += nums[i];
		offset += 1;
		hash_arr[offset+nums[i]] = 1;
	}

	int count=0, max_count=0;
	if(hash_arr[0] == 1)
	{
		count=1; max_count=1;
	}
	for(unsigned long int i=1; i<N; i++)
	{
		if(hash_arr[i] == 0)
		{
			if(count > max_count)
				max_count = count;
			count =0;
		} else if(hash_arr[i] == 1)
		{
			count++;
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



int main()
{
	Solution obj1;
	vector<int> nums;
	nums.push_back(0);
	int ret_val = obj1.longestConsecutive(nums);
	cout<<"\n count = " << ret_val << endl;

	return 0;
}
