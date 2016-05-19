#include<math.h>

#include<map>
#include<vector>
#include<iostream>
using namespace std;

//unsigned int max_num[32];

class diff
{
	private:
		unsigned int N, K;
		vector<unsigned int> arr;
		map<unsigned int, bool> m[32];

	public:
		void process_input();
		diff();
		unsigned int count_diff_k();
};

diff::diff()
{
	//for(unsigned int i=0; i<32; i++) { max_num[i] = 2 << i; }
}

void diff::process_input()
{
	cin >> N >> K;
	unsigned int buf;
	for(unsigned int i=0; i<N; i++)
	{
		cin >> buf;
		arr.push_back(buf);
		unsigned int index = log2(buf);
		m[index][buf] = false;
	}

	cout << count_diff_k() << endl;
}

unsigned int diff::count_diff_k()
{
	unsigned int diff_counter = 0;

	for(unsigned int i=0; i<N; i++)
	{
		unsigned int index = log2(arr[i]);
		//if(m[index][arr[i]] == true) // This is already counted.
		//	continue;

		unsigned int num1=0, num2 = arr[i]+K;
		unsigned int index1=0, index2= log2(num2);
		if(arr[i] > K) 
		{
			num1= arr[i]-K;
			index1 = log2(num1);
		}	
		
		if(m[index2].find(num2) != m[index2].end())
		{
			if(m[index2][num2] == false)
			{	
				m[index][arr[i]] = true;
				diff_counter++;
			}	
		}

		if((num1 != 0) && (m[index1].find(num1) != m[index1].end()))
		{
			if(m[index1][num1] == false)
			{
				m[index][arr[i]] = true;
				diff_counter++;
			}	
		}
	}
	return diff_counter;
}

int main()
{
	diff obj;
	obj.process_input();
	return 0;
}
