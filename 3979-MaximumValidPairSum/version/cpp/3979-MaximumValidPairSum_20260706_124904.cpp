// Last updated: 06/07/2026, 12:49:04
1class Solution {
2public:
3    int maxValidPairSum(vector<int>& nums, int k) {
4        int res = 0, pre = 0, n = nums.size();
5        for (int i = 0; i < n - k; i++) {
6            pre = max(pre, nums[i]);
7            res = max(res, pre + nums[i + k]);
8        }
9        return res;
10    }
11};