#include<stdlib.h>
#include<string.h>
#include<assert.h>

#include<algorithm>
#include<vector>
#include<list>
#include<iostream>
#include<string>
using namespace std;


class rev_str
{
	private:
		unsigned int N;
		string str;
		string rand_str;
		int count[27];
		int count_ref[27];
		int const_count_ref[27];
		string get_random_input();
	public:
		rev_str() { srand(time(NULL)); }
		void process_input();
		void get_the_min_str();
};



string rev_str::get_random_input()
{
	cout<<"--------------------------------------------------------------------------------\n";
	unsigned int in_len = 1 + rand()%8;
//	unsigned int in_len = 1 + rand()%100;
	char arr0[in_len], arr1[in_len+1], arr2[in_len+1];
	char final_arr[2*in_len+1];

	for(unsigned int i=0; i<in_len; i++)
	{
		char offset = rand()%26;
		arr0[i] = arr1[i] = arr2[i] = 97+offset;
	}
	//sort(arr0, arr0+in_len);

	for(int i=0; i<in_len; i++)
		arr1[in_len-1-i] = arr0[i];

	arr0[in_len] = arr2[in_len] = 0;
	cout<<"len = " << strlen(arr2) <<", Word   = " << arr0 << endl;
	random_shuffle(arr2, arr2+in_len);
	cout<<"len = " << strlen(arr2) <<", Random = " << arr2 << endl;

	rand_str = string(arr0);

	int c1=0, c2=0;
	for(int i=0; i<2*in_len; i++)
	{
		if(rand()%2)
		{
			if(c1 != in_len)
				final_arr[i] = arr1[c1++];
			else
				final_arr[i] = arr2[c2++];
		}
		else
		{
			if(c2 != in_len)
				final_arr[i] = arr2[c2++];
			else
				final_arr[i] = arr1[c1++];
		}

		if(c1>in_len || c2>in_len)
			assert(false);
	}
	arr1[in_len] = arr2[in_len] = final_arr[2*in_len] = 0;
	
	int ct1[27], ct2[27];
	for(int i=0; i<27; i++)
	{
		ct1[i] = ct2[i] = 0;
	}
	for(int i=0; i<in_len; i++)
	{
		ct1[arr1[i]]++;
	}
	for(int i=0; i<2*in_len; i++)
	{
		ct2[final_arr[i]]++;
	}
	for(int i=0; i<27; i++)
	{
		if(2*ct1[i] != ct2[i])
			assert(false);
	}


	cout <<"len = " << strlen(final_arr) <<", Shuffled word = " << final_arr << endl;
	return string(final_arr);
}


void rev_str::process_input()
{
	//cin >> str;
	str = get_random_input();
	//str = string("dfcxxggcvjrzrjxxvfxxzwvwvd");
	N = str.size();
	if(N == 0)
	{
		cout << endl;
		return;
	}
#if DEBUG_LOG
	for(int i=0; i<N; i++)
	{
		cout << char(str[i]) <<" at " << i << endl;
	}
#endif

	for(unsigned int i=0; i<N; i++)
		str[i] = str[i]-96;

	for(int i=0; i<27; i++)
		const_count_ref[i] = count_ref[i] = count[i] = 0;

	for(int i=0; i<N; i++) 
	{
		count[str[i]]++; 
		count_ref[str[i]]++;
		const_count_ref[str[i]]++;
	}	

	for(int i=0; i<27; i++)
	{
		count[i] = count[i]/2;
		//count_ref[i] = count_ref[i]/2;
	}	

	get_the_min_str();
}


void rev_str::get_the_min_str()
{
	string final_str;  final_str.resize(N/2);
	unsigned int char_count = 0;
	bool used[N];
	for(unsigned int i=0; i<N; i++) used[i] = false;
	
	char max = 0;
	int prev_max_index=-1, max_index = 0;
	while(char_count != N/2)
	{
		max = 0;
		max_index = 0;

		for(int i=0; i<N; i++)
		{
			if(count[str[i]] == 0 || used[i] == true)
			{
				//cout <<"COntinuing for i = " << i << endl;
				continue;
			}	

			if(count_ref[str[i]] == 0)
				assert(false);

			count_ref[str[i]]--;
			if(count_ref[str[i]] == 0 && i < prev_max_index)
				assert(false);
			
			//if(i <=  prev_max_index) continue;

			if(count_ref[str[i]] <  count[str[i]])
			{
				if(max == 0)
				{
					max = str[i];
					max_index = i;
				}else if(max_index <= prev_max_index)
				{
					max = 0;
					max_index = 0;
					for(int jj=prev_max_index+1; jj<=i ; jj++)
					{
						if(count[str[jj]] == 0)
							continue;

						if(max < str[jj])
						{
							max = str[jj];
							max_index = jj;
						}
					}
				}
#if DEBUG_LOG
				cout <<" Count at " << i <<" for "<< char(str[i]+96) << "\t  ";
				cout<<" count= " << count_ref[str[i]] <<" count/2= " << count[str[i]] << "\t  ";
				cout <<" Max at " << max_index <<" is  "<< char(str[max_index]+96) << " prev_max_index= " << prev_max_index << endl;
#endif

				break;
			} 
			if(max < str[i])
			{
				max = str[i]; 
				max_index = i;
			}
		}
		
		for(unsigned int k=0; k<27; k++)
		{
			count_ref[k] = const_count_ref[k];
		}
		const_count_ref[max]--;
		count_ref[max]--;
		count[max]--;
		used[max_index] = true;
		prev_max_index = max_index;

		final_str[N/2-1-char_count] = max+96;
		//sorted_char.push_back(pos(max, max_index));

		char_count++;
	}

	//cout << "len= " << final_str.size() <<", string= " << final_str << endl;

#if 1
	cout<<"\n in  = " << rand_str <<"\n out = " << final_str << endl;
	if(rand_str <  final_str)
	{
		assert(false);
	}
#endif

	cout << final_str << endl;
}




int main(int argc, char* argv[])
{
rev_str obj;
int count = atoi(argv[1]);
//int count = 1;
while(count--)
	obj.process_input();
return 0;
}
