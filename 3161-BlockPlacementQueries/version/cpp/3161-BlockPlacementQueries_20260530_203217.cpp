// Last updated: 30/05/2026, 20:32:17
1class Solution {
2public:
3
4    vector<int> seg;
5    const int MAXX = 50000;
6
7    void update(int node, int l, int r, int idx, int val) {
8        if (l == r) {
9            seg[node] = val;
10            return;
11        }
12
13        int mid = (l + r) / 2;
14
15        if (idx <= mid)
16            update(2 * node, l, mid, idx, val);
17        else
18            update(2 * node + 1, mid + 1, r, idx, val);
19
20        seg[node] = max(seg[2 * node], seg[2 * node + 1]);
21    }
22
23    int query(int node, int l, int r, int ql, int qr) {
24        if (ql > r || qr < l)
25            return 0;
26
27        if (ql <= l && r <= qr)
28            return seg[node];
29
30        int mid = (l + r) / 2;
31
32        return max(
33            query(2 * node, l, mid, ql, qr),
34            query(2 * node + 1, mid + 1, r, ql, qr)
35        );
36    }
37
38    vector<bool> getResults(vector<vector<int>>& queries) {
39
40        seg.resize(4 * (MAXX + 1), 0);
41
42        set<int> obstacles;
43        obstacles.insert(0);
44
45        // Build final obstacle configuration
46        for (auto &q : queries) {
47            if (q[0] == 1) obstacles.insert(q[1]);
48        }
49
50        vector<int> pos(obstacles.begin(), obstacles.end());
51        // at pos[i] we have a gap of (pos[i] - pos[i - 1]) which we are storing
52        // in the segment tree
53        for (int i = 1; i < (int)pos.size(); i++) {
54            update(1,0,MAXX,pos[i],pos[i] - pos[i - 1]);
55        }
56
57        vector<bool> ans;
58
59        for (int i = (int)queries.size() - 1; i >= 0; i--) {
60
61            if (queries[i][0] == 2) {
62
63                int x = queries[i][1];
64                int sz = queries[i][2];
65                // find a prev obstacle lesser than x, then we can fit the block
66                //before prev or between prev to x
67                auto it = prev(obstacles.upper_bound(x));
68
69                int prevObstacle = *it;
70                int best = query(1,0,MAXX,0,prevObstacle);
71
72                best = max(best, x - prevObstacle);
73                ans.push_back(best >= sz);
74            }
75            else {
76
77                int x = queries[i][1]; // so we now remove x obstacle
78                auto it = obstacles.find(x);
79                int leftPos = *prev(it); //left of x
80
81                update(1,0,MAXX,x,0); // update gap at x to 0 or remove gap ending at x
82
83                auto rightIt = next(it);
84
85                if (rightIt != obstacles.end()) {
86                    int rightPos = *rightIt;
87                    // merging the interval from leftpos to rightpos as one single gap
88                    update(1,0,MAXX,rightPos,rightPos - leftPos);
89                }
90
91                obstacles.erase(it);
92            }
93        }
94
95        reverse(ans.begin(), ans.end());
96        return ans;
97    }
98};