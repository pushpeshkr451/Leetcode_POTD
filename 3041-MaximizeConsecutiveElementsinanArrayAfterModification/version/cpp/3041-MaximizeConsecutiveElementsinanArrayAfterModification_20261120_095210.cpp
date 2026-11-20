// Last updated: 20/11/2026, 09:52:10
1class Solution {
2public:
3    int maxSelectedElements(vector<int>& nums) {
4        sort(begin(nums), end(nums));
5        vector<int> dp(1000002, 0);
6        for (auto num : nums) {
7            dp[num + 1] = 1 + dp[num];
8            dp[num] = max(dp[num], 1 + dp[num - 1]);
9        }
10        return *max_element(begin(dp), end(dp));
11    }
12};