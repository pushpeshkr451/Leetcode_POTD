// Last updated: 22/07/2026, 13:44:31
1class Solution {
2public:
3    bool uniqueOccurrences(vector<int>& arr) {
4        unordered_map<int,int>mp;
5        set<int>st;
6
7        for(auto it:arr)mp[it]++;
8
9        for(auto it:mp){
10            if(st.find(it.second)!=st.end())return false;
11
12            st.insert(it.second);
13        }
14        return true;
15    }
16};