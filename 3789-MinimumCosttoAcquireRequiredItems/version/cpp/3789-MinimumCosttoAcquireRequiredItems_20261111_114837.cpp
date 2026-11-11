// Last updated: 11/11/2026, 11:48:37
1class Solution {
2public:
3    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
4                          int need2) {
5        long long min, max, ans;
6        min = fmin(need1, need2);
7        max = fmax(need1, need2);
8        ans = (long long)need1 * cost1 + (long long)need2 * cost2;
9        ans = fmin(ans, (long long)min * costBoth +
10                            (long long)(need1 - min) * cost1 +
11                            (long long)(need2 - min) * cost2);
12        ans = fmin(ans, (long long)max * costBoth);
13        return ans;
14    }
15};