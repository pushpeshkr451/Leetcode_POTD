// Last updated: 15/07/2026, 03:16:42
1class Solution {
2public:
3    int differenceOfSum(vector<int>& nums) {
4        int sum=accumulate(nums.begin(),nums.end(),0);
5
6        int n=nums.size();
7        int dsum=0;
8
9        for(int i=0;i<n;i++){
10            string s=to_string(nums[i]);
11            for(auto it:s)dsum+=(it-'0');
12        }
13
14        return abs(sum-dsum);
15
16    }
17};