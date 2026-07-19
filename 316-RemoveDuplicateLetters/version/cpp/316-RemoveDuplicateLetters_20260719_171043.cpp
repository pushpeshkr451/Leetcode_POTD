// Last updated: 19/07/2026, 17:10:43
1class Solution {
2public:
3    string removeDuplicateLetters(string s) {
4        vector<int> last(26);
5
6        for (int i = 0; i < s.size(); i++)
7            last[s[i] - 'a'] = i;
8
9        vector<bool> vis(26, false);
10        string st = "";
11
12        for (int i = 0; i < s.size(); i++) {
13            char c = s[i];
14
15            if (vis[c - 'a'])
16                continue;
17
18            while (!st.empty() &&
19                   st.back() > c &&
20                   last[st.back() - 'a'] > i) {
21                vis[st.back() - 'a'] = false;
22                st.pop_back();
23            }
24
25            st.push_back(c);
26            vis[c - 'a'] = true;
27        }
28
29        return st;
30    }
31};