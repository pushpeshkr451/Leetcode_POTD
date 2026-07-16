// Last updated: 16/07/2026, 21:51:08
1class Solution {
2public:
3    int countWords(vector<string>& words1, vector<string>& words2) {
4        unordered_map<string,int>mp1,mp2;
5
6        for(auto it:words1)mp1[it]++;
7
8        for(auto it:words2){
9            mp2[it]++;
10        }
11
12        int ans=0;
13
14        for(auto it:mp1){
15            if(it.second==1 && (mp2.find(it.first)!=mp2.end()&&mp2[it.first]==1))ans++;
16        }
17
18        return ans;
19    }
20};