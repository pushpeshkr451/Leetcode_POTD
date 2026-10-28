// Last updated: 28/10/2026, 12:09:25
1class Solution {
2public:
3    int minCost(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        int maxi = 1024;
8
9        vector<vector<vector<bool>>> dp(
10            m, vector<vector<bool>>(n, vector<bool>(maxi, false)));
11
12        // Starting cell is included in the XOR
13        dp[0][0][grid[0][0]] = true;
14
15        for (int i = 0; i < m; i++) {
16            for (int j = 0; j < n; j++) {
17                for (int x = 0; x < maxi; x++) {
18
19                    if (!dp[i][j][x])
20                        continue;
21
22                    // Move down
23                    if (i + 1 < m) {
24                        dp[i + 1][j][x ^ grid[i + 1][j]] = true;
25                    }
26
27                    // Move right
28                    if (j + 1 < n) {
29                        dp[i][j + 1][x ^ grid[i][j + 1]] = true;
30                    }
31                }
32            }
33        }
34
35        int ans = 1e9;
36
37        for (int x = 0; x < maxi; x++) {
38            if (dp[m - 1][n - 1][x]) {
39                ans = min(ans, x);
40            }
41        }
42
43        return ans;
44    }
45};