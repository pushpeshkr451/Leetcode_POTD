// Last updated: 20/07/2026, 14:25:53
1class Solution {
2public:
3    int strStr(string haystack, string needle) {
4        int n = haystack.size();
5        int m = needle.size();
6
7        for (int i = 0; i <= n - m; i++) {
8            if (haystack.substr(i, m) == needle)
9                return i;
10        }
11
12        return -1;
13    }
14};