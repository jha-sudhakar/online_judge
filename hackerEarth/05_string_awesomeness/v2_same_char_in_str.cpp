#include <stdint.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define P 997
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
		vector<unsigned int> counts;
		int arr[256];
		int key_len;
	public:
		Str(); 
		void read_input();
		void count_awesome_strings();
		void update_matching_range(unsigned int _l, unsigned int _r);
		void print_counts_in_range();
		bool is_matching();
};

Str::Str()
{
	key = "hackerearth";
	for(int i=0; i<256; i++)
		arr[i] = 0;

	key_len = key.size();
}

bool Str::is_matching()
{
	int _count = 0;
	for(int i=0; i<key.size(); i++)
		_count += arr[key[i]];

	if(_count == key_len)
		return true;
	else
		return false;
}

void Str::read_input()
{
	while (cin >> text)
	{
		std::transform(text.begin(), text.end(), text.begin(), ::tolower);

		cin >> q;
		queries.clear(); queries.resize(q); counts.clear(); counts.resize(q);
		
		for(unsigned int i=0; i<q; i++)
		{
			cin>> queries[i].l >> queries[i].r;
			counts[i] = 0;
		}

		count_awesome_strings();
	}
	
	print_counts_in_range();
}

void Str::count_awesome_strings()
{
	//unsigned int D = pow(10, string("Awesome").size()-1); D = D%P;
	if(text.size() < key.size()) // If text size smaller than keyword then return zero.
	{
		for(unsigned int i=0; i<q; i++)
			cout << 0 << endl;
		return;
	}

	vector<unsigned int> index;

	// calcluate rolling hash for key and same no of char's in text.
	uint64_t val_k = 1, val_t = 1;
	for(unsigned int i=0; i<key.size(); i++)
	{
		val_k = val_k *  (key[i]-OFFSET);  //val_k = val_k % P;
		val_t = val_t *  (text[i]-OFFSET); //val_t = val_t % P;
		arr[text[i]] = 1;
	}

	for(unsigned int i=0; i<=(text.size() - key.size()); i++)
	{
		if(val_k == val_t)
		{
			/*
			if( 0 == text.compare(i, key.size(), key)) // It matches the key.
			{
				index.push_back(i);
				cout <<" Found the match at " << i << endl;
			}
			*/
			//cout <<" Found the match at " << i << endl;
			if(is_matching()) 
			{ 
				update_matching_range(i+1, i+key.size());
				//cout <<" Found the match at " << i << endl;
			}
		}

		//val_t = ((val_t + D*P  - D * text[i]) * 10 + text[i+1]) % P;
		val_t =  (text[i+key.size()]-OFFSET) * ( val_t / (text[i]-OFFSET));
		arr[text[i]] = 0; arr[text[i+key.size()]] = 1;
		
	}
}


void Str::update_matching_range(unsigned int _l, unsigned int _r)
{
	for(unsigned int i=0; i<queries.size(); i++)
	{
		if(_l>=queries[i].l && _r<=queries[i].r && _l<_r)
		{
			counts[i] = counts[i]+1;
		}
	}
}


void Str::print_counts_in_range()
{
	for(unsigned int i=0; i<queries.size(); i++)
	{
		cout<<counts[i] << endl;
	}
}

int main()
{
	Str obj;
	obj.read_input();
	return 0;
}
