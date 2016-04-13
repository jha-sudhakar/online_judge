#include<assert.h>

#include<vector>
#include<iostream>
using namespace std;

class sl
{
	private:
		unsigned int T, S, L;
		unsigned char snake[101];
		unsigned char ladder[101];
		unsigned char game[100][7];
		bool is_inserted[100];
		vector<unsigned char> *cur, *next;
		int find_min_steps_to_reach_top();
	public:
		void process_input();
};

void sl::process_input()
{
	cur = new vector<unsigned char>;
	next = new vector<unsigned char>;

	cin >> T;
	for(unsigned char i=0; i<T; i++)
	{
		//cout<<" Processing test case " << i+1 << endl;
		for(unsigned char i=0; i<100; i++)
		{
			snake[i] = ladder[i] = 0;
		}

		cin >> L;
		for(unsigned char k=0; k<L; k++)
		{
			unsigned int start, end;
			cin >> start >> end;
			unsigned char start_ch = start, end_ch = end;
			ladder[start_ch] = end_ch;
		}
	
		cin >> S;
		for(unsigned char k=0; k<S; k++)
		{
			unsigned int start, end;
			cin >> start >> end;
			unsigned char start_ch = start, end_ch = end;
			snake[start_ch] = end_ch;
		}

		for(unsigned char i=0; i<100; i++)
		{
			is_inserted[i] = false;
			for(unsigned char j=1; j<7;j++)
			{
				game[i][j] = i+j;
				if(ladder[i+j] != 0)
					game[i][j] = ladder[i+j];
				else if(snake[i+j] != 0)
					game[i][j] = snake[i+j];
			}
		}
		//cout<<"Finding the no of steps \n";
		int  ret = find_min_steps_to_reach_top();
		cout<< ret << endl;
	}
	delete cur;
	delete next;
}

int sl::find_min_steps_to_reach_top()
{
	cur->clear();
	next->clear();
	unsigned char no_of_steps =0;
	const unsigned char start = 1, end = 100;
	cur->push_back(start);
	while(cur->size())
	{
		//cout<<" queue size " << cur->size() << ", no_of_steps = " << no_of_steps+1 << "-> ";
		no_of_steps++;
		if(no_of_steps > end)
			assert(false);

		for(unsigned char i=0; i<cur->size(); i++)
		{
			unsigned char cur_pos = (*cur)[i];
			for(unsigned char j=1; j<7; j++)
			{
				if(game[cur_pos][j] == end)
					return no_of_steps;
				if(game[cur_pos][j] > end) 
					continue;
				if(is_inserted[game[cur_pos][j]] == false)
				{
					next->push_back(game[cur_pos][j]);
					is_inserted[game[cur_pos][j]] = true;
				}
			}
			//cout<<" " << (int)cur_pos;
		}
		cur->clear();
		vector<unsigned char>* tmp_vec = cur;
		cur = next;
		next = tmp_vec;;
		//cout<< endl; // << endl << endl;
	}
	return -1;
}


int main()
{
	sl obj1;
	obj1.process_input();
	return 0;
}
