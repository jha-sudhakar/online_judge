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
		string _buf;
		vector< list<char>  > vec;
		const int N;
	public:
		void merge_last_two_que();
		void readInput(string& _arg);
		void readInput_in_Vec(string& _arg);
		string findAnswer();
		Question(string& _arg, const int _N=V);
		Question(const int _N=V);
		void printInput();
};

void Question::readInput(string& _arg)
{
	_buf = _buf + _arg;	
}

void Question::readInput_in_Vec(string& _arg)
{
	int j=0;
	while(j < _arg.size())
	{ 
		list<char> que;
		for(int i=0; i<N && j<_arg.size(); i++)
		{		
			que.push_back(_arg[j]);
			j++;
		}
		vec.push_back(que);
	}
	merge_last_two_que();
}

void Question::merge_last_two_que()
{
	if(vec.size() == 1) return;
	for(std::list<char>::iterator it = vec[vec.size()-1].begin(); it != vec[vec.size()-1].end(); it++)
	{
		vec[vec.size()-2].push_back(*it);
	}
	vec.pop_back();
}

Question::Question(const int _N):N(_N) { }
Question::Question(string& _arg,const int _N): N(_N) {	readInput(_arg); }

void Question::printInput()
{
	//cout<<"\n Printing Input string...\n";
	cout<<endl;
	for(int i=0; i<vec.size(); i++)
	{
		 list<char> que = vec[i];
		for(std::list<char>::iterator it = que.begin(); it != que.end(); it++)
		{
			cout<<*it;
		}
		//cout<<endl;
	}
	cout<<"###";
}


string Question::findAnswer()
{
	readInput_in_Vec(_buf); _buf.clear();
	//printInput();	//cout<<"\n Size of vector= "<< vec.size() << endl;	//sleep(1);
	if(vec.size() == 0) return "Input size is zero";

	int arr_index = 0;
	int arr_pos = (N-1) % vec[0].size();;
	while( vec[0].size() != 1)
	{
		//printInput();

        list<char>& que = vec[arr_index];
        std::list<char>::iterator it = que.begin();
		int index = 0;
		for(; (it != que.end()) && (index != arr_pos); ++it, index++); // Reach the correct index.
		if(que.end() == it) { assert(false); }
		que.erase(it);
				
		// Now this list has less than N elements, so move the elements from back to top.
		for(int k=arr_index+1; k<vec.size(); k++)
		{
			vec[k-1].push_back(vec[k].front()); vec[k].pop_front();
		}

		if(vec.size() > 1 && vec[vec.size()-1].size() < N) 
		{ 
			if(arr_index == vec.size()-1)
			{
				arr_pos = arr_pos+N;
				arr_index--;
			}
			merge_last_two_que();
		}

		if(arr_pos+N-1 < vec[arr_index].size()) // Id list has more than N elements and next entry falls in same range.
		{
			arr_pos = arr_pos+N-1;
		} else if (vec.size() > 1)
		{
			arr_pos = (N-1) - (vec[arr_index].size() - arr_pos);
			arr_index = (arr_index+1) % vec.size();
		}
		else // If next entry falls outside the end of this queue.
		{
			int offset = (N-1) % vec[arr_index].size();
			if(arr_pos+offset < vec[arr_index].size())
			{
				//cout<<"\n 1.Pos = " <<arr_pos <<", New pos= "<< (arr_pos+offset) << ", size()= " <<  vec[arr_index].size();;
				arr_pos = (arr_pos+offset);
			}
			else
			{
				if(arr_pos == vec[arr_index].size())
				{
					//cout<<"\n 2.Pos = " <<arr_pos <<", New pos= "<< (offset)  << ", size()= " <<  vec[arr_index].size();
					arr_pos = offset;
				}else
				{	
				//cout<<"\n 3.Pos = " <<arr_pos <<", New pos= "<< (arr_pos+offset -vec[arr_index].size())  << ", size()= " <<  vec[arr_index].size(); 
					arr_pos = arr_pos+offset -vec[arr_index].size();
				}
			}
		}
	}

	std::list<char>::iterator it = vec[0].begin();// As one char is left.
	//cout<< "\n Last char left is " << (*it) << ", Q size= " << vec[0].size() << endl;
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
obj1.readInput(in_arg);

}

cout<< obj1.findAnswer() << endl;
return 0;
}

