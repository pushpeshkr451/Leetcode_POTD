// Last updated: 30/10/2026, 11:06:41
1class Solution {
2public:
3    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
4        vector<vector<pair<int, int>>> adj(n);
5
6        for (auto& it : edges)
7            adj[it[0]].push_back({it[1], it[2]});
8
9        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
10
11        priority_queue<array<int, 3>, vector<array<int, 3>>,
12                       greater<array<int, 3>>>
13            pq;
14
15        dist[0][1] = 0;
16        pq.push({0, 0, 1});
17
18        while (!pq.empty()) {
19            auto [d, u, c] = pq.top();
20            pq.pop();
21
22            if (d > dist[u][c])
23                continue;
24
25            if (u == n - 1)
26                return d;
27            for (auto& [v, w] : adj[u]) {
28                int cnt;
29                if (labels[u] == labels[v])
30                    cnt = c + 1;
31                else
32                    cnt = 1;
33
34                if (cnt <= k) {
35                    if (d + w < dist[v][cnt]) {
36                        dist[v][cnt] = d + w;
37                        pq.push({dist[v][cnt], v, cnt});
38                    }
39                }
40            }
41        }
42        return -1;
43    }
44};