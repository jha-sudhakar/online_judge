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
	unsigned int in_len = 1 + rand()%18;
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
	string str1;
	cin >> str1;
	//str1 = get_random_input();
	//str = string("dfcxxggcvjrzrjxxvfxxzwvwvd");
	str.resize(str1.size());
	for(int i=str1.size()-1; i>-1; i--)
		str[str1.size()-1-i]  = str1[i];

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
	
	char min = 30;
	int prev_min_index=-1, min_index = 0;
	while(char_count != N/2)
	{
		min = 30;
		min_index = 0;

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
			if(count_ref[str[i]] == 0 && i < prev_min_index)
				assert(false);
			
			//if(i <=  prev_max_index) continue;

			if(count_ref[str[i]] <  count[str[i]])
			{
				if(min == 30)
				{
					min = str[i];
					min_index = i;
				}else if(min_index <= prev_min_index)
				{
					min = 30;
					min_index = 0;
					for(int jj=prev_min_index+1; jj<=i ; jj++)
					{
						if(count[str[jj]] == 0)
							continue;

						if(min > str[jj])
						{
							min = str[jj];
							min_index = jj;
						}
					}
				}
#if DEBUG_LOG
				cout <<" Count at " << i <<" for "<< char(str[i]+96) << "\t  ";
				cout<<" count= " << count_ref[str[i]] <<" count/2= " << count[str[i]] << "\t  ";
				cout <<" Min at " << min_index <<" is  "<< char(str[min_index]+96) << " prev_min_index= " << prev_min_index << endl;
#endif

				break;
			} 
			if(min > str[i])
			{
				min = str[i]; 
				min_index = i;
			}
		}
		
		for(unsigned int k=0; k<27; k++)
		{
			count_ref[k] = const_count_ref[k];
		}
		const_count_ref[min]--;
		count_ref[min]--;
		count[min]--;
		used[min_index] = true;
		prev_min_index = min_index;

		final_str[char_count] = min+96;
		//sorted_char.push_back(pos(max, max_index));

		char_count++;
	}

	//cout << "len= " << final_str.size() <<", string= " << final_str << endl;

#if 0
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
//int count = atoi(argv[1]);
int count = 1;
while(count--)
	obj.process_input();
return 0;
}
