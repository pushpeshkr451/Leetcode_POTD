// Last updated: 04/07/2026, 13:18:55
1class Solution {
2public:
3    int minScore(int n, vector<vector<int>>& roads) {
4        vector<int> root(n + 1);
5        iota(root.begin(), root.end(), 0);
6
7        auto find = [&](this auto& self, int i) -> int {
8            return root[i] == i ? i : root[i] = self(root[i]);
9        };
10
11        for (auto& r : roads)
12            root[find(r[0])] = find(r[1]);
13
14        int res = 10001;
15        for (auto& r : roads)
16            if (find(r[0]) == find(1))
17                res = min(res, r[2]);
18
19        return res;
20    }
21};