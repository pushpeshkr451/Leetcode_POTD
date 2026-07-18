// Last updated: 18/07/2026, 22:35:21
1class Solution {
2public:
3    int findGCD(vector<int>& nums) {
4        sort(nums.begin(),nums.end());
5        int a=nums[0],b=nums[nums.size()-1];
6        return __gcd(a,b);
7    }
8};