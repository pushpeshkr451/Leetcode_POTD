// Last updated: 12/07/2026, 13:11:30
1class Solution {
2public:
3    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
4        int m = grid.size(), n = grid[0].size();
5        vector<bitset<250>> compat(n);
6        for (auto& b : compat) {
7            for (int k = 0; k < n; ++k)
8                b[k] = 1;
9        }
10
11        vector<int> order(n), val(n);
12        vector<bitset<250>> pref(n + 1);
13
14        for (int i = 0; i < m; ++i) {
15            iota(order.begin(), order.end(), 0);
16            sort(order.begin(), order.end(),
17                 [&](int a, int b) { return grid[i][a] < grid[i][b]; });
18            for (int p = 0; p < n; ++p)
19                val[p] = grid[i][order[p]];
20            pref[0].reset();
21            for (int p = 0; p < n; ++p) {
22                pref[p + 1] = pref[p];
23                pref[p + 1][order[p]] = 1;
24            }
25            for (int j = 0; j < n; ++j) {
26                int v = grid[i][j];
27                int lo = lower_bound(val.begin(), val.end(), v - limit) -
28                         val.begin();
29                int hi = upper_bound(val.begin(), val.end(), v + limit) -
30                         val.begin();
31                compat[j] &= (pref[hi] ^ pref[lo]);
32            }
33        }
34
35        vector<int> dp(n, 1);
36        int ans = 1;
37        for (int j = 0; j < n; ++j) {
38            for (int k = compat[j]._Find_first(); k < j;
39                 k = compat[j]._Find_next(k))
40                dp[j] = max(dp[j], dp[k] + 1);
41            ans = max(ans, dp[j]);
42        }
43        return ans;
44    }
45};