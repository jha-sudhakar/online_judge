#include <assert.h>
#include <stack> 
#include <stdint.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class parenthesis
{
	private:
		int T;
		string str;	

	public:
		void process_input();
		void generate_parenthesis();
};

void parenthesis::process_input()
{
	cin >> T;
	for(int i=0; i<T; i++)
	{
 cin >> str;
   generate_parenthesis();
	}
}

void parenthesis::generate_parenthesis()
{
	unsigned int lp=0, rp=0;
	if(str.size() == 1)
	{
		cout<<"()" << endl;
		return;
	}


	stack<char> stk;
	for(int i=0; i<str.size(); i++)
	{	
		if(str[i] == '(')
		{
			stk.push(str[i]);
		} else if(str[i] == ')')
		{
			if(stk.empty())
			{
				lp++;
			} else if(stk.top() == '(')
			{
				stk.pop();
			} else
			{
				assert(false);
			}
		}
	}

	while(!stk.empty())
	{
		stk.pop(); rp++;
	}

	for(int i=0; i<lp; i++)	cout<<"(";
	cout<<str;
	for(int i=0;i<rp; i++)	cout<<")";
	cout<<endl;
}


int main()
{

parenthesis obj;
obj.process_input();
return 0;
}
