// Last updated: 23/08/2026, 06:13:50
1class Solution {
2public:
3    bool sumGame(string s) {
4        double res = 0;
5        double n = s.length();
6        for (int i = 0; i < n; i++) {
7            double sign;
8            if (i < n / 2) {
9                sign = 1;
10            } else {
11                sign = -1;
12            }
13            double value;
14            if (s[i] == '?') {
15                value = 4.5;
16            } else {
17                value = s[i] - '0';
18            }
19            res += sign * value;
20        }
21        if (res != 0.0) {
22            return true;
23        } else {
24            return false;
25        }
26    }
27};