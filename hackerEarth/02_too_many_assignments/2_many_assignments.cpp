#include <queue>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Kth_small
{
	private:
		//vector<char> vec;
		unsigned int N;
		char vec[1000000];

	public:
		void op_0(const unsigned int index, const char val);
		string op_1(const unsigned int l, const unsigned int r, const unsigned int k);
		void parse_input_and_execute();
		void print_str();
};

void Kth_small::print_str()
{
	cout<<endl;
	for(int i=0; i<N; i++)
		cout<<vec[i];
	cout<<endl;
}
void Kth_small::op_0(const unsigned int index, const char val )
{
	if(index > N-1)
	{
		return;
	}

	vec[index] = val;
}

string Kth_small::op_1(const unsigned int l, const unsigned int r, const unsigned int k)
{

	//cout<<"\n l= " << l <<", r= " << r <<", k= " << k <<",arr-size= " << N <<endl;
	string ret_str;
	if(l == r)
	{
		if(k == 1)
		{	
			ret_str.push_back(vec[l]); 	return ret_str;
		}
		else
			return "Out of range";
	} else if (l > r)
	{
		return "Out of range";
	} else if (k > r-l+1)
	{
		return "Out of range";
	} else if (r > N-1 && k >N)
	{
		return "Out of range";
	}
	
	unsigned int q_end = r;
	if (r > N-1)
		q_end = N-1;
	priority_queue<char> q (vec+l , vec+q_end+1);
	//cout<<"\n No of elements in Q= " << q.size() <<", k= " << k;
	while ( k != q.size())
	{
		q.pop();
	}

	// Now only k elements are left so top value should be Kth smallest.
	ret_str.push_back(q.top());  return ret_str;
}

void Kth_small::parse_input_and_execute()
{
	unsigned int Q;
	while(cin >> N >> Q)
	{
		//cout<<"\n N= " << N <<", Q= " << Q;

		string str; cin >> str;
		for(unsigned int i=0; i<str.size(); i++)
			vec[i] = (str[i]);

    while(Q > 0)
    {

		//cout<<"\n Read the input, running the operations now";
		int op;
		cin >> op;
		if(0 == op)
		{
			unsigned int index; char ch;
			cin >> index >> ch;
			//cout<<"\n Calling op-0 with index= " << index << ", val= " << ch; print_str();
			op_0(index-1, ch);
		} else if (1 == op)
		{
			unsigned int l,r,k;
			cin >> l >> r >> k;
			//cout<<"\n Calling op-1 with left= " << l << ", right= " << r <<", k= " << k;; print_str();
			string output = op_1(l-1,r-1,k);
			cout<<output<<endl;
			//cout<<"\n Output=##" << output <<"##" << endl;
		}

		Q--;
	}
	}
}

int main()
{
Kth_small obj1;
obj1.parse_input_and_execute();
return 0;
}
