// Last updated: 27/07/2026, 14:45:08
1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        int n=nums.size();
5        sort(nums.begin(),nums.end());
6
7        return (nums[n-1]-1)*(nums[n-2]-1);
8    }
9};