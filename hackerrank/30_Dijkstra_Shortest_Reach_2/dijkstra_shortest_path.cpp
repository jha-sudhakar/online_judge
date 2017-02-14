#include<limits.h>
#include<stdio.h>

#include<assert.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;

#define MAX 3001
#define MAX_W 1000000000
//---------------------- jha1 ---------------------------------
struct node
{
	unsigned int key;
	unsigned int index;
	node(unsigned int _key, unsigned int _index) { key=_key; index=_index;}
	node() { }
};


class PQ
{
	private:
		node arr[MAX];
		unsigned int addr[MAX];		
		unsigned int size, start;
		
	private:
		void swap_val(node& val1, node& val2);
		void send_up(unsigned int pos);
		void send_down(unsigned int pos);
	public:
		PQ() { srand(time(NULL)); size= 0; start = 1; }
		const unsigned int get_size() { return size; }
		void read_input();
		void build_heap(const unsigned int L);
		void insert(const node ele);
		void update_key(unsigned int new_key_val, unsigned int index);	
		const node root();
		const node pop_root();
		void reset() { size= 0; start = 1;}
};

void PQ::swap_val(node& val1, node& val2)
{
	node buf = val1;
	val1 = val2;
	val2 = buf;
}

void PQ::read_input()
{
	//fill random input

}
void PQ::build_heap(const unsigned int L)
{
	for(unsigned int i=1; i<=L; i++)
	{
		size++;
		arr[size] = node(MAX_W, i);
    	addr[i] = size;
	}
}

void PQ::send_up(unsigned int pos)
{
	while(pos > start)
	{
		unsigned int parent_pos = pos/2;
		if( arr[parent_pos].key > arr[pos].key)
		{
			addr[arr[pos].index] = parent_pos;
			addr[arr[parent_pos].index] = pos;
			swap_val(arr[pos], arr[parent_pos]);
			pos = parent_pos;
		}
		else
		{
			break;
		}
	}
}

void PQ::send_down(unsigned int pos)
{
	while(pos < size)
	{
		unsigned int child_pos = pos*2;
		if(child_pos > size)
			return;
		if(size>= child_pos+1 && arr[child_pos].key > arr[child_pos+1].key)
		{
			child_pos++;
		}
		if((child_pos > size) || (arr[pos].key <= arr[child_pos].key))
		{		
			break;
		}
		else
		{
			addr[arr[pos].index] = child_pos;
			addr[arr[child_pos].index] = pos;
			swap_val(arr[pos], arr[child_pos]);
			pos = child_pos;
		}
	}
}

void PQ::insert(const node ele)
{
	size++;
	arr[size] = ele;
	addr[ele.index] = size;
	send_up(size);
}

void PQ::update_key(unsigned int new_key_val, unsigned int index)
{
	unsigned int pos_in_pq = addr[index];
	arr[pos_in_pq].key = new_key_val;
	send_up(pos_in_pq);
}


const node PQ::pop_root()
{
	if(size == 0)
		return node();
	node buf = arr[start];
	addr[arr[start].index] = 0;
	arr[start] = arr[size];
	size--;

	send_down(start);
	return buf;
}

const node PQ::root()
{
	if(size != 0)
		return arr[start];
	else
		return node();
}

#if 0
int main()
{
PQ obj;
obj.test_automation();
return 0;
}
#endif
//---------------------- jha2 ---------------------------------


struct e
{
	unsigned int v,w;
	e(unsigned int _v,unsigned int _w) { v=_v;w=_w;}
};


class ssp
{
	private:
		unsigned int N,M,S,T;
		vector< vector<e> > graph;
		void find_shortest_paths();
		unsigned int *dist;
		PQ pq;		
	public:
		void read_input();
};

void ssp::read_input()
{
	cin >> T;
	graph.reserve(3005);
	unsigned int x,y,r;
	for(unsigned int i=0; i<T; i++)
	{
		pq.reset();
		//cin >> N >> M;
		scanf("%u %u", &N, &M);
		dist = new unsigned int[N+1];
		for(unsigned int j=0; j<=N; j++) dist[j] = MAX_W;
		graph.resize(N+1);
		for(unsigned int j=0; j<M; j++)
		{
			//cin >> x >> y >> r;
			scanf("%u %u %u", &x, &y, &r);
			graph[x].push_back(e(y,r));
			graph[y].push_back(e(x,r));
		}
		//cin >> S;
		scanf("%u", &S);
		find_shortest_paths();	
		graph.clear();
		delete [] dist;
	}
}


void ssp::find_shortest_paths()
{
	pq.build_heap(N);
	pq.update_key(0,S);	

	while(pq.get_size())
	{
		node top = pq.pop_root();
		if(top.key == MAX_W)
			break;
		dist[top.index] = top.key;
		for(unsigned int k=0; k<graph[top.index].size(); k++)
		{
			if(dist[top.index] + graph[top.index][k].w < dist[graph[top.index][k].v])
			{
				pq.update_key(dist[top.index]+graph[top.index][k].w, graph[top.index][k].v);
				dist[graph[top.index][k].v] = dist[top.index]+graph[top.index][k].w;
			}
		}
	}
	for(unsigned int p=1; p<=N; p++)
	{
		if(p == S) 
			continue;
		else if(dist[p] == MAX_W)
			printf("%d ", -1);//cout << -1 << " ";
		else
			printf("%u ", dist[p]);//cout << dist[p] << " ";
	}
	printf("\n");//cout <<endl;
}

int main()
{
ssp obj;
obj.read_input();
return 0;
}
