// Last updated: 15/07/2026, 15:30:06
1class Solution {
2public:
3    int largestSumAfterKNegations(vector<int>& nums, int k) {
4
5        while (k--) {
6            sort(nums.begin(), nums.end());
7            nums[0] = -nums[0];
8        }
9
10        return accumulate(nums.begin(), nums.end(), 0);
11    }
12};