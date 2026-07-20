// Last updated: 20/07/2026, 21:40:21
1class Solution {
2public:
3    vector<int> numberOfPairs(vector<int>& nums) {
4        unordered_map<int,int>mp;
5
6        for(auto it:nums)mp[it]++;
7        vector<int>ans(2,0);
8
9        for(auto it:mp){
10            ans[0]+=(it.second)/2;
11            if(it.second%2)ans[1]++;
12        }
13        return ans;
14    }
15};