// Last updated: 24/11/2026, 11:18:07
1class Solution {
2public:
3    int maxLength(vector<int>& nums) {
4        int n = nums.size();
5        int bestLen = 0;
6        for (int i = 0; i < n; i++) {
7            unsigned long long prod;
8            int clcm;
9            int cgcd;
10            for (int j = i; j < n; j++) {
11                if (i == j) {
12                    prod = nums[j];
13                    clcm = nums[j];
14                    cgcd = nums[j];
15                } else {
16                    prod *= nums[j];
17                    clcm = lcm(clcm, nums[j]);
18                    cgcd = gcd(cgcd, nums[j]);
19                }
20                if (prod == clcm * cgcd)
21                    bestLen = max(bestLen, j - i + 1);
22            }
23        }
24        return bestLen;
25    }
26};