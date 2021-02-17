#include<vector>
#include <iostream>
#include <sstream>
using namespace std;
class Sol
{
	private:
		unsigned int N;
		vector<unsigned int> avec, bvec;

	public:
		void read_input();
		void execute();
};

void Sol::read_input()
{
	unsigned int tmp;
	string line_str;
	getline(cin, line_str);
	stringstream ss(line_str);
	ss >> N;
	avec.reserve(N);
	bvec.reserve(N);

	getline(cin, line_str);
	stringstream ss2(line_str);
	//ss << line_str;
	for(unsigned int i=0; i<N; i++)
	{
		ss2 >> tmp;
		//cout <<"Input = " << tmp <<  endl;
		avec.push_back(tmp);
	}
	
	getline(cin, line_str);
	stringstream ss3(line_str);
	//ss << line_str;
	for(unsigned int i=0; i<N; i++)
	{
		ss3 >> tmp;
		//cout <<"Input = " << tmp <<  endl;
		bvec.push_back(tmp);
	}
}

void Sol::execute()
{
	unsigned int max_match = 0;
	unsigned int match = 0, next_index = N;
	//cout <<"N = " << N << endl;
	for(unsigned int off = 0; off<N; off++)
	{
		match  = 0;
		//cout <<"\n\nOffset = " << off << endl;
		for(unsigned int index = 0; index<N; index++)
		{
			if(avec[index] == bvec[(index+off)%N])
			{
				//cout << "index: " << index <<"-- Match: " << avec[index] << " == " << bvec[(off+index)%N] << endl;
				match++;
			}
		}
		if(match > max_match)
			max_match = match;
	}
	//cout << endl << max_match <<endl;
	cout << max_match <<endl;
}


int main()
{
	Sol obj;
	obj.read_input();
	obj.execute();
	return 0;
}
