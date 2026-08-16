// Last updated: 16/08/2026, 22:55:40
1class Solution {
2public:
3    bool stoneGameIX(vector<int>& stones) {
4        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
5        for (int val : stones) {
6            if (int type = val % 3; type == 0) {
7                ++cnt0;
8            } else if (type == 1) {
9                ++cnt1;
10            } else {
11                ++cnt2;
12            }
13        }
14        if (cnt0 % 2 == 0) {
15            return cnt1 >= 1 && cnt2 >= 1;
16        }
17        return cnt1 - cnt2 > 2 || cnt2 - cnt1 > 2;
18    }
19};