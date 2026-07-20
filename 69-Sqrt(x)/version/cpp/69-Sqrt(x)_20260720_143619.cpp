// Last updated: 20/07/2026, 14:36:19
1class Solution {
2public:
3    int mySqrt(int x) {
4        int lo = 1, hi = x;
5
6        while (lo <= hi) {
7            int mid = lo + (hi - lo) / 2;
8            long long num = 1LL * mid * mid;
9
10            if (num == x)
11                return mid;
12            else if (num > x)
13                hi = mid - 1;
14            else
15                lo = mid + 1;
16        }
17
18        return hi;
19    }
20};