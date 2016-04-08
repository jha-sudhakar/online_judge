#include <stdlib.h>

// Input : X and Y co-ordinates of the points in order. 
// Each point is represented by (X[i], Y[i])
int Solution::coverPoints(vector<int> &x, vector<int> &y)
{

	if(x.size() <2)
	{
		return 0;
	}
	
	int dist = 0;
	int prev_x = x[0];
	int prev_y = y[0];
	for(int i=1; i<x.size(); i++)
	{
		//If points are on the line then one or both value will be zero so the logical expression.
		if(!(abs(x[i]-prev_x) && abs(y[i]-prev_y)))
		{
			dist += abs(x[i]-prev_x) + abs(y[i]-prev_y);
		} else if(abs(x[i]-prev_x) == abs(y[i]-prev_y)) // Diagonal points so diff is same for both points.
		{
			dist += abs(x[i]-prev_x);
		} else
		{
			dist += (abs(x[i]-prev_x) > abs(y[i]-prev_y)?abs(x[i]-prev_x) :abs(y[i]-prev_y));
		}
		prev_x = x[i];
		prev_y = y[i];
	}
	return dist;
}

