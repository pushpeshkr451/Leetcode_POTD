// Last updated: 15/07/2026, 03:33:10
1class Solution {
2public:
3    int countKeyChanges(string s) {
4        int ans = 0;
5
6        for (int i = 1; i < s.size(); i++) {
7            if (tolower(s[i]) != tolower(s[i - 1]))
8                ans++;
9        }
10
11        return ans;
12    }
13};