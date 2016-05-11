
#define LEN 1000000000
unsigned int t[LEN], l[LEN];;

struct order
{
	unsigned int tm,ln;
	order(unsigned int _tm, unsigned int _ln) { tm = _tm; ln=_ln; }
};

class mwt
{
	private:
		unsigned int N;

	public:
		void process_input();
};

void mwt::process_input()
{
	priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int> > min_pq;

	cin >> N;
	cin >> t[0] >> l[0];
	for(unsigned int i=1; i<N; i++)
	{
		cin >> t[i] >> l[i];
		



	}




}
