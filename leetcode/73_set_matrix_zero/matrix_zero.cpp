#include<stdlib.h>
#include<assert.h>
#include<time.h>

#include<vector>
#include<iostream>
using namespace std;

class mt
{
	private:
		unsigned int m,n, r,c;
		vector< vector<int> > a, b;
	public:
		mt() { srand(time(NULL)); }
		void process_input();
		void set_matrix_b();
		void set_matrix_a();
		void validate_matrix();
		void print_matrix();
};

void mt::print_matrix()
{
	cout<<"\nPrinting a with inplace logic -------------\n";
	for(unsigned int i=0; i<m; i++)
	{
		for(unsigned int j=0; j<n; j++)
		{
			cout << a[i][j] <<" " ;
		}
		cout << endl;
	}

	cout<<"\nPrinting b with extra mem logic -------------\n";
	for(unsigned int i=0; i<m; i++)
	{
		for(unsigned int j=0; j<n; j++)
		{
			cout << b[i][j] <<" " ;
		}
		cout << endl;
	}
	cout <<endl;
}


void mt::process_input()
{
	m = 5 + rand()% 20;
	n = 5 + rand()% 20;

	a.clear(); b.clear();
	a.resize(m); b.resize(m);

	for(unsigned int i=0; i<m; i++)
	{
		a[i].resize(n); b[i].resize(n);
		for(unsigned int j=0; j<n; j++)
		{
			unsigned int val = 10 + (rand()%1000);
			if(val%7)
			{
				a[i][j] = b[i][j] = val;
			}
			else
			{
				a[i][j] = b[i][j] = 0;

			}	
		}
	}
	
	set_matrix_a();
	set_matrix_b();
	validate_matrix();
}
void mt::set_matrix_a()
{

	if(m == 0 && n == 0)
		return;

	bool is_first_row_zero = false;
	bool is_first_col_zero = false;
	for(int j=0; j<n; j++)
	{
		if(a[0][j] == 0)
		{
			is_first_row_zero = true;
			break;
		}
	}

	if(m == 1)
	{
		if(is_first_row_zero)
			for(int j=0; j<n; j++)
				a[0][j] = 0;
		return;	
	}

	for(int i=0; i<m; i++)
	{
		if(a[i][0] == 0)
		{
			is_first_col_zero = true;
			break;
		}
	}
	if(n == 1)
	{
		if(is_first_col_zero)
			for(int i=0; i<m; i++)
				a[i][0] = 0;
		return;	
	}
	// for(int i=0; i<m; i++) a[i][n-1] = a[i][0];
	// for(int j=0; j<n-1; j++) a[0][j] = a[m-1][0];
	for(unsigned int i=1; i<m; i++)
	{
		for(unsigned int j=1; j<n; j++)
		{
			if(a[i][j] == 0)
			{
				a[0][j] = 0;
				a[i][0] = 0;
			}
		}
	}

	for(unsigned int i=1; i<m; i++)
	{
		if(a[i][0] == 0)
		{
			for(unsigned int j=1; j<n; j++)
			a[i][j] = 0;
		}
	}

	for(unsigned int j=1; j<n; j++)
	{
		if(a[0][j] == 0)
		{
			for(unsigned int i=1; i<m; i++)
			a[i][j] = 0;
		}
	}

	if(is_first_row_zero == true)
		for(unsigned int j=0; j<n; j++)
			a[0][j] = 0;
			

	if(is_first_col_zero == true)
		for(unsigned int i=0; i<m; i++)
			a[i][0] = 0;
}


void mt::set_matrix_b()
{
	unsigned int rows[m];
	unsigned int cols[n];

	for(unsigned int i=0; i<m; i++)
		rows[i] = 1;

	for(unsigned int i=0; i<n; i++)
		cols[i] = 1;

	for(unsigned int i=0; i<m; i++)
	{
		for(unsigned int j=0; j<n; j++)
		{
			if(b[i][j] == 0)
			{
				rows[i] =0; cols[j]=0;
			}

		}
	}	

	for(unsigned int i=0; i<m; i++)
	{
		if(rows[i] == 1)
			continue;

		for(unsigned int j=0; j<n; j++)
			b[i][j] = 0;
	}

	for(unsigned int j=0; j<n; j++)
	{
		if(cols[j] == 1)
			continue;

		for(unsigned int i=0; i<m; i++)
			b[i][j] = 0;
	}
}

void mt::validate_matrix()
{
	for(unsigned int i=0; i<m; i++)
		for(unsigned int j=0; j<n; j++)
		{
			if(a[i][j] != b[i][j])
			{
				print_matrix();
				assert(false);
			}	
		}
}


int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		cout<<"Usage:- exe count\n";
		return 0;
	}
	int loop = atoi(argv[1]);
	mt obj1;
	for(int i=0; i<loop; i++)
	{
		obj1.process_input();
		cout <<"Completed loop " << i+1 << endl;
	}
	return 0;

}
