// Last updated: 15/07/2026, 03:50:42
1class Solution {
2public:
3    int maximumWealth(vector<vector<int>>& accounts) {
4        int ans=INT_MIN;
5
6        for(auto row:accounts){
7            int sum=accumulate(row.begin(),row.end(),0);
8            ans=max(ans,sum);
9        }
10
11        return ans;
12    }
13};