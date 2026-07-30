// Last updated: 30/07/2026, 21:19:20
1class Solution {
2public:
3    int minimumPushes(string word) {
4        int n = word.size();
5        int ans = 0;
6        for (int i = 0; i < n; ++i) {
7            ans += i / 8 + 1;
8        }
9        return ans;
10    }
11};