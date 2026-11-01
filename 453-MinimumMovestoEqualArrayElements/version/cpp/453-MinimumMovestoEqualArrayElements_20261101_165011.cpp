// Last updated: 01/11/2026, 16:50:11
1class Solution {
2public:
3    int minMoves(vector<int>& nums) {
4        return accumulate(nums.begin(), nums.end(), 0ll) -
5               (nums.size() * ranges::min(nums));
6    }
7};