#include<stdio.h>
#include<algorithm>
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
		vector<unsigned int>* city_roads;
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
		city_roads = new vector<unsigned int> [N];
		for(unsigned int i=0; i<N; i++)
		{
			len[i] = 0;
			is_visited[i] = false;
		}

		for(unsigned int k=0; k<M; k++)
		{
			unsigned int u,v;
			cin >> u >> v;
			u--;v--;
			city_roads[u].push_back(v);
			city_roads[v].push_back(u);
		}

		for(unsigned int i=0; i<N; i++) { sort(city_roads[i].begin(), city_roads[i].end()); }

		unsigned int start_node;
		cin >> start_node; start_node--;
		run_bfs(start_node);

		delete [] is_visited;
		delete [] city_roads;	
		for(unsigned int i=0; i<N; i++)
		{
			if(i == start_node)
				continue;

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
	unsigned int visit_count = 1;
	while(lst.size())
	{

		vt tmp = lst.front();
		lst.pop_front();
		unsigned int min_v=0,max_v=N;
		if(city_roads[tmp.index].size())
		{
			min_v = city_roads[tmp.index][0];
			max_v = city_roads[tmp.index][city_roads[tmp.index].size()-1];
		}

		for(unsigned int i=0; i<N; i++)
		{
			if(is_visited[i] == true)
			{
				continue;
			}
			
			bool skip_this_station = false;

			if(i >= min_v && i<= max_v)
			{
				for(unsigned int k=0; k<city_roads[tmp.index].size(); k++)
				{
					if(i == city_roads[tmp.index][k])
					{
						skip_this_station = true;
						break;
					}	
				}
			}
			if(true == skip_this_station)
				continue;
	
			//cout<<"Src= " << tmp.index <<", dst= " << i << ", Len= " << 1+tmp.len << endl;
			lst.push_back(vt(i, 1+tmp.len));
			is_visited[i] = true; visit_count++;
			len[i] = 1+tmp.len;
			if(visit_count == N)
				return;
		}

	}
}

int main()
{
BFS obj;
obj.process_input();
return 0;
}
