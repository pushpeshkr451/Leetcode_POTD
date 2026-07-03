// Last updated: 03/07/2026, 13:01:37
1class Solution {
2public:
3    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
4                         long long k) {
5        int n = online.size();
6        vector<vector<pair<int, int>>> g(n);
7        int l = INT_MAX, r = 0;
8
9        for (auto& edge : edges) {
10            int u = edge[0];
11            int v = edge[1];
12            int w = edge[2];
13            if (!online[u] || !online[v]) {
14                continue;
15            }
16            g[u].push_back({v, w});
17            l = min(l, w);
18            r = max(r, w);
19        }
20
21        auto check = [&](int mid) -> bool {
22            vector<long long> dis(n, LLONG_MAX);
23            priority_queue<pair<long long, int>, vector<pair<long long, int>>,
24                           greater<>>
25                q;
26
27            dis[0] = 0;
28            q.push({0, 0});
29
30            while (!q.empty()) {
31                auto [d, u] = q.top();
32                q.pop();
33
34                if (d > k) {
35                    return false;
36                }
37                if (u == n - 1) {
38                    return true;
39                }
40                if (d > dis[u]) {
41                    continue;
42                }
43
44                for (auto& [v, w] : g[u]) {
45                    if (w < mid) {
46                        continue;
47                    }
48                    if (dis[v] > dis[u] + w) {
49                        dis[v] = dis[u] + w;
50                        q.push({dis[v], v});
51                    }
52                }
53            }
54            return false;
55        };
56
57        if (!check(l)) {
58            return -1;
59        }
60
61        while (l <= r) {
62            int mid = (l + r) >> 1;
63            if (check(mid)) {
64                l = mid + 1;
65            } else {
66                r = mid - 1;
67            }
68        }
69        return r;
70    }
71};