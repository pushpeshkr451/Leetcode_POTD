// Last updated: 07/09/2026, 14:23:02
1class Solution {
2public:
3    int distinctSubseqII(string s) {
4        const int mod = 1e9 + 7;
5
6        vector<long long> dp(26, 0);
7
8        for (char c : s) {
9            int x = c - 'a';
10
11            long long total = 1;
12
13            for (int i = 0; i < 26; i++) {
14                total = (total + dp[i]) % mod;
15            }
16
17            dp[x] = total;
18        }
19
20        long long ans = 0;
21
22        for (int i = 0; i < 26; i++) {
23            ans = (ans + dp[i]) % mod;
24        }
25
26        return ans;
27    }
28};