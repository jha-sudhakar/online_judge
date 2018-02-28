#include<iostream>
using namespace std;

class Solution
{
	public:
		int uniquePaths(int m, int n)
		{
			int** val = new int* [m+1];
			for(int i=0; i<=m; i++)
				val[i] = new int [n+1];

/*
			for(int i=0; i<=m; i++)
				va[i][0] = 0;
			for(int i=0; i<=n; i++)
				va[0][i] = 0;
*/					
			for(int i=0; i<=m; i++)
				val[i][1] = 1;
			for(int i=0; i<=n; i++)
				val[1][i] = 1;

			for(int i=2; i<=m; i++)
			{
				for(int j=2; j<=n; j++)
				{
					val[i][j] = val[i-1][j] + val[i][j-1];
				}
			}

			int ret_val = val[m][n];

			for(int i=0; i<=m; i++)
				delete [] val[i];
			delete [] val;
			
			return ret_val;
		}
};
