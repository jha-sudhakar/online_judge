#include<iostream>
using namespace std;

#define log cout


class RM
{
	private:
		unsigned int N, Q, A;
		unsigned int** a;
	
	public:
		void process_input();
		void rotate_and_print_matrix(unsigned int);
};


void RM::process_input()
{

	cin >> N >> Q;

	a = new unsigned int* [N];
	for(unsigned int i=0; i<N; i++)
	{
		a[i] = new unsigned int [N];
	}

	log <<"Input = \n";
	for(unsigned int i=0; i<N; i++)
	{
		for(unsigned int j=0; j<N; j++)
		{
			unsigned int tmp; cin >> tmp;
			a[i][j] = tmp;
			log  << a[i][j] << " ";
		}
		log << endl;
	}

	for(unsigned int k=0; k<N; k++)
	{
		unsigned int q; cin >> q;
		rotate_and_print_matrix(q);
	}
}

void RM::rotate_and_print_matrix(unsigned int q)
{
	q = q%360;

	unsigned int cur_a[N][N];
	unsigned int prev_a[N][N];
	for(int i=0; i<N;i++)
		for(int j=0; j<N; j++)
			prev_a[i][j] = a;

	unsigned int **prev=prev_a, **cur=cur_a;;
	for(int loop=0; loop<q/90; loop++)
	{


	}

}

int main()
{

RM obj1;
obj1.process_input();
return 0;
}
