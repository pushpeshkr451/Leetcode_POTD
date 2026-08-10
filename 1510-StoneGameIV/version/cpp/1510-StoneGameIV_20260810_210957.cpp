// Last updated: 10/08/2026, 21:09:57
1class Solution {
2public:
3    bool winnerSquareGame(int n) {
4        vector<bool> dp(n + 1, false);
5
6        dp[0] = false;
7
8        for (int i = 1; i <= n; ++i) {
9            for (int j = 1; j * j <= i; ++j) {
10                if (!dp[i - j * j]) {
11                    dp[i] = true;
12
13                    break;
14                }
15            }
16        }
17
18        return dp[n];
19    }
20};