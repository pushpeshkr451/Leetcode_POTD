// Last updated: 05/07/2026, 16:12:17
1class Solution {
2public:
3    bool canMakeSubsequence(string s, string t) {
4        int i = 0, j = 0, n = s.length();
5        for (char c : t) {
6            j = max(j + (j < n && c == s[j] ? 1 : 0), i + 1);
7            i += (i < n && c == s[i] ? 1 : 0);
8        }
9        return j >= n;
10    }
11};