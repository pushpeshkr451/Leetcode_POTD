// Last updated: 05/07/2026, 16:13:09
1class Solution {
2public:
3    int divisibleGame(vector<int>& nums) {
4        const long long MOD = 1e9 + 7;
5        long long bestScore = -*min_element(nums.begin(), nums.end());
6        int bestPrime = 2;
7        set<int> Prime;
8        for(int num : nums) {
9            int x = num;
10            for(int i = 2; i * i <= x; i++) {
11                if(x % i == 0) {
12                    Prime.insert(i);
13                    while(x % i == 0) x/= i;
14                }
15            }
16            if(x > 1) Prime.insert(x);
17        }
18        for(int p : Prime) {
19            long long cur = 0;
20            long long maxi = LLONG_MIN;
21            for(int num : nums) {
22                long long val = (num % p == 0) ? num : -num;
23                cur = max(val, val + cur);
24                maxi = max(maxi, cur);
25            }
26            if(maxi > bestScore) {
27                bestScore = maxi;
28                bestPrime = p;
29            }
30            else if(maxi == bestScore && p < bestPrime) bestPrime = p;
31        }
32        bestScore = (bestScore % MOD + MOD) % MOD;
33        return (bestScore * bestPrime) % MOD;
34    }
35};