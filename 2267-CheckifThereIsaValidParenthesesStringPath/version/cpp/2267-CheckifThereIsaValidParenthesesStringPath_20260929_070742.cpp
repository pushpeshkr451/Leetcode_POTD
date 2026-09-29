// Last updated: 29/09/2026, 07:07:42
1class Solution {
2public:
3    bool hasValidPath(vector<vector<char>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        // A valid parentheses string must have even length.
8        if ((m + n - 1) % 2 == 1)
9            return false;
10
11        // dp[i][j] = set of possible balances when reaching (i, j)
12        vector<vector<unordered_set<int>>> dp(m, vector<unordered_set<int>>(n));
13
14        // Starting cell must be '('.
15        if (grid[0][0] == ')')
16            return false;
17
18        dp[0][0].insert(1);
19
20        for (int i = 0; i < m; i++) {
21            for (int j = 0; j < n; j++) {
22
23                if (i == 0 && j == 0)
24                    continue;
25
26                int change = (grid[i][j] == '(') ? 1 : -1;
27
28                // From top
29                if (i > 0) {
30                    for (int balance : dp[i - 1][j]) {
31                        int newBalance = balance + change;
32
33                        if (newBalance >= 0)
34                            dp[i][j].insert(newBalance);
35                    }
36                }
37
38                // From left
39                if (j > 0) {
40                    for (int balance : dp[i][j - 1]) {
41                        int newBalance = balance + change;
42
43                        if (newBalance >= 0)
44                            dp[i][j].insert(newBalance);
45                    }
46                }
47            }
48        }
49
50        // A valid path must finish with balance 0.
51        return dp[m - 1][n - 1].count(0) > 0;
52    }
53};