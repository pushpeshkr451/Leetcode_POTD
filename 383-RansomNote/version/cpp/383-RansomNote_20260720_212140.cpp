// Last updated: 20/07/2026, 21:21:40
1class Solution {
2public:
3    bool canConstruct(string a, string b) {
4        unordered_map<char,int>mp;
5
6        for(auto it:a)mp[it]++;
7
8        for(auto it:b){
9            if(mp.find(it)!=mp.end()){
10                mp[it]--;
11                if(mp[it]==0)mp.erase(it);
12            }
13        }
14
15        return mp.size()==0;
16    }
17};