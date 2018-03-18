
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int> coin;
    int inpt;
    int n;
    while(scanf("%d,",&inpt)==1)
        coin.push_back(inpt);
    scanf("%d",&inpt);
    coin.push_back(inpt);
    coin.pop_back();
    coin.pop_back();
    n = inpt;
  //  scanf("%d",&n);
/*    for(int i = 0; i < coin.size(); ++ i)
        printf("%d ",coin[i]);
    puts(""); 
    printf("%d\n",n); */
    sort(coin.begin(), coin.end());
    vector<int> dp(n + 1);
    dp[0] = 1;
    for(int i = 0; i < coin.size(); ++ i){
        for(int j = coin[i]; j <= n; ++ j)
            dp[j] += dp[j - coin[i]];
    }
    printf("%d\n",dp[n]);
    return 0;
}
