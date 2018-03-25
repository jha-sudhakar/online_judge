#include<stdlib.h>

#include<iostream>
using namespace std;

#define MAX 100000
unsigned int arr[MAX][2];

struct node
{
	unsigned int data;
	node* next;
	node(unsigned int _data) { data = _data; next = NULL;}
	node() { data = 0; next = NULL;}
};

class LCA
{
	private:
		unsigned int N, M, m_count;
		node** vertex;
		unsigned int* m_arr;
		bool print_done;
	public:
		void read_input();
		void build_dist_to_parent(unsigned int v, node* child);
};

void LCA::read_input()
{
	print_done = false;
	m_count=0;
	cin >> N;
	vertex = new node* [N];
	m_arr = new unsigned int[N];
	for(unsigned int i=0; i<N; i++)
	{	
		vertex[i] = NULL;
		m_arr[i] = 0;
	}
	unsigned int parent;
	for(unsigned int i=1; i<N; i++)
	{
		cin >> parent;
		node* child = new node(i);
		child->next = vertex[parent];
		vertex[parent] = child;
	}

	cin >> M;
	unsigned int m_buf;
	for(unsigned int i=0; i<M; i++)
	{
		cin >> m_buf;
		if(m_buf == 0)
		{
			cout << 0 << endl;
			return;
		}
		m_arr[m_buf] = 1;
	}

	build_dist_to_parent(0, vertex[0]);
}

void LCA::build_dist_to_parent(unsigned int v, node* child)
{
	unsigned int my_count = m_count;
	while(child != NULL)
	{
		build_dist_to_parent(child->data, vertex[child->data]);
		child = child->next;
	}
	
	if(m_arr[v] == 1)
	{
		m_count++;
	}
	if(M == m_count)
	{
		if(my_count == 0 && print_done == false)
		{
			cout << v << endl;
			//print_done = true;
			exit(0);
		}
		return;
	}

}

int main()
{
	LCA obj;
	obj.read_input();
	return 0;
}