// Last updated: 06/08/2026, 19:59:20
1class Solution {
2public:
3    int smallestNumber(int n, int t) {
4        auto [q, r] = div(n, 10);
5
6        int req = t / gcd(q + (10 - q) / 10, t);
7        int nxt = ((r + req - 1) / req) * req;
8        int x = nxt - (nxt - 10) * (nxt / 10);
9
10        return q * 10 + x;
11    }
12};