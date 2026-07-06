// Last updated: 06/07/2026, 12:50:01
1class Solution {
2public:
3    int minOperations(string s1, string s2) {
4        if (s1 == "1" && s2 == "0") {
5            return -1;
6        }
7        int res = 0, n = s1.length();
8        for (int i = 0; i < n; i++) {
9            if (s1[i] == s2[i])
10                continue;
11            if (s1[i] == '0') {
12                res++;
13            } else if (i < n - 1) {
14                res += s1[i + 1] == '1' ? 1 : 2;
15                s1[i + 1] = '0';
16            } else {
17                res += 2;
18            }
19        }
20        return res;
21    }
22};