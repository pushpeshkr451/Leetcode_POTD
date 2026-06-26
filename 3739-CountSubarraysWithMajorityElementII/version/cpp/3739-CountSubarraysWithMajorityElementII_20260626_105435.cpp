// Last updated: 26/06/2026, 10:54:35
1class Solution {
2public:
3    long long countMajoritySubarrays(vector<int>& nums, int target) {
4        int n = nums.size();
5        // represents the occurrence count of prefix sums -n, -(n-1), ..., 0, 1,
6        // ..., n, with index offset by n.
7        vector<int> pre(n * 2 + 1, 0);
8        pre[n] = 1;
9        int cnt = n;
10        long long ans = 0, presum = 0;
11        for (int i = 0; i < n; ++i) {
12            if (nums[i] == target) {
13                presum += pre[cnt];
14                ++cnt;
15                ++pre[cnt];
16            } else {
17                --cnt;
18                presum -= pre[cnt];
19                ++pre[cnt];
20            }
21            ans += presum;
22        }
23        return ans;
24    }
25};