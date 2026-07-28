// Last updated: 28/07/2026, 07:25:10
1class Solution {
2public:
3    string smallestPalindrome(string s) {
4        vector<int> freq(26, 0);
5        for (char c : s)
6            freq[c - 'a']++;
7
8        string a = "", b = "";
9
10        for (int i = 0; i < 26; ++i) {
11            if (freq[i] % 2 == 1)
12                b = string(1, 'a' + i);
13            a += string(freq[i] / 2, 'a' + i);
14        }
15
16        string c = a;
17        reverse(c.begin(), c.end());
18
19        return a + b + c;
20    }
21};