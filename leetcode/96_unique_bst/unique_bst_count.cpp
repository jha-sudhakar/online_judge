#include <iostream>
using namespace std;

class unique_bst_count
{
	private:
		int N;

	public:
		int count_trees();
		unique_bst_count(int _N) { N = _N; }
};

int unique_bst_count::count_trees()
{
	int table[N+1];
	table[0] = 1;
	table[1] = 1;
	table[2] = 2;
	if(N<3)
		return table[N];

	int n,root;
	for(n=3; n<=N; n++)
	{
		int sum = 0;
		for(root=1; root<=n;root++)
		{
			int left_count = table[root-1];
			int right_count = table[n-root];
			sum += (left_count * right_count);
		}
		table[n] = sum;
	}
	return table[n-1];
}
