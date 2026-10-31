// Last updated: 31/10/2026, 13:26:28
1class Solution {
2public:
3    int mod = 1e9 + 7;
4    vector<vector<vector<int>>> dp;
5
6    int solve(vector<vector<int>>& grid, int i, int j, int prev) {
7        int n = grid.size();
8        int m = grid[0].size();
9
10        if (i >= n || j >= m)
11            return 0;
12
13        if (i == n - 1 && j == m - 1)
14            return 1;
15
16        if (dp[i][j][prev + 1] != -1)
17            return dp[i][j][prev + 1];
18
19        int right = 0, down = 0;
20
21        if (grid[i][j] == 1) {
22            if (prev == 0)
23                down = solve(grid, i + 1, j, 1);
24            else if (prev == 1)
25                right = solve(grid, i, j + 1, 0);
26        }
27        else {
28            right = solve(grid, i, j + 1, 0);
29            down = solve(grid, i + 1, j, 1);
30        }
31
32        return dp[i][j][prev + 1] =
33            (right % mod + down % mod) % mod;
34    }
35
36    int uniquePaths(vector<vector<int>>& grid) {
37        dp.resize(grid.size(),
38            vector<vector<int>>(grid[0].size(),
39                vector<int>(3, -1)));
40
41        return solve(grid, 0, 0, -1);
42    }
43};