// Last updated: 16/06/2026, 20:23:13
1class Solution {
2public:
3    string processStr(std::string s) {
4        string res = "";
5        for (char c : s) {
6            if (c != '*' && c != '#' && c != '%') {
7                res += c;
8            } else if (c == '#') {
9                res += res;
10            } else if (c == '%') {
11                reverse(res.begin(), res.end());
12            } else {
13                if (!res.empty()) res.pop_back();
14            }
15        }
16        return res;
17    }
18};