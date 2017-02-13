#include<assert.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;

#define MAX 1000

typedef unsigned int mytype;

class PQ
{
	private:
		mytype arr[MAX];
		unsigned int size, start;
		
	private:
		void swap_val(mytype& val1, mytype& val2);
		void send_up(unsigned int pos);
		void send_down(unsigned int pos);
	public:
		PQ() { srand(time(NULL)); size= 0; start = 1; }
		void test_automation();
		const unsigned int get_size() { return size; }
		void read_input();
		void build_heap();
		void insert(const mytype ele);
		const mytype root();
		const mytype pop_root();
};

void PQ::test_automation()
{
	unsigned int l=0,loop = 200000;
	while(l++<loop)
	{
		unsigned int rand_size = rand()%500;
		cout <<"\nRunning loop " << l << ", op-count= " << rand_size << endl;
		priority_queue<int, vector<int>, greater<int> > stl_mpq;
		cout <<"\nInsert/pop elements\n";
		for(unsigned int i=0; i<rand_size; i++)
		{
			unsigned int num = 10+ rand()%50;
			if(rand()%3)
			{
				stl_mpq.push(num);
				insert(num);
				cout << num << ", ";
			}
			else if(get_size())
			{
				pop_root();
				stl_mpq.pop();
			}
			if(get_size() != stl_mpq.size())
				assert(false);
		}
		
		cout <<"\nMy Sorted elements\n";
		
		while(get_size())
		{
			mytype val = pop_root();
			if(val != stl_mpq.top())
			{
				cout <<"\n My code val= " << val <<", stl-val= " << stl_mpq.top() << endl;
				assert(false);
			}
			cout << val << ", ";
			stl_mpq.pop();
		}
		cout << endl;
		if(get_size() != stl_mpq.size())
			assert(false);
	}
}

void PQ::swap_val(mytype& val1, mytype& val2)
{
	mytype buf = val1;
	val1 = val2;
	val2 = buf;
}

void PQ::read_input()
{
	//fill random input

}
void PQ::build_heap()
{

}

void PQ::send_up(unsigned int pos)
{
	while(pos > start)
	{
		unsigned int parent_pos = pos/2;
		if( arr[parent_pos] > arr[pos])
		{
			swap_val(arr[pos], arr[parent_pos]);
			pos = parent_pos;
		}
		else
		{
			break;
		}
	}
}

void PQ::send_down(unsigned int pos)
{
	while(pos < size)
	{
		unsigned int child_pos = pos*2;
		if(child_pos > size)
			return;
		if(size>= child_pos+1 && arr[child_pos] > arr[child_pos+1])
		{
			child_pos++;
		}
		if((child_pos > size) || (arr[pos] <= arr[child_pos]))
		{		
			break;
		}
		else
		{
			swap_val(arr[pos], arr[child_pos]);
			pos = child_pos;
		}
	}
}

void PQ::insert(const mytype ele)
{
	size++;
	arr[size] = ele;
	send_up(size);
}

const mytype PQ::pop_root()
{
	if(size == 0)
		return 0;
	mytype buf = arr[start];
	arr[start] = arr[size];
	size--;

	send_down(start);
	return buf;
}

const mytype PQ::root()
{
	if(size != 0)
		return arr[start];
	else
		return 0;
}


int main()
{
PQ obj;
obj.test_automation();
return 0;
}
