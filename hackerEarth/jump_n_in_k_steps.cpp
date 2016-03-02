#include <stdint.h>
#include <cassert>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include<limits.h>
#include <vector>

#define MAX_T  (10*10*10*10) * (10*10*10*10) * 10* 2;
#include <iostream>
using namespace std;

class Jump
{
	private:
		//vector<uint64_t> arr;
		uint32_t K, N, size;

	public:
		vector<uint64_t> arr;
		uint64_t find_k_steps();
		uint64_t find_max_jump();
		Jump(uint32_t _N, uint32_t _K, uint32_t _size, vector<uint64_t> v);
		Jump(uint32_t _N, uint32_t _K, uint32_t _size);
		Jump();

		uint32_t validate_max_jump_dist(const uint64_t max_jump);
};


Jump::Jump()
{
	K=N=size=0;
	arr.clear();
}

Jump::Jump(uint32_t _N, uint32_t _K, uint32_t _size)
{
    K=_K;
    N=_N;
    size=_size;
	arr.reserve(size);
}



Jump::Jump(uint32_t _N, uint32_t _K, uint32_t _size, vector<uint64_t> v)
{
	K=_K;
	N=_N;
	size=_size;
	arr.clear();
	arr = v;
}


uint64_t Jump::find_k_steps()
{
	uint64_t ret=0;
	if(N <= K)
		assert(false);
	if(K+1 == N)
	{
		ret= find_max_jump();
		//cout<<"\n " << __LINE__ <<": " <<ret;
		return ret;
	}

	if(K == 1)
	{
		uint64_t diff = arr[size-1] - arr[0];
		return diff;
	}

	uint64_t low = find_max_jump();
	uint64_t high = low * K;
	uint64_t val=0, prev = 0;
	
	while(low < high)
	{
		uint64_t mid = (low+high)/2;
		val = validate_max_jump_dist(mid);
		if(val == N)
		{
			high = mid-1;
		}
		else
		{
			low = mid+1;
		}
	}

	val = validate_max_jump_dist(low);
	if(val != N)
	{
		low++;
	}
	//cout<<"\n " << __LINE__ <<": " << low << endl;
	return low;
}

uint64_t Jump::find_max_jump()
{
	uint64_t max = 0;
	for(uint32_t i=1; i<size; i++)
	{
		uint64_t diff = arr[i]-arr[i-1];
		if(diff > max)
			max = diff;
	}
	return max;	
}

uint32_t Jump::validate_max_jump_dist(const uint64_t max_jump)
{
	uint32_t prev_index=0, cur_index = 1, i=0;;
	
	for(i=0; i<K; i++)
	{
		while( cur_index < N && (arr[cur_index] - arr[prev_index] <= max_jump))
		cur_index++;

		if(cur_index == N)
		{	
			//cout<<"\n  Max jump size= " <<max_jump <<", cur_index is N and i= " << i << endl;
			return cur_index;
		}

		prev_index = cur_index -1;
	}	
	//cout<<"\n *Max jump size= " <<max_jump <<", cur_index is " << cur_index <<" and i= " << i << endl;
	return cur_index;
}

int main()
{

	uint32_t no_of_testcase;
	std::string line;
	getline(std::cin, line);
	std::istringstream iss(line);
	iss >> no_of_testcase;
	while(no_of_testcase--)
	{
		uint32_t N=0, K=0;
		getline(std::cin, line);
		std::istringstream iss2(line);
		iss2 >> N; iss2 >> K;
		vector<uint64_t> v;

		getline(std::cin, line);
		std::istringstream iss3(line);
		Jump obj1(N,K,N);
		uint64_t tmp=0;
		uint32_t index=0;
		while (iss3 >> tmp)
		{
			obj1.arr[index++] = tmp;
		}
		if(index != N)
			assert(false);

		//cout<<"\nN= " << N <<", K= "<< K << "   "<< endl;
		cout<< obj1.find_k_steps() << endl;
		//obj1.validate_max_jump_dist(53051249);obj1.validate_max_jump_dist(53051250); obj1.validate_max_jump_dist(53051251); 
	}

	return 0;
}
