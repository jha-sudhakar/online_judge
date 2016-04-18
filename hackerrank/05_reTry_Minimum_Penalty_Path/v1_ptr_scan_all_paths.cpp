#include<stdio.h>
#include<limits.h>

#include<vector>
#include<iostream>
using namespace std;

struct e
{
	unsigned int v;
	unsigned int c;
	e(unsigned int _v, unsigned int _c) { v=_v; c=_c;}
};

class dfs
{
	private:
		unsigned int N, M;
		unsigned int start, end, min_penalty;;
		bool *is_visited;
	public:
		vector<struct e> *table; 
		void process_input();
		void all_paths(unsigned int s);
		vector<unsigned int> cur_path;

};

void dfs::process_input()
{
	cin >> N >> M;
	table = new vector<struct e> [N]; 
	
	is_visited = new bool [N];
	for(unsigned int i=0; i<N; i++) 
		is_visited[i] = false;

	for(unsigned int i=0; i<M; i++)
	{
		unsigned int u, v, c;
		cin >> u >> v >> c;

		table[u-1].push_back(e(v-1, c));
		table[v-1].push_back(e(u-1, c));
	}
	cin >> start >> end;
	min_penalty = UINT_MAX;

	end--; start--;
	is_visited[start-1] = true;
	all_paths(start);

	cout << min_penalty << endl;
	for(unsigned int i=0; i<N; i++)
		table[i].clear();
	delete [] table;
	delete [] is_visited;
}

void dfs::all_paths(unsigned int s)
{
	if(s == end)
	{
		unsigned int ret = 0;
		for(unsigned int i=0; i<cur_path.size(); i++)
		{
			ret = ret | cur_path[i];
		}
		if(ret < min_penalty)
		{
			min_penalty = ret;
		}
		if(cur_path.size())
			return;
	}

	for(unsigned int i=0; i<table[s].size(); i++)
	{
		if((is_visited[table[s][i].v] == false) || (s == table[s][i].v)) // Dst node is visited or self loop scenario.
		{
			is_visited[table[s][i].v] = true;
			cur_path.push_back(table[s][i].c);
			all_paths(table[s][i].v);
			cur_path.pop_back();

			if(s != table[s][i].v)
				is_visited[table[s][i].v] = false;
		}
	}
}

int main()
{
dfs obj1;
obj1.process_input();

return 0;
}



