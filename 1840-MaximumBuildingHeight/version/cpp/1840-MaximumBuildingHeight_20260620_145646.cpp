// Last updated: 20/06/2026, 14:56:46
1class Solution {
2public:
3    int maxBuilding(int n, vector<vector<int>>& r) {
4        if(r.empty()) return n - 1;
5
6        sort(r.begin(), r.end());
7
8        int id = 1, h = 0;
9
10        for(auto &x : r) {
11            x[1] = min(x[1], x[0] - id + h);
12            id = x[0];
13            h = x[1];
14        }
15
16        for(int i = r.size() - 2; i >= 0; i--) {
17            r[i][1] = min(r[i][1], r[i+1][1] + r[i+1][0] - r[i][0]);
18        }
19
20        int ans = n - r.back()[0] + r.back()[1];
21        id = 1; h = 0;
22
23        for(auto &x : r) {
24            int steps = x[0] - id - abs(x[1] - h);
25            int higher = max(x[1], h);
26            ans = max(ans, higher + steps / 2);
27            id = x[0];
28            h = x[1];
29        }
30
31        return ans;
32    }
33};