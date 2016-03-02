
#include <vector>
#include <iostream>
using namespace std;


class Tree
{
	private:
		unsigned int N, root;
		vector< vector<unsigned int> > tree;
		vector<bool> is_visited;
		unsigned long K, _count;
	public:
		void read_input();
		void find_ancestor();
		bool is_it_dead_end(const unsigned int index);
};

void Tree::read_input()
{
	cin >> N >> K;
	tree.resize(N+1);
	is_visited.resize(N+1);
	_count = 0;
	unsigned int arr[N+1];
	for(unsigned int i=0; i<= N; i++)
	{
		arr[i] = 0;
	}

	unsigned int src,dst;
	for(int i=0; i<N-1; i++)
	{
		cin >> src >> dst;
		tree[src].push_back(dst);
		arr[dst] = 1;
	}

	for(unsigned int i=1; i<= N; i++)
	{
		if(arr[i] == 0)
		{
			root = i;
			//cout<<"Root node = " << root << endl;
			break;
		}
	}

	// Find ancestor at max-distance K;
	find_ancestor();
}


bool Tree::is_it_dead_end(const unsigned int index)
{
	if(tree[index].size() == 0)
	{
		return true; // This node does not have any children.
	} else 
	{
		for(int i=0; i<tree[index].size(); i++)
		{
			if(is_visited[tree[index][i]] == false)
				return false;
		}
		return true;
	}
}

void Tree::find_ancestor()
{
	for(unsigned int i=0; i<=N; i++)
		is_visited[i] = false;
	
	vector<unsigned int> path;
	path.push_back(root);

	unsigned int min_val_in_path = N+1;;

	while(path.size() != 0)
	{
		unsigned int val = path[path.size()-1];
		if(is_it_dead_end(val))
		{
			if(val <= K)
			{
			for(unsigned int i=0; i<path.size()-1; i++)
			{
				unsigned long buf1 = val; 
				unsigned long buf2 = path[i]; 
				if(buf1 * buf2 <= K)
				{
					//cout << val << endl;
					//cout<< val <<" * " << path[i] <<" < " << K << endl;
					_count++;
				}
			}
			}

			path.pop_back();
			is_visited[val] = true;
		} else
		{
			for(int i=0; i<tree[val].size(); i++)
			{
				if(is_visited[tree[val][i]] == false)
				{
					path.push_back(tree[val][i]);
					break;
				}
			}
		}
	}

	cout<< _count << endl;
}



int main()
{

Tree obj;
obj.read_input();
return 0;
};
