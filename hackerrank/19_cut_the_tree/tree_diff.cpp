//#include<math.h>
#include<stdlib.h>
#include<limits.h>

#include<vector>
#include<iostream>
using namespace std;

vector<unsigned int> g[100000];
unsigned int w[100000];

struct node
{
	unsigned int n;
	unsigned int index;
	node(unsigned int _n, unsigned int _index) { n=_n; index=_index;}
};

class tree_diff
{
	private:
		unsigned int N;
		long long int SUM;
	public:
		void process_input();
		unsigned long int get_min_diff();
};

void tree_diff::process_input()
{
	SUM = 0;
	cin >> N;
	w[0] = 0;
	for(unsigned int i=1; i<=N; i++)
	{
		cin >> w[i];
		SUM += w[i];
	}
	
	unsigned int u,v;
	for(unsigned int i=1; i<=N; i++)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	cout << get_min_diff() << endl;
}


unsigned long int tree_diff::get_min_diff()
{
	bool is_visited[N+1];
	for(unsigned int i=0; i<=N; i++)
	{
		is_visited[i] = false;
	}
	unsigned long int max_diff=-1;;
	long long int cur_w = 0;
	vector<node> vec;
	vec.push_back(node(1, 0));
	is_visited[1] = true;
	while(!vec.empty())
	{
		node& nref = vec[vec.size()-1];	
		if(nref.index >= g[nref.n].size()) // All outgoing edges are traversed so remove this vertex now.
		{
			if( nref.n == 1)
				break;
				
			w[vec[vec.size()-2].n] += w[nref.n]; // Add its weight to the parent;
			cur_w = 2*w[nref.n];

			if(abs(SUM-cur_w) < max_diff)
				max_diff = abs(SUM-cur_w);
			//cout <<"Diff at " << nref.n << "= " << abs(SUM-cur_w) << endl;
			vec.pop_back();
			continue;
		}
		
		unsigned int child = g[nref.n][nref.index];
		 vec[vec.size()-1].index++; //nref.index++;
		if(is_visited[child] == false)
		{
			vec.push_back(node(child, 0));
			is_visited[child] = true;
		}
	}
	return max_diff;
}


int main()
{
	tree_diff obj;
	obj.process_input();
	return 0;
}
