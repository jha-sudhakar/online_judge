#include<stdlib.h>
#include<vector>
#include<iostream>
using namespace std;
class Solution
{

	public:
		void rotate(vector<int>& nums, int k);
};


void Solution::rotate(vector<int>& arr, int k)
{
	k = k % arr.size();

	int cur, prev = arr[0];
	int start_index = 0;

	int prev_index = 0;
	for(int i=0; i<arr.size(); i++)
	{
		int new_index = (prev_index+k)% arr.size();
		cur  = arr[new_index];
		arr[new_index] = prev;
		prev = cur;
		
		if(new_index == start_index)
		{
			start_index++;
			prev_index = (1+new_index);
			prev = arr[start_index];
		}
		else
		prev_index = new_index;
	}

}


int main(int argc, char* argv[])
{
	int shift = atoi(argv[1]);
	int arr[] = { 1,2,3,4,5,6,7,8,9};
	vector<int> vec(arr, arr+ sizeof(arr)/sizeof(arr[0]) );
	Solution obj;
	cout<<"Before rotation:- ";
	for(int i=0; i<vec.size(); i++)
	cout << vec[i] <<"  ";
	cout<<endl;

	obj.rotate(vec, shift);

	cout<<"After rotation:-  ";
	for(int i=0; i<vec.size(); i++)
	cout << vec[i] <<"  ";
	cout<<endl;
	return 0;
}
