// Last updated: 06/09/2026, 19:47:02
1class Solution {
2public:
3int dp[1005][1005];
4    int solve(int i, int j, string& s, string& t) {
5        if (j == t.size())
6            return 1;
7        if (i == s.size())
8            return 0;
9        if(dp[i][j]!=-1)return dp[i][j];
10        int ans = 0;
11        if (s[i] == t[j]) {
12            ans += solve(i + 1, j + 1, s, t);
13        }
14        ans += solve(i + 1, j, s, t);
15        return dp[i][j]=ans;
16    }
17    int numDistinct(string s, string t) { 
18        memset(dp,-1,sizeof(dp));
19        return solve(0, 0, s, t); 
20    }
21};