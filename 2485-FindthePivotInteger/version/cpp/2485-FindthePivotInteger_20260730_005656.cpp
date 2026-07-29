// Last updated: 30/07/2026, 00:56:56
1class Solution {
2public:
3    int pivotInteger(int n) {
4        int sum = n * (n + 1) / 2;
5
6        int cnt = 0;
7        for (int i = 1; i <= n; i++) {
8            cnt += i;
9            if (cnt == sum - cnt + i)
10                return i;
11        }
12
13        return -1;
14    }
15};