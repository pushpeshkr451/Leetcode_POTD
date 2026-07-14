// Last updated: 15/07/2026, 02:34:56
1class Solution {
2public:
3    int firstUniqChar(string s) {
4        unordered_map<char,int>mp;
5
6        for(auto it:s)mp[it]++;
7
8        for(int i=0;i<s.size();i++){
9            if(mp[s[i]]==1)return i;
10        }
11
12        return -1;
13    }
14};