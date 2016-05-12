#include<string>
#include<queue>
#include<iostream>
using namespace std;

class str
{
	private:
		string str;
		unsigned int N, T;
		unsigned char arr[26];

	public:
		void process_input();
		void print_next_str();
};

void str::process_input()
{
	cin >> T;
	for(unsigned int i=0; i<T; i++)
	{
		cin >> str;
		N = str.size();
		print_next_str();
	}
}


void str::print_next_str()
{
	priority_queue<unsigned char, vector<unsigned char>, greater<unsigned char> > min_pq;
	for(unsigned int i=0; i<26; i++)
		arr[i] = 0;

	for(unsigned int i=0; i<N; i++)
		arr[str[i]-97]++;
	
	unsigned char max_char = 0;
	int i=0;
	for(i=N-1; i>=0; i--)
	{
		if(str[i] < max_char)
			break;
	
		if(str[i] > max_char)
			max_char = str[i];

		min_pq.push(str[i]);	
	}

	if(i == -1)
	{
		cout<< "no answer" << endl;
		return;
	}

	min_pq.push(str[i]);
	//str[i] = max_char;
	unsigned int swap_index = i;
	unsigned int swap_char = str[i];
	i++;
	int is_char_swapped = false;
	while(!min_pq.empty())
	{
		if(is_char_swapped == false && (min_pq.top() > swap_char)) // max_char ia already used once so ignore first instance;
		{
			str[swap_index] = min_pq.top();
			min_pq.pop();
			is_char_swapped = true;
			continue;
		}
		str[i] = min_pq.top();
		min_pq.pop();
		i++;
	}
	cout << str << endl;
}

int main()
{
str obj;
obj.process_input();
return 0;
}
