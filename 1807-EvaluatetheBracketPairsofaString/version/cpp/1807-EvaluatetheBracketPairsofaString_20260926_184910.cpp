// Last updated: 26/09/2026, 18:49:10
1class Solution {
2public:
3    string evaluate(string s, vector<vector<string>>& knowledge) {
4        
5        unordered_map<string, string> mp;
6
7        for (auto x : knowledge) {
8            mp[x[0]] = x[1];
9        }
10
11        string org = "";
12
13        for (int i = 0; i < s.size(); i++) {
14
15            // Normal character
16            if (s[i] != '(') {
17                org += s[i];
18            }
19            
20            else {
21                string key = "";
22                i++;  // skip '('
23
24                while (s[i] != ')') {
25                    key += s[i];
26                    i++;
27                }
28
29                if (mp.find(key) != mp.end()) {
30                    org += mp[key];
31                }
32                else {
33                    org += "?";
34                }
35            }
36        }
37
38        return org;
39    }
40};