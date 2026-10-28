// Last updated: 28/10/2026, 20:32:15
1class Solution {
2public:
3    int maxEqualAdjacentPairs(vector<int>& nums) {
4        int ans = 0;
5        vector<array<int, 2>> v;
6        int cur = nums[0], count = 0;
7        for (auto& n : nums) {
8            if (n == cur)
9                ++count;
10            else {
11                v.push_back({cur, count});
12                cur = n;
13                count = 1;
14            }
15        }
16        v.push_back({cur, count});
17        int sum = 0;
18        for (auto& [f, s] : v)
19            sum += s - 1;
20
21        map<array<int, 2>, int> m;
22        int j = 0;
23        for (int i = 0; i < v.size(); ++i) {
24            if (i - 1 >= 0) {
25                ++m[{v[i - 1][0], v[i][0]}];
26                j = max(j, m[{v[i - 1][0], v[i][0]}]);
27            }
28
29            if (i + 1 < v.size()) {
30                ++m[{v[i + 1][0], v[i][0]}];
31                j = max(j, m[{v[i + 1][0], v[i][0]}]);
32            }
33        }
34        return sum + j;
35    }
36};