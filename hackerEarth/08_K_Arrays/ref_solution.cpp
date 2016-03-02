

    // setter : pranjuldb
    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    ll mod = 1000000007;
    ll fast_power(ll base, ll exponent, ll modulus)
    {
        ll result = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1)
                result = (result * base) % modulus;
            exponent = exponent >> 1;
            base = (base * base) % modulus;
        }
        return result;
    }
    int main()
    {
        int t;
        cin >> t;
        assert(1 <= t && t <= 5);
        while(t--) {
            int n, k;
            cin >> n >> k;
            assert(1 <= n && n <= 16);
            assert(1 <= k && k <= 10);
            vector < ll > v[k];
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < n; j++) {
                    ll x;
                    cin >> x;
                    v[i].push_back(x);
                }
            }
            int p = (1<<n);
            ll maxm = -1;
            ll minm = LONG_LONG_MAX;
            int maxmsiz = -1;
            int minmsiz = INT_MAX;
            for (int i = 1; i < p; i++) {
                ll mul = 1;
                int ctr = 0;
                for (int j = 0; j < n; j++) {
                    if (i&1<<j) {
                        ctr++;
                        ll add = 0;
                        for (int t = 0; t < k; t++) {
                            add = (add + v[t][j]);
                        }
                        mul = mul*add;
                        mul = mul%mod;
                    }
                }
                ll val = (mul*fast_power(ctr, mod-2, mod) )%mod;
                if (val >= maxm) {
                    if (val == maxm && maxmsiz > ctr) {
                        maxmsiz = ctr;
                    } else if (val > maxm) {
                        maxm = val;
                        maxmsiz = ctr;
                    }
                }
                if (val <= minm) {
                    if (val == minm && minmsiz < ctr) {
                        minmsiz = ctr;
                    } else if (val < minm) {
                        minm = val;
                        minmsiz = ctr;
                    }
                }
            }
			//cout<<"max-val= " << maxm <<", max-size=" << maxmsiz <<", min-val= "<<minm <<", min-size= " << minmsiz <<"  ";
            cout << (maxm^minm) << " " << (maxmsiz^minmsiz) << endl;
			
        }
        return 0;
    }


