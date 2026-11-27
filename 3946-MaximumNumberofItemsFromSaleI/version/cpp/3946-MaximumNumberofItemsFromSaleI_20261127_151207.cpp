// Last updated: 27/11/2026, 15:12:07
1class Solution {
2public:
3    int maximumSaleItems(vector<vector<int>>& items, int budget) {
4        vector<int> f(budget + 1, 0);
5        int mn = INT_MAX;
6        for (const auto& item : items) {
7            int factor = item[0], price = item[1];
8            mn = min(mn, price);
9            int cnt = 0;
10            for (const auto& other : items) {
11                if (other[0] % factor == 0) {
12                    cnt++;
13                }
14            }
15            for (int j = budget; j >= price; j--) {
16                f[j] = max(f[j], f[j - price] + cnt);
17            }
18        }
19        int ans = 0;
20        for (int j = 0; j <= budget; j++) {
21            ans = max(ans, f[j] + (budget - j) / mn);
22        }
23        return ans;
24    }
25};