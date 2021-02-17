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
	avec.reserve(N+1);
	bvec.reserve(N+1);

	getline(cin, line_str);
	stringstream ss2(line_str);
	//ss << line_str;
	for(unsigned int i=0; i<N; i++)
	{
		ss2 >> tmp;
		//cout <<"Input = " << tmp <<  endl;
		avec[tmp] = i;
	}
	
	getline(cin, line_str);
	stringstream ss3(line_str);
	//ss << line_str;
	for(unsigned int i=0; i<N; i++)
	{
		ss3 >> tmp;
		//cout <<"Input = " << tmp <<  endl;
		bvec[tmp] = i;
	}
}

void Sol::execute()
{
	unsigned int max_match = 0;
	unsigned int* shift = new unsigned int[N];
	for(unsigned int i=0; i<N; i++)
		shift[i] = 0;

	for(unsigned int index = 1; index<=N; index++)
	{
		unsigned int pos1 = avec[index];
		unsigned int pos2 = bvec[index];
		unsigned int rotate  = 0;
		if(pos2 > pos1)
			rotate = pos2-pos1;
		else if(pos2 < pos1)
			rotate = N-(pos1-pos2);

		shift[rotate]++;
		if(shift[rotate] > max_match)
			max_match = shift[rotate];

	}
	delete [] shift;
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
