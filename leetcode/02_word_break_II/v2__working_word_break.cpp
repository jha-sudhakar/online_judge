#include<vector>
#include <assert.h>
#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;


struct  v
{
    int row;
    int col;
};

class Solution
{
	private:
		unsigned int** table;
		unsigned int N;
	public:
    	bool wordBreak(string s, unordered_set<string>& wordDict);
		void print_all_valid_word_breaks(string& s);
		void print_string(string& s, vector<struct v>& path);
};

bool Solution::wordBreak(string s, unordered_set<string>& wordDict)
{
	bool result = false;
	N = s.size();
	table = new unsigned int* [N];
	for(unsigned int i=0; i<N; i++)
	{
		table[i] = new unsigned int [N];
	}

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
			table[i][j] = 0;    
        }
    }

	for(int i=0; i<N; i++)
	{
		table[i][i] = (wordDict.find(s.substr(i,1)) == wordDict.end()? 0:1);
	}

	for(int d=1; d<N; d++)
	{
		for(int i=0; i+d<N; i++)
		{
			int j = i+d;
			for(int k=i; k<=j; k++)
			{
				bool left=false, right= false;
				left = ((wordDict.find(s.substr(i,k-i+1)) != wordDict.end()) || table[i][k]);;
				if(k+1 <= j)
				{
					right = ((wordDict.find(s.substr(k+1,j-(k+1)+1)) != wordDict.end()) || table[k+1][j]);
				}
				else
					right = true;

				if(left && right)
				{
					table[i][j] = 1;
					break;
				}
			}
		}
	}
	result = table[0][N-1];

#if 0
	//Print the lookup table.
	cout<<endl <<" ";

	for(int i=0; i<N; i++)
		cout<< " " << char(s[i]);
	cout<<endl;
	for(int i=0; i<N; i++)
	{
		cout<< char(s[i]) << " ";
		for(int j=0; j<N; j++)
			cout<<table[i][j] <<" ";
		cout<<endl;
	}
#endif

	print_all_valid_word_breaks(s);

    for(unsigned int i=0; i<N; i++) { delete [] table[i]; }
	delete [] table;
	return result;
}

void Solution::print_string(string& s,  vector<struct v>& path)
{
        int prev_col = 0;
        //cout<<"\nPath string= ";
        for(int p=0; p<path.size(); p++)
        {
            cout<< s.substr(prev_col, path[p].col - prev_col+1) <<" ";
            prev_col = path[p].col+1;
        }
        cout<<endl;
}

void Solution::print_all_valid_word_breaks(string& s)
{
	//struct  v     {         int row;         int col;     };

    vector<struct v> path;
    for(int i=0; i<N; i++)
    {
        if(table[0][i] == 1)
        {
            v buf; buf.row=0, buf.col=i;path.push_back(buf);
			break;
        }
    }

    while(path.size())
    {
        v buf = path[path.size()-1];
		if(buf.col == N-1)
		{			
			if(table[buf.row][buf.col] == 1)
			{
				print_string(s, path);                
			}

			path.pop_back();
			if(path.size() && path[path.size()-1].col != N-1)
				path[path.size()-1].col += 1;
			continue;
		} else if(table[buf.row][buf.col] == 0)
		{
			path[path.size()-1].col++;
			continue;
		}

		int set_col = buf.col+1;
		for(; set_col<N; set_col++)
		{
			if(table[buf.col+1][set_col] == 1)
				break;
		}
		if(set_col == N)	
		{
			path[path.size()-1].col += 1;
		}
		else
		{
			v new_str; new_str.row = buf.col+1; new_str.col = set_col;
			path.push_back(new_str);;
		}
    }
}

#if 1
int main()
{
	Solution obj;
	bool result = false;
	std::unordered_set<std::string> myset1 = {"ab", "pq", "xy"}; 
	//string s1("abpxy");  result = obj.wordBreak(s1, myset1);	cout<<s1 <<" found= " << result << endl;
	string s2("abpqxy"); result = obj.wordBreak(s2, myset1);	cout<<s2 <<" found= " << result << endl;
	//string s3("abqxy");  result = obj.wordBreak(s3, myset1);	cout<<s3 <<" found= " << result << endl;

	//unordered_set<string> myset2={"aaaa","aaa"};string s4("aaaaaaa");  result = obj.wordBreak(s4, myset2);    cout<<s4 <<" found= " << result << endl;

	//std::unordered_set<std::string> myset = {"yellow", "green", "blue"}; result = obj.wordBreak("yellowgreenblue", myset);
	//cout<<"Work break  found = " << result << endl;

	return 0;
}
#endif
