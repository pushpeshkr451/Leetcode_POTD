// Last updated: 02/08/2026, 15:32:58
1class Solution {
2public:
3    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
4        int a = 0, b = 0, c = 0;
5
6        int ans = 0;
7        int n = garbage.size();
8        for (int i = 0; i < n; i++) {
9            string s = garbage[i];
10            if (i == 0) {
11                ans += s.size();
12            } else {
13                for (int j = 0; j < s.size(); j++) {
14                    if (s[j] == 'M')
15                        a++;
16                    else if (s[j] == 'P')
17                        b++;
18                    else
19                        c++;
20                }
21            }
22        }
23
24        for (int i = 1; i < n; i++) {
25            string s = garbage[i];
26
27            int x = 0, y = 0, z = 0;
28            for (int j = 0; j < s.size(); j++) {
29                if (s[j] == 'M')
30                    x++;
31                else if (s[j] == 'P')
32                    y++;
33                else
34                    z++;
35            }
36            if (a > 0 || x > 0) {
37                ans += x;
38                ans += travel[i - 1];
39                a -= x;
40            }
41            if (b > 0 || y > 0) {
42                ans += y;
43                ans += travel[i - 1];
44                b -= y;
45            }
46            if (c > 0 || z > 0) {
47                ans += z;
48                ans += travel[i - 1];
49                c -= z;
50            }
51        }
52
53        return ans;
54    }
55};