#include<assert.h>

#include <algorithm> 
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Upgrade
{
	private:
		unsigned int N, Q, root;
		vector<unsigned int> w,h; 
		vector<unsigned int> c_to_p;

		void path_sum(const unsigned int x, const unsigned int y);
		void path_reverse(const unsigned int x, const unsigned int y);
		void build_child_height();
	public:
		void read_input();
		void execute();

};

void Upgrade::read_input()
{
	root = 0;
	cin >> N >> Q;
	w.resize(N+1);
	h.resize(N+1);
	c_to_p.resize(N+1);

	c_to_p[0] = 0;
	w[0] = h[0]= 0;

	unsigned int buf;
	for(unsigned int i=1; i<=N; i++)
	{
		cin >> buf;
		w[i] = buf;
		c_to_p[i] = h[i] = 0;
	}

	unsigned int parent, child;
	for(unsigned int j=1; j<N; j++)
	{
		cin >> parent >> child;
		c_to_p[child] = parent;
	}
	
	for(unsigned int j=1; j<=N; j++)
	{
		if(c_to_p[j] == 0)
		{
			root = j;
			break;
		}
	}
	if(root == 0)
		assert(false);
#if DBG
	cout << "Root= " << root << endl;
#endif
}



void Upgrade::build_child_height()
{
	h[root] = 1;
	for(unsigned int i=1;i<=N; i++)
	{
		if(h[i] != 0)
			continue;
		vector<unsigned int> path;
		unsigned int cur = i;
		while(h[cur] == 0)
		{
			path.push_back(cur);
			cur = c_to_p[cur]; // Go to its parent;
		}
		unsigned int h_start = h[cur];
		for(unsigned int k=path.size(); k>0; k--)
		{
			//h_start++;
			h[path[k-1]] = ++h_start;
		}
	}
#if DBG
	cout << endl;
	for(unsigned int i=1; i<=N; i++)
		cout << "Node= " << i << ",\t Height= " << h[i] << endl;
#endif

}

void Upgrade::path_sum(const unsigned int x, const unsigned int y)
{
	unsigned int path_sum = 0;
	if(x == y)
	{
		cout << w[x] << endl;
		return;
	}

	unsigned int min_node, max_node;
	if(h[x] <=h[y])
	{
		min_node = x;
		max_node = y;
	}
	else
	{
		min_node = y;
		max_node = x;
	}
	
	while(h[max_node] != h[min_node])
	{
		path_sum += w[max_node];
		max_node = c_to_p[max_node];
	}

	while(max_node != min_node)
	{
		path_sum += w[max_node];
		max_node = c_to_p[max_node];

		path_sum += w[min_node];
		min_node = c_to_p[min_node];
	}

	path_sum += w[max_node]; // Weight of common node is added.
	cout << path_sum << endl;
}		

void Upgrade::path_reverse(const unsigned int x, const unsigned int y)
{
	if(x == y)
		return;	

	vector<unsigned int> minh_path, maxh_path;
	unsigned int min_node, max_node;
	if(h[x] <=h[y])
	{
		min_node = x;
		max_node = y;
	}
	else
	{
		min_node = y;
		max_node = x;
	}
	
	while(h[max_node] != h[min_node])
	{
		maxh_path.push_back(max_node);
		max_node = c_to_p[max_node];
	}

	while(max_node != min_node)
	{
		maxh_path.push_back(max_node);
		max_node = c_to_p[max_node];

		minh_path.push_back(min_node);
		min_node = c_to_p[min_node];
	}
	maxh_path.push_back(max_node); // Common node is added to longer path.
	
	// Now merge the smaller vector to bigger one.
	for(unsigned int k=minh_path.size(); k>0; k--)
	{
		maxh_path.push_back(minh_path[k-1]);
	}

	unsigned int i=0, j=maxh_path.size()-1;
	while(i<j)
	{
		unsigned int tmp = w[maxh_path[i]];
		w[maxh_path[i]] = w[maxh_path[j]];;
		w[maxh_path[j]] = tmp;
		i++; j--;
	}

}

void Upgrade::execute()
{
	read_input();
	build_child_height();
	string str;
	unsigned int l1, l2;
	for(unsigned int i=0; i<Q; i++)
	{
		cin >> str;
		cin >> l1 >> l2;
#if DBG
		cout <<"Operation= #" << str << "#" << ", arg1= " << l1 << ", arg2= " << l2 << endl;
#endif
		if(str[0] == 'R')
		{
			path_reverse(l1, l2);
		}
		else
		{
			path_sum(l1, l2);
		}
	}
}

int main()
{
Upgrade obj;
obj.execute();
return 0;
}
