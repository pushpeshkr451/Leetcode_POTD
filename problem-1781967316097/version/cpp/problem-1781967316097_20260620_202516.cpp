// Last updated: 20/06/2026, 20:25:16
1class Solution {
2public:
3    long long dp[20][11][2][2];
4    int k;
5    string s;
6
7    long long dfs(int i,int prev,int less,int lz){
8        if(i==s.size())return 1;
9        if(dp[i][prev][less][lz]!=-1)return dp[i][prev][less][lz];
10
11        long long ans=0;
12        int lim=less?9:(s[i]-'0');
13
14        for(int d=0;d<=lim;d++){
15            if(lz){
16                ans+=dfs(i+1,d==0?10:d,less||(d<lim),lz&&(d==0));
17            }
18            else{
19                if(abs(d-prev)<=k){
20                    ans+=dfs(i+1,d,less||(d<lim),0);
21                }
22            }
23        }
24        return dp[i][prev][less][lz]=ans;
25    }
26    long long solve(long long n){
27        if(n<0)return 0;
28
29        s=to_string(n);
30        memset(dp,-1,sizeof(dp));
31        return dfs(0,10,0,1);
32    }
33    long long goodIntegers(long long l, long long r, int a) {
34        k=a;
35
36        return solve(r)-solve(l-1);
37    }
38};