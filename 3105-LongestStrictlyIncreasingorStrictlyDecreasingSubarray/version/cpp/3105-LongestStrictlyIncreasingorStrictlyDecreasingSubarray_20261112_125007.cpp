// Last updated: 12/11/2026, 12:50:07
1class Solution {
2public:
3    int longestMonotonicSubarray(vector<int>& nums) {
4        int inc = 1, dec = 1;
5        int ans = INT_MIN;
6        for (int i = 1; i < nums.size(); i++) {
7            if (nums[i - 1] < nums[i]) {
8                inc++;
9                ans = max(ans, dec);
10                dec = 1;
11
12            } else if (nums[i - 1] > nums[i]) {
13                dec++;
14                ans = max(ans, inc);
15                inc = 1;
16
17            } else {
18                ans = max(ans, inc);
19                inc = 1;
20                ans = max(ans, dec);
21                dec = 1;
22            }
23        }
24        ans = max(ans, inc);
25        ans = max(ans, dec);
26        return ans;
27    }
28};