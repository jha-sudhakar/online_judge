#include<assert.h>
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

struct exp
{
	unsigned int c;
	unsigned int p;
};

class dfs
{
	private:
		unsigned int N, M;
		unsigned int start, end, min_penalty;;
		vector<char> is_visited;
		bool** nr;
	public:
		vector< vector<struct e> >table; 
		void process_input();
		void all_paths(unsigned int s);
		vector<unsigned int> cur_path;

};

void dfs::process_input()
{
	cin >> N >> M;

	nr = new bool * [N];
	for(int i=0; i<N; i++)
		nr[i] = new bool [2048];
	for(unsigned int i=0; i<N; i++)
		for(unsigned int j=0; j<2048; j++)
			nr[i][j] = false;


	table.resize(N);
	is_visited.resize(N);
	for(unsigned int i=0; i<N; i++) 
		is_visited[i] = 0;

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
	is_visited[start] = 1;
	cur_path.push_back(0);
	all_paths(start);

	if(min_penalty == UINT_MAX)
		cout << -1 << endl;
	else	
		cout << min_penalty << endl;
	
	for(unsigned int i=0; i<N; i++)
		table[i].clear();
}

void dfs::all_paths(unsigned int s)
{
	if(s == end)
	{
		//cout<<"Reached end-- ";
		unsigned int ret = cur_path[cur_path.size()-1];
		//cout<< ", penalty= " << ret << endl;
		if(ret < min_penalty)
		{
			min_penalty = ret;
		}
		return;
	}

	for(unsigned int i=0; i<table[s].size(); i++)
	{
		if(is_visited[table[s][i].v] > 2 || is_visited[table[s][i].v] < 0)
		assert(false);

		//node is visited or self-loop scenario.
		if((is_visited[table[s][i].v] == 0) || ((s == table[s][i].v) && (is_visited[s] <2)))
		{
			is_visited[table[s][i].v]++;
			unsigned int penalty = cur_path[cur_path.size()-1];
			penalty = penalty | table[s][i].c;
			if(penalty >= 2048)
				assert(false);

			if(nr[table[s][i].v][penalty] == false)
			{
				nr[table[s][i].v][penalty] = true;
				cur_path.push_back(penalty);
				all_paths(table[s][i].v);
				cur_path.pop_back();
			}	
			is_visited[table[s][i].v]--;
		}
	}
}

int main()
{
dfs obj1;
obj1.process_input();

return 0;
}



