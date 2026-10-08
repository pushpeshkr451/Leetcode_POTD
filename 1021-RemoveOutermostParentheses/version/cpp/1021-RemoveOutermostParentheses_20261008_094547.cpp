// Last updated: 08/10/2026, 09:45:47
1class Solution {
2public:
3    string removeOuterParentheses(string s) {
4        string res;
5        int level = 0;
6
7        for (char c : s)
8            if (c == '(') {
9                if (level > 0)
10                    res += c;
11                level++;
12            } else {
13                level--;
14                if (level > 0)
15                    res += c;
16            }
17
18        return res;
19    }
20};