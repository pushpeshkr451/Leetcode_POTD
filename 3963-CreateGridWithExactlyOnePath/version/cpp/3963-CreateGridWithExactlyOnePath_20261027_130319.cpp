// Last updated: 27/10/2026, 13:03:19
1class Solution {
2public:
3    vector<string> createGrid(int m, int n) {
4        vector<string> grid(m, string(n, '#'));
5
6        for (int j = 0; j < n; j++)
7            grid[0][j] = '.';
8        for (int i = 0; i < m; i++)
9            grid[i][n - 1] = '.';
10
11        return grid;
12    }
13};