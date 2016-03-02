#include <string>
#include <list>
#include <iostream>
using namespace std;

class Max_Str_Rotation
{
	private:
	

	public:
		Max_Str_Rotation(string& _str) { str = _str;}
		string str;
		string find_largest_lexicographical_rotation();
};


string Max_Str_Rotation::find_largest_lexicographical_rotation()
{
	unsigned int max = str[0];

	//1. Calculate the First char for rotation.
	for(unsigned int i=1; i< str.size(); i++)
	{
		if(str[i] > max)
			max = str[i];
	}

	list<unsigned int> mylist;
    for(unsigned int i=0; i< str.size(); i++)
    {
        if(str[i] == max)
            mylist.push_back(i);
    }

	for(unsigned int count=1; count < str.size(); count++)
	{

		if(mylist.size() == 1)
		{
			break;
		}

		// Find index of max among all the indicies in the list.
		unsigned int max_val = str[count+ mylist.front()];
		for (std::list<unsigned int>::iterator it=mylist.begin(); it != mylist.end(); ++it)
		{
		    unsigned int pos =  *it;
			unsigned int arr_index = (count+pos) % str.size();
			if(max_val < str[arr_index])
			{
				max_val = str[arr_index];
			} 
		}
		
		for (std::list<unsigned int>::iterator it=mylist.begin(); it != mylist.end(); )
		{
			unsigned int pos =  *it;
			unsigned int arr_index = (count+pos) % str.size();
			if(str[arr_index] < max_val)
			{
				it = mylist.erase (it);
			}
			else
			{
				it++;
			}
		}
	}

	//cout<<"\n Original str  = " << str;
	//cout<<"\n Result string = ";
	unsigned int _index =  mylist.front();
    for(unsigned int count=0; count < str.size(); count++)
    {
		cout<<str[(_index+count)% str.size()];
	}
	cout<<endl;
	return "Hello";
}


int main()
{
//string _arg = "azbzczdz"; //"bidhnan"; //"bidhan";
string _arg;
while(cin >> _arg)
{
	Max_Str_Rotation obj1(_arg);
	obj1.find_largest_lexicographical_rotation();
}
//cout<<endl;
return 0;
}

