#include<vector>
#include<algorithm>
#include <iostream>
using namespace std;


//Project Team

class Proj
{
	private:
		unsigned int T, N;
		
	public:
		void execute();
};

void Proj::execute()
{
	cin >> T;
	vector<unsigned int> arr;

	for(unsigned int i=0; i<T; i++)
	{
		arr.clear();
		cin >> N;
		arr.resize(N);
		for(unsigned int j=0; j<N; j++)
			cin >> arr[j];
#if DEBUG
		for(unsigned int j=0; j<N; j++)
			cout << arr[j] <<" ";
		cout << endl;
#endif
		sort(arr.begin(), arr.end());
#if DEBUG
		for(unsigned int j=0; j<N; j++)
			cout << arr[j] <<" ";
		cout << endl;
#endif
		vector<unsigned int> arr_sum;
		for(unsigned i=0; i<N/2; i++)
		{
			arr_sum.push_back(arr[i]+arr[N-1-i]);
		}
		sort(arr_sum.begin(), arr_sum.end());
		int val1 = arr_sum[0];
		int val2 = arr_sum[N/2-1];
		
		cout << abs(val1-val2) << endl;
	}
}

int main()
{
	Proj obj;
	obj.execute();
	return 0;
}