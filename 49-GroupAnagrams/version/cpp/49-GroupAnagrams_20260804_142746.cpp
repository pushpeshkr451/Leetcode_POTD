// Last updated: 04/08/2026, 14:27:46
1class Solution {
2public:
3    vector<vector<string>> groupAnagrams(vector<string>& strs) {
4        unordered_map<string,vector<int>>mp;
5
6        int n=strs.size();
7        for(int i=0;i<n;i++){
8            string s=strs[i];
9            string p=s;
10            sort(p.begin(),p.end());
11
12            mp[p].push_back(i);
13        }
14
15        vector<vector<string>>ans;
16
17        for(auto it:mp){
18            vector<int>v=it.second;
19            vector<string>temp;
20            for(auto it:v){
21                temp.push_back(strs[it]);
22            }
23
24            ans.push_back(temp);
25        }
26        
27        return ans;
28    }
29};