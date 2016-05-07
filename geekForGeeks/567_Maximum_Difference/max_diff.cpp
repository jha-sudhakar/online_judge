#include<iostream>
#include<vector>
using namespace std;

class max_diff
{
	private:
		vector<int> arr;

	public:
		void process_input();
		int find_max_diff();
};

void max_diff::process_input()
{
	unsigned int T, N;
	cin >> T;
	for(unsigned int i=0; i<T; i++)
	{
		cin >> N;
		arr.clear(); arr.resize(N);
		for(unsigned int j=0; j<N; j++)
		{
			cin >> arr[j];
		}
		cout << find_max_diff() << endl;
	}
}

int max_diff::find_max_diff()
{
	int max_diff = -1;
	if(arr.size() <= 1)
	{
		return max_diff;	
	}
	vector<int> lst;
	lst.push_back(arr[0]);
	for(unsigned int i=0; i<arr.size(); i++)
	{
		if(arr[i] > lst[lst.size()-1])
		{
			if(lst.size() != 1)
			{
				lst.pop_back();
			}
			lst.push_back(arr[i]);
		} else if(arr[i] < lst[0])
		{
			if(lst.size() > 1)
			{
				if(max_diff < lst[1] - lst[0])
					max_diff = lst[1] - lst[0];
				lst.pop_back();	
			}
			lst[0] = arr[i];
		}
	}

	if(max_diff < lst[1] - lst[0])
		max_diff = lst[1] - lst[0];
	return max_diff;
}

int main()
{
max_diff obj1;
obj1.process_input();
return 0;
}
