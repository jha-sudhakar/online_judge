
#define MAX 100000
unsigned int arr[MAX][2];

class LCA
{
	private:
		unsigned int N,M;
	
	public:
		void read_input();
		void build_dist_to_parent();
};

void LCA::read_input()
{
	cin >> N;
	unsigned int in_tmp;
	for(unsigned int i=1; i<N; i++)
	{
		cin >> in_tmp;
		arr[i][0] = in_tmp;
		arr[i][1] = 2*N;
	}
	arr[0][0] = 0;
	arr[0][1] = 0;
	
	build_dist_to_parent();
}

void LCA::build_dist_to_parent()
{
	for(unsigned int i=1; i<N; i++)
	{
		if(arr[i][1] != 2*N)
			continue;
		unsigned int counter = 0, p=i;
		vector<unsigned int> path;
		while(arr[p][1] == 2*N)
		{
			path.push_back(p);
			p = arr[p][1];
		}
		counter = arr[p][1];
		
		for(unsigned int i= path.size(); i>0; i--)
		{
			arr[i-1][1] = counter + (path.size()-i) +1;
		}
	}
}

