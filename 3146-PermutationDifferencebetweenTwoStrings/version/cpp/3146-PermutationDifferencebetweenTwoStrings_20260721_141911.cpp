// Last updated: 21/07/2026, 14:19:11
1class Solution {
2public:
3    int findPermutationDifference(string s, string t) {
4        unordered_map<char,int>mp;
5
6        for(int i=0;i<s.size();i++)mp[s[i]]=i;
7
8        int ans=0;
9        for(int i=0;i<s.size();i++){
10            ans+=abs(i-mp[t[i]]);
11        }
12
13        return ans;
14    }
15};