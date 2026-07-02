// Last updated: 02/07/2026, 12:43:14
1class Solution {
2public:
3    bool findSafeWalk(vector<vector<int>>& grid, int health) {
4        int m = grid.size(), n = grid[0].size();
5        vector<vector<int>> dis(m, vector<int>(n, -1));
6        int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
7
8        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
9                       greater<>>
10            pq;
11        pq.emplace(grid[0][0], 0, 0);
12        while (!pq.empty()) {
13            auto [val, cx, cy] = pq.top();
14            pq.pop();
15            if (dis[cx][cy] >= 0) {
16                continue;
17            }
18            dis[cx][cy] = val;
19            for (int k = 0; k < 4; k++) {
20                int nx = cx + dirs[k][0];
21                int ny = cy + dirs[k][1];
22                if (nx < 0 || ny < 0 || nx >= m || ny >= n ||
23                    dis[nx][ny] >= 0) {
24                    continue;
25                }
26                pq.emplace(val + grid[nx][ny], nx, ny);
27            }
28        }
29
30        return dis[m - 1][n - 1] < health;
31    }
32};