// Last updated: 20/07/2026, 14:08:15
1class Solution {
2public:
3    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        int total = m * n;
8        k %= total;
9
10        vector<vector<int>> ans(m, vector<int>(n));
11
12        for (int i = 0; i < m; i++) {
13            for (int j = 0; j < n; j++) {
14
15                int oldIndex = i * n + j;
16
17                int newIndex = (oldIndex + k) % total;
18
19                int newRow = newIndex / n;
20                int newCol = newIndex % n;
21
22                ans[newRow][newCol] = grid[i][j];
23            }
24        }
25
26        return ans;
27    }
28};