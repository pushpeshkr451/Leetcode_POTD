// Last updated: 14/11/2026, 12:15:40
1class Solution {
2public:
3    using ll = long long;
4    const ll inf = 1e18;
5    int minimumSumSubarray(vector<int>& nums, int l, int r) {
6        ll n = nums.size();
7        std::vector<ll> pref(n + 1, 0);
8        for (int i = 1; i <= n; i++) {
9            pref[i] = pref[i - 1] + nums[i - 1];
10        }
11
12        ll ans = inf;
13        for (int i = 0; i < n; i++) {
14            for (int j = l; j <= r && i + j <= n; j++) {
15                ll x = pref[i + j] - pref[i];
16
17                if (x > 0) {
18                    ans = std::min(ans, x);
19                }
20            }
21        }
22
23        return ans == inf ? -1 : ans;
24    }
25};