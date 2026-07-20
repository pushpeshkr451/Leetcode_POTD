// Last updated: 20/07/2026, 14:36:38
1class Solution {
2public:
3    int mySqrt(int x) {
4        if (x == 0)
5            return 0;
6
7        int lo = 1, hi = x;
8
9        while (lo <= hi) {
10            int mid = lo + (hi - lo) / 2;
11
12            if (mid == x / mid)
13                return mid;
14            else if (mid > x / mid)
15                hi = mid - 1;
16            else
17                lo = mid + 1;
18        }
19
20        return hi;
21    }
22};