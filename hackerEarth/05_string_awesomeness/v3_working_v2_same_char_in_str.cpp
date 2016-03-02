#include <unistd.h>

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
	unsigned int index;
};

bool compare_range(const range &x, const range& y)
{
	return (x.l > y.l);
}

class Str
{

	private:
		string key;
		string text;
		unsigned int q;
		vector<range> queries;
		vector<unsigned int> counts;
		int arr[256];
		int ref_arr[256];
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
		queries.clear(); queries.resize(q); counts.clear(); counts.resize(q);
		
		for(unsigned int i=0; i<q; i++)
		{
			cin>> queries[i].l >> queries[i].r; queries[i].index = i;
			counts[i] = 0;
		}

#if 1
		std::sort(queries.begin(), queries.end(), compare_range);
		// for(unsigned int k=0; k<queries.size(); k++) cout<<"Range " << k+1 <<" = [" << queries[k].l <<", " << queries[k].r <<"]\n";
#endif
		count_awesome_strings();
	}
	
	print_counts_in_range();
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
				update_matching_range(i+1, i+key.size());
				//cout <<" Found the match at " << i << endl;
			}
		}

		val_t =  (text[i+key.size()]-OFFSET) * ( val_t / (text[i]-OFFSET));
		arr[text[i]]--; arr[text[i+key.size()]]++;
		
	}
}


void Str::update_matching_range(unsigned int _l, unsigned int _r)
{
	unsigned int start_index = 0, low=0, high = queries.size()-1;

	//cout<<" Calling range queries ........................................................" << endl;
#if 1
	while(1)
	{
        if((high-low) <2)
        {
            start_index = low; // Sorted in decreasing order.
            break;
        }

		unsigned int mid = (low+high)/2;
		if(queries[mid].l > _l)
		{
			low = mid+1;
		} else 
		{
			high = mid-1;
		}
		//cout<<"\n Low = " << low <<", High = " << high <<", mid = " << mid << endl; sleep(1);
	}
#endif
	for(unsigned int i=start_index; i<queries.size(); i++)
	{
		if(_l>=queries[i].l && _r<=queries[i].r && _l<_r)
		{
			counts[queries[i].index] =  counts[queries[i].index] +  1;
		}
		
		//if(_l > queries[i].r) { return;}
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
