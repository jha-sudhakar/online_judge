#include<vector>
#include<iostream>
using namespace std;

class Solution
{
	public:
    int minDistance(string word1, string word2)
	{
			const int M = word1.size();
			const int N = word2.size();
			int tab[M+1][N+1];

			for(int i=0; i<=M; i++)
				tab[i][0] = i;
			
			for(int i=0; i<=N; i++)
				tab[0][i] = i;
			
			for(int i=1; i<=M; i++)
			{
				for(int j=1; j<=N; j++)
				{
					int min_val = tab[i-1][j-1];
					if(word1[i-1] != word2[j-1])
						min_val++;
					if(min_val > tab[i-1][j]+1)
						min_val = tab[i-1][j]+1;
					if(min_val > tab[i][j-1]+1)
						min_val = tab[i][j-1]+1;
					
					tab[i][j] = min_val;
				}
			}
			return tab[M][N];
    }
};