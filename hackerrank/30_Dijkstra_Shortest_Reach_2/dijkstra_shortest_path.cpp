#include<limits.h>

#include<assert.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;

#define MAX 3001

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
		void test_automation();
		const unsigned int get_size() { return size; }
		void read_input();
		void build_heap(const unsigned int L);
		void insert(const node ele);
		void update_key(unsigned int new_key_val, unsigned int index);	
		const node root();
		const node pop_root();
};

void PQ::test_automation()
{

	unsigned int l=0,loop = 20000;
	while(l++<loop)
	{
		unsigned int counter=1;
		unsigned int rand_size = 20 + rand()%500;
		cout <<"\nRunning loop " << l << ", op-count= " << rand_size << endl;
		vector<node> vec;
		cout <<"\nInsert/pop elements\n";
		for(unsigned int i=0; i<rand_size; i++)
		{
			unsigned int num = 10+ rand()%50;
			if(rand()%3)
			{
				
				vec.push_back(node(num,counter));
				insert(node(num,counter));
				cout << num << ", ";
				counter++;
			}
			else if(get_size())
			{
				node tmp = pop_root();
				unsigned int pos=vec.size()+1;
				for(unsigned int k=0; k<vec.size(); k++)
				{
					if(vec[k].key < tmp.key)
						assert(false);
					else if(vec[k].key == tmp.key && vec[k].index == tmp.index)
						 pos = k;
				}
				if(pos >= vec.size()) assert(false);
				vec.erase(vec.begin()+pos);
			}
			if(get_size() != vec.size())
				assert(false);
		}
		
		cout <<"\nMy Sorted elements\n";
		
		while(get_size())
		{
			node tmp = pop_root();
			unsigned int pos=vec.size()+1;
			for(unsigned int k=0; k<vec.size(); k++)
			{
				if(vec[k].key < tmp.key)
					assert(false);
				else if(vec[k].key == tmp.key && vec[k].index == tmp.index)
					pos = k;
			}
			if(pos >= vec.size()) assert(false);
			vec.erase(vec.begin()+pos);
			cout << tmp.key << ", ";
		
			if(get_size() != vec.size())
			assert(false);
		}
		cout << endl;
		if(get_size() != vec.size())
			assert(false);
	}
}

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
		arr[size] = node(UINT_MAX, i);
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
	unsigned int x,y,r;
	for(unsigned int i=0; i<T; i++)
	{
		cin >> N >> M;
		dist = new unsigned int[N+1];
		for(unsigned int j=0; j<=N; j++) dist[j] = UINT_MAX;
		graph.resize(N+1);
		for(unsigned int j=0; j<M; j++)
		{
			cin >> x >> y >> r;
			graph[x].push_back(e(y,r));
			graph[y].push_back(e(x,r));
		}
		cin >> S;
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
		else if(dist[p] == UINT_MAX)
			cout << -1 << " ";
		else
			cout << dist[p] << " ";
	}
	cout <<endl;
}

int main()
{
ssp obj;
obj.read_input();
return 0;
}
