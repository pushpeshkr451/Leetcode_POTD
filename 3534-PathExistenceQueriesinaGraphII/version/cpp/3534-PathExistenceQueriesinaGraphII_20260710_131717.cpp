// Last updated: 10/07/2026, 13:17:17
1class Solution {
2public:
3    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
4        int LOG = 18;
5
6        vector<pair<int, int>> vec;
7        for (int i = 0; i < n; i++) {
8            vec.push_back({nums[i], i});
9        }
10
11        sort(vec.begin(), vec.end());
12
13        vector<int> getSortIdx(n);
14        for (int i = 0; i < n; i++) {
15            getSortIdx[vec[i].second] = i;
16        }
17
18        vector<vector<int>> st(n, vector<int>(LOG, 0));
19        int l = 0;
20
21        for (int r = 0; r < n; r++) {
22            while (vec[r].first - vec[l].first > maxDiff) {
23                st[l][0] = r - 1;
24                l++;
25            }
26        }
27
28        while (l < n) {
29            st[l][0] = n - 1;
30            l++;
31        }
32
33        for (int j = 1; j < LOG; j++) {
34            for (int i = 0; i < n; i++) {
35                st[i][j] = st[st[i][j - 1]][j - 1];
36            }
37        }
38
39        vector<int> ans(queries.size(), -1);
40
41        for (int i = 0; i < queries.size(); i++) {
42            int a = getSortIdx[queries[i][0]];
43            int b = getSortIdx[queries[i][1]];
44
45            if (a > b) swap(a, b);
46
47            if (a == b) {
48                ans[i] = 0;
49                continue;
50            }
51
52            int cur = a;
53            int step = 0;
54
55            for (int j = LOG - 1; j >= 0; j--) {
56                if (st[cur][j] < b) {
57                    step += 1 << j;
58                    cur = st[cur][j];
59                }
60            }
61
62            if (st[cur][0] >= b) {
63                ans[i] = step + 1;
64            }
65        }
66
67        return ans;
68    }
69};