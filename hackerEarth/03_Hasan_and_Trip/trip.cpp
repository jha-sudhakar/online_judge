#include <stdio.h>
#include <limits>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#include <vector>

#include <iostream>
using namespace std;

#define MIN_FLOAT -2 * 100000

class Trip
{
	private:
		//vector <unsigned int[3] > arr;
		vector < vector<double> >  arr;
		vector<double> happy;
		double **table;
		const double  min_double_val;
	public:
		Trip():min_double_val(MIN_FLOAT) {  }
		void readInput();
		double calculateMaxHappiness();
		double calculateMaxHappiness_recursive();
		double calculateMaxHappiness_iterative();

		double calculateMaxHappiness_recursive(unsigned int l, unsigned int r);
		double calculateMaxHappiness_iterative(unsigned int l, unsigned int r);

};


void Trip::readInput()
{
	int n=0;
	while(cin >> n)
	{
		int tmp=0;
		for(int tmp=0; tmp<n; tmp++)
		{
			vector<double> v;//unsigned int v[3];
			v.resize(3);
			cin >> v[0] >> v[1] >> v[2];
			arr.push_back(v);
		}
	}

	const int _size = arr.size();
	table = new double* [_size];
	for(int ii=0; ii<_size; ii++)
		table[ii] = new double [_size];

	for(int i=0; i< arr.size(); i++)
		for(int j=0; j< arr.size(); j++)
			table[i][j] = min_double_val;
	//cout<<"\n Read " << arr.size() <<" city's data";
}

double Trip::calculateMaxHappiness()
{
	double ret_val = calculateMaxHappiness_iterative();
	printf("%.6f\n", ret_val);
	return ret_val;
}


double Trip::calculateMaxHappiness_recursive()
{
    const int _size = arr.size();
    table = new double* [_size];
    for(int ii=0; ii<_size; ii++)
        table[ii] = new double [_size];

    for(int i=0; i< arr.size(); i++)
        for(int j=0; j< arr.size(); j++)
            table[i][j] = min_double_val;

	return calculateMaxHappiness_recursive(0, arr.size()-1) + arr[0][2];
}

double Trip::calculateMaxHappiness_recursive(unsigned int l, unsigned int r)
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
        return min_double_val;
    }  

/*
	if(table[l][r] >  min_double_val+1)
	{
		return table[l][r];
	}
*/
	if (l+1 == r)
	{
		double dist = sqrt(pow(arr[r][0]-arr[l][0], 2.0) + pow(arr[r][1]-arr[l][1], 2.0));
		table[l][r] = arr[r][2] - dist;
		return arr[r][2] - dist;

	} else if (l+2 == r)
	{
		double dist2 =  arr[r][2] - sqrt(pow(arr[r][0]-arr[l][0], 2.0) + pow(arr[r][1]-arr[l][1], 2.0));
		double dist1A = arr[r-1][2] - sqrt(pow(arr[r-1][0]-arr[l][0], 2.0) + pow(arr[r-1][1]-arr[l][1], 2.0));
		double dist1B = arr[r][2] - sqrt(pow(arr[r][0]-arr[r-1][0], 2.0) + pow(arr[r][1]-arr[r-1][1], 2.0));
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

	double max_happiness = 0.0;
	double val1 = calculateMaxHappiness_recursive(l,r-1) + calculateMaxHappiness_recursive(r-1, r);
	double val2 = calculateMaxHappiness_recursive(l,r-2) + calculateMaxHappiness_recursive(r-2, r);
	max_happiness = val1 > val2 ? val1:val2;
	//cout<<"\n Max hapiness = " << max_happiness;;	
	table[l][r] = max_happiness;
	return max_happiness;
}


double Trip::calculateMaxHappiness_iterative()
{
	happy.resize(arr.size());
	for(int i=0; i< arr.size(); i++)
	{
		happy[i] = min_double_val;
	}
	happy[0] = double(arr[0][2]); // F value for 1st place;
	if(arr.size() == 1)
	{
		return happy[0];
	}
	return calculateMaxHappiness_iterative(1,arr.size()-1);
}


double Trip::calculateMaxHappiness_iterative(unsigned int l, unsigned int r)
{
	//cout<<"Max happiness at " << 0 << " = " << happy[0] << endl;
	for(int i=l; i<=r; i++)
	{
		double max_happy = min_double_val;
		for(int j=0; j<i; j++)
		{
			double dist = sqrt(pow(arr[i][0]-arr[j][0], 2.0) + pow(arr[i][1]-arr[j][1], 2.0));
			double tmp = arr[i][2] - dist + happy[j];
			//cout<<"Happiness to " <<i <<" via " << j <<" = " << tmp <<" max so far = " << max_happy << endl;
			if(tmp > max_happy) { max_happy = tmp; }
		}		
		happy[i] = max_happy;
		//cout<<"Max happiness at " << i << " = " << happy[i] << endl;
	}
	return happy[r];
}


int main()
{
	Trip obj;
	obj.readInput();
	double retval = obj.calculateMaxHappiness();
	//cout<<"\n Return value = " << retval;
	

	//cout<<endl;
	return 0;
}
