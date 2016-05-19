#include<assert.h>

#include<vector>
#include<iostream>
#include<map>

using namespace std;

class connected_grid
{
	private:
		int m, n;
		int set[11][11];
		vector< vector<int> >arr;
		bool is_valid(const int a, const int b);
		void merge(const int x, const int y);
	public:
		void process_input();
		unsigned int get_max_connected_size();
};

void connected_grid::process_input()
{
	cin >> m;
	cin >> n;

	arr.resize(m);
	for(int i=0; i<m; i++)
	{
		arr[i].resize(n);
		for(int j=0; j<n; j++)
			cin >> arr[i][j];
	}
	
	cout << get_max_connected_size() << endl;
	//arr.clear();
}


bool  connected_grid::is_valid(const int a, const int b)
{
	if((a >-1 && a<m) && (b>-1 && b<n))
		return true;
	else
		return false;
}


void connected_grid::merge(const int x, const int y)
{
	if(x == 0 || y == 0)
		assert(false);

	if(x == y)
		return;
	int min, max;
	if(x > y)
	{
		max = x;
		min = y;
	} else
	{
		max = y;
		min = x;
	}
	for(unsigned int i=0; i<m; i++)
	{
		for(unsigned int j=0; j<n; j++)
		{
			if(set[i][j] == max)
				set[i][j] = min;
		}
	}
}

unsigned int connected_grid::get_max_connected_size()
{
	unsigned int counter = 1;
	for(unsigned int i=0; i<m; i++)
	{	for(unsigned int j=0; j<n; j++)
		{
			if(arr[i][j] == 0)
				set[i][j] = 0;
			else
				set[i][j] = counter;
			
			counter++;
		}
	}	

	for(unsigned int i=0; i<m; i++)
	{
		for(unsigned int j=0; j<n; j++)
		{
			if(arr[i][j] == 0)
				continue;

			// Diagonally left up.
			if(is_valid(i-1,j-1) && (arr[i-1][j-1] != 0))
			{
					merge(set[i][j], set[i-1][j-1]);
			}
			
			//Above
			if(is_valid(i-1,j) && (arr[i-1][j] != 0))
			{
				merge(set[i][j], set[i-1][j]);
			}
			
			// Diagonally right up.
			if(is_valid(i-1,j+1) && (arr[i-1][j+1] != 0))
			{
				merge(set[i][j],set[i-1][j+1]);
			}	

			// Left.
			if(is_valid(i,j-1) && (arr[i][j-1] != 0))
			{
				merge(set[i][j], set[i][j-1]);
			}
		}
	}


	map<unsigned int, unsigned int> map_v;
	map<unsigned int, unsigned int>::iterator itr;
	for(unsigned int i=0; i<m; i++)
	{
		for(unsigned int j=0; j<n; j++)
		{
			itr = map_v.find(set[i][j]);
			if(itr != map_v.end())
				map_v[set[i][j]]++;
			else
				map_v[set[i][j]] = 1;
			//cout << set[i][j] << " ";	
		}
		//cout << endl;
	}

	unsigned int max_len = 0;
	for(itr = map_v.begin(); itr != map_v.end(); itr++)
	{
		//cout <<"[" << itr->first << "]= " << itr->second << endl;
		if((itr->first != 0) && (itr->second > max_len))
			max_len = itr->second;
	}
	return max_len;
}


int main()
{
connected_grid obj;
obj.process_input();
return 0;
}
