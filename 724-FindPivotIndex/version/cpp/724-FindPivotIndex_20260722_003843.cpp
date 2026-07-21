// Last updated: 22/07/2026, 00:38:43
1class Solution {
2public:
3    int pivotIndex(vector<int>& nums) {
4        int n = nums.size();
5
6        vector<int> pre(n, 0), suff(n, 0);
7        pre[0] = nums[0];
8        suff[n - 1] = nums[n - 1];
9        for (int i = 1; i < n; i++)
10            pre[i] = pre[i - 1] + nums[i];
11
12        for (int i = n - 2; i >= 0; i--)
13            suff[i] = suff[i + 1] + nums[i];
14        for (int i = 0; i < n; i++) {
15            int psum = (i == 0) ? 0 : pre[i - 1];
16            int ssum = (i == n - 1) ? 0 : suff[i + 1];
17
18            if (psum == ssum)
19                return i;
20        }
21        return -1;
22    }
23};