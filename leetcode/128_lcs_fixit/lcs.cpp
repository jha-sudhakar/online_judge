
#include<vector>
#include<iostream>
using namespace std;

class lcs
{
	private:
		vector<int> arr;

	public:
		void set_input();
		void set_input(vector<int>& vec);
		int  process_input();
};

void lcs::set_input()
{


}

void lcs::set_input(vector<int>& vec)
{
	arr = vec;
}


int lcs::process_input()
{
	unsigned int count[arr.size()];
	//for(unsigned int i=0; i<arr.size(); i++) { count[i] = 0; }
	if(arr.size() == 0)
	{
		return 0;
	}
	count[0] = 1;
	unsigned int max = 1;	
	for(unsigned int i=1; i<arr.size(); i++)
	{
		unsigned int max_len = 1;
		for(unsigned int j=0; j<i; j++)
		{
			if(arr[j] < arr[i])
			{
				if(count[j]+1 > max_len)
					max_len = count[j]+1;
			}
		}
		count[i] = max_len;
		if(count[i] > max)
			max = count[i];
	}
	return max;
}

class Solution {
	public:
   		int lengthOfLIS(vector<int>& nums)
		{
			lcs obj;
			obj.set_input(nums);
			return obj.process_input();

		}
};

