// Last updated: 15/09/2026, 09:51:10
1class Solution {
2public:
3    int maxPalindromes(string s, int k) {
4        int n = s.size(), lastEnd = 0, count = 0;
5
6        for (int center = 0; center < 2 * n; center++) {
7            int left = center / 2;
8            int right = left + center % 2;
9
10            while (left >= 0 && right < n && s[left] == s[right]) {
11                if (right - left + 1 >= k) {
12                    int end = right + 1;
13
14                    if (left >= lastEnd)
15                        lastEnd = end, count++;
16                    else
17                        lastEnd = min(lastEnd, end);
18
19                    break;
20                }
21                left--, right++;
22            }
23        }
24
25        return count;
26    }
27};