#include<string>
#include<iostream>
using namespace std;


#define MAX 100001

class PQ
{
	private:
		unsigned int arr[MAX];
		unsigned int start, end;
	private:
		void push(const unsigned int score);
		unsigned int diff();
		unsigned int count_high();
		unsigned int count_low();

	public:
		PQ();
		void read_input();
	
};

PQ::PQ()
{
	start = end = 0;
	for(unsigned int i=0; i<MAX; i++)
		arr[i] = 0;
}

void PQ::read_input()
{
	unsigned int Q, _score;
	cin >> Q;
	string in_str;

	for(unsigned int i=0; i<Q; i++)
	{
		cin >> in_str;
		if(in_str == "Push")
		{
			cin >> _score;
			push(_score);
		} else if(in_str == "Diff")
		{
			diff();
		} else if(in_str == "CountHigh")
		{
			count_high();
		} else if(in_str == "CountLow")
		{
			count_low();
		}
	}
}

void PQ::push(const unsigned int score)
{
	if(start == 0)
	{
		start = end = score;
		arr[score] = 1;
		return;
	}

	arr[score]++;
	if(score<start)
		start = score;
	else if(score>end)
		end = score;

}

unsigned int PQ::diff()
{
	if(start = 0)
	{
		cout << -1 << endl;
		return;
	}
	if(start ==  end)
	{
		if(arr[start]>0)
			arr[start]--;

		if(arr[start] == 0)
		{
			start = end = 0;
		}
	}
	else
	{
		arr[end]--;
		arr[start]--;
		unsigned int l=start;
		while(arr[start] == 0 && start < MAX)
		start++;

		if(start == MAX || end == 0)
			start = end = 0;
		
		while(arr[end] == 0 && end>0)
		end--;
	}
}

unsigned int PQ::count_high()
{


}

unsigned int PQ::count_low()
{


}

int main()
{



	return 0;
}
