
#include <string>
#include <iostream>
using namespace std;

unsigned int len [5000][5000];

class CC
{
	private:
		//unsigned int len[5000][5000];
		string str1;
		string str2;
		unsigned int max3(const unsigned int a, const unsigned int b, const unsigned int c);

	public:
		CC () {  }
		CC(string& s1, string& s2) {str1= s1; str2= s2;}
		void read_input();
		void find_common_child();
};

void CC::read_input()
{
	while(cin >> str1)
	{
		cin >> str2;
		//cout<<"Str1 = " << str1 << endl; cout<<"Str2 = " << str2 << endl; 
		find_common_child();
	}
}


unsigned int CC::max3(const unsigned int a, const unsigned int b, const unsigned int c)
{
	unsigned int e=0;
	if(a > b)
		e = a;
	else
		e = b;

	if(e < c)
		e = c;

	return e;
}


void CC::find_common_child()
{
/*
	len(i,j) = max of {
							1+ len(i-1,j-1) if str1[i] == str2[j]
						Or
							len(i, j-1)
						Or
							len(i-1, j)
*/

	const unsigned int l1= str1.size();
	const unsigned int l2= str2.size();
	if((l1 == 0) || (l2 == 0))
	{
		cout<< 0 << endl;
		return ;
	}

	//unsigned int len[l1][l2];
	for(unsigned int i=0; i<l1;i++)
		for(unsigned int j=0; j<l2; j++)
			len[i][j] = 0;

	if(str1[0] == str2[0])
	{
		len[0][0] = 1;
	}


    for(unsigned int i=1; i<l1; i++)
    {
        if(str1[i] == str2[0])
        {
            len[i][0] = 1;
        } else
        {
            len[i][0] = len[i-1][0];
        }
    }


    for(unsigned int j=1; j<l2; j++)
    {
        if(str1[0] == str2[j])
        {
            len[0][j] = 1;
        } else
        {
            len[0][j] = len[0][j-1];
        }
    }



	for(unsigned int i=1; i<l1; i++)
	{
		for(unsigned int j=1; j<l2; j++)
		{
			unsigned int val1,val2,val3;
			val1 = len[i-1][j];
			val2 = len[i][j-1];
			val3 = len[i-1][j-1]; if(str1[i] == str2[j]) { val3++; }
			len[i][j] = max3(val1, val2, val3);
		}

	}

	cout << len[l1-1][l2-1] << endl;
}


int main()
{
CC obj;
obj.read_input();
return 0;
}
