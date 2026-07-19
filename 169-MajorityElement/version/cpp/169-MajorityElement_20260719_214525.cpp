// Last updated: 19/07/2026, 21:45:25
1class Solution {
2public:
3    int majorityElement(vector<int>& nums) {
4        int n=nums.size();
5        if(n==1)return nums[0];
6
7        sort(nums.begin(),nums.end());
8        return nums[(n+1)/2-1];
9    }
10};