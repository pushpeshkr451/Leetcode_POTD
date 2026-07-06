// Last updated: 06/07/2026, 12:46:31
1class Solution {
2public:
3    int removeCoveredIntervals(vector<vector<int>>& intervals) {
4        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
5            if (a[0] == b[0]) return a[1] > b[1];
6            return a[0] < b[0];
7        });
8
9        int ans = 0;
10        int prevEnd = -1;
11
12        for (auto &it : intervals) {
13            if (it[1] > prevEnd) {
14                ans++;
15                prevEnd = it[1];
16            }
17        }
18
19        return ans;
20    }
21};