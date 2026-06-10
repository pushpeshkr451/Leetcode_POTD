// Last updated: 10/06/2026, 13:46:39
1class Solution {
2public:
3    long long maxTotalValue(vector<int>& nums, int k) {
4        int n = nums.size();
5        int logn = 32 - __builtin_clz(n);
6        vector<vector<int>> stMax(n, vector<int>(logn));
7        vector<vector<int>> stMin(n, vector<int>(logn));
8        for (int i = 0; i < n; i++) {
9            stMax[i][0] = stMin[i][0] = nums[i];
10        }
11        for (int j = 1; j < logn; j++) {
12            for (int i = 0; i + (1 << j) <= n; i++) {
13                stMax[i][j] =
14                    max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
15                stMin[i][j] =
16                    min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
17            }
18        }
19        auto queryMax = [&](int l, int r) {
20            int j = 31 - __builtin_clz(r - l + 1);
21            return max(stMax[l][j], stMax[r - (1 << j) + 1][j]);
22        };
23        auto queryMin = [&](int l, int r) {
24            int j = 31 - __builtin_clz(r - l + 1);
25            return min(stMin[l][j], stMin[r - (1 << j) + 1][j]);
26        };
27        priority_queue<tuple<int, int, int>> pq;
28        for (int l = 0; l < n; l++) {
29            pq.emplace(queryMax(l, n - 1) - queryMin(l, n - 1), l, n - 1);
30        }
31        long long ans = 0;
32        while (k--) {
33            auto [val, l, r] = pq.top();
34            pq.pop();
35            ans += val;
36            if (r > l) {
37                pq.emplace(queryMax(l, r - 1) - queryMin(l, r - 1), l, r - 1);
38            }
39        }
40        return ans;
41    }
42};