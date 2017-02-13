#include<iostream>
using namespace std;

class Nty
{
	private:
		unsigned int stream[200001];
		unsigned int N, D, arr[201];
		unsigned int index[3][10]; //At offset 100, 50, 25.
		unsigned int mid1, mid2, notification_count;
	private:
		void process_stream();
		void process_notification(const unsigned int pos);
	public:
		void read_input();


};

void Nty::read_input()
{
	notification_count = 0;
	for(unsigned int i=0; i<201; i++)
	{
		arr[i] = 0;
	}
	for(unsigned int i=0; i<3; i++)
		for(unsigned int j=0; j<10; j++)
			index[i][j] = 0;
	cin >> N >> D;
	
	mid1 = (D+1)/2;
	mid2 = (D+2)/2;

	process_stream();
}


void Nty::process_stream()
{
	unsigned int tmp, i=0;
	for(i=0; i<D; i++)
	{
		cin >> tmp;
		stream[i] = tmp;
		arr[tmp]++;
	}

	for(i=D; i<N; i++)
	{
		cin >> tmp;
		stream[i] = tmp;
		process_notification(i);
		arr[tmp]++;
		arr[stream[i-D]]--;
	}
	
	cout << notification_count << endl;
		
}

void Nty::process_notification(const unsigned int pos)
{
	unsigned int mid1_val, mid2_val,sum=0, i;
	for(i=0; i<201; i++)
	{
		sum+= arr[i];
		if(sum >=mid1)
			break;
	}
	mid1_val = i;
	if(sum >=mid2)
		mid2_val = i;
	else
	{
		for(++i; i<201; i++)
		{
			if(arr[i])
				break;
		}
		mid2_val = i;
	}
	unsigned int max_spend = (mid1_val+mid2_val);
	if(stream[pos] >= max_spend)
	{
		notification_count++;
	}
}


int main()
{
Nty obj;
obj.read_input();
return 0;
}
