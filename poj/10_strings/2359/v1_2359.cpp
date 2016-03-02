#include <string>
#include <list>
#include <iostream>
using namespace std;


class Question
{
	private:
		list<char> que;
		const int N;
	public:
		void readInput(string& _arg);
		string findAnswer();
		Question(string& _arg, const int _N=1999);
		void printInput();
};

void Question::readInput(string& _arg)
{
	for(int i=0; i<_arg.size(); i++)
	{
		que.push_back(_arg[i]);
	}
}


Question::Question(string& _arg,const int _N): N(_N)
{
	readInput(_arg);
}

void Question::printInput()
{
	//cout<<"\n Printing Input string...\n";
	for(std::list<char>::iterator it = que.begin(); it != que.end(); it++)
	{
		cout<<*it;
	}
	cout<<"###" <<endl;
}


string Question::findAnswer()
{
	if(que.size() == 0)
		return "Input size is zero";

	std::list<char>::iterator it = que.begin();
	while(que.size() > 1)
	{
		for(int n=0; n<N-1; n++)
		{
			it++;
			if(it == que.end())
				it = que.begin();
		}	
		it = que.erase(it);
		if(it == que.end())
			it= que.begin();
		//printInput();
	}

	it = que.begin();// As one char is left.

	cout<< "\n Last char left is " << (*it) << endl;
	string end_val = "? ";
	if(*it == end_val[0])
		return "Yes";
	else if(*it == end_val[1])
		return "No";
	else
		return "No comments";
}


int main()
{
string in_arg;
while(getline(cin, in_arg))
{
Question obj1(in_arg);
obj1.printInput();
cout<< obj1.findAnswer() << endl;

}

return 0;
}

