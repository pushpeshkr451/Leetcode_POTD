// Last updated: 23/06/2026, 21:38:48
1class Solution {
2public:
3    int zigZagArrays(int n, int l, int r) {
4        int MOD = 1e9 + 7;
5        r -= l;
6        vector<int> dp(r + 1, 1);
7        for (int i = 1; i < n; i++) {
8            int pre = 0, pre2;
9            if (i & 1) {
10                for (int v = 0; v <= r; v++) {
11                    pre2 = pre + dp[v];
12                    dp[v] = pre;
13                    pre = pre2 % MOD;
14                }
15            } else {
16                for (int v = r; v >= 0; v--) {
17                    pre2 = pre + dp[v];
18                    dp[v] = pre;
19                    pre = pre2 % MOD;
20                }
21            }
22        }
23        int res = 0;
24        for (int v : dp)
25            res = (res + v) % MOD;
26        return res * 2 % MOD;
27    }
28};