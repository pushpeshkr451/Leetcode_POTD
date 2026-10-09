// Last updated: 09/10/2026, 06:56:48
1class Solution {
2public:
3    int minInsertions(string s) {
4        stack<char> v;
5        int ans = 0;
6        for (int i = 0; i < s.size(); i++) {
7            if (s[i] == '(')
8                v.push(s[i]);
9            else {
10                if (s[i] == ')' && i < s.size() && s[i + 1] == ')') {
11                    if (!v.empty())
12                        v.pop();
13                    else
14                        ans++;
15                    i++; // because we considered i+1 in this case
16                } else if (s[i] == ')' && i < s.size() && s[i + 1] != ')') {
17                    if (!v.empty()) {
18                        v.pop();
19                        ans++;
20                    } else
21                        ans += 2;
22                }
23            }
24        }
25        if (v.empty())
26            return ans;
27        return v.size() * 2 + ans;
28    }
29};