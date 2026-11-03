// Last updated: 03/11/2026, 11:56:03
1class Solution {
2public:
3    int minMoves(vector<int>& nums) {
4        int ans = 0;
5        int mx = *max_element(nums.begin(), nums.end());
6
7        for (int elem : nums)
8            ans += mx - elem;
9
10        return ans;
11    }
12};