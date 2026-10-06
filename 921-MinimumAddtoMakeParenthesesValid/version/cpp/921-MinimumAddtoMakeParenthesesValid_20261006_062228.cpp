// Last updated: 06/10/2026, 06:22:28
1class Solution {
2public:
3    int minAddToMakeValid(string s) {
4        int a = 0, b = 0;
5        for (auto it : s) {
6            if (it == '(')
7                a++;
8            else if (it == ')' && a > 0)
9                a--;
10            else if (it == ')')
11                b++;
12        }
13        return a + b;
14    }
15};