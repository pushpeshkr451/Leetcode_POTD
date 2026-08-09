// Last updated: 09/08/2026, 22:22:08
1class Solution {
2public:
3    int stoneGameII(vector<int>& piles) {
4        int n = piles.size();
5        
6        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
7        vector<int> suffixSum(n, 0);
8        suffixSum[n - 1] = piles[n - 1];
9        
10        for (int i = n - 2; i >= 0; i--) {
11            suffixSum[i] = suffixSum[i + 1] + piles[i];
12        }
13        
14        for (int i = n - 1; i >= 0; i--) {
15            for (int m = 1; m <= n; m++) {
16                if (i + 2 * m >= n) {
17                    dp[i][m] = suffixSum[i];
18                } else {
19                    for (int x = 1; x <= 2 * m; x++) {
20                        dp[i][m] = max(dp[i][m], suffixSum[i] - dp[i + x][max(m, x)]);
21                    }
22                }
23            }
24        }
25        
26        return dp[0][1];
27    }
28};