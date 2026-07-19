// Last updated: 19/07/2026, 08:40:41
1class Solution {
2public:
3    string rearrangeString(string s, char x, char y) {
4        vector<int> freq(26, 0);
5
6        for (char c : s)
7            freq[c - 'a']++;
8
9        string t = "";
10
11        while (freq[y - 'a'] > 0) {
12            t += y;
13            freq[y - 'a']--;
14        }
15
16        for (char c = 'a'; c <= 'z'; c++) {
17            if (c == x || c == y)
18                continue;
19
20            while (freq[c - 'a'] > 0) {
21                t += c;
22                freq[c - 'a']--;
23            }
24        }
25
26        while (freq[x - 'a'] > 0) {
27            t += x;
28            freq[x - 'a']--;
29        }
30
31        return t;
32    }
33};