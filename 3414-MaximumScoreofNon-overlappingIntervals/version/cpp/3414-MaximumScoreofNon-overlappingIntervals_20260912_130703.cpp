// Last updated: 12/09/2026, 13:07:03
1class Solution {
2public:
3    vector<int> maximumWeight(vector<vector<int>>& intervals) {
4        int n = intervals.size();
5        vector<vector<int>> a(n, vector<int>(4, 0));
6        for (int i = 0; i < n; i++) {
7            a[i][0] = intervals[i][0];
8            a[i][1] = intervals[i][1];
9            a[i][2] = intervals[i][2];
10            a[i][3] = i;
11        }
12        sort(a.begin(), a.end());
13        vector<int> ls(n, 0);
14        for (int i = 0; i < n; i++)
15            ls[i] = a[i][0];
16        vector<vector<long long>> s(n + 1, vector<long long>(5, 0));
17        vector<vector<vector<int>>> p(n + 1, vector<vector<int>>(5));
18        for (int i = n - 1; i >= 0; i--) {
19            int nx = upper_bound(ls.begin(), ls.end(), a[i][1]) - ls.begin();
20            for (int k = 1; k <= 4; k++) {
21                s[i][k] = s[i + 1][k];
22                p[i][k] = p[i + 1][k];
23                long long t = (long long)a[i][2] + s[nx][k - 1];
24                vector<int> q = p[nx][k - 1];
25                q.push_back(a[i][3]);
26                sort(q.begin(), q.end());
27                if (t > s[i][k] || (t == s[i][k] && q < p[i][k])) {
28                    s[i][k] = t;
29                    p[i][k] = q;
30                }
31            }
32        }
33        return p[0][4];
34    }
35};