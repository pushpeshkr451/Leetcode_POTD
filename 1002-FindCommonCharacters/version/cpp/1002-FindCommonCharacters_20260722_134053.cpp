// Last updated: 22/07/2026, 13:40:53
1class Solution {
2public:
3    vector<string> commonChars(vector<string>& words) {
4        vector<string> res;
5        
6        sort(words.begin(), words.end());
7        
8        for (char c : words[0]) {
9            bool common = true;
10            
11            for (int i = 1; i < words.size(); i++) {
12                if (words[i].find(c) == string::npos) {
13                    common = false;
14                    break;
15                } else {
16                    words[i].erase(words[i].find(c), 1);
17                }
18            }
19            if (common) {
20                res.push_back(string(1, c));
21            }
22        }
23        return res;
24    }
25};