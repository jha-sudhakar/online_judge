#include<stdlib.h>
#include<assert.h>
#include<math.h>

#include<algorithm>
#include<queue>
#include<iomanip>
#include<iostream>
using namespace std;

//unsigned int arr[100000];
//unsigned int la[100000];

vector<unsigned int> arr, la;
class fm
{
	private:
		//vector<unsigned int> arr;
		unsigned int N;

	public:
		void process_input();
		//fm() { srand(time(NULL)); }
};

void fm::process_input()
{
	N = 1+ rand()%100;
	arr.resize(N); la.resize(N);
	for(unsigned int i=0; i<N; i++)
		la[i] = arr[i] = rand()%1000;

	priority_queue<unsigned int, vector<unsigned int>, less<unsigned int> > max_pq; // Keeps 1st half of data.
	priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int> > min_pq; // Keeps 2nd half of data +1..

	long double avg=0.0, lavg=0.0;
	//Special handling for first two elements;
	if(N == 1)
	{
		cout<<" Input size= " << N <<", Mean= " << fixed << setprecision(1) << double(arr[0]) << endl;
		return;
	} else if(N == 2)
	{
		cout<<" Input size= " << N <<", Mean= " << fixed << setprecision(1) << double(arr[0]) << endl;
		cout<<" Input size= " << N <<", Mean= " << fixed << setprecision(1) << double(arr[0]+arr[1])/2.0 << endl;
		return;
	}
	else
	{
		if(arr[0] > arr[1])
		{
			min_pq.push(arr[0]);
			max_pq.push(arr[1]);
		} else
		{
			max_pq.push(arr[0]);
			min_pq.push(arr[1]);
		}
		//cout << fixed << setprecision(1) << double(arr[0]) << endl;
		//cout << fixed << setprecision(1) << double(arr[0]+arr[1])/2.0 << endl;
	}

	for(unsigned int i=2; i<N; i++)
	{
		if((i+1)%2 == 1) //Before new value, both have Equal no of elements and now right half should get one extra;.
		{
			if(arr[i] > max_pq.top())
			{
				min_pq.push(arr[i]);
			}
			else
			{
				min_pq.push(max_pq.top());
				max_pq.pop();
				max_pq.push(arr[i]);
			}

		} else // Before this value, right half has one element more so balance them.
		{
			if(arr[i] <  min_pq.top())
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
	
		//cout <<"Size= " << (i+1) <<"   left_pq-top = " << max_pq.top() <<", right_pq-top= " << min_pq.top() << endl;
		//cout << fixed << setprecision(1) << (avg/2.0) << endl;
	}


	if((N)%2) 
		avg = min_pq.top() + min_pq.top();
	else
		avg = min_pq.top() + max_pq.top();
	avg = avg/2.0;
	//cout << fixed << setprecision(1) << avg << endl;
	
	sort(la.begin(), la.end());
	lavg = la[floor(double(N+1)/2.0)-1] + la[ceil(double(N+1)/2.0)-1];
	lavg = lavg/2.0;
	if(lavg != avg)
	{
		cout<<"Heap-avg= " << avg <<", arry-avg= " << lavg << endl;

		cout << "Un-sorted array, N= " << N <<" -- ";
		for(unsigned int i=0; i<N; i++)
			cout << arr[i] <<"  ";
		cout<<endl;

		cout << "---Sorted array, N= " << N <<" -- ";
		for(unsigned int i=0; i<N; i++)
		{
			cout << la[i];
			if((i+1 == (ceil(double(N+1)/2.0))) || (i+1 == (floor(double(N+1)/2.0))))
				cout<<"<-";
			else
				cout <<"  ";
		}
		cout << endl;
		assert(false);
	}
	else
	{
		cout<<" Input size= " << N <<", Mean= " << fixed << setprecision(1) << lavg << endl;
	}
}

int main(int argc, char* argv[])
{

	srand(time(NULL));
	int loop= atoi(argv[1]);
	for(int i=0; i<loop; i++)
	{
		fm obj1;
		obj1.process_input();
	}
	return 0;
}
