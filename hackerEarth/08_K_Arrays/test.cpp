#include <stdint.h>
#include <iostream>
using namespace std;

int main()
{
uint64_t val = -1;
cout<<"\n uint64_t max= " << val <<endl;
for(unsigned int i=0; i<20; i++)
{
 cout<< (1 << i) << endl;

}

return 0;
}
