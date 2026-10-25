// Last updated: 25/10/2026, 07:25:50
1class Solution {
2public:
3    bool dfs(vector<vector<int>>& g, int i, int j) {
4        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size()) {
5            return false;
6        }
7        if (g[i][j] == 1) {
8            return true;
9        }
10        g[i][j] = 1;
11        bool d1 = dfs(g, i + 1, j);
12        bool d2 = dfs(g, i, j + 1);
13        bool d3 = dfs(g, i - 1, j);
14        bool d4 = dfs(g, i, j - 1);
15        return d1 && d2 && d3 && d4;
16    }
17    int closedIsland(vector<vector<int>>& grid) {
18        int res = 0;
19        for (int i = 0; i < grid.size(); i++) {
20            for (int j = 0; j < grid[0].size(); j++) {
21                if (grid[i][j] == 0) {
22                    res += dfs(grid, i, j) ? 1 : 0;
23                }
24            }
25        }
26        return res;
27    }
28};