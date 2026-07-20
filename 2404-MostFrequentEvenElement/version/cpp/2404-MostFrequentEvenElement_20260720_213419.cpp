// Last updated: 20/07/2026, 21:34:19
1class Solution {
2public:
3    int mostFrequentEven(vector<int>& nums) {
4        map<int,int>mp;
5
6        for(auto it:nums){
7            if(it%2==0)mp[it]++;
8        }
9
10        int mx=INT_MIN;
11        for(auto it:mp)mx=max(it.second,mx);
12
13        for(auto it:mp){
14            if(it.second==mx)return it.first;
15        }
16
17        return -1;
18    }
19};