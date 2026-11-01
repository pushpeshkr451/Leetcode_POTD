// Last updated: 01/11/2026, 16:49:03
1class Solution {
2public:
3    int minMoves(vector<int>& nums) {
4        return accumulate(nums.begin(), nums.end(), 0ll) - (nums.size() * ranges::min(nums));
5    }
6};