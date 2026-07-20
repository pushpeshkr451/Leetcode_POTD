// Last updated: 20/07/2026, 14:44:26
1class Solution {
2public:
3    bool isAnagram(string s, string t) { 
4        unordered_map<char,int>mp;
5        for(auto it:s){
6            mp[it]++;
7        }
8        for(auto it:t){
9            mp[it]--;
10            if(mp[it]==0)mp.erase(it);
11        }
12        return mp.size()==0;
13    }
14};