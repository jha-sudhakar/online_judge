
#include <vector>
#include <iostream>
using namespace std;

class rotate_arr
{
	private:
		//int N, K;

	public:
		void rotate(vector<int>& arr, int k);
};

void rotate_arr::rotate(vector<int>& arr, int k)
{
	int count = 0;
	int start = 0;
	int cur=(k)%arr.size();; //start+k;;
	int prev = arr[start];
	int next = 0;
	while(count<arr.size())
	{
		next = arr[cur];
		arr[cur] = prev;
		prev = next;

		if(cur == start) 
		{
			cur = (start+1)%arr.size();
			start = cur;
			prev = arr[start];
			cur = (cur+k)%arr.size();
		}
		else
		{
			cur = (cur+k)%(arr.size());
		}
		count++;
	}
}


class Solution 
{

	public:
		void rotate(vector<int>& nums, int k)
		{
			rotate_arr obj;
			obj.rotate(nums,k);

		}
};



int main()
{
int k=6;
int arr[] = {1,2,3,4,5,6};
vector<int> vec(arr, arr+ (sizeof(arr)/sizeof(arr[0])));
cout<<"Before ==> ";
for(int i=0; i<vec.size(); i++)
cout<<" " << vec[i];
cout<<endl;

rotate_arr obj;
obj.rotate(vec, k);
cout<<"Shifting by " << k << endl;
cout<<"After  ==> ";
for(int i=0; i<vec.size(); i++)
cout<<" " << vec[i];
cout<<endl;


return 0;
}
