#include<iostream>
#include<vector>
using namespace std;

class Graph
{
	private:
		unsigned int N,M;
		vector< vector<unsigned int> >graph;

	public:
		void read_input();
		void find_count();
		unsigned long long int nC2(const unsigned int n);
};

void Graph::read_input()
{
	cin >> N >> M;
	graph.resize(N);

	unsigned int u,v;
	for(unsigned int i=0; i<M; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
}
		

void Graph::find_count()
{
	bool* is_visited = new bool[N];
	for(unsigned int i=0; i<N; i++)
		is_visited[i] = false;

	vector<unsigned int>* cur_n =  new vector<unsigned int>;
	vector<unsigned int> cluster_size;
	for(unsigned int i=0; i<N; i++)
	{
		unsigned int cur_size=0;
		if(is_visited[i] == true)
			continue;
		cur_size++;
		cur_n->push_back(i);
		is_visited[i] = true;
		//cout <<"\n\nInserted " << i << endl;
		while(cur_n->size())
		{
			unsigned int vertex = cur_n->at(cur_n->size()-1);
			cur_n->pop_back();
			for(unsigned int j=0; j<graph[vertex].size(); j++)
			{
				if(is_visited[graph[vertex][j]] == true) continue;
				cur_n->push_back(graph[vertex][j]);
				is_visited[graph[vertex][j]] = true;
				//cout <<"Inserted " << graph[vertex][j] << endl;
				cur_size++;
			}
		}
		cluster_size.push_back(cur_size);
	}
	
	delete  cur_n;
	delete [] is_visited;

	unsigned long long diff_count=0,count=0;
	//cout <<"cluster-size= " << cluster_size.size() <<", count= " << count << endl;
	for(unsigned int k=0; k<cluster_size.size(); k++)
	{
		//cout <<"component size= " << cluster_size[k] << endl;
		unsigned long long buf = nC2(cluster_size[k]);
		diff_count += buf;
		count += cluster_size[k];
	}
	count = nC2(count);
	cout << (count-diff_count) << endl;
}

unsigned long long int Graph::nC2(const unsigned int n)
{
	if(n == 1)
		return 0;
	unsigned long long int ret = n;
	ret = ret*(ret-1);
	return ret/2;

}

int main()
{
	Graph obj;
	obj.read_input();
	obj.find_count();
	return 0;
}
