// Last updated: 12/08/2026, 22:05:35
1class Solution {
2public:
3    vector<int> getConcatenation(vector<int>& nums) {
4        vector<int>ans(nums.begin(),nums.end());
5
6        for(auto it:nums)ans.push_back(it);
7
8        return ans;
9    }
10};