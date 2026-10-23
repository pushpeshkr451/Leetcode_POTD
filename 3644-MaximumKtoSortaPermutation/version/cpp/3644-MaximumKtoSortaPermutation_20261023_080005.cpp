// Last updated: 23/10/2026, 08:00:05
1class Solution {
2public:
3    int sortPermutation(vector<int>& nums) {
4        int n = (int)nums.size();
5        int k = -1;
6        bool ok = true;
7        for (int i = 0; i < n; ++i) {
8            if (nums[i] != i) {
9                ok = false;
10                k &= (i & nums[i]);
11            }
12        }
13        if (ok)
14            return 0;
15        return k;
16    }
17};