#include<iostream>
using namespace std;

class k_arr
{
	private:
		unsigned int T, N, K;
		unsigned int arr[10][16];
	public:
		void read_input();
		void calculate_PQ();


};

void k_arr::read_input()
{
	cin >> T;
	for(int i1=0; i1<T; i1++)
	{
		cin >> N >> K;
		for(int i2=0; i2<K; i2++)
		{
			for(int i3=0;i3<N; i3++)
			{
				cin >> arr[i2][i3];
			}
		}
	}

	calculate_PQ();
}


void k_arr::calculate_PQ()
{
const unsigned long int NUM = 7+1e9;

unsigned int sum_arr[N];
for(int j=0; j<N; j++)
{
	unsigned int sum =0;
	for(int i=0; i<K; i++)
	{
		sum += arr[i][j];
	}
	sum_arr[j] = sum;
}
	unsigned int max_p = 0, max_size=0; unsigned int min_p = -1, min_size = -1;

	for(int i=0; i<N; i++)
	{
		for(int j=i; j<N; j++)
		{
			unsigned long long  sum = 1;
			unsigned int X = j-i+1;
			for(int k=i; k<=j;k++)
			{
				sum = sum * sum_arr[k];
			}
			unsigned long long  _Q = sum / X;
			unsigned int _P = _Q % NUM;

			// Handles min-case;
			if(_P < min_p)
			{
				min_p = _P;
				min_size = X;
			} else if (_P == min_p)
			{
				if(min_size < X)
					min_size = X;
			}


            // Handles max-case;
            if(_P >  max_p)
            {
                max_p = _P;
                max_size = X;
            } else if (_P == max_p)
            {
                if(max_size > X)
                    max_size = X;
            }

		}
	}
	//cout<<"\n min_p= " << min_p <<", min_size= " << min_size << endl;
	//cout<<"\n max_p= " << max_p <<", max_size= " << max_size << endl;
	cout << (min_p ^ max_p) <<" " << (min_size ^ max_size) << endl;
}

int main()
{
	k_arr obj;
	obj.read_input();
	return 0;
}
