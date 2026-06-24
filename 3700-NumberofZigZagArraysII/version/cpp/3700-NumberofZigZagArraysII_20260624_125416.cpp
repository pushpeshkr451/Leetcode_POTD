// Last updated: 24/06/2026, 12:54:16
1class Solution {
2public:
3    const int mod = 1e9+7;
4    using ll = long long;
5    void matmul(vector<vector<ll>> &a,vector<vector<ll>> b){
6        int n = a.size(), m = a[0].size(), p = b[0].size();
7        vector<vector<ll>> c(n,vector<ll>(p,0));
8        for(int i=0; i<n; i++){
9            for(int j=0; j<p; j++){
10                for(int k=0; k<m; k++){
11                    c[i][j] = (c[i][j] + a[i][k]*b[k][j])%mod;
12                }
13            }
14        }
15        a = c;
16    }
17    vector<vector<ll>> pow_mod(vector<vector<ll>> &x, int y){
18        int n = x.size();
19        vector<vector<ll>> res(n,vector<ll>(n,0));
20        for(int i=0; i<n; i++) res[i][i] = 1;
21        while(y>0){
22            if(y&1) matmul(res,x);
23            y/=2; matmul(x,x);
24        }
25        return res;
26    }
27
28    int zigZagArrays(int n, int l, int r) {
29        int m = (r-l+1);
30        vector<vector<ll>> a(2*m,vector<ll>(2*m,0));
31        vector<vector<ll>> dp(2*m,vector<ll>(1,1));
32
33        for(int i=0; i<m; i++){
34            for(int j=0; j<i; j++){
35                a[i][j+m] = 1;
36            }
37            for(int j=i+1; j<m; j++){
38                a[i+m][j] = 1;
39            }
40        }
41
42        a = pow_mod(a,n-1);
43        matmul(a,dp);
44        long long ans = 0;
45        for(int i=0; i<2*m; i++) ans += a[i][0], ans %= mod;
46        return ans;
47    }
48};