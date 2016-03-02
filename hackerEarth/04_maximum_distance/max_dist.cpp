#include <stdio.h>
	
#include <iomanip>
#include <vector>
#include <iostream>
using namespace std;

class max_speed
{

	private:
		unsigned int n, fuel_left;;
		vector<unsigned int > speed;
		vector<unsigned int> fuel;
		

	public:
	void read_input();
	double calculate_max_dist();
};


void max_speed::read_input()
{
	while(cin >> n)
	{
		speed.clear(); speed.resize(n);
		fuel.clear();  fuel.resize(n);
		for(int i=0; i<n; i++)
		{
			cin >> speed[i];
		}

		for(int i=0; i<n; i++)
		{
			cin >> fuel[i];
		}
		
		cin >> fuel_left;

		double max_dist = calculate_max_dist();
		//cout<<"Max dist = " << setprecision(3) << max_dist << endl;
		printf("%.3f\n", max_dist);
		//return max_dist;
	}
}

double max_speed::calculate_max_dist()
{
	//double max_dist = double(fuel_left) * double(speed[0]) / (double(fuel[0]));
	double max_dist = double(speed[0]) / (double(fuel[0]));
	for(int i=1; i<n; i++)
	{
		//double cur_dist = double(fuel_left) * double(speed[i]) / (double(fuel[i]));
		double cur_dist = double(speed[i]) / (double(fuel[i]));
		if(cur_dist > max_dist)
			max_dist = cur_dist;
	}
	max_dist = max_dist * double(fuel_left);
	return max_dist;
}

int main()
{
	max_speed obj;
	obj.read_input();


	return 0;
}
