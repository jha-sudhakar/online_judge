#include <vector>
#include<algorithm>
#include <iostream>
#include<sstream>
using namespace std;

class Years
{
	private:
		unsigned int N;
		vector<unsigned int> dob;
		vector<unsigned int> dod;

	public: 
		void read_input();
		void execute();
};

void Years::read_input()
{
	string line_str;
	getline(cin, line_str);
	stringstream readSize(line_str);
	readSize >> N;
	
	dob.reserve(N);
	dod.reserve(N);
	unsigned int b=0, d=0;
	for(unsigned int i=0; i<N; i++)
	{
		getline(cin, line_str);
		//cout << "Read line = " << line_str << endl;
		stringstream stream(line_str);
		stream >> b;
		stream >> d;
		//cout <<"Birth= " << b <<", Death= " << d <<"\n";
		dob.push_back(b);
		dod.push_back(d);
	}
	//cout <<"\n";
}


void Years::execute()
{
	sort(dob.begin(), dob.end());
	sort(dod.begin(), dod.end());
	unsigned int pos_b=0, pos_d = 0;
	unsigned int alive = 0;
	unsigned int max_year = dob[0], max_alive = 0;;
	//cout <<"max year = " << max_year << "\n";
	while(pos_b < dob.size() && pos_d < dod.size())
	{
		if(dob[pos_b] == dod[pos_d])
		{
			pos_b++; pos_d++;
		}
		else if(dob[pos_b] < dod[pos_d])
		{
			alive++;
			if(alive > max_alive)
			{ 	
				max_alive = alive;
				max_year = dob[pos_b];
				//cout <<"Max year is being changed\n";
			}
			pos_b++;
		}
		else
		{
			alive--;
			pos_d++;
		}
	}
	cout << max_year << " " << max_alive <<"\n";
}

int main()
{
	Years obj;
	obj.read_input();
	obj.execute();
	return 0;
}
