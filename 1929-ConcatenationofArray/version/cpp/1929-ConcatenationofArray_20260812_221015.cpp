// Last updated: 12/08/2026, 22:10:15
1class Solution {
2public:
3    vector<int> buildArray(vector<int>& nums) {
4        int n=nums.size();
5
6        vector<int>ans(n);
7
8        for(int i=0;i<n;i++)ans[i]=nums[nums[i]];
9
10        return ans;
11    }
12};