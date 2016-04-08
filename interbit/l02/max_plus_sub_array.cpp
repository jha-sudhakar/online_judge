#include<stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{

	public:
		vector<int> maxset(vector<int> &a);
};


vector<int> Solution::maxset(vector<int> &a)
{
// Do not write main() function.
// Do not read input, instead use the arguments to the function.
// Do not print the output, instead return values as specified
// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
vector<int> out;

if(a.size() == 0)
{
	return out;
} else if(a.size() == 1)
{
	if(a[0] >=0)
	{	out.push_back(a[0]); return out; }
	else
		return out;
}

	int start_index = 0, max_start_index=0;;
	int len=0, max_len=-1;;
	long unsigned int sum=0, max_sum = 0;

	for(int i=0; i<a.size(); i++)
	{
		if(a[i] < 0)
		{
			if((sum > max_sum) || ((sum == max_sum)&& (len > max_len)))
			{
				max_sum = sum;
				max_len = len;
				max_start_index = start_index;
			}
			sum = len = 0;
			start_index = i+1;
		} else
		{
			sum +=a[i];
			len++;
		}
	}
	if((sum > max_sum) || ((sum == max_sum)&& (len > max_len)))
	{
		max_sum = sum;
		max_len = len;
		max_start_index = start_index;
	}

	cout<<"\n Start index = " << max_start_index <<", len = " <<max_len;
	//vector<int> out;
	for(int i=max_start_index; i<max_start_index+max_len; i++)
	{
		out.push_back(a[i]);
	}

	return out;
}

int main()
{

Solution obj;
//int arr[] = {0, 0, -1, 0};
int arr[] = {1967513926, 1540383426, -1303455736, -521595368};
vector<int> vec(arr, arr+(sizeof(arr)/sizeof(arr[0])));
vector<int> out = obj.maxset(vec);
cout<<"\n Out size= " << out.size() <<", values= ";
for(int i=0; i<out.size(); i++)
cout<<" " << out[i];
cout<<endl;

return 0;
}
