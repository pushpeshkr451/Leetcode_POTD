// Last updated: 08/11/2026, 16:19:16
1class Solution {
2public:
3    int countServers(vector<vector<int>>& grid) {
4        int n = grid.size();
5        int m = grid[0].size();
6
7        vector<int> row(n, 0), col(m, 0);
8
9        // Step 1: Count servers per row and column
10        for (int i = 0; i < n; i++) {
11            for (int j = 0; j < m; j++) {
12                if (grid[i][j] == 1) {
13                    row[i]++;
14                    col[j]++;
15                }
16            }
17        }
18
19        int ans = 0;
20        // Step 2: Count servers that can communicate
21        for (int i = 0; i < n; i++) {
22            for (int j = 0; j < m; j++) {
23                if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) {
24                    ans++;
25                }
26            }
27        }
28
29        return ans;
30    }
31};
32