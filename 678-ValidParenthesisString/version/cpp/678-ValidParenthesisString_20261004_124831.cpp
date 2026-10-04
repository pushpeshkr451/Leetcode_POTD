// Last updated: 04/10/2026, 12:48:31
1class Solution {
2public:
3    bool checkValidString(string s) {
4        int l = 0, h = 0;
5
6        for (auto& c : s) {
7            l += ((c == '(') << 1) - 1;
8            h += ((c != ')') << 1) - 1;
9
10            if (h < 0) return 0;
11
12            l = max(l, 0);
13        }
14
15        return l == 0;
16    }
17};