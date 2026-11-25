// Last updated: 25/11/2026, 12:36:48
1class Solution {
2public:
3    const long long MOD1 = 1e9 + 7;
4    const long long MOD2 = 1e9 + 9;
5
6    const long long P1 = 911382323;
7    const long long P2 = 972663759;
8
9    pair<long long, long long> get_hash(vector<int>& v, int l, int r) {
10        long long h1 = 0;
11        long long h2 = 0;
12
13        for (int i = l; i <= r; i++) {
14            h1 = (h1 * P1 + v[i]) % MOD1;
15            h2 = (h2 * P2 + v[i]) % MOD2;
16        }
17
18        return {h1, h2};
19    }
20
21    map<pair<long long, long long>, int> mp;
22    void solve(int len, vector<int>& a) {
23        int n = a.size();
24        long long pow1 = 1;
25        long long pow2 = 1;
26
27        for (int i = 0; i < len - 1; i++) {
28            pow1 = (pow1 * P1) % MOD1;
29            pow2 = (pow2 * P2) % MOD2;
30        }
31
32        long long h1 = 0;
33        long long h2 = 0;
34
35        for (int i = 0; i < len; i++) {
36            h1 = (h1 * P1 + a[i]) % MOD1;
37            h2 = (h2 * P2 + a[i]) % MOD2;
38        }
39
40        mp[{h1, h2}]++;
41
42        for (int i = len; i < n; i++) {
43            h1 = (((h1 - (a[i - len] * pow1) % MOD1 + MOD1) % MOD1) * P1 +
44                  a[i]) %
45                 MOD1;
46
47            h2 = (((h2 - (a[i - len] * pow2) % MOD2 + MOD2) % MOD2) * P2 +
48                  a[i]) %
49                 MOD2;
50
51            mp[{h1, h2}]++;
52        }
53    }
54    bool check(int len, vector<int>& nums) {
55        mp.clear();
56        solve(len, nums);
57        for (auto [val, freq] : mp) {
58            if (freq == 1)
59                return true;
60        }
61
62        return false;
63    }
64    int smallestUniqueSubarray(vector<int>& nums) {
65        int n = nums.size();
66        int l = 1, r = n;
67
68        while (l <= r) {
69            int mid = (l + r) / 2;
70            if (check(mid, nums))
71                r = mid - 1;
72            else
73                l = mid + 1;
74        }
75
76        return l;
77    }
78};