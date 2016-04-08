#include<vector>
#include<algorithm>
using namespace std;

vector<int> Solution::wave(vector<int> &A) 
{
// Do not write main() function.
// Do not read input, instead use the arguments to the function.
// Do not print the output, instead return values as specified
// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

vector<int> out = A;

sort(out.begin(), out.end());
for(int i=0; i<out.size()-1; i+=2)
{
	int val1 = out[i];
	out[i] = out[i+1];
	out[i+1] = val1;
}

return out;
}
