// Last updated: 19/07/2026, 22:41:14
1class Solution {
2public:
3    int maximumProduct(vector<int>& nums) {
4        sort(nums.begin(),nums.end());
5
6        int n=nums.size();
7        return max(nums[0]*nums[1]*nums[n-1],nums[n-1]*nums[n-2]*nums[n-3]);
8    }
9};