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
		bool* is_visited;
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
	is_visited = new bool[N];
	vertex = new node* [N];
	m_arr = new unsigned int[N];
	for(unsigned int i=0; i<N; i++)
	{	
		vertex[i] = NULL;
		is_visited[i] = false;
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
	if(child == NULL)
		return;
	unsigned int my_count = m_count;
	if(m_arr[v] == 1)
	if(is_visited[v] == false && m_count != M)
	{
		is_visited[v] = true;
		m_count++;
		if(M == m_count)
		{
			if(my_count == 0 && print_done == false)
			{
				cout << v << endl;
				print_done = true;
			}
			return;
		}
	}
	if(v == 4)
		cout <<"m_count = " << m_count << endl;
		
	while(child != NULL)
	{
		if(v == 4)
			cout <<"m_count = " << m_count << endl;

		if(m_arr[child->data] == 1)
		{
			if(is_visited[child->data] == false && m_count != M)
			{
				is_visited[child->data] = true;
				m_count++;
				if(v == 4){
					cout <<"M= " << M <<", m_count = " << m_count << endl;
				}

				if(M == m_count)
				{
					if(my_count == 0 && print_done == false)
					{
						cout << v << endl;
						print_done = true;
					}
					return;
				}
				
			}
		}
		build_dist_to_parent(child->data, vertex[child->data]);
		if(v == 4)
			cout <<"m_count = " << m_count << endl;
		if(M == m_count)
		{
			if(my_count == 0 && print_done == false)
			{
				cout << v << endl;
				print_done = true;
			}
			return;
		}
		child = child->next;
	}
}

int main()
{
	LCA obj;
	obj.read_input();
	return 0;
}