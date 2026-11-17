// Last updated: 17/11/2026, 12:10:24
1
2class Solution {
3public:
4    int minimumChanges(string s, int k) {
5        int n = s.size();
6        const int INF = 1e9;
7
8        vector<vector<int>> cost(n, vector<int>(n, INF));
9
10        // Precompute semi-palindrome conversion costs.
11        for (int l = 0; l < n; l++) {
12            for (int r = l + 1; r < n; r++) {
13
14                int len = r - l + 1;
15
16                // Try every proper divisor.
17                for (int d = 1; d < len; d++) {
18
19                    if (len % d != 0)
20                        continue;
21
22                    int changes = 0;
23                    int m = len / d;
24
25                    // Process each group.
26                    for (int t = 0; t < d; t++) {
27
28                        // Compare mirrored characters.
29                        for (int q = 0; q < m / 2; q++) {
30
31                            int i = l + t + q * d;
32                            int j = l + t + (m - 1 - q) * d;
33
34                            if (s[i] != s[j])
35                                changes++;
36                        }
37                    }
38
39                    cost[l][r] = min(cost[l][r], changes);
40                }
41            }
42        }
43
44        // DP: dp[i][j] = minimum changes to partition
45        // first i characters into exactly j substrings.
46        vector<vector<int>> dp(
47            n + 1, vector<int>(k + 1, INF)
48        );
49
50        dp[0][0] = 0;
51
52        for (int j = 1; j <= k; j++) {
53            for (int i = 2 * j; i <= n; i++) {
54
55                for (int p = 2 * (j - 1); p <= i - 2; p++) {
56
57                    if (dp[p][j - 1] == INF)
58                        continue;
59
60                    dp[i][j] = min(
61                        dp[i][j],
62                        dp[p][j - 1] + cost[p][i - 1]
63                    );
64                }
65            }
66        }
67
68        return dp[n][k];
69    }
70};