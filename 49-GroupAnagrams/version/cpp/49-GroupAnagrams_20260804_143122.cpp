// Last updated: 04/08/2026, 14:31:22
1class Solution {
2public:
3    vector<vector<string>> groupAnagrams(vector<string>& strs) {
4
5        unordered_map<string, vector<string>> mp;
6
7        for (string s : strs) {
8            string p = s;
9            sort(p.begin(), p.end());
10
11            mp[p].push_back(s);
12        }
13
14        vector<vector<string>> ans;
15
16        for (auto it : mp) {
17            ans.push_back(it.second);
18        }
19
20        return ans;
21    }
22};