// Last updated: 20/09/2026, 09:21:05
1class Solution {
2public:
3    int reverseDegree(string s) {
4        int sum = 0;
5        for (int i = 0; i < s.size(); i++) {
6            sum += (i + 1) * (26 - (s[i] - 'a'));
7        }
8        return sum;
9    }
10};
11