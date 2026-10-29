// Last updated: 29/10/2026, 12:06:19
1class BIT {
2private:
3    vector<int> tree;
4    int n;
5
6public:
7    BIT(int _n) : n(_n), tree(_n + 1) {}
8
9    static int lowbit(int x) { return x & -x; }
10
11    void update(int x, int v) {
12        while (x <= n) {
13            tree[x] ^= v;
14            x += lowbit(x);
15        }
16    }
17
18    int query(int x) {
19        int ret = 0;
20        while (x) {
21            ret ^= tree[x];
22            x -= lowbit(x);
23        }
24        return ret;
25    }
26
27    void updateRange(int l, int r, int v) {
28        update(l, v);
29        update(r + 1, v);
30    }
31};
32
33class Solution {
34public:
35    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s,
36                                vector<string>& queries) {
37        vector<vector<int>> g(n);
38        for (auto& e : edges) {
39            g[e[0]].push_back(e[1]);
40            g[e[1]].push_back(e[0]);
41        }
42
43        int LOG = 32 - __builtin_clz(n);
44        vector<vector<int>> fa(n, vector<int>(LOG));
45        vector<int> dep(n), l(n), r(n);
46        int timer = 0;
47
48        auto dfs = [&](auto&& dfs, int u, int p) -> void {
49            l[u] = ++timer;
50            fa[u][0] = p;
51            for (int v : g[u]) {
52                if (v == p) {
53                    continue;
54                }
55                dep[v] = dep[u] + 1;
56                dfs(dfs, v, u);
57            }
58            r[u] = timer;
59        };
60        dfs(dfs, 0, 0);
61
62        for (int j = 1; j < LOG; ++j) {
63            for (int i = 0; i < n; ++i) {
64                fa[i][j] = fa[fa[i][j - 1]][j - 1];
65            }
66        }
67
68        auto lca = [&](int u, int v) {
69            if (dep[u] < dep[v]) {
70                swap(u, v);
71            }
72            int diff = dep[u] - dep[v];
73            for (int i = 0; i < LOG; ++i) {
74                if ((diff >> i) & 1) {
75                    u = fa[u][i];
76                }
77            }
78            if (u == v) {
79                return u;
80            }
81            for (int i = LOG - 1; i >= 0; --i) {
82                if (fa[u][i] != fa[v][i]) {
83                    u = fa[u][i];
84                    v = fa[v][i];
85                }
86            }
87            return fa[u][0];
88        };
89
90        BIT bit(n + 1);
91        for (int i = 0; i < n; ++i) {
92            bit.updateRange(l[i], r[i], 1 << (s[i] - 'a'));
93        }
94
95        vector<bool> ans;
96        for (string& q : queries) {
97            stringstream ss(q);
98            string op;
99            ss >> op;
100            if (op == "update") {
101                int u;
102                char c;
103                ss >> u >> c;
104                bit.updateRange(l[u], r[u],
105                                (1 << (s[u] - 'a')) ^ (1 << (c - 'a')));
106                s[u] = c;
107            } else {
108                int u, v;
109                ss >> u >> v;
110                int w = lca(u, v);
111                int mask =
112                    bit.query(l[u]) ^ bit.query(l[v]) ^ (1 << (s[w] - 'a'));
113                ans.push_back(__builtin_popcount(mask) <= 1);
114            }
115        }
116        return ans;
117    }
118};