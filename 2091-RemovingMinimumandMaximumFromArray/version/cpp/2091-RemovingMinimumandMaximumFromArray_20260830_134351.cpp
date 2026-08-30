// Last updated: 30/08/2026, 13:43:51
1class Solution {
2public:
3    int minimumDeletions(vector<int>& nums) {
4        int n = nums.size();
5
6        int mi = INT_MAX, ma = INT_MIN;
7        int midx = -1, madx = -1;
8
9        for (int i = 0; i < n; i++) {
10            if (nums[i] > ma) {
11                ma = nums[i];
12                madx = i;
13            }
14
15            if (nums[i] < mi) {
16                mi = nums[i];
17                midx = i;
18            }
19        }
20
21        int left = min(midx, madx);
22        int right = max(midx, madx);
23
24        int ans = min({right + 1, n - left, left + 1 + n - right});
25
26        return ans;
27    }
28};