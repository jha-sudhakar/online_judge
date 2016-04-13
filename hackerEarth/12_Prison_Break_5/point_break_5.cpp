#include<stdio.h>
#include<stdint.h>

#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define log cout

struct vertex
{
	int v;
	int pos;
	int move; 
	vertex(int _v, int _pos, int _move) { v=_v; pos=_pos; move=_move;}

};

class point_break_5
{
	private:
		int T, N;
		vector< vector<int> > grid;
	public:
		void process_input();
		int count_no_of_paths();

};

void point_break_5::process_input()
{
	cin >> T;
	for(int i=0; i<T; i++)
	{
		int buf;
		cin >> N;
		grid.resize(N);
		for(int j=0; j<N; j++)
		{
			for(int k=0; k<N; k++)
			{
				cin >> buf;
				grid[j].push_back(buf);
			}
		}
		int path_count = count_no_of_paths();
		//cout<<" No of paths = " << path_count << endl;
		cout<< path_count << endl;
		grid.clear();
	}
}

int point_break_5::count_no_of_paths()
{
	unsigned int path_count = 0;
	vector<vertex> stk;
	bool visited[N][N];
	for(int i=0; i<N; i++)
	for(int j=0; j<N; j++)
	{
		visited[i][j] = false;
	}

	if(N == 1 && grid[0][0] == 0)
		return 1;
	if(grid[0][0] == 1)
	{
		return 0;
	} else if (grid[N-1][N-1] == 1)
		return 0;

	stk.push_back(vertex(0,0,0));
	visited[0][0] = true;
	while(stk.size())
	{
		int last= stk.size()-1;
		int pos= stk[last].pos;
		int v = stk[last].v;
		int move = stk[last].move;

		if(pos == N-1 && v == N-1)
		{
#if 0
			cout<<"Path ";
			for(int i=0; i<stk.size(); i++)
				cout<< " -> (" << int(stk[i].v) <<", " << stk[i].pos <<") ";
			cout << endl;
#endif
			path_count++;
			visited[stk[last].v][pos] = false;
			//log<<" Popped " << int(stk[last].v) << endl;
			stk.pop_back();
			//stk[stk.size()-1].move++;
			continue;
		}

		if(pos-1 >=0 && grid[v][pos-1] == 0 && move == 0 && visited[v][pos-1] == false)
		{
			stk[last].move=1;
			visited[v][pos-1] = true;
			stk.push_back(vertex(v,pos-1,0));
		} else if (v-1>=0 && grid[v-1][pos] == 0 && move <= 1 && visited[v-1][pos] == false)
		{
			stk[last].move=2;
			visited[v-1][pos] = true;
			stk.push_back(vertex(v-1,pos,0));
		} else if(pos+1 <N && grid[v][pos+1] == 0 && move <= 2 && visited[v][pos+1] == false)
		{
			stk[last].move=3;
			visited[v][pos+1] = true;
			stk.push_back(vertex(v,pos+1,0));
		} else if(v+1 <N && grid[v+1][pos] == 0 && move <= 3 && visited[v+1][pos] == false)
		{
			stk[last].move=4;
			visited[v+1][pos] = true;
			stk.push_back(vertex(v+1,pos,0));
		} else
		{
			visited[stk[last].v][pos] = false;
			stk.pop_back();
			//stk[stk.size()-1].move++;
		}
	}
	return path_count;
}

int main()
{
	point_break_5 obj1;
	obj1.process_input();
	return 0;
}
