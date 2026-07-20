// Last updated: 20/07/2026, 14:31:39
1class Solution {
2public:
3    int lengthOfLastWord(string s) {
4        int cnt = 0, ans;
5        int n = s.size();
6
7        int i = 0;
8        while (i < n) {
9            if (s[i] == ' ') {
10                if (cnt != 0)
11                    ans = cnt;
12                cnt = 0;
13            } else
14                cnt++;
15            i++;
16        }
17        if (cnt != 0)
18            ans = cnt;
19        return ans;
20    }
21};