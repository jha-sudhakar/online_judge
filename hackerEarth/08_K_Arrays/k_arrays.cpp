
#include <math.h>
#include <stdint.h>
#include<iostream>
using namespace std;

class k_arr
{
	private:
		unsigned int T, N, K;
		uint64_t arr[20][20];
		uint64_t max_uint64_t_val;
	public:
		void read_input();
		void calculate_PQ();


};

void k_arr::read_input()
{
	max_uint64_t_val = -1;
	//const uint64_t NUM = 7+1e9; cout<<"\n NUM= " << (NUM) << endl;
	cin >> T;
	for(int i1=0; i1<T; i1++)
	{
		cin >> N >> K;
		for(int i2=0; i2<K; i2++)
		{
			for(int i3=0;i3<N; i3++)
			{
				uint64_t val=0; cin >> val;
				arr[i2][i3] = val;
			}
		}
		 calculate_PQ();
	}

}


void k_arr::calculate_PQ()
{
	const uint64_t NUM = 7+1e9;
	uint64_t sum_arr[N];
	unsigned long int  max_p = 0, max_size=100; unsigned long int min_p = 8+1e9, min_size = 0;
	const unsigned int BIT_MAX = (pow(2,N) -1);
	//cout<<"N= " << N <<", BIT_MAX= " << BIT_MAX << endl;

	for(unsigned int i=1; i<=BIT_MAX; i++)
	{
		//cout<<endl;
		uint64_t  mul = 1;
		uint64_t X = 0;
        for(unsigned int j=0; j<N; j++)
        {
            unsigned int cur_val = 1 << j;
            //cout<<" --> " << j+1 << endl;
            if(0 == (i & cur_val))
            {
                continue; //This index is not selected;
            }
			X++;
		}
		const uint64_t MAX_VAL = X * NUM;
		double MAX_VAL_FLOAT = log(max_uint64_t_val);

		for(unsigned int j=0; j<N; j++)
		{
			unsigned int cur_val = 1 << j;
			if(0 == (i & cur_val))
			{
				continue; //This index is not selected;
			}

			uint64_t sum_k = 0;
	        for(int i=0; i<K; i++)
		    {
				mul = mul % MAX_VAL;
				uint64_t tmp = mul* arr[i][j];
				double TMP_FLOAT = log(mul) + log(arr[i][j]);
				//if(TMP_FLOAT+0. > MAX_VAL_FLOAT) { 	cout<<"MAX_VAl= " <<MAX_VAL <<", mul= " << mul <<", arr-val= " << arr[i][j] << endl; }
				//if(tmp > MAX_VAL) { /*cout<<"Over-run with tmp, MAX_VAL=" << MAX_VAL  << endl;*/   tmp = tmp % MAX_VAL;}
			    sum_k += tmp;
				//if(sum_k > MAX_VAL) { /*cout<<"Over-run with sum_k, MAX_VAL= " << MAX_VAL  << endl;*/ sum_k = sum_k % MAX_VAL; }
			}
			mul = sum_k;
		}

		mul = mul/X;
		const uint64_t _P = mul % NUM;
		//cout<<"\n X= " << X << ", P= " << _P << endl;

		// Handles min-case;
		if(_P < min_p)
		{
			min_p = _P;
			min_size = X;
		} else if (_P == min_p)
		{
			if(min_size < X) { 	min_size = X;}
		}


        // Handles max-case;
        if(_P >  max_p)
        {
			max_p = _P;
            max_size = X;
        } else if (_P == max_p)
        {
			if(max_size > X) { max_size = X; }
		}	
	}
	//cout<<"max_p= " << max_p <<", max_size= " << max_size << " ";
	//cout<<"min_p= " << min_p <<", min_size= " << min_size << " ";
	cout << (min_p ^ max_p) <<" " << (min_size ^ max_size) << endl;
}

int main()
{
	k_arr obj;
	obj.read_input();
	return 0;
}
