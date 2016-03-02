#include <assert.h>
//#include <unistd.h>
#include <time.h>
#include <vector>
#include <string>
#include <list>
#include <iostream>
using namespace std;

#define V 1999
//#define V 4

class Question
{
	private:
		string buf;
		const int N;
	public:
		void readInput(string& _arg);
		string findAnswer();
		Question(string& _arg, const int _N=V);
		Question(const int _N=V);
		void printInput();
};

void Question::readInput(string& _arg)
{
	buf = buf + _arg;	
}


Question::Question(const int _N):N(_N) { }
Question::Question(string& _arg,const int _N): N(_N) {	readInput(_arg); }

void Question::printInput()
{
	cout<<"\n Printing Input string...\n";
	//cout << endl;
	cout << buf;	
	cout << "###";
}


string Question::findAnswer()
{
	// _buf.erase(_buf.begin()+i);
	vector<char> _buf;
	for(int i=0; i<buf.size(); i++)
	{
		_buf.push_back(buf[i]);
	}

	printInput();
	int arr_pos = 0;
	int old_arr_pos=0;
	while(_buf.size() > 1)
	{
		cout<<"\n Size of string= " << _buf.size();
		old_arr_pos = arr_pos;
		int index = (N-1) % _buf.size();
		if(arr_pos+index >= _buf.size())
		{
			arr_pos = index  -(_buf.size()-arr_pos);	
		}
		else
		{
			arr_pos = arr_pos+index;
		}

		if(arr_pos < 0 || arr_pos >=_buf.size())
		assert(false);

		 _buf.erase(_buf.begin()+arr_pos -1);

		if(arr_pos == _buf.size()) // last element got deleted.
			arr_pos = 0;
	}

	char it = _buf[0];// As one char is left.
	cout<< "\n Last char left is #-" << (it) << "-#, Q size= " << _buf.size() << endl;
	string end_val = "? ";
	if(it == end_val[0])
		return "Yes";
	else if(it == end_val[1])
		return "No";
	else
		return "No comments";
}


int main()
{
string in_arg;
Question obj1;
while(getline(cin, in_arg))
{
obj1.readInput(in_arg);

}

cout<< obj1.findAnswer() << endl;
return 0;
}

