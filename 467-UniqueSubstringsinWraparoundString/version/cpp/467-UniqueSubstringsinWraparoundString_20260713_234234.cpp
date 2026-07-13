// Last updated: 13/07/2026, 23:42:34
1class Solution {
2public:
3    int findSubstringInWraproundString(string s) {
4        int n = s.size();
5        vector<int> dp(26, 0);
6
7        int len = 0;
8
9        for (int i = 0; i < n; i++) {
10            // cout << (s[i] - 'a') << " ";
11
12            if (i > 0 && ((s[i] - 'a') - (s[i - 1] - 'a') + 26) % 26 == 1)
13                len++;
14            else
15                len = 1;
16            dp[s[i] - 'a'] = max(dp[s[i] - 'a'], len);
17        }
18
19        int ans = 0;
20        for (auto it : dp)
21            ans += it;
22        return ans;
23    }
24};