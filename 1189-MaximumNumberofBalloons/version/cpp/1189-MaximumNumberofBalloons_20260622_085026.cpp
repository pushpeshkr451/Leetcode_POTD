// Last updated: 22/06/2026, 08:50:26
1class Solution {
2public:
3    int maxNumberOfBalloons(string text) {
4        int ans = 0;
5
6        while (true) {
7            string word = "balloon";
8
9            for (char &c : word) {
10                bool found = false;
11
12                for (char &ch : text) {
13                    if (ch == c) {
14                        ch = '#';
15                        found = true;
16                        break;
17                    }
18                }
19
20                if (!found) return ans;
21            }
22
23            ans++;
24        }
25    }
26};