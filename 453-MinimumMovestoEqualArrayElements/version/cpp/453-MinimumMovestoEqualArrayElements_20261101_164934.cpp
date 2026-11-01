// Last updated: 01/11/2026, 16:49:34
1class Solution {
2public:
3    int minMoves(vector<int>& nums) {
4        return accumulate(nums.begin(), nums.end(), 0ll) -
5               (nums.size() * ranges::min(nums));
6    }
7};