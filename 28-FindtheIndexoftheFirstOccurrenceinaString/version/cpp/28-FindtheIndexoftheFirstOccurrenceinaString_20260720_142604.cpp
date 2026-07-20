// Last updated: 20/07/2026, 14:26:04
1class Solution {
2public:
3    int strStr(string haystack, string needle) {
4        int n = haystack.size();
5        int m = needle.size();
6
7        if (m == 0)
8            return 0;
9
10        for (int i = 0; i <= n - m; i++) {
11            int j = 0;
12
13            while (j < m && haystack[i + j] == needle[j])
14                j++;
15
16            if (j == m)
17                return i;
18        }
19
20        return -1;
21    }
22};