#include <assert.h>
//#include <unistd.h>
#include <time.h>
#include <vector>
#include <string>
#include <list>
#include <iostream>
using namespace std;

//#define V 1999
#define V 4
class Question
{
	private:
		string _buf;
		//list<char> _buf;
		vector< list<char>  > vec;
		const int N;
	public:
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
	cout<<"\n Printing Input string...\n";
	for(int i=0; i<vec.size(); i++)
	{
		 list<char> que = vec[i];
		for(std::list<char>::iterator it = que.begin(); it != que.end(); it++)
		{
			cout<<*it;
		}
		cout<<endl;
	}
	cout<<"###" <<endl;
}


string Question::findAnswer()
{
	readInput_in_Vec(_buf); _buf.clear();
	//printInput();
	//cout<<"\n Size of vector= "<< vec.size() << endl;
	//sleep(1);

	if(vec.size() == 0)
		return "Input size is zero";

	int cur_pos = 0;
	int k=0;
	int arr_index=0;
	int arr_pos=N-1;
	if(vec.size() == 1)
		arr_pos=0;
	while(vec.size() != 1)
	{

		if(arr_pos >= vec[arr_index].size()) // Arr_index in last list may overflow.
		{
			int new_arr_index = (arr_index+1) % vec.size();
			cout<<"\n Arr pos " << arr_pos <<" is being changed to " <<(arr_pos - vec[arr_index].size()) <<", index= " << arr_index <<" , new_index= " << new_arr_index;;
			arr_pos = arr_pos - vec[arr_index].size();
			arr_index = new_arr_index;
			//assert(false);
		}

		if(arr_pos <0)
		{
			assert(false);
		}

		 // Element falls in this bucket so delete it.
        list<char>& que = vec[arr_index];;
        int index=0;
        std::list<char>::iterator it = que.begin();

		for(; (it != que.end()) && (index != arr_pos); ++it, index++); // Reach the correct index.
		if(que.end() == it)
		{
			assert(false);
		}
		que.erase(it);
				
		// Now this list has less than N elements, so move the elements from back to top.
		for(int k=arr_index+1; k<vec.size(); k++)
		{
			vec[k-1].push_back(vec[k].front()); vec[k].pop_front();
		}

		if(vec[vec.size()-1].size() == 0) // If last list has no elements then delete it;
		{
			if(arr_index == vec.size() -1)
				arr_index--; // It should roll over to 0'th position even when vector size shrinks.
			vec.pop_back();
		}

		if(arr_pos == vec[arr_index].size() && (arr_index == vec.size()-1)) // Last element in last list got deleted.
		{
			int arr_pos2 = N-1;
		 cout<<"\n # Cur_pos= " << arr_pos <<", New pos= " << arr_pos2 << " cur_index = " << arr_index <<" list-size= " << vec[arr_index].size() <<", vec-size= " << vec.size();
			arr_pos = arr_pos2;;

		} else
		{
        int arr_pos2 = ((N-1) + arr_pos) % (vec[arr_index].size());
		cout<<"\n  Cur_pos= " << arr_pos <<", New pos= " << arr_pos2 << " cur_index = " << arr_index <<" list-size= " << vec[arr_index].size() <<", vec-size= " << vec.size();
		arr_pos = arr_pos2;
		}
        arr_index = (arr_index+1) % vec.size();
	}


	list<char> que = vec[0];
	std::list<char>::iterator it = que.begin();
	for(int i=0; i<arr_pos; i++)
	{
		it++;
	}
	it = que.erase(it);
	if(it == que.end())
		it = que.begin();

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

	cout<< "\n Last char left is " << (*it) << ", Q size= " << que.size() << endl;
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

