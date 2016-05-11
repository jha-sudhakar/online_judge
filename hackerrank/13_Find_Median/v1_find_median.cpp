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
	cin >> N;
	unsigned int l1,l2;
	l1 = -1; l2 = 0;
	double avg=0.0;
	for(unsigned int i=0; i<N; i++)
	{
		cin >> arr[i];
		if((i+1)%2) // Odd case, both l1 and l2 should point to same value;
		{
			l1++;
			avg= arr[l1]+arr[l2];
		} else // Even no of objects, l1+1 should be l2;
		{
			l2++;
			avg= arr[l1]+arr[l2];
		}

		cout << fixed << setprecision(1) << (avg/2.0) << endl;
	}
}

int main()
{
	fm obj1;
	obj1.process_input();
	return 0;
}
