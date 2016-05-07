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
		void insert(node** cur_node, const string& str, unsigned int index);
		unsigned int word_count(const string& str);
		unsigned int get_recursive_child_count(node* n);
		unsigned int word_count_partial(const string& str);
	public:
		Trie3();
		void insert(const string& str);
		void delete2(string& str); //Will do last.
		bool find(const string& str);
		unsigned int frequency(const string& str);
		unsigned int word_count_partial_public(const string& str);
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

void Trie3::insert(const string& str)
{
	if(str.size() == 0)
	{
		return;
	}	
	else if(str.size() == 1)
	{
		root[str[0]][0].count++;
		return;
	}
	else if(str.size() == 2)
	{
		root[str[0]][str[1]].count++;
		return;
	}

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

void Trie3::delete2(string& str)
{

	if(str.size() == 0)
	{
		return;
	}	
	else if(str.size() == 1)
	{
		root[str[0]][0].count--;
		return;
	}
	else if(str.size() == 2)
	{
		root[str[0]][str[1]].count--;
		return;
	}

	node* child = NULL;
	if(root[str[0]][str[1]].ch < str[2])
	{
		child = (root[str[0]][str[1]].gt);
	}
	else if(root[str[0]][str[1]].ch ==  str[2])
	{
		child = (root[str[0]][str[1]].gt);
	}
	else
	{
		child = (root[str[0]][str[1]].gt);
	}
	unsigned int index = 2;
	vector<pnode> search_path;

	while(index < str.size())
	{
		if(child == NULL)
			return;

		if(child->ch < str[index])
		{
			search_path.push_back(pnode(RIGHT,child));
			child = child->gt;
		}
		else if(child->ch == str[index])
		{
			if(index == str.size()-1)
				break;
			index++;
			search_path.push_back(pnode(MID,child));
			child = child->eq;
		}
		else
		{
			search_path.push_back(pnode(LEFT,child));
			child = child->lt;
		}
	}
	// Once the loop ends, pointer is at node having last char so decrement it;
	if(child->count >0)
	{
		child->count--;
	} else
	{
		search_path.clear(); // Not found so clear the path.
		return;
	}


	// Delete the path/sub-path if this is the only word on this path.
	while(search_path.size())
	{
		if(child->lt != NULL || child->eq != NULL || child->gt != NULL) // It has sub-tree below so don't delete;
		return;
		if(child->count != 0)
		return;

		pnode pn = search_path[search_path.size()-1];
		search_path.pop_back();
		switch (pn.dir)
		{
			case LEFT:
				delete child;
				child = pn.n;
				pn.n->lt = NULL;
				break;
			case MID:
				delete child;
				child = pn.n;
				pn.n->eq = NULL;
				break;

			case RIGHT:
				delete child;
				child = pn.n;
				pn.n->gt = NULL;
				break;
		}
	}
}

unsigned int Trie3::word_count(const string& str)
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
	// Once the loop ends, pointer is at node having last char so decrement it;
	return child->count;
}

unsigned int Trie3::word_count_partial_public(const string& s)
{
	vector<char> str;
	str.resize(3);

	if(s.size() == 0)
		return 0;

	if(s.size() == 1)
	{
		str[0] = s[0];
		unsigned int sum1 = 0;
		for(int i='a'; i<='z'; i++)
		{

			str[1] = i;
			for(int j='a'; j<= 'z'; j++)
			{
				str[2] = j;
				sum1 += word_count_partial(string(str.begin(), str.end()));
			}	
		}
		return sum1;
	}
	else if(s.size() == 2)
	{
		str[0] = s[0]; str[1] = s[1];
		unsigned int sum2 = 0;
		for(int i='a'; i<='z'; i++)
		{

			str[2] = i;
			sum2 += word_count_partial(string(str.begin(), str.end()));
		}
		return sum2;
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
	unsigned int sum = get_recursive_child_count(child);
	return sum;
}

unsigned int  Trie3::get_recursive_child_count(node* n)
{
	if(n == NULL)
		return 0;
	unsigned int child_sum = 0;
	child_sum+= get_recursive_child_count(n->lt);
	child_sum+= get_recursive_child_count(n->eq);
	child_sum+= get_recursive_child_count(n->gt);
	child_sum+= n->count;
	return child_sum;
}

unsigned int Trie3::frequency(const string& str)
{
	return word_count(str);
}

bool Trie3::find(const string& str)
{
	unsigned int ret= word_count(str);
	if(ret)
		return true;
	else
		return false;
}

int main(int argc, char* argv[])
{

if(argc != 4)
{
cout<<" exe insert/delete-op-count validate-op-count iteration-count\n";
cout<<" Example ==>  ./a.out 200 40 10\n";
return 0;
}

Trie3 obj1;
map<string, unsigned int> dict;
map<string, unsigned int>::iterator map_itr;

const char* words_arr[]= {"abc", "pqr", "lmn", "xyz", "zzz", "aaa", "pqrz", "pqn", "pqq", "pqrr"};
//const char* words_arr[] = {"pqr", "pqn"};
vector<string> str_vec(words_arr, words_arr+sizeof(words_arr)/sizeof(words_arr[0])); 
unsigned int v_len = str_vec.size(); cout << "Vector size= " << v_len << endl;

unsigned int loop = atoi(argv[3]);
while(loop > 1)
{
	unsigned int count = atoi(argv[1]);
	srand(time(NULL));

	for(int i=0; i<count; i++)
	{

		unsigned int random_int = rand()%v_len;
		if(random_int%2)// Odd num then insert else delete;
		{
			log<< i+1 << "  Inserting " << str_vec[random_int] << endl;
			obj1.insert(str_vec[random_int]);
			map_itr = dict.find(str_vec[random_int]);
			if(map_itr == dict.end())
				dict[str_vec[random_int]] = 1;
			else
				map_itr->second++;
		} 
		else
		{
			log<< i+1 << "  Deleting " << str_vec[random_int] << endl;
			obj1.delete2(str_vec[random_int]);
			map_itr = dict.find(str_vec[random_int]);
			if(map_itr != dict.end())
				if(map_itr->second >0)
					map_itr->second--;

		}
	//}

	unsigned int search_count = atoi(argv[2]);
	bool is_assert = false;
	//for(unsigned int i=0; i<search_count; i++)
	unsigned int pq_count = 0;
	string partial_str("p");
	for(unsigned int i=0; i<v_len; i++)
	{
		unsigned int random_int = i; //rand()%v_len;
		unsigned int trie_ret=0, map_ret=0;

		trie_ret = obj1.frequency(str_vec[random_int]);
		
		map_itr = dict.find(str_vec[random_int]);
		if(map_itr != dict.end()) map_ret = map_itr->second;

		if(trie_ret != map_ret)
		{
			cout<< i+1 <<"  " << str_vec[random_int] << " not matched , trie-count= " << trie_ret <<", map-count= " <<map_ret << endl;
			//assert(false);
			is_assert = true;
		}
		//log<< i+1 <<"  " << str_vec[random_int] << " matched , count= " << map_ret << endl;
		if(string::npos != str_vec[random_int].find(partial_str))
		{
			pq_count += trie_ret;
		}
	}
	
	log<< "pq-count= " <<  obj1.word_count_partial_public(partial_str) << ", sum of pq_prefix= " << pq_count <<endl;
	if(pq_count != obj1.word_count_partial_public(partial_str))
		assert(false);

	if(is_assert)
		assert(false);
	cout <<" Loop " << loop <<" finished\n";
	//loop--;

	}
	loop--;
}

return 0;
}
