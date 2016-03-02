#include <stdlib.h>

#include <iostream>
#include <string>

using namespace std;

class string_subsequence
{

private:
	string seq;
	string str;

public:
	bool is_sub_sequence();
	string_subsequence(string& _seq, string& _str);

};


string_subsequence::string_subsequence(string& _seq, string& _str)
{
	seq = _seq;
	str = _str;
}

bool string_subsequence::is_sub_sequence()
{
	int j = seq.size()-1;
	for(int i=str.size()-1; i>=0; i--)
	{
		if(str[i] == seq[j])
		{
			j--;
			if(j == -1) return true;
		}
	}
	return false;
}


int main(int argc, char* argv[])
{
#if 0
	if(argc != 3)
	{
		cout<<"\n Usage:- exe  sequence string\n";
		exit(0);
	}
#endif

	bool print_line = false;
	string seq,str;
	while(cin >> seq >> str)
	{
	//string seq; cin >> seq;// = argv[1];
	//string str; cin >> str;// = argv[2];
	string_subsequence obj(seq, str);
	bool result = obj.is_sub_sequence();

	//if(print_line == true) 	cout<<"\n";

	if(result)
		cout<<"Yes" << endl;
	else
		cout<<"No" << endl;

	print_line = true;
	}

	return 0;
}
