
#include <assert.h>
#include <string>
#include <stdint.h>
#include <iostream>
using namespace std;

uint64_t grid[1001][1001];
class Grid
{
	private:
		unsigned int D, N, K,A;
		unsigned int x1,y1,x2,y2, z;
		string op;
		uint64_t PRIME;
	public:
		void read_input();
		void set_op();
		void  get_op();
		Grid(): PRIME(7+1.0e9) { /*cout<<"PRime= " << PRIME << endl;*/ }
		
};


void Grid::get_op()
{
	uint64_t sum = 0;
	for(int i=x1; i<=x2; i++)
		for(int j=y1; j<=y2; j++)
		{
			sum += grid[i][j];
			if(sum/PRIME) { sum = sum % PRIME;}

		}

	cout<< (sum % PRIME) << endl;
}


void Grid::set_op()
{
	uint64_t val = grid[x1][y1];
	val = (val % PRIME)* (z % PRIME);;
	val = val % PRIME;
	grid[x1][y1] = val;
}


void Grid::read_input()
{
	cin >> D;
	while(D>0)
	{
		cin >> N >> K;
		for(int i=1; i<=N; i++)
			for(int j=1; j<=N; j++)
				grid[i][j] = K;
		cin >> A;
		while(A>0)
		{
			cin >> op;
			if(op[0] == 's')
			{
				cin >> x1 >> y1 >> z;
				set_op();
			} else if(op[0] == 'm')
			{
				cin >> x1 >> y1 >> x2 >> y2;
				get_op();
			} else
			{
				assert(false);
			}			

			A--;
		}

		D--;
	}
}

int main()
{
Grid obj;
obj.read_input();
return 0;
};
