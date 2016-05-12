#include<assert.h>

#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

#define LEN 100000


//unsigned int t[LEN], l[LEN];;

struct order
{
	unsigned int tm,ln;
	order(unsigned int _tm, unsigned int _ln) { tm = _tm; ln=_ln; }
	order() { }
	bool operator<(const order& o) const
	{
		if(ln >  o.ln) // Greater comparison for min priority queue, vice-versa otherwise.
			return true;
		else if(ln == o.ln)
		{
			if(tm > o.tm)
				return true;
			else
				return false;
		} 
		else
			return false;
	}
};

bool compare_order(const order& l, const order& r)
{
	if(l.tm <  r.tm) // Greater comparison for min priority queue, vice-versa otherwise.
		return true;
	else
		return false;
}

struct order lst[LEN];

class mwt
{
	private:
		unsigned long int N;

	public:
		void process_input();
};

void mwt::process_input()
{
	cin >> N;
	for(unsigned int k=0; k<N; k++)
	{
		cin >> lst[k].tm >> lst[k].ln;
	}

	sort(lst, lst+N, compare_order);

	unsigned long int total_wait=0;
	priority_queue<order> min_pq;
	unsigned int i=0;
	unsigned long int cur_max_order_time = 0;
	while(i != N || !min_pq.empty())
	{
		if(min_pq.empty())
		{
			if(cur_max_order_time > lst[i].tm)
				assert(false);

			cur_max_order_time = lst[i].tm;
			min_pq.push(order(lst[i].tm, lst[i].ln));
			i++;
			continue;
		}

		order cur_order= min_pq.top();
		min_pq.pop();
		if(cur_max_order_time < cur_order.tm)
			assert(false);

		total_wait += (cur_max_order_time - cur_order.tm) + cur_order.ln;
		cur_max_order_time += cur_order.ln;
		while(i < N)
		{
			if(lst[i].tm <= cur_max_order_time)
			{
				min_pq.push(order(lst[i].tm, lst[i].ln));
				i++;
			}
			else
			{
				break;
			}
		}
	}

	unsigned long int avg_wait_time = total_wait/N;
	cout << avg_wait_time  << endl;
}

int main()
{	
	mwt obj1;
	obj1.process_input();
	return 0;
}	

