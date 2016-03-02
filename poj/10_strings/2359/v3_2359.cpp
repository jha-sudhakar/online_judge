#include <vector>
#include <string>
#include <list>
#include <iostream>
using namespace std;


class Question
{
	private:
		//list<char> que;
		vector< list<char>  > vec;
		const int N;
	public:
		void readInput(string& _arg);
		string findAnswer();
		Question(string& _arg, const int _N=1999);
		Question(const int _N=1999);
		void printInput();
};

void Question::readInput(string& _arg)
{
	int j=0;
	while(j < _arg.size())
	{ 
		list<char> que;
		for(int i=0; i<N && j<_arg.size(); i++,j++)
		{		
			que.push_back(_arg[j]);
		}
		vec.push_back(que);
	}
}

Question::Question(const int _N):N(_N)
{

}

Question::Question(string& _arg,const int _N): N(_N)
{
	readInput(_arg);
}

void Question::printInput()
{
	//cout<<"\n Printing Input string...\n";
	for(int i=0; i<vec.size(); i++)
	{
		 list<char> que = vec[i];
		for(std::list<char>::iterator it = que.begin(); it != que.end(); it++)
		{
			cout<<*it;
		}
	}
	cout<<"###" <<endl;
}


string Question::findAnswer()
{
	if(vec.size() == 0)
		return "Input size is zero";

	int cur_pos = 0;
	int k=0;
	while(vec.size() != 1)
	{
		int new_pos = cur_pos+ N-1;
		for(int i=k; i<vec.size(); i=(i+1)%vec.size())
		{
			if(vec[i].size() < new_pos+1)
			{
				new_pos = new_pos - vec[i].size(); // In the next bucket in vector;
			}
			else
			{
				// Element falls in this bucket so delete it.
				list<char> que;
				int index = 0;
				std::list<char>::iterator it = que.begin();
				for(; (it != que.end()) && (index != new_pos); ++it, index++); // Reach the correct index.
				it = que.erase(it);
				k = i+1;
				
				// Now this list has less than N elements, so move the elements from back to top.
				for(int k=i+1; k<vec.size(); k++)
				{
					vec[k-1].push_back(vec[k].front()); vec[k].pop_front();
				}

				if(vec[vec.size()-1].size() == 0) // If last list has no elements then delete it;
				{
					if(i == vec.size() -1)
						i--; // It should roll over to 0'th position even when vector size shrinks.
					vec.pop_back();
				}

			}

		}


	}


	list<char> que = vec[0];
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

	//cout<< "\n Last char left is " << (*it) << endl;
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
Question obj1;
while(getline(cin, in_arg))
{
//Question obj1(in_arg);
obj1.readInput(in_arg);//obj1.printInput();
//cout<< obj1.findAnswer() << endl;

}

cout<< obj1.findAnswer() << endl;
return 0;
}

