// Last updated: 12/06/2026, 12:24:25
1class Solution {
2public:
3    static const int MOD = 1000000007;
4
5    vector<int> depth;
6    vector<vector<int>> up;
7    vector<vector<int>> graph;
8    int LOG;
9
10    void dfs(int node, int parent) {
11        up[node][0] = parent;
12
13        for (int j = 1; j < LOG; j++) {
14            up[node][j] = up[up[node][j - 1]][j - 1];
15        }
16
17        for (int next : graph[node]) {
18            if (next == parent) continue;
19
20            depth[next] = depth[node] + 1;
21            dfs(next, node);
22        }
23    }
24
25    int lca(int a, int b) {
26        if (depth[a] < depth[b]) swap(a, b);
27
28        int diff = depth[a] - depth[b];
29
30        for (int j = LOG - 1; j >= 0; j--) {
31            if ((diff >> j) & 1) {
32                a = up[a][j];
33            }
34        }
35
36        if (a == b) return a;
37
38        for (int j = LOG - 1; j >= 0; j--) {
39            if (up[a][j] != up[b][j]) {
40                a = up[a][j];
41                b = up[b][j];
42            }
43        }
44
45        return up[a][0];
46    }
47
48    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
49        int n = edges.size() + 1;
50
51        LOG = 17;
52        while ((1 << LOG) <= n) LOG++;
53
54        graph.assign(n + 1, {});
55        for (auto &e : edges) {
56            int u = e[0];
57            int v = e[1];
58
59            graph[u].push_back(v);
60            graph[v].push_back(u);
61        }
62
63        depth.assign(n + 1, 0);
64        up.assign(n + 1, vector<int>(LOG, 1));
65
66        dfs(1, 1);
67
68        vector<int> pow2(n + 1, 1);
69        for (int i = 1; i <= n; i++) {
70            pow2[i] = (long long)pow2[i - 1] * 2 % MOD;
71        }
72
73        vector<int> ans;
74
75        for (auto &q : queries) {
76            int u = q[0];
77            int v = q[1];
78
79            int ancestor = lca(u, v);
80
81            int dist = depth[u] + depth[v] - 2 * depth[ancestor];
82
83            if (dist == 0) {
84                ans.push_back(0);
85            } else {
86                ans.push_back(pow2[dist - 1]);
87            }
88        }
89
90        return ans;
91    }
92};