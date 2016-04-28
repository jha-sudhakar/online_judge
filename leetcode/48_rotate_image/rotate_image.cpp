#include<time.h>
#include<stdlib.h>

#include<vector>
#include<iostream>
using namespace std;

enum DIRECTION //Clockwise shift;
{
RIGHT,
DOWN,
LEFT,
UP
};

class Solution 
{
	private:
		DIRECTION d;
		int start, end;
		void get_new_pos(int &x, int &y, int offset);
	public:
    	void rotate(vector<vector<int> >& matrix);
};


void Solution::get_new_pos(int &x, int &y, int offset)
{
	switch (d)
	{
		case RIGHT:
				y = y+offset;
				if(y > end) { offset= y-end; y = end; d = DOWN; get_new_pos(x,y, offset); }
				break;
		case DOWN:
				x = x+offset;
				if(x > end) { offset= x-end; x = end; d = LEFT; get_new_pos(x,y, offset);}
				break;
		case LEFT:
				y = y-offset;
				if(y < start) { offset= start-y; y = start; d = UP; get_new_pos(x,y, offset);}
				break;
		case UP:
				x = x-offset;
				if(x < start) { offset= start-x; x = start; d = RIGHT; get_new_pos(x,y,offset);}
				break;
	}

}


void Solution::rotate(vector<vector<int> >&v )
{
	const int n = v.size();
	start = -1;
	end = n;
	for(int count = n; count>1; count -=2)
	{
		d = RIGHT;
		start++; end--;
		
		for(int i=start; i<end; i++)
		{
			int cur_row= start, cur_col= i;
			int next_val, cur_val = v[cur_row][cur_col];
			for(int j=1; j<5; j++)
			{
				//cout<<"Current row= " << cur_row <<", col= " << cur_col << "       ";
				get_new_pos(cur_row, cur_col, end-start);
				//cout<<"Updated row= " << cur_row <<", col= " << cur_col << ", direction= " << d << endl;
				next_val = v[cur_row][cur_col];
				v[cur_row][cur_col] = cur_val;
				cur_val = next_val;
			}
		}

	}
}



int main()
{
	Solution obj;
	srand(time(NULL));
	int n = 6;
	vector< vector<int> >v; v.resize(n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			int buf = rand()%90;
			buf += 10;
			v[i].push_back(buf);
		}
	}

	cout<<"\n Printing the matrix\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<< v[i][j] << "  ";
		}
		cout << endl;
	}

	obj.rotate(v);

	cout<<"\n Printing the rotated matrix\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<< v[i][j] << "  ";
		}
		cout << endl;
	}

	return 0;
}
