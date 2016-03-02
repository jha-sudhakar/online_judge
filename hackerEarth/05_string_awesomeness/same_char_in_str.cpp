#include <unistd.h>
#include <assert.h>

#include <stdint.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define OFFSET 96
struct range
{
	unsigned int l;
	unsigned int r;
};

class Str
{

	private:
		string key;
		string text;
		unsigned int q;
		vector<range> queries;
		int key_len;
		vector<unsigned int> match;
		int arr[256];
		int ref_arr[256];
	public:
		Str(); 
		void read_input();
		void count_awesome_strings();
		void update_matching_range(unsigned int _l, unsigned int _r);
		void print_counts_in_range_v2();
		bool is_matching();
};

Str::Str()
{
	key = "hackerearth";
	for(int i=0; i<256; i++) {	arr[i] = ref_arr[i] =0; }
	for(int i=0; i<key.size(); i++) { ref_arr[key[i]]++; }

	key_len = key.size();
}

bool Str::is_matching()
{
	int _count = 0;
	for(int i=0; i<key.size(); i++)
	{	
		if(ref_arr[key[i]] != arr[key[i]])
		{
			return false;
		}
	}

	return true;
}

void Str::read_input()
{
	while (cin >> text)
	{
		std::transform(text.begin(), text.end(), text.begin(), ::tolower);

		cin >> q;
		queries.clear(); queries.resize(q); 
		match.clear(); match.resize(text.size()+1);
		for(unsigned int i=0; i<q; i++)
		{
			cin>> queries[i].l >> queries[i].r; 
		}

		
		match[0] = match[1] =0;
		// for(unsigned int k=0; k<queries.size(); k++) cout<<"Range " << k+1 <<" = [" << queries[k].l <<", " << queries[k].r <<"]\n";
		count_awesome_strings();
		print_counts_in_range_v2();
	}
}

void Str::count_awesome_strings()
{
	if(text.size() < key.size()) // If text size smaller than keyword then return zero.
	{
		for(unsigned int i=0; i<q; i++)
			cout << 0 << endl;
		return;
	}

	vector<unsigned int> index;

	uint64_t val_k = 1, val_t = 1;
	for(unsigned int i=0; i<key.size(); i++)
	{
		val_k = val_k *  (key[i]-OFFSET); 
		val_t = val_t *  (text[i]-OFFSET);
		arr[text[i]]++;
	}

	for(unsigned int i=0; i<=(text.size() - key.size()); i++)
	{
		if(val_k == val_t)
		{
			if(is_matching()) 
			{ 
				match[i+1] = match[i]+1;
				//cout <<" Found the match at " << i << endl;
			} else
			{
				match[i+1] = match[i];
			}
		} else
		{
			match[i+1] = match[i];
		}
		
		val_t =  (text[i+key.size()]-OFFSET) * ( val_t / (text[i]-OFFSET));
		arr[text[i]]--; arr[text[i+key.size()]]++;
		
	}
}


void Str::print_counts_in_range_v2()
{
	unsigned int len = key.size();
    for(unsigned int i=0; i<queries.size(); i++)
    {
		if(queries[i].r -queries[i].l < len-1)
		{
			cout<< 0 << endl;
			continue; // Range is smaller than the size of key.
		}

        //if((queries[i].r+1 - len > q) || (queries[i].l -1 > q))  assert(false);

		int val1 = match[queries[i].r+1 - len];
		int val2 = match[queries[i].l -1];
        cout<< (val1 - val2) << endl;
    }
}

int main()
{
	Str obj;
	obj.read_input();
	return 0;
}
