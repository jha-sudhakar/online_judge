/*
Single Round Match 789 Round 1 - Division II, Level Two
Definition
	Class:	StringsBetween
	Method:	count
	Parameters:	int, String, String
	Returns:	long
	Method signature:	long count(int L, String A, String B)
	(be sure your method is public)
	*/
#include<string>
#include<iostream>
using namespace std;

class StringsBetween
{
	private:
		unsigned long long* pow_26;

		unsigned long long max_l(const int l)
		{
			unsigned long long ret = 0;
			for (int i = 0; i <= l; i++)
			{
				ret += pow_26[i];
			}
			return ret;
		}

		unsigned long long  count_private(string str, int L)
		{
			if(str.size() <= 1) return str.size();
			unsigned long long  count_total=1;
			int MAX = str.size();

			for(int i=MAX-1; i>0; i--)
			{
				unsigned long long offset = (str[i] - 'a');
				count_total += 1 + offset * max_l(L-1-i);
			}
			return count_total;
		}

	public:
		StringsBetween()
		{
			pow_26 = new unsigned long long[11];

			unsigned long long mul = 1;
			for (int i = 0; i <= 10; i++)
			{
				pow_26[i] = mul;
				mul = mul * 26;
			}
		}
		~StringsBetween() { delete [] pow_26; }

		long long  count(int L, string str1, string str2)
		{
			unsigned long long  sum1 = count_private(str1, L);
			unsigned long long  sum2 = count_private(str2, L);
			unsigned long long  sum1B = 0, sum2B = 0;
			unsigned long long  x1 = 0, x2 = 0;
			if(str1.size() != 0)
				x1 = str1[0] - 'a';

			if(str2.size() != 0)
				x2 = str2[0] - 'a';

			if(x1 != x2)
			{
				sum1B = (x1) * (max_l(L-1));
				sum2B = (x2) * ( max_l(L-1));
			}
			cout << "sum1 =" << sum1 << ", sum1B =" << sum1B << endl;
			cout << "sum2 =" << sum2 << ", sum2B =" << sum2B << endl;
			long long ret_val = sum2+sum2B - (sum1 + sum1B);
			if(ret_val != 0)
			 	ret_val--;
			 return ret_val;
		}

};

int main(int argc, char* argv[])
{
	int l = 1;
	std::string str1("");
	std::string str2("d");

	if (0)
	{
		l = atoi(argv[1]);
		str1 = std::string(argv[2]);
		str2 = std::string(argv[3]);
	}
	cout << "L = " << l << ", String A = " << str1 << ", String B = " << str2 << endl;
	StringsBetween obj;
	unsigned long long  val = obj.count(l, str1, str2);
	//unsigned long long  val = obj.count(1, string(""), string("b"));
	

	cout << "Output = " << val << endl;
	return 0;	
}