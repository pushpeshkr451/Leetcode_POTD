// Last updated: 21/08/2026, 13:06:33
1class Solution {
2public:
3    long long gcd(long long a, long long b) {
4        while (b) {
5            long long t = a % b;
6            a = b;
7            b = t;
8        }
9        return a;
10    }
11
12    long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
13
14    long long findKthSmallest(vector<int>& coins, int k) {
15        int n = coins.size();
16
17        vector<pair<long long, int>> subsets;
18
19        for (int mask = 1; mask < (1 << n); ++mask) {
20            long long curLcm = 1;
21            int bits = 0;
22
23            for (int i = 0; i < n; ++i) {
24                if (mask & (1 << i)) {
25                    ++bits;
26                    curLcm = lcm(curLcm, coins[i]);
27                }
28            }
29
30            subsets.push_back({curLcm, bits & 1 ? 1 : -1});
31        }
32
33        auto count = [&](long long x) {
34            long long total = 0;
35
36            for (auto [v, sign] : subsets) {
37                if (v > x)
38                    continue;
39
40                total += sign * (x / v);
41            }
42
43            return total;
44        };
45
46        long long left = 1;
47        long long right = 1LL * k * (*min_element(coins.begin(), coins.end()));
48
49        while (left < right) {
50            long long mid = left + (right - left) / 2;
51
52            if (count(mid) >= k)
53                right = mid;
54            else
55                left = mid + 1;
56        }
57
58        return left;
59    }
60};