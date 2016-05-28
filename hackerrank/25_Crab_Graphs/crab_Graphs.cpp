
unsigned int graph[101][101];

class kg
{
	private:
		unsigned int C, N, T, M;

	public:
		void process_input();
		void get_vertex_count();
};


void kg::process_input()
{
	cin >> C;
	for(int i=0; i<C; i++)
	{
		
		cin >> N >> T >> M;
		unsigned int u,v;
		for(int i=0; i<=N; i++)
			for(int j=0; j<=N; j++)
				graph[i][j] = 0;
	
		for(unsigned int j=0; j<M; j++)
		{
			cin >> u >> v;
			graph[u][v] = 1;
			graph[v][u] = 1;
		}
		
		cout << get_vertex_count() << endl;
	}	
}

void kg::get_vertex_count()
{
	bool is_set[N+1];
	for(int i=0; i<=N; i++)
		is_set[i] = false;

	bool found_v = true;
	while(found_v)
	{
		found_v = false;
		int count=0;
		for(int i=1; i<=N; i++)
		{
			int count_i=0, index=0;;
			for(int j=1; j<=N; j++)
			{
				if(graph[i][j] == 1 && is_set[j] == false)
					count_i++;
			}
			if(count < count_i)
			{
				count = count_i;
				index = i;
			}
		}

		



	}





}
