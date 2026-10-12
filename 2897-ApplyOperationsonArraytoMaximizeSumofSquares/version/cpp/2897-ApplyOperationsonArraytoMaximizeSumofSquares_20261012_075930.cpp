// Last updated: 12/10/2026, 07:59:30
1class Solution {
2public:
3    int maxSum(vector<int>& nums, int k) {
4        const int MOD = 1e9 + 7;
5        vector<int> store(31, 0);
6        for (int n : nums) {
7            for (int i = 0; i < 31; ++i) {
8                if ((n >> i) & 1) {
9                    store[i]++;
10                }
11            }
12        }
13        long long sum = 0;
14
15        for (int i = 0; i < k; ++i) {
16            long long cv = 0;
17            for (int b = 0; b < 31; ++b) {
18                if (store[b] > 0) {
19                    cv |= (1LL << b);
20                    store[b]--;
21                }
22            }
23            long long sqv = (cv % MOD) * (cv % MOD) % MOD;
24            sum = (sum + sqv) % MOD;
25        }
26        return sum;
27    }
28};