#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution
{
public:
	int longestConsecutive(const vector<int> &A);
};


int Solution::longestConsecutive(const vector<int> &A)
{
// Do not write main() function.
// Do not read input, instead use the arguments to the function.
// Do not print the output, instead return values as specified
// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	if(A.size() < 2)
		return A.size();

	map<int, int>h;
	for(int i=0; i<A.size(); i++)
	{
		if(h.end() == h.find(A[i]))
			h[A[i]] =1;
		else
			h[A[i]]++;
	}

	int max_len =0, len =0;
	int prev;
	map<int,int>::iterator it = h.begin();
	prev = it->first;
	len++;// = it->second;;
	
	cout<<" num=" << it->first <<", len= " << it->second << endl;

	for( ++it; it != h.end(); it++)
	{
		cout<<" num=" << it->first <<", len= " << it->second << endl;
		if(prev+1 == it->first)
		{
			len++;// += it->second;
			prev = it->first;
		}
		else
		{
			if(len > max_len)
			{
				max_len = len;
			}
			prev = it->first;
			len =1;// it->second;
		}
	}

	if(len> max_len)
		max_len = len;

	return max_len;	
}

//100, 4, 200, 1, 3, 2 
int main()
{

Solution obj;
//int arr[] = {0, 0, -1, 0};
//int arr[] = {100, 4, 200, 1, 3, 2};
int arr[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
vector<int> vec(arr, arr+(sizeof(arr)/sizeof(arr[0])));
int out = obj.longestConsecutive(vec);
cout<<"\n Out len= " << out << endl;;
//for(int i=0; i<out.size(); i++) cout<<" " << out[i];
cout<<endl;

return 0;
}
         
