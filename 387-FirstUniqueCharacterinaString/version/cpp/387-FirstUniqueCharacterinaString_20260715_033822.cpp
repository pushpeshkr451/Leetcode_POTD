// Last updated: 15/07/2026, 03:38:22
1class Solution {
2public:
3    string triangleType(vector<int>& nums) {
4        sort(nums.begin(),nums.end());
5        if(nums[0]+nums[1]<=nums[2])return "none";
6        vector<string>triangle{"equilateral","isosceles","scalene"};
7        if(nums[0]==nums[1] && nums[1]==nums[2])return triangle[0];
8        else if(nums[0]==nums[1] || nums[1]==nums[2]||nums[0]==nums[2])return triangle[1];
9        return triangle[2];
10    }
11};