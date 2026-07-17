// Last updated: 17/07/2026, 21:48:21
1class Solution {
2public:
3    bool isIsomorphic(string s, string t) {
4        unordered_map<char, char> mp1;
5        unordered_map<char, char> mp2;
6
7        for (int i = 0; i < s.size(); i++) {
8
9            if (mp1.find(s[i]) != mp1.end()) {
10                if (mp1[s[i]] != t[i])
11                    return false;
12            } else {
13                mp1[s[i]] = t[i];
14            }
15
16            if (mp2.find(t[i]) != mp2.end()) {
17                if (mp2[t[i]] != s[i])
18                    return false;
19            } else {
20                mp2[t[i]] = s[i];
21            }
22        }
23
24        return true;
25    }
26};