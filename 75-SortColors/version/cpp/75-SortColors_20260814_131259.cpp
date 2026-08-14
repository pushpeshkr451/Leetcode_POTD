// Last updated: 14/08/2026, 13:12:59
1class Solution {
2public:
3    void sortColors(vector<int>& nums) {
4        vector<int>ans=nums;
5        sort(ans.begin(),ans.end());
6        nums=ans;
7    }
8};