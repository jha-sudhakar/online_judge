#include<vector>
#include<string>
#include<iostream>
using namespace std;

enum DIR
{
	LEFT,
	UP,
	RIGHT,
	DOWN,
	OFF
};

struct pos
{
	unsigned int x, y;
	DIR dir; // Clockwise direction Left=1,Up=2, RIGHT=3, DOWN=4
	//pos(unsigned int _x, unsigned int _y) { x=_x;y=_y; dir = OFF;}
	pos(unsigned int _x, unsigned int _y, DIR _dir) { x=_x;y=_y; dir = _dir;}
};

class Solution 
{
	public:
		void process_input();
		bool exist(vector< vector<char> >& board, string word); 
};

void Solution::process_input()
{
	vector< vector<char> >board;

	string st1= string("ABCE");
	vector<char> buf1(st1.begin(), st1.end());

	st1 = string("SFES");
	vector<char> buf2(st1.begin(), st1.end());

	st1 = string("ADEE");
	vector<char> buf3(st1.begin(), st1.end());

	board.push_back(buf1);
	board.push_back(buf2);
	board.push_back(buf3);

	string word("ABCEFSADEESE");
	cout << exist(board, word) << endl;
}

bool Solution::exist(vector< vector<char> >& board, string word)
{

	unsigned int m = board.size();
	unsigned int n = board[0].size();
	unsigned int wlen = word.size();
	vector<pos> start_pos;

	bool is_visited[m][n];
	for(unsigned int i=0; i<m; i++)
	{	for(unsigned int j=0; j<n; j++)
		{
			is_visited[i][j] = false;
			if(board[i][j] == word[0])
				start_pos.push_back(pos(i,j, OFF));
		}	
	}

	for(unsigned int i=0; i<start_pos.size(); i++)
	{
		is_visited[start_pos[i].x][start_pos[i].y] = true;
		vector<pos> path;
		path.push_back(pos(start_pos[i].x, start_pos[i].y, LEFT));

		while(!path.empty())
		{
/*
			cout <<"vector= "; 
			for(int i=0; i<path.size(); i++) 
				cout << board[path[i].x][path[i].y];
			cout << "   ,x= " << path[path.size()-1].x <<",y= " << path[path.size()-1].y <<",dir= " << path[path.size()-1].dir;	
			cout << endl;
*/
			pos& cur_pos = path[path.size()-1];
			int x= cur_pos.x;
			int y = cur_pos.y;
			//DIR dir = cur_pos.dir;

			if(path.size() == word.size())
				return true;
			
			if(cur_pos.dir == LEFT)
			{
				if(y-1>=0 && board[x][y-1] == word[path.size()] && is_visited[x][y-1] == false)
				{	
					cur_pos.dir = UP;
					path.push_back(pos(x,y-1,LEFT));
					is_visited[x][y-1] = true;
				} else
				{
					cur_pos.dir = UP;
					continue;
				}

			} else if(cur_pos.dir == UP) 
			{
				if(x-1>=0 && board[x-1][y] == word[path.size()] && is_visited[x-1][y] == false)
				{	
					cur_pos.dir = RIGHT;
					path.push_back(pos(x-1,y,LEFT));
					is_visited[x-1][y] = true;
				} else
				{
					cur_pos.dir = RIGHT;
					continue;

				}
			} else if(cur_pos.dir == RIGHT) 
			{
				if(y+1<n && board[x][y+1] == word[path.size()] && is_visited[x][y+1] == false)
				{		
					cur_pos.dir = DOWN;
					path.push_back(pos(x,y+1,LEFT));
					is_visited[x][y+1] = true;
				} else
				{
					cur_pos.dir = DOWN;
					continue;
				}

			} else if(cur_pos.dir == DOWN) 
			{
				if(x+1<m && board[x+1][y] == word[path.size()] && is_visited[x+1][y] == false)
				{	
					cur_pos.dir = OFF;
					path.push_back(pos(x+1, y ,LEFT));
					is_visited[x+1][y] = true;
				} else
				{
					cur_pos.dir = OFF;
					continue;
				}

			} else
			{
				is_visited[x][y] = false;
				path.pop_back();
			}
		}

	}
	return false;
}


int main()
{
Solution obj;
obj.process_input();
return 0;
}
