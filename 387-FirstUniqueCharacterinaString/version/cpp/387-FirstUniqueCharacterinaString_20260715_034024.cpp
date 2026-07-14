// Last updated: 15/07/2026, 03:40:24
1class Solution {
2public:
3    vector<int> sortedSquares(vector<int>& nums) {
4        vector<int>ans;
5
6        for(auto it:nums){
7            int num=it*it;
8            ans.push_back(num);
9        }
10        sort(ans.begin(),ans.end());
11        return ans;
12    }
13};