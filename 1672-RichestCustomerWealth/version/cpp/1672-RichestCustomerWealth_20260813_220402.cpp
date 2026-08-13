// Last updated: 13/08/2026, 22:04:02
1class Solution {
2public:
3    int maximumWealth(vector<vector<int>>& accounts) {
4
5        int n=accounts.size();
6        int ans=INT_MIN;
7
8        for(int i=0;i<n;i++){
9            int sum=accumulate(accounts[i].begin(),accounts[i].end(),0);
10            ans=max(sum,ans);
11        }
12        
13        return ans;
14    }
15};