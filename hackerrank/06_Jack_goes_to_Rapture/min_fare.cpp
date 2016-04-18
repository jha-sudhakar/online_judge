#include<limits.h>
#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

struct e
{
unsigned int v;
unsigned int c;
e(unsigned int _v, unsigned int _c) { v=_v; c=_c;}
};

class min_fare
{
	private:
		unsigned int N, E;
		vector< vector<e> >g;
		vector<long long int> min_val;
		vector<bool> is_inq;
	public:
		void process_input();
		void get_min_fare_for_N();
		bool find_min_fare(vector<unsigned int>& cur_st);
};

void min_fare::process_input()
{
	cin >> N >> E;
	g.resize(N);
	min_val.resize(N);
	is_inq.resize(N);
	for(int i=0; i<N; i++)
	{
		min_val[i] = UINT_MAX;
		is_inq[i] = false;
	}
	for(unsigned int i=0; i<E; i++)
	{
		unsigned int u, v, c;
		cin >> u >> v >> c;
		u--;v--;
		g[u].push_back(e(v,c));
		g[v].push_back(e(u,c));
	}

	get_min_fare_for_N();
}

void min_fare::get_min_fare_for_N()
{
	for(unsigned int i=0; i<N; i++)
	{
		min_val[0] = 0;
		vector<unsigned int> cur_st;
		cur_st.push_back(0);
		for(unsigned int i=0; i<N; i++) is_inq[i] = false;
		is_inq[0] = true;
		bool is_changed = find_min_fare(cur_st);
		if(is_changed == false)
			break;
	}
	//for(int i=0; i<N; i++) { cout<<"[" << i+1 <<"]= "<< min_val[i] << endl; }
	if(min_val[N-1] == UINT_MAX)
		cout << "NO PATH EXISTS" << endl;
	else	
		cout << min_val[N-1] << endl;
}

bool min_fare::find_min_fare(vector<unsigned int>& cur_st)
{
	bool is_changed = false;

	while(cur_st.size())
	{
		unsigned int st = cur_st[cur_st.size()-1];
		cur_st.pop_back();
		//is_inq[st] = false;
		for(unsigned int i=0; i<g[st].size(); i++)
		{
			//bool is_changed = false;
			long long int buf = g[st][i].c;
			if(buf-min_val[st] <0)
			{
				if( min_val[st] <  min_val[g[st][i].v])
				{
					min_val[g[st][i].v] = min_val[st]; // -ve so its free ride and hance previous fare is cur now.
					is_changed = true;
				}	
			} else
			{
				if (buf < min_val[g[st][i].v])
				{
					min_val[g[st][i].v] = buf;
					is_changed = true;
				}	

			}
			//if(is_inq[g[st][i].v] == false && is_changed == true)
			if(is_inq[g[st][i].v] == false)
			{
				cur_st.push_back(g[st][i].v);
				is_inq[g[st][i].v] = true;
			}	
		}
	}
	return is_changed;
}



int main()
{
min_fare obj;
obj.process_input();
return 0;
}
