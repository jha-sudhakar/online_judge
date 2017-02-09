#include<assert.h>

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Upgrade
{
	private:
		unsigned int N, Q, root;
		vector<unsigned int> w,c_to_p;;
		
		void path_sum(const unsigned int x, const unsigned int y);
		void path_reverse(const unsigned int x, const unsigned int y);
	public:
		void read_input();
		void execute();

};

void Upgrade::read_input()
{
	root = 0;
	cin >> N >> Q;
	w.push_back(0);

	c_to_p.resize(N+1);
	c_to_p[0] = 0;

	unsigned int buf;
	for(unsigned int i=1; i<=N; i++)
	{
		cin >> buf;
		w.push_back(buf);
		c_to_p[i] = 0;
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
	//cout << "Root= " << root << endl;
}


void Upgrade::path_sum(const unsigned int x, const unsigned int y)
{
	//cout <<"Hello " << __LINE__ << endl;	
	vector<unsigned int> path_x, path_y;
	unsigned int node = 0, sum_x=0, sum_y=0;

	node = x;
	while(node != root)
	{
		path_x.push_back(node);
		sum_x += w[node];
		node = c_to_p[node];
	}
	path_x.push_back(root);
	sum_x += w[root];

	//cout <<"Hello " << __LINE__ << endl;	
	node = y;
	while(node != root)
	{
		path_y.push_back(node);
		sum_y += w[node];
		node = c_to_p[node];
	}
	path_y.push_back(root);
	sum_y += w[root];

#if DBG
	cout <<"Hello " << __LINE__ << endl;	
	cout <<"path_x="; for(unsigned int p=0; p<path_x.size(); p++) cout <<" " << path_x[p];
	cout << endl;
	cout <<"path_y="; for(unsigned int p=0; p<path_y.size(); p++) cout <<" " << path_y[p];
	cout << endl;
#endif

	unsigned int i=0;
	unsigned int prev_node = 0;
	while((i<path_x.size()) && (i<path_y.size()) && (path_x[path_x.size()-1-i] == path_y[path_y.size()-1-i]))
	{
		sum_x -= w[path_x[path_x.size()-1-i]];
		sum_y -= w[path_y[path_y.size()-1-i]];
		i++;
	}
	//cout <<"Hello " << __LINE__ << endl;	
	cout << (sum_x + sum_y + w[path_x[path_x.size()-1-(i-1)]]) << endl;
	//cout <<"Hello " << __LINE__ << endl;	
}


void Upgrade::path_reverse(const unsigned int x, const unsigned int y)
{
	vector<unsigned int> path_all, path_x, path_y;
	unsigned int node = x;
	while(node != root)
	{
		path_x.push_back(node);
		node = c_to_p[node];
	}
	path_x.push_back(root);
	node = y;
	while(node != root)
	{
		path_y.push_back(node);
		node = c_to_p[node];
	}
	path_y.push_back(root);

#if DBG
	cout <<"Hello " << __LINE__ << endl;	
	cout <<"path_x="; for(unsigned int p=0; p<path_x.size(); p++) cout <<" " << path_x[p];
	cout << endl;
	cout <<"path_y="; for(unsigned int p=0; p<path_y.size(); p++) cout <<" " << path_y[p];
	cout << endl;
#endif

	unsigned int i=0;
	while((i<path_x.size()) && (i<path_y.size()) && (path_x[path_x.size()-1-i] == path_y[path_y.size()-1-i]))
	{
		i++;
	}

	path_all.reserve(path_x.size()+ path_y.size()+ 4- 2*(i));
	long int max_index = path_x.size();
	for(long int  k=0; k>=0 && k<=max_index-1-i; k++)
	{
		path_all.push_back(path_x[k]);
	} 
	path_all.push_back(path_x[path_x.size()-1-(i-1)]);
	for(long int k=path_y.size()-1-i; k>=0; k--)
	{
		path_all.push_back(path_y[k]);
	} 
	
#if DBG
	cout <<"Hello " << __LINE__ << endl;	
	cout <<"path_all="; for(unsigned int p=0; p<path_all.size(); p++) cout <<" " << path_all[p];
	cout << endl;
#endif


	unsigned int n1=0, n2=path_all.size()-1;
	while(n1<n2)
	{
		unsigned int tmp = w[path_all[n1]];
		w[path_all[n1]] = w[path_all[n2]];
		w[path_all[n2]] = tmp;
		n1++; n2--;
	}
}



void Upgrade::execute()
{
	read_input();
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
