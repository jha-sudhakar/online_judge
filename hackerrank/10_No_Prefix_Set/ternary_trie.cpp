#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#include<vector>
#include<map>
#include<string>
#include<iostream>
using namespace std;

#define CHAR_COUNT 256
#define log cout

enum POS
{
LEFT,
MID,
RIGHT
};

struct node
{
	unsigned int count;
	unsigned char ch;
	struct node *lt, *eq, *gt;
	node() { count=0;ch=0; lt=eq=gt=NULL;}
	node(unsigned char _ch) { count = 0; ch=_ch; lt=eq=gt=NULL; }
};

struct pnode
{
	POS dir;
	node* n;
	pnode(POS _dir, node* _node) { dir=_dir; n=_node;}
};

class Trie3
{
	private:
		struct node root[CHAR_COUNT][CHAR_COUNT];
		int insert(node** cur_node, const string& str, unsigned int index);
	public:
		Trie3();
		int insert(const string& str);
		void process_input();
};

Trie3::Trie3()
{
	for(int i=0; i<CHAR_COUNT; i++)
	{
		for(int j=0; j<CHAR_COUNT; j++)
		{
			root[i][j].ch = j;
		}
	}
}

void Trie3::process_input()
{
	unsigned int N;
	cin >> N;
	string word;
	for(unsigned int i=0; i<N; i++)
	{
		cin >> word;
		int ret_val = insert(word);
		if(ret_val == -1)
		{
			cout << "BAD SET" << endl << word << endl;
			return;
		}
	}
	cout << "GOOD SET" << endl;
}


int Trie3::insert(const string& str)
{
	if(str.size() == 0)
	{
		return 0;
	}	
	else if(str.size() == 1)
	{
		for(int i=0; i<CHAR_COUNT; i++)
		{
			if(root[str[0]][i].count ||
				(root[str[0]][i].gt != NULL || root[str[0]][i].eq != NULL || root[str[0]][i].lt != NULL))
			return -1;
		}	
		root[str[0]][0].count++;
		return 0;
	}
	else if(str.size() == 2)
	{
		if(root[str[0]][0].count)
			return -1;
	
		if(root[str[0]][str[1]].count || 
			(root[str[0]][str[1]].gt != NULL || root[str[0]][str[1]].eq != NULL || root[str[0]][str[1]].lt != NULL))
			return -1;
		root[str[0]][str[1]].count++;
		return 0;
	}


	if((root[str[0]][str[1]].count)||(root[str[0]][0].count))
		return -1;

	if(root[str[0]][str[1]].ch < str[2])
	{
		return insert(&(root[str[0]][str[1]].gt), str, 2);
	}
	else if(root[str[0]][str[1]].ch ==  str[2])
	{
		return insert(&(root[str[0]][str[1]].eq), str, 2);
	}
	else
	{
		return insert(&(root[str[0]][str[1]].lt), str, 2);
	}
}

int Trie3::insert(node** cur_node, const string& str, unsigned int index)
{
	while(index < str.size())
	{
		if(*cur_node == NULL)
		{
			*cur_node = new node(str[index]);
			if(index == str.size()-1)
			{
				(*cur_node)->count++;
				return 0;
			}
			index++;
			cur_node = &((*cur_node)->eq);
			continue;
		}

		if((*cur_node)->ch < str[index])
		{
			cur_node = &((*cur_node)->gt);
		}
		else if((*cur_node)->ch == str[index])
		{
			if((*cur_node)->count)
				return -1;
					
			if(index == str.size()-1)
			{
				if((*cur_node)->eq)
					return -1;

				(*cur_node)->count++;
				return 0;
			}	
			else	
			{
				cur_node = &((*cur_node)->eq);
				index++;
			}	

		}
		else
		{
			cur_node = &((*cur_node)->lt);
		}
	}
	// Once the loop ends, pointer is at node having last char so increment it;
	assert(false);
}

int main(int argc, char* argv[])
{
Trie3 obj1;
obj1.process_input();
return 0;
}
