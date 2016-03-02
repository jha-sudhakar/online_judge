#include <stdio.h>
#include <limits>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#include <vector>

#include <iostream>
using namespace std;

class Trip
{
	private:
		//vector <unsigned int[3] > arr;
		vector < vector<float> >  arr;
		float **table;
		const float min_float_val;
	public:
		Trip():min_float_val(numeric_limits<float>::min()) {  }
		void readInput();
		float calculateMaxHappiness();
		float calculateMaxHappiness(unsigned int l, unsigned int r);

};


void Trip::readInput()
{
	int n=0;
	while(cin >> n)
	{
		int tmp=0;
		for(int tmp=0; tmp<n; tmp++)
		{
			vector<float> v;//unsigned int v[3];
			v.resize(3);
			cin >> v[0] >> v[1] >> v[2];
			arr.push_back(v);
		}
	}

	const int _size = arr.size();
	table = new float* [_size];
	for(int ii=0; ii<_size; ii++)
		table[ii] = new float [_size];

	for(int i=0; i< arr.size(); i++)
		for(int j=0; j< arr.size(); j++)
			table[i][j] = min_float_val;
	//cout<<"\n Read " << arr.size() <<" city's data";
}

float Trip::calculateMaxHappiness()
{
	float ret_val = calculateMaxHappiness(0, arr.size()-1) + arr[0][2];
	printf("%.6f\n", ret_val);
	return ret_val;
}

float Trip::calculateMaxHappiness(unsigned int l, unsigned int r)
{

	if(l == r)
	{
		return arr[l][2];
	} else if (l > r)
	{
		assert(false);
		return 0.0;
	}  else if (l<0 or r<0)
    {
        return min_float_val;
    }  

/*
	if(table[l][r] >  min_float_val+1)
	{
		return table[l][r];
	}
*/
	if (l+1 == r)
	{
		float dist = sqrt(pow(arr[r][0]-arr[l][0], 2.0) + pow(arr[r][1]-arr[l][1], 2.0));
		table[l][r] = arr[r][2] - dist;
		return arr[r][2] - dist;

	} else if (l+2 == r)
	{
		float dist2 =  arr[r][2] - sqrt(pow(arr[r][0]-arr[l][0], 2.0) + pow(arr[r][1]-arr[l][1], 2.0));
		float dist1A = arr[r-1][2] - sqrt(pow(arr[r-1][0]-arr[l][0], 2.0) + pow(arr[r-1][1]-arr[l][1], 2.0));
		float dist1B = arr[r][2] - sqrt(pow(arr[r][0]-arr[r-1][0], 2.0) + pow(arr[r][1]-arr[r-1][1], 2.0));
		if(dist2 > dist1A+dist1B)
		{
			table[l][r] = dist2;
			return dist2;
		} else
		{
			 table[l][r] = dist1A+dist1B;
			return dist1A+dist1B;
		}
	}

	float max_happiness = 0.0;
	float val1 = calculateMaxHappiness(l,r-1) + calculateMaxHappiness(r-1, r);
	float val2 = calculateMaxHappiness(l,r-2) + calculateMaxHappiness(r-2, r);
	max_happiness = val1 > val2 ? val1:val2;
	//cout<<"\n Max hapiness = " << max_happiness;;	
	table[l][r] = max_happiness;
	return max_happiness;
}


int main()
{
	Trip obj;
	obj.readInput();
	float retval = obj.calculateMaxHappiness();
	//cout<<"\n Return value = " << retval;
	

	//cout<<endl;
	return 0;
}
