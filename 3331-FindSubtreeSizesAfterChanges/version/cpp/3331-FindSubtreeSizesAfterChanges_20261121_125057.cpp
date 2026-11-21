// Last updated: 21/11/2026, 12:50:57
1class Solution {
2public:
3    void dfs(int pre, int cur, vector<vector<int>>& g, vector<vector<int>>& par,
4             vector<int>& ans, string& s) {
5        par[s[cur] - 'a'].push_back(cur);
6        for (auto& x : g[cur]) {
7            dfs(cur, x, g, par, ans, s);
8        }
9        par[s[cur] - 'a'].pop_back();
10        ans[cur] += 1;
11        if (par[s[cur] - 'a'].size() > 0) {
12            int prev = par[s[cur] - 'a'].back();
13            ans[prev] += ans[cur];
14        } else if (pre != -1) {
15            ans[pre] += ans[cur];
16        }
17    }
18
19    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
20        int n = parent.size();
21        vector<vector<int>> g(n);
22        for (int i = 1; i < n; i++)
23            g[parent[i]].push_back(i);
24
25        vector<vector<int>> par(26);
26        vector<int> ans(n, 0);
27        dfs(-1, 0, g, par, ans, s);
28        return ans;
29    }
30};