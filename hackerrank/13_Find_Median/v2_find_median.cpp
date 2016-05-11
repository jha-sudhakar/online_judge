#include<queue>
#include<iomanip>
#include<iostream>
using namespace std;

unsigned int arr[100000];
class fm
{
	private:
		//vector<unsigned int> arr;
		unsigned int N;

	public:
		void process_input();
};

void fm::process_input()
{
	priority_queue<unsigned int, vector<unsigned int>, less<unsigned int> > max_pq; // Keeps 1st half of data.
	priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int> > min_pq; // Keeps 2nd half of data +1..

	cin >> N;
	double avg=0.0;
	//Special handling for first two elements;
	if(N == 1)
	{
		cin >> arr[0];
		cout << fixed << setprecision(1) << double(arr[0]) << endl;
		return;
	} else if(N == 2)
	{
		cin >> arr[0];
		cin >> arr[1];
		cout << fixed << setprecision(1) << double(arr[0]) << endl;
		cout << fixed << setprecision(1) << double(arr[0]+arr[1])/2.0 << endl;
		return;
	}
	else
	{
		cin >> arr[0];
		cin >> arr[1];
		if(arr[0] > arr[1])
		{
			min_pq.push(arr[0]);
			max_pq.push(arr[1]);
		} else
		{
			max_pq.push(arr[0]);
			min_pq.push(arr[1]);
		}
		cout << fixed << setprecision(1) << double(arr[0]) << endl;
		cout << fixed << setprecision(1) << double(arr[0]+arr[1])/2.0 << endl;
	}

	for(unsigned int i=2; i<N; i++)
	{
		cin >> arr[i];
		if((i+1)%2 == 1) //Before new value, both have Equal no of elements.
		{
			if(arr[i] >= max_pq.top())
			{
				min_pq.push(arr[i]);
			}
			else
			{
				min_pq.push(max_pq.top());
				max_pq.pop();
				max_pq.push(arr[i]);
			}

		} else // Before this value, right half has one lement more so balance them.
		{
			if(arr[i] <=  max_pq.top())
			{
				max_pq.push(arr[i]);
			}
			else
			{
				max_pq.push(min_pq.top());
				min_pq.pop();
				min_pq.push(arr[i]);
			}
		}
		
		if((i+1)%2) 
			avg = min_pq.top() + min_pq.top();
		else
			avg = min_pq.top() + max_pq.top();
	
		cout <<"Size= " << (i+1) <<"   left_pq-top = " << max_pq.top() <<", right_pq-top= " << min_pq.top() << endl;
		//cout << fixed << setprecision(1) << (avg/2.0) << endl;
		cout << setprecision(1) << (avg/2.0) << endl;
	}
}

int main()
{
	fm obj1;
	obj1.process_input();
	return 0;
}
