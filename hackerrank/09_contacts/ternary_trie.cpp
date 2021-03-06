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
		unsigned int l1[26];
		unsigned int l2[26][26];
		struct node root[CHAR_COUNT][CHAR_COUNT];
		void insert(node** cur_node, const string& str, unsigned int index);
		unsigned int get_recursive_child_count(node* n);
		unsigned int word_count_partial(const string& str);
	public:
		Trie3();
		void insert(const string& str);
		unsigned int word_count_partial_public(const string& str);
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

	for(int i=0; i<26; i++)
	{
		l1[i] = 0;
		for(int j=0; j<26; j++)
			l2[i][j] = 0;
	}
}

void Trie3::process_input()
{
	unsigned int N;
	cin >> N;
	string op, word;
	for(unsigned int i=0; i<N; i++)
	{
		cin >> op; cin >> word;
		if(op == string("add"))
		{
			insert(word);
		} else if(op == string("find"))
		{
			cout << word_count_partial_public(word) << endl;
		}
	}
}


void Trie3::insert(const string& str)
{
	if(str.size() == 0)
	{
		return;
	}	
	else if(str.size() == 1)
	{
		l1[str[0]-97]++;
		root[str[0]][0].count++;
		return;
	}
	else if(str.size() == 2)
	{
		l1[str[0]-97]++;
		l2[str[0]-97][str[1]-97]++;
		root[str[0]][str[1]].count++;
		return;
	}

	l1[str[0]-97]++;
	l2[str[0]-97][str[1]-97]++;

	if(root[str[0]][str[1]].ch < str[2])
	{
		insert(&(root[str[0]][str[1]].gt), str, 2);
	}
	else if(root[str[0]][str[1]].ch ==  str[2])
	{
		insert(&(root[str[0]][str[1]].eq), str, 2);
	}
	else
	{
		insert(&(root[str[0]][str[1]].lt), str, 2);
	}
}

void Trie3::insert(node** cur_node, const string& str, unsigned int index)
{
	while(index < str.size())
	{
		if(*cur_node == NULL)
		{
			*cur_node = new node(str[index]);
			if(index == str.size()-1)
			{
				(*cur_node)->count++;
				return;
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
			if(index == str.size()-1)
			{
				(*cur_node)->count++;
				return;
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

unsigned int Trie3::word_count_partial_public(const string& s)
{
	if(s.size() == 1)
	{
		return l1[s[0]-97];
	}
	else if(s.size() == 2)
	{
		return l2[s[0]-97][s[1]-97];
	}
	else
		return word_count_partial(s);

}

unsigned int Trie3::word_count_partial(const string& str)
{
	if(str.size() == 0)
	{
		return 0;
	}	
	else if(str.size() == 1)
	{
		return root[str[0]][0].count;
	}
	else if(str.size() == 2)
	{
		return root[str[0]][str[1]].count;
	}

	node* child = NULL;
	if(root[str[0]][str[1]].ch < str[2])
	{
		child = (root[str[0]][str[1]].gt);
	}
	else if(root[str[0]][str[1]].ch ==  str[2])
	{
		child = (root[str[0]][str[1]].eq);
	}
	else
	{
		child = (root[str[0]][str[1]].lt);
	}
	unsigned int index = 2;
	while(index < str.size())
	{
		if(child == NULL)
			return 0;

		if(child->ch < str[index])
		{
			child = child->gt;
		}
		else if(child->ch == str[index])
		{
			if(index == str.size()-1)
				break;
			index++;
			child = child->eq;
		}
		else
		{
			child = child->lt;
		}
	}
	// Once the loop ends, pointer is at node having last char so save it;
	unsigned int sum = 0;
	if(child->eq != NULL)
		sum = get_recursive_child_count(child->eq);
	sum+= child->count;		
	return sum;
}

unsigned int  Trie3::get_recursive_child_count(node* n)
{
	//if(n == NULL) return 0;
	unsigned int child_sum = 0;
	if(n->lt != NULL)
		child_sum+= get_recursive_child_count(n->lt);
	if(n->eq != NULL)
		child_sum+= get_recursive_child_count(n->eq);
	if(n->gt != NULL)
		child_sum+= get_recursive_child_count(n->gt);
	child_sum+= n->count;
	return child_sum;
}

int main(int argc, char* argv[])
{
Trie3 obj1;
obj1.process_input();
return 0;
}
