#include<stdio.h>
#include<vector>
#include<list>
#include<iostream>
using namespace std;

struct vt
{
	unsigned int index;
	unsigned int len;
	vt(unsigned int _index, unsigned int _len) { index=_index; len=_len; }
};

class BFS
{
	private:
		unsigned int N,M,T;
		bool** city_roads;
		bool* is_visited;
		unsigned int* len;
		void run_bfs(const unsigned int start);
	public:
		void process_input();




};



void BFS::process_input()
{
	cin >> T;
	for(unsigned int i=0; i<T; i++)
	{
		cin >> N >> M;

		len = new unsigned int [N];
		is_visited = new bool [N];
		city_roads = new bool* [N];
		for(unsigned int i=0; i<N; i++)
		{
			len[i] = 0;
			city_roads[i] = new bool [N];
			is_visited[i] = false;
		}

		for(unsigned int i=0; i<N; i++)
			for(unsigned int j=0; j<N; j++)
				city_roads[i][j] = true;

		for(unsigned int k=0; k<M; k++)
		{
			unsigned int u,v;
			cin >> u >> v;
			u--;v--;
			city_roads[u][v] = false;
			city_roads[v][u] = false;
		}

		unsigned int start_node;
		cin >> start_node; start_node--;
		run_bfs(start_node);

		delete [] is_visited;
		for(unsigned int i=0; i<N; i++)
			delete [] city_roads[i];
		delete [] city_roads;	
		for(unsigned int i=1; i<N; i++)
		{
			cout<< len[i];
			if(i<N-1)
				cout <<" ";
		}
		cout << endl;
		delete [] len;
	}
}

void BFS::run_bfs(const unsigned int start)
{
	is_visited[start] = true;
	list<vt> lst;
	lst.push_back(vt(start, 0));

	while(lst.size())
	{
		vt tmp = lst.front();
		lst.pop_front();
		for(unsigned int i=0; i<N; i++)
		{
			if(is_visited[i] == false && city_roads[tmp.index][i] == true)
			{
				lst.push_back(vt(i, 1+tmp.len));
				is_visited[i] = true;
				len[i] = 1+tmp.len;
			}
		}

	}
}

int main()
{
BFS obj;
obj.process_input();
return 0;
}
