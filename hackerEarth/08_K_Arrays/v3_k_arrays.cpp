#include <stdint.h>
#include<iostream>
using namespace std;

class k_arr
{
	private:
		unsigned int T, N, K;
		uint64_t arr[14][19];
	public:
		void read_input();
		void calculate_PQ();


};

void k_arr::read_input()
{
	const uint64_t NUM = 7+1e9;
	//cout<<"\n NUM= " << (NUM) << endl;
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
		 calculate_PQ();
	}

}


void k_arr::calculate_PQ()
{
const uint64_t NUM = 7+1e9;

uint64_t sum_arr[N];
for(int j=0; j<N; j++)
{
	uint64_t sum =0;
	for(int i=0; i<K; i++)
	{
		sum += arr[i][j];
	}
	sum_arr[j] = sum;
}
	unsigned long int  max_p = 0, max_size=0; unsigned long int min_p = -1, min_size = -1;

	for(int i=0; i<N; i++)
	{
		for(int j=i; j<N; j++)
		{
			uint64_t  sum = 1;
			const uint64_t X = j-i+1;
			const uint64_t MAX_VAL = X * NUM;
			//cout<< endl;
			for(int k=i; k<=j;k++)
			{
				uint64_t _sum = sum * sum_arr[k];
				if(_sum > MAX_VAL)
				{	
					//cout<<" ***** sum= " << _sum << endl;
					_sum = _sum % NUM;
				}
				sum = _sum;
			}
			//uint64_t  _Q = sum / X; uint64_t  _P = _Q % NUM;
			sum = sum/X;
			uint64_t _P = sum % NUM;

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
	//cout<<"min_p= " << min_p <<", min_size= " << min_size << endl;
	//cout<<"max_p= " << max_p <<", max_size= " << max_size << endl;
	cout << (min_p ^ max_p) <<" " << (min_size ^ max_size) << endl;
}

int main()
{
	k_arr obj;
	obj.read_input();
	return 0;
}
